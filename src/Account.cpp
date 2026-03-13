#include "Account.h"
#include "Exceptions.h"
#include "Constants.h"

Account::Account(const std::string& accountId, std::shared_ptr<Customer> owner, double initialBalance)
    : accountId(accountId), balance(initialBalance), owner(owner) {
}

void Account::deposit(double amount) {
    if (amount < Constants::MIN_TRANSACTION_AMOUNT) {
        throw InvalidAmountException(amount);
    }

    balance += amount;
}

std::string Account::getAccountId() const {
    return accountId;
}

double Account::getBalance() const {
    return balance;
}

std::shared_ptr<Customer> Account::getOwner() const {
    return owner;
}