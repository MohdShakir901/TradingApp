#include "../include/Holding.h"
#include <iostream>
using namespace std;


Holding::Holding(Stock stock, int quantity, double averagePrice):
    stock(stock),
    quantity(quantity),
    averagePrice(averagePrice)
    {
    }

    void Holding::displayHolding() const
    {
        cout << "\n========== HOLDING ==========\n";
        cout << "Stock       : " << stock.getSymbol() << endl;
        cout << "Company     : " << stock.getCompanyName() << endl;
        cout << "Quantity    : " << quantity << endl;
        cout << "Average Price: ₹" << averagePrice << endl;
        cout << "Current Price: ₹" << stock.getPrice() << endl;
        cout << "Current Value: ₹" << getCurrentValue() << endl;
    }

    Stock Holding::getStock() const
    {
        return stock;
    }

    int Holding::getQuantity() const
    {
        return quantity;
    }

    double Holding::getAveragePrice() const
    {
        return averagePrice;
    }

    void Holding::addQuantity(int newQuantity, double price)
    {
        if (newQuantity <= 0)
        {
            return;
        }

        double totalCost = (quantity * averagePrice) +
                           (newQuantity * price);

        quantity += newQuantity;

        averagePrice = totalCost / quantity;
    }

    bool Holding::removeQuantity(int quantityToRemove)
    {
        if (quantityToRemove <= 0 || quantityToRemove > quantity)
        {
            return false;
        }

        quantity -= quantityToRemove;

        return true;
    }

    double Holding::getCurrentValue() const
    {
        return quantity * stock.getPrice();
    }