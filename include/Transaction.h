#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string transactionId;
    std::string type;
    double amount;

public:
    Transaction(const std::string& transactionId, const std::string& type, double amount);

    std::string getTransactionId() const;
    std::string getType() const;
    double getAmount() const;
};

#endif