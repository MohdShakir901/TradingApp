#include "../include/TransactionHistory.h"
#include <iostream>

using namespace std;

TransactionHistory::TransactionHistory()
    : nextTransactionId(1)
{
}

void TransactionHistory::addTransaction(std::string type, std::string stockSymbol, int quantity, double price){

    Transaction transaction(
        nextTransactionId,
        type,
        stockSymbol,
        quantity,
        price
    );

    transactions.push_back(transaction);

    nextTransactionId++;
}

void TransactionHistory::displayHistory() const
{
    if (transactions.empty())
    {
        cout << "\nNo transactions found.\n";
        return;
    }

    cout << "\n========== TRANSACTION HISTORY ==========\n";

    for (const Transaction &transaction : transactions)
    {
        transaction.displayTransaction();
    }
}

const std::vector<Transaction> &
TransactionHistory::getTransactions() const
{
    return transactions;
}

void TransactionHistory::loadTransactions(
    const std::vector<Transaction> &loadedTransactions)
{
    transactions = loadedTransactions;

    if (!transactions.empty())
    {
        nextTransactionId =
            transactions.back().getTransactionId() + 1;
    }
}