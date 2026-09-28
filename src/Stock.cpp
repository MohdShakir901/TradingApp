#include "../include/Stock.h"
#include <iostream>
using namespace std;

Stock::Stock(int id, std::string symbol, std::string companyName, double price)
    : stockId(id),
      symbol(symbol),
      companyName(companyName),
      price(price)
{
}

void Stock::displayStock() const{
    cout << "Stock ID     : " << stockId << endl;
    cout << "Symbol       : " << symbol << endl;
    cout << "Comapny      : " << companyName << endl;
    cout << "Price        : ₹" << price << endl;
}

int Stock::getStockId() const
{
    return stockId;
}

std::string Stock::getSymbol() const
{
    return symbol;
}

std::string Stock::getCompanyName() const
{
    return companyName;
}

double Stock::getPrice() const
{
    return price;
}