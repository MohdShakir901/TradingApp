#include "../include/StockMarket.h"
#include <iostream>

using namespace std;

void StockMarket::addStock(const Stock &stock)
{
    stocks.push_back(stock);
}

void StockMarket::displayStocks() const{
    if (stocks.empty())
    {
        cout << "\nNo stocks available.\n";
        return;
    }

    cout << "\n========== AVAILABLE STOCKS ==========\n";

    for (const Stock &stock : stocks)
    {
        stock.displayStock();
        cout << "--------------------------------\n";
    }
}
Stock *StockMarket::findStock(const std::string &symbol)
{
    for (Stock &stock : stocks)
    {
        if (stock.getSymbol() == symbol)
        {
            return &stock;
        }
    }

    return nullptr;
}

Stock *StockMarket::getStockById(int id)
{
    for (Stock &stock : stocks)
    {
        if (stock.getStockId() == id)
        {
            return &stock;
        }
    }

    return nullptr;
}