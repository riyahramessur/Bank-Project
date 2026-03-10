#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string customerId;
    std::string name;
    std::string email;

public:
    Customer(const std::string& customerId, const std::string& name, const std::string& email);

    std::string getCustomerId() const;
    std::string getName() const;
    std::string getEmail() const;
};

#endif