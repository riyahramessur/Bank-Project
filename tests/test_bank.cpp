#include <memory>
#include <gtest/gtest.h>

#include "Customer.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "BusinessAccount.h"
#include "BankSystem.h"
#include "Exceptions.h"

TEST(BankTests, DepositIncreasesBalance) {
    auto customer = std::make_shared<Customer>("C001", "Alice", "alice@example.com");
    CheckingAccount account("A001", customer, 1000.0);

    account.deposit(500.0);

    EXPECT_DOUBLE_EQ(account.getBalance(), 1500.0);
}

TEST(BankTests, CheckingWithdrawReducesBalance) {
    auto customer = std::make_shared<Customer>("C002", "Bob", "bob@example.com");
    CheckingAccount account("A002", customer, 1000.0);

    account.withdraw(300.0);

    EXPECT_DOUBLE_EQ(account.getBalance(), 700.0);
}

TEST(BankTests, SavingsWithdrawAboveLimitThrows) {
    auto customer = std::make_shared<Customer>("C003", "Carol", "carol@example.com");
    SavingsAccount account("A003", customer, 1000.0);

    EXPECT_THROW(account.withdraw(600.0), BankException);
}

TEST(BankTests, BusinessWithdrawAppliesFee) {
    auto customer = std::make_shared<Customer>("C004", "David", "david@example.com");
    BusinessAccount account("A004", customer, 1000.0);

    account.withdraw(200.0);

    EXPECT_DOUBLE_EQ(account.getBalance(), 750.0);
}

TEST(BankTests, InvalidDepositThrowsException) {
    auto customer = std::make_shared<Customer>("C005", "Emma", "emma@example.com");
    CheckingAccount account("A005", customer, 1000.0);

    EXPECT_THROW(account.deposit(-100.0), InvalidAmountException);
}

TEST(BankTests, MissingAccountThrowsException) {
    BankSystem bank;

    EXPECT_THROW(bank.depositToAccount("A999", 100.0), AccountNotFoundException);
}