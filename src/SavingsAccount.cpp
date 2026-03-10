#include "SavingsAccount.h"
#include "Exceptions.h"

SavingsAccount::SavingsAccount(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance)
    : Account(accountId, owner, initialBalance) {
}

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw InvalidAmountException(amount);
    }

    if (amount > 500.0) {
        throw BankException("Savings withdrawal limit exceeded");
    }

    if (amount > balance) {
        throw InsufficientFundsException();
    }

    balance -= amount;
}

std::string SavingsAccount::getType() const {
    return "Savings";
}