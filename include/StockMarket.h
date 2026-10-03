#ifndef STOCK_MARKET_H
#define STOCK_MARKET_H

#include "Stock.h"
#include <vector>

class StockMarket{
    private:
       std::vector<Stock> stocks;

   public:
       void addStock(const Stock &stock);

       void displayStocks() const;

       Stock *findStock(const std::string &symbol);

       Stock *getStockById(int id);
};

#endif