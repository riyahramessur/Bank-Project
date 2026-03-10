#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance);

    void withdraw(double amount) override;
    std::string getType() const override;
};

#endif