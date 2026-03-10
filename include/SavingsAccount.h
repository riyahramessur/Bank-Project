#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance);

    void withdraw(double amount) override;
    std::string getType() const override;
};

#endif