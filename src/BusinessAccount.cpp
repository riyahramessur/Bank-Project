#include "BusinessAccount.h"
#include "Exceptions.h"
#include "Constants.h"

BusinessAccount::BusinessAccount(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance)
    : Account(accountId, owner, initialBalance) {
}

void BusinessAccount::withdraw(double amount) {
    const double fee = Constants::BUSINESS_TRANSACTION_FEE;

    if (amount <= 0) {
        throw InvalidAmountException(amount);
    }

    if (amount + fee > balance) {
        throw InsufficientFundsException();
    }

    balance -= (amount + fee);
}

std::string BusinessAccount::getType() const {
    return "Business";
}