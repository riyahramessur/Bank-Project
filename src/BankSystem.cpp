#include <iostream>
#include "BankSystem.h"
#include "Exceptions.h"

void BankSystem::addCustomer(std::shared_ptr<Customer> customer) {
    customers.push_back(customer);
}

void BankSystem::addAccount(std::unique_ptr<Account> account) {
    accounts.push_back(std::move(account));
}

void BankSystem::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

std::shared_ptr<Customer> BankSystem::findCustomerById(const std::string& customerId) const {
    for (const auto& customer : customers) {
        if (customer->getCustomerId() == customerId) {
            return customer;
        }
    }
    return nullptr;
}

Account* BankSystem::findAccountById(const std::string& accountId) const {
    for (const auto& account : accounts) {
        if (account->getAccountId() == accountId) {
            return account.get();
        }
    }

    throw AccountNotFoundException(accountId);
}

void BankSystem::depositToAccount(const std::string& accountId, double amount) {
    Account* account = findAccountById(accountId);

    account->deposit(amount);

    transactions.push_back(Transaction(
        "T" + std::to_string(transactions.size() + 1),
        "Deposit",
        amount
    ));
}

void BankSystem::withdrawFromAccount(const std::string& accountId, double amount) {
    Account* account = findAccountById(accountId);

    account->withdraw(amount);

    transactions.push_back(Transaction(
        "T" + std::to_string(transactions.size() + 1),
        "Withdraw",
        amount
    ));
}

void BankSystem::transferBetweenAccounts(
    const std::string& fromAccountId,
    const std::string& toAccountId,
    double amount)
{
    Account* fromAccount = findAccountById(fromAccountId);
    Account* toAccount = findAccountById(toAccountId);

    fromAccount->withdraw(amount);
    toAccount->deposit(amount);

    transactions.push_back(Transaction(
        "T" + std::to_string(transactions.size() + 1),
        "Transfer",
        amount
    ));
}

void BankSystem::showAllCustomers() const {
    for (const auto& customer : customers) {
        std::cout << "Customer ID: " << customer->getCustomerId()
            << ", Name: " << customer->getName()
            << ", Email: " << customer->getEmail() << std::endl;
    }
}

void BankSystem::showAllAccounts() const {
    for (const auto& account : accounts) {
        std::cout << "Account ID: " << account->getAccountId()
            << ", Type: " << account->getType()
            << ", Owner: " << account->getOwner()->getName()
            << ", Balance: " << account->getBalance() << std::endl;
    }
}

void BankSystem::showAllTransactions() const {
    for (const auto& transaction : transactions) {
        std::cout << "Transaction ID: " << transaction.getTransactionId()
            << ", Type: " << transaction.getType()
            << ", Amount: " << transaction.getAmount() << std::endl;
    }
}