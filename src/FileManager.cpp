#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <variant>
#include "FileManager.h"
#include "Exceptions.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "BusinessAccount.h"

static std::vector<std::string> splitLine(const std::string& line, char delimiter) {
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string part;

    while (std::getline(ss, part, delimiter)) {
        parts.push_back(part);
    }

    return parts;
}

void FileManager::saveCustomers(const BankSystem& bankSystem, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw BankException("Failed to open customer file for writing: " + filename);
    }

    for (const auto& customer : bankSystem.getCustomers()) {
        file << customer->getCustomerId() << ","
            << customer->getName() << ","
            << customer->getEmail() << "\n";
    }
}

void FileManager::saveAccounts(const BankSystem& bankSystem, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw BankException("Failed to open account file for writing: " + filename);
    }

    for (const auto& account : bankSystem.getAccounts()) {
        file << account->getAccountId() << ","
            << account->getType() << ","
            << account->getOwner()->getCustomerId() << ","
            << account->getBalance() << "\n";
    }
}

void FileManager::saveTransactions(const BankSystem& bankSystem, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw BankException("Failed to open transaction file for writing: " + filename);
    }

    for (const auto& transaction : bankSystem.getTransactions()) {
        file << transaction.getTransactionId() << ","
            << transaction.getType() << ","
            << transaction.getAmount();

        std::visit([&file](const auto& data) {
            using T = std::decay_t<decltype(data)>;

            if constexpr (std::is_same_v<T, DepositData>) {
                file << "," << data.accountId;
            }
            else if constexpr (std::is_same_v<T, WithdrawData>) {
                file << "," << data.accountId;
            }
            else if constexpr (std::is_same_v<T, TransferData>) {
                file << "," << data.fromAccountId
                    << "," << data.toAccountId;
            }
            }, transaction.getData());

        file << "\n";
    }
}

void FileManager::loadCustomers(BankSystem& bankSystem, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw BankException("Failed to open customer file for reading: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> parts = splitLine(line, ',');

        if (parts.size() != 3) {
            throw BankException("Invalid customer record: " + line);
        }

        bankSystem.addCustomer(
            std::make_shared<Customer>(parts[0], parts[1], parts[2])
        );
    }
}

void FileManager::loadAccounts(BankSystem& bankSystem, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw BankException("Failed to open account file for reading: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> parts = splitLine(line, ',');

        if (parts.size() != 4) {
            throw BankException("Invalid account record: " + line);
        }

        std::string accountId = parts[0];
        std::string type = parts[1];
        std::string ownerId = parts[2];
        double balance = std::stod(parts[3]);

        auto ownerOptional = bankSystem.findCustomerById(ownerId);

        if (!ownerOptional) {
            throw BankException("Owner not found for account: " + accountId);
        }

        std::shared_ptr<Customer> owner = *ownerOptional;

        if (type == "Checking") {
            bankSystem.addAccount(
                std::make_unique<CheckingAccount>(accountId, owner, balance)
            );
        }
        else if (type == "Savings") {
            bankSystem.addAccount(
                std::make_unique<SavingsAccount>(accountId, owner, balance)
            );
        }
        else if (type == "Business") {
            bankSystem.addAccount(
                std::make_unique<BusinessAccount>(accountId, owner, balance)
            );
        }
        else {
            throw BankException("Unknown account type: " + type);
        }
    }
}

void FileManager::loadTransactions(BankSystem& bankSystem, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw BankException("Failed to open transaction file for reading: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> parts = splitLine(line, ',');

        if (parts.size() < 4) {
            throw BankException("Invalid transaction record: " + line);
        }

        std::string transactionId = parts[0];
        std::string type = parts[1];
        double amount = std::stod(parts[2]);

        if (type == "Deposit") {
            if (parts.size() != 4) {
                throw BankException("Invalid deposit transaction: " + line);
            }

            bankSystem.addTransaction(
                Transaction(transactionId, amount, DepositData{ parts[3] })
            );
        }
        else if (type == "Withdraw") {
            if (parts.size() != 4) {
                throw BankException("Invalid withdraw transaction: " + line);
            }

            bankSystem.addTransaction(
                Transaction(transactionId, amount, WithdrawData{ parts[3] })
            );
        }
        else if (type == "Transfer") {
            if (parts.size() != 5) {
                throw BankException("Invalid transfer transaction: " + line);
            }

            bankSystem.addTransaction(
                Transaction(transactionId, amount, TransferData{ parts[3], parts[4] })
            );
        }
        else {
            throw BankException("Unknown transaction type: " + type);
        }
    }
}