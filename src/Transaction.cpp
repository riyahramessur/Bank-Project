#include "Transaction.h"

Transaction::Transaction(const std::string& transactionId, const std::string& type, double amount)
    : transactionId(transactionId), type(type), amount(amount) {
}

std::string Transaction::getTransactionId() const {
    return transactionId;
}

std::string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}