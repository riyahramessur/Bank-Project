#include "CheckingAccount.h"
#include "Exceptions.h"

CheckingAccount::CheckingAccount(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance)
    : Account(accountId, owner, initialBalance) {
}

void CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw InvalidAmountException(amount);
    }

    if (amount > balance) {
        throw InsufficientFundsException();
    }

    balance -= amount;
}

std::string CheckingAccount::getType() const {
    return "Checking";
}