#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include "BankSystem.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "BusinessAccount.h"
#include "FileManager.h"

void showMenu() {
    std::cout << "\n===== Bank Project Menu =====\n";
    std::cout << "1. Add Customer\n";
    std::cout << "2. Create Checking Account\n";
    std::cout << "3. Create Savings Account\n";
    std::cout << "4. Create Business Account\n";
    std::cout << "5. Deposit\n";
    std::cout << "6. Withdraw\n";
    std::cout << "7. Transfer\n";
    std::cout << "8. Show Customers\n";
    std::cout << "9. Show Accounts\n";
    std::cout << "10. Show Transactions\n";
    std::cout << "11. Save Data\n";
    std::cout << "12. Load Data\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    BankSystem bank;
    int choice = -1;

    while (choice != 0) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            clearInput();
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        clearInput();

        try {
            if (choice == 1) {
                std::string customerId, name, email;

                std::cout << "Enter customer ID: ";
                std::getline(std::cin, customerId);

                std::cout << "Enter customer name: ";
                std::getline(std::cin, name);

                std::cout << "Enter customer email: ";
                std::getline(std::cin, email);

                bank.addCustomer(std::make_shared<Customer>(customerId, name, email));
                std::cout << "Customer added successfully.\n";
            }
            else if (choice == 2 || choice == 3 || choice == 4) {
                std::string accountId, ownerId;
                double initialBalance;

                std::cout << "Enter account ID: ";
                std::getline(std::cin, accountId);

                std::cout << "Enter owner customer ID: ";
                std::getline(std::cin, ownerId);

                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;

                if (std::cin.fail()) {
                    clearInput();
                    std::cout << "Invalid balance input.\n";
                    continue;
                }

                clearInput();

                auto ownerOptional = bank.findCustomerById(ownerId);

                if (!ownerOptional) {
                    std::cout << "Customer not found.\n";
                    continue;
                }

                std::shared_ptr<Customer> owner = *ownerOptional;

                if (choice == 2) {
                    bank.addAccount(std::make_unique<CheckingAccount>(accountId, owner, initialBalance));
                    std::cout << "Checking account created successfully.\n";
                }
                else if (choice == 3) {
                    bank.addAccount(std::make_unique<SavingsAccount>(accountId, owner, initialBalance));
                    std::cout << "Savings account created successfully.\n";
                }
                else {
                    bank.addAccount(std::make_unique<BusinessAccount>(accountId, owner, initialBalance));
                    std::cout << "Business account created successfully.\n";
                }
            }
            else if (choice == 5) {
                std::string accountId;
                double amount;

                std::cout << "Enter account ID: ";
                std::getline(std::cin, accountId);

                std::cout << "Enter deposit amount: ";
                std::cin >> amount;

                if (std::cin.fail()) {
                    clearInput();
                    std::cout << "Invalid amount input.\n";
                    continue;
                }

                clearInput();

                bank.depositToAccount(accountId, amount);
                std::cout << "Deposit successful.\n";
            }
            else if (choice == 6) {
                std::string accountId;
                double amount;

                std::cout << "Enter account ID: ";
                std::getline(std::cin, accountId);

                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;

                if (std::cin.fail()) {
                    clearInput();
                    std::cout << "Invalid amount input.\n";
                    continue;
                }

                clearInput();

                bank.withdrawFromAccount(accountId, amount);
                std::cout << "Withdrawal successful.\n";
            }
            else if (choice == 7) {
                std::string fromAccountId, toAccountId;
                double amount;

                std::cout << "Enter source account ID: ";
                std::getline(std::cin, fromAccountId);

                std::cout << "Enter destination account ID: ";
                std::getline(std::cin, toAccountId);

                std::cout << "Enter transfer amount: ";
                std::cin >> amount;

                if (std::cin.fail()) {
                    clearInput();
                    std::cout << "Invalid amount input.\n";
                    continue;
                }

                clearInput();

                bank.transferBetweenAccounts(fromAccountId, toAccountId, amount);
                std::cout << "Transfer successful.\n";
            }
            else if (choice == 8) {
                bank.showAllCustomers();
            }
            else if (choice == 9) {
                bank.showAllAccounts();
            }
            else if (choice == 10) {
                bank.showAllTransactions();
            }
            else if (choice == 11) {
                FileManager::saveCustomers(bank, "data/customers.txt");
                FileManager::saveAccounts(bank, "data/accounts.txt");
                FileManager::saveTransactions(bank, "data/transactions.txt");
                std::cout << "Data saved successfully.\n";
            }
            else if (choice == 12) {
                FileManager::loadCustomers(bank, "data/customers.txt");
                FileManager::loadAccounts(bank, "data/accounts.txt");
                FileManager::loadTransactions(bank, "data/transactions.txt");
                std::cout << "Data loaded successfully.\n";
            }
            else if (choice == 0) {
                std::cout << "Exiting program.\n";
            }
            else {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}