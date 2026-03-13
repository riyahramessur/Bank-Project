#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <memory>
#include <optional>
#include <vector>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"
#include <optional>

class BankSystem {
private:
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::unique_ptr<Account>> accounts;
    std::vector<Transaction> transactions;

public:
    const std::vector<std::shared_ptr<Customer>>& getCustomers() const;
    const std::vector<std::unique_ptr<Account>>& getAccounts() const;
    const std::vector<Transaction>& getTransactions() const;

    void addCustomer(std::shared_ptr<Customer> customer);
    void addAccount(std::unique_ptr<Account> account);
    void addTransaction(const Transaction& transaction);

    std::optional<std::shared_ptr<Customer>> findCustomerById(const std::string& customerId) const;
    Account* findAccountById(const std::string& accountId) const;

    void depositToAccount(const std::string& accountId, double amount);
    void withdrawFromAccount(const std::string& accountId, double amount);
    void transferBetweenAccounts(const std::string& fromAccountId, const std::string& toAccountId, double amount);

    void showAllCustomers() const;
    void showAllAccounts() const;
    void showAllTransactions() const;

    void clearAllData();
};

#endif