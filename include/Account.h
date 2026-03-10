#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <memory>
#include <string>
#include "Customer.h"

class Account {
protected:
    std::string accountId;
    double balance;
    std::shared_ptr<Customer> owner;

public:
    Account(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance);
    virtual ~Account() = default;

    void deposit(double amount);
    virtual void withdraw(double amount) = 0;
    virtual std::string getType() const = 0;

    std::string getAccountId() const;
    double getBalance() const;
    std::shared_ptr<Customer> getOwner() const;
};

#endif