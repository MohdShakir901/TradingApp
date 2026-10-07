#ifndef STOCK_H
#define STOCK_H

#include<string>

class Stock{
    
    private:
    int stockId;
    std::string symbol;
    std::string companyName;
    double price;

    public:
    Stock(int id, std::string symbol, std::string companyName, double price);

    void displayStock() const;

    int getStockId() const;
    std::string getSymbol() const;
    std::string getCompanyName() const;
    double getPrice() const;
};
#endif