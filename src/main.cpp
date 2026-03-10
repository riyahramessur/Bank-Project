#include <iostream>
#include <memory>
#include "BankSystem.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "BusinessAccount.h"

int main() {
    BankSystem bank;

    std::shared_ptr<Customer> customer1 = std::make_shared<Customer>(
        "C001", "Alice Smith", "alice@example.com"
    );

    std::shared_ptr<Customer> customer2 = std::make_shared<Customer>(
        "C002", "Bob Johnson", "bob@example.com"
    );

    bank.addCustomer(customer1);
    bank.addCustomer(customer2);

    bank.addAccount(std::make_unique<CheckingAccount>("A001", customer1, 1000.0));
    bank.addAccount(std::make_unique<SavingsAccount>("A002", customer1, 2000.0));
    bank.addAccount(std::make_unique<BusinessAccount>("A003", customer2, 5000.0));

    try {
        bank.depositToAccount("A001", -100.0);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}