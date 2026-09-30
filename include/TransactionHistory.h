#ifndef TRANSACTION_HISTORY_H
#define TRANSACTION_HISTORY_H

#include "Transaction.h"
#include <vector>

class TransactionHistory
{
private:
    std::vector<Transaction> transactions;
    int nextTransactionId;

public:
    TransactionHistory();

    void addTransaction(
        std::string type,
        std::string stockSymbol,
        int quantity,
        double price);

    void displayHistory() const;
};

#endif