#include "../include/Transaction.h"
#include <iostream>

using namespace std;

Transaction::Transaction(
    int id,
    std::string type,
    std::string stockSymbol,
    int quantity,
    double price)
    : transactionId(id),
      type(type),
      stockSymbol(stockSymbol),
      quantity(quantity),
      price(price),
      totalAmount(quantity * price)
{
}

void Transaction::displayTransaction() const{

    cout << "\n========== TRANSACTION ==========\n";

    cout << "Transaction ID : " << transactionId << endl;
    cout << "Type           : " << type << endl;
    cout << "Stock          : " << stockSymbol << endl;
    cout << "Quantity       : " << quantity << endl;
    cout << "Price          : ₹" << price << endl;
    cout << "Total Amount   : ₹" << totalAmount << endl;
}

int Transaction::getTransactionId() const{
    return transactionId;
}

std::string Transaction::getType() const{
    return type;
}

std::string Transaction::getStockSymbol() const{
    return stockSymbol;
}

int Transaction::getQuantity() const{
    return quantity;
}

double Transaction::getPrice() const{
    return price;
}

double Transaction::getTotalAmount() const{
    return totalAmount;
}