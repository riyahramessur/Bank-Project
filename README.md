# Bank Project

A console-based C++ banking system built using object-oriented programming and modern C++ features.

## Overview

This project simulates a simple banking system where users can:

- add customers
- create different account types
- deposit money
- withdraw money
- transfer money between accounts
- view customers, accounts, and transactions
- save data to files
- load data from files

The project was designed to demonstrate OOP principles, inheritance, polymorphism, smart pointers, exception handling, file I/O and unit testing.

## Features

### Customer management
- Add customers with ID, name, and email

### Account management
- Create checking accounts
- Create savings accounts
- Create business accounts

### Banking operations
- Deposit money
- Withdraw money
- Transfer money between accounts

### Transaction tracking
- Records deposits, withdrawals, and transfers
- Uses `std::variant` to store different transaction data types
- Uses `std::visit` to process transaction data safely

### File persistence
- Save customers, accounts, and transactions to text files
- Load saved data back into the system

### Error handling
- Custom exceptions for:
  1. account not found
  2. invalid amounts
  3. insufficient funds
  4. file access failures

### Unit testing
- GoogleTest is used to test the core banking logic

## Project Structure

Bank Project/
├── include/
│   ├── Account.h
│   ├── BankSystem.h
│   ├── BusinessAccount.h
│   ├── CheckingAccount.h
│   ├── Constants.h
│   ├── Customer.h
│   ├── Exceptions.h
│   ├── FileManager.h
│   ├── SavingsAccount.h
│   └── Transaction.h
├── src/
│   ├── Account.cpp
│   ├── BankSystem.cpp
│   ├── BusinessAccount.cpp
│   ├── CheckingAccount.cpp
│   ├── Customer.cpp
│   ├── FileManager.cpp
│   ├── main.cpp
│   ├── SavingsAccount.cpp
│   └── Transaction.cpp
├── tests/
│   └── test_bank.cpp
├── data/
├── CMakeLists.txt
├── README.md
└── .gitignore