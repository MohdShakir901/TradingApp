#ifndef HOLDING_H
#define HOLDING_H

#include "Stock.h"

class Holding{
    private:
        Stock stock;
        int quantity;
        double averagePrice;

    public: 
        Holding(Stock stock, int quantity, double averagePrice);

        void displayHolding() const;

        Stock getStock() const;
        int getQuantity() const;
        double getAveragePrice() const;

        void addQuantity(int quantity, double price);
        bool removeQuantity(int quantity);

        double getCurrentValue() const;
};
#endif