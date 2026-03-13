#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "BankSystem.h"

class FileManager {
public:
    static void saveCustomers(const BankSystem& bankSystem, const std::string& filename);
    static void saveAccounts(const BankSystem& bankSystem, const std::string& filename);
    static void saveTransactions(const BankSystem& bankSystem, const std::string& filename);

    static void loadCustomers(BankSystem& bankSystem, const std::string& filename);
    static void loadAccounts(BankSystem& bankSystem, const std::string& filename);
    static void loadTransactions(BankSystem& bankSystem, const std::string& filename);
};

#endif