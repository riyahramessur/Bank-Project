#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <variant>

struct DepositData {
    std::string accountId;
};

struct WithdrawData {
    std::string accountId;
};

struct TransferData {
    std::string fromAccountId;
    std::string toAccountId;
};

using TransactionData = std::variant<DepositData, WithdrawData, TransferData>;

class Transaction {
private:
    std::string transactionId;
    double amount;
    TransactionData data;

public:
    Transaction(const std::string& transactionId, double amount, const TransactionData& data);

    std::string getTransactionId() const;
    double getAmount() const;
    TransactionData getData() const;
    std::string getType() const;
};

#endif