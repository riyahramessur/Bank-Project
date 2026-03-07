cmake_minimum_required(VERSION 3.16)

project(BankProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BankProject
    src/main.cpp
    src/Account.cpp
    src/SavingsAccount.cpp
    src/CheckingAccount.cpp
    src/BusinessAccount.cpp
    src/Customer.cpp
    src/Transaction.cpp
    src/BankSystem.cpp
    src/FileManager.cpp
)

target_include_directories(BankProject PRIVATE include)