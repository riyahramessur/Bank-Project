#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class BankException : public std::runtime_error {
public:
    explicit BankException(const std::string& message)
        : std::runtime_error(message) {}
};

class AccountNotFoundException : public BankException {
public:
    explicit AccountNotFoundException(const std::string& id)
        : BankException("Account not found: " + id) {
    }
};

class InvalidAmountException : public BankException {
public:
    explicit InvalidAmountException(double amount)
        : BankException("Invalid amount: " + std::to_string(amount)) {
    }
};

class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException()
        : BankException("Insufficient funds") {
    }
};

#endif