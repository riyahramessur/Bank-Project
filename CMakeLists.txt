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

# ---------------------------
# GoogleTest setup
# ---------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(BankProjectTests
    tests/test_bank.cpp
    src/Account.cpp
    src/SavingsAccount.cpp
    src/CheckingAccount.cpp
    src/BusinessAccount.cpp
    src/Customer.cpp
    src/Transaction.cpp
    src/BankSystem.cpp
    src/FileManager.cpp
)

target_include_directories(BankProjectTests PRIVATE include)

target_link_libraries(BankProjectTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(BankProjectTests)