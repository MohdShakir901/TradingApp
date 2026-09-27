#include "../include/stock.h"
#include <iostream>
using namespace std;

Stock::Stock(int id, std::string symbol, std::string companyName, double price){
    this->stockId = id;
    this->symbol = symbol;
    this->companyName = companyName;
    this->price = price;
}

void Stock::displayStock() const{
    cout << "Stock ID     : " << stockId << endl;
    cout << "Symbol       : " << symbol << endl;
    cout << "Comapny      : " << companyName << endl;
    cout << "Price        : ₹" << price << endl;
}