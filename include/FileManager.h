#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Transaction.h"
#include <vector>
#include <string>

class FileManager
{
public:
    static void saveTransactions(
        const std::vector<Transaction> &transactions,
        const std::string &filename);

    static std::vector<Transaction> loadTransactions(
        const std::string &filename);
};

#endif