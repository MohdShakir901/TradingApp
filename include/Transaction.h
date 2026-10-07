#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction{
    
private:
    int transactionId;
    std::string type;
    std::string stockSymbol;
    int quantity;
    double price;
    double totalAmount;

public:
    Transaction(
        int id,
        std::string type,
        std::string stockSymbol,
        int quantity,
        double price);

    void displayTransaction() const;

    int getTransactionId() const;
    std::string getType() const;
    std::string getStockSymbol() const;
    int getQuantity() const;
    double getPrice() const;
    double getTotalAmount() const;
};

#endif