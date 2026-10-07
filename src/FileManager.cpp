#include "../include/FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void FileManager::saveTransactions(
    const vector<Transaction> &transactions,
    const string &filename){
    ofstream file(filename);

    if (!file.is_open()){
        cout << "Error: Could not open file for writing.\n";
        return;
    }

    for (const Transaction &transaction : transactions){
        file << transaction.getTransactionId() << "|"
             << transaction.getType() << "|"
             << transaction.getStockSymbol() << "|"
             << transaction.getQuantity() << "|"
             << transaction.getPrice() << "|"
             << transaction.getTotalAmount()
             << "\n";
    }

    file.close();
}

vector<Transaction> FileManager::loadTransactions(
    const string &filename){
    vector<Transaction> transactions;

    ifstream file(filename);

    if (!file.is_open()){
        return transactions;
    }

    string line;

    while (getline(file, line)){
        stringstream ss(line);

        string id;
        string type;
        string symbol;
        string quantity;
        string price;
        string totalAmount;

        getline(ss, id, '|');
        getline(ss, type, '|');
        getline(ss, symbol, '|');
        getline(ss, quantity, '|');
        getline(ss, price, '|');
        getline(ss, totalAmount, '|');

        Transaction transaction(
            stoi(id),
            type,
            symbol,
            stoi(quantity),
            stod(price));

        transactions.push_back(transaction);
    }

    file.close();

    return transactions;
}