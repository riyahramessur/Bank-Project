#ifndef BUSINESSACCOUNT_H
#define BUSINESSACCOUNT_H

#include "Account.h"

class BusinessAccount : public Account {
public:
    BusinessAccount(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance);

    void withdraw(double amount) override;
    std::string getType() const override;
};

#endif