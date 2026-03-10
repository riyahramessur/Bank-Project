#include "Customer.h"

Customer::Customer(const std::string& customerId, const std::string& name, const std::string& email)
    : customerId(customerId), name(name), email(email) {
}

std::string Customer::getCustomerId() const {
    return customerId;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getEmail() const {
    return email;
}