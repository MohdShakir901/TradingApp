#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Holding.h"
#include <vector>

class Portfolio{
    private:
       std::vector<Holding> holdings;

    public:
       void addHolding(Stock stock, int quantity, double price);

       bool sellStock(const std::string& symbol, int quantity);

       void displayPortfolio() const;

       double getTotalValue() const;
    };
#endif