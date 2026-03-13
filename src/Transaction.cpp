#include "Transaction.h"

Transaction::Transaction(const std::string& transactionId, double amount, const TransactionData& data)
    : transactionId(transactionId), amount(amount), data(data) {
}

std::string Transaction::getTransactionId() const {
    return transactionId;
}

double Transaction::getAmount() const {
    return amount;
}

TransactionData Transaction::getData() const {
    return data;
}

std::string Transaction::getType() const {
    if (std::holds_alternative<DepositData>(data)) {
        return "Deposit";
    }
    if (std::holds_alternative<WithdrawData>(data)) {
        return "Withdraw";
    }
    return "Transfer";
}