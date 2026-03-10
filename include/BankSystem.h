#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <memory>
#include <optional>
#include <vector>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"

class BankSystem {
private:
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::unique_ptr<Account>> accounts;
    std::vector<Transaction> transactions;

public:
    void addCustomer(std::shared_ptr<Customer> customer);
    void addAccount(std::unique_ptr<Account> account);
    void addTransaction(const Transaction& transaction);

    std::shared_ptr<Customer> findCustomerById(const std::string& customerId) const;
    Account* findAccountById(const std::string& accountId) const;

    void depositToAccount(const std::string& accountId, double amount);
    void withdrawFromAccount(const std::string& accountId, double amount);
    void transferBetweenAccounts(const std::string& fromAccountId, const std::string& toAccountId, double amount);

    void showAllCustomers() const;
    void showAllAccounts() const;
    void showAllTransactions() const;
};

#endif