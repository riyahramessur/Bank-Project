#include "SavingsAccount.h"
#include "Exceptions.h"
#include "Constants.h"

SavingsAccount::SavingsAccount(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance)
    : Account(accountId, owner, initialBalance) {
}

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw InvalidAmountException(amount);
    }

    if (amount > Constants::SAVINGS_WITHDRAWAL_LIMIT) {
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