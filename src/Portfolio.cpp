#include "../include/Portfolio.h"
#include <iostream>

using namespace std;

void Portfolio::addHolding(Stock stock, int quantity, double price){

    if (quantity <= 0){
        cout << "Invalid quantity.\n";
        return;
    }

    for (Holding &holding : holdings){

        if (holding.getStock().getSymbol() == stock.getSymbol()){
            holding.addQuantity(quantity, price);

            cout << "Stock added to existing holding.\n";
            return;
        }
    }

    Holding newHolding(stock, quantity, price);
    holdings.push_back(newHolding);

    cout << "Stock added to portfolio.\n";
}

bool Portfolio::sellStock(const std::string &symbol, int quantity){

    if (quantity <= 0){
        cout << "Invalid quantity.\n";
        return false;
    }

    for (auto it = holdings.begin(); it != holdings.end(); ++it){

        if (it->getStock().getSymbol() == symbol){

            if (!it->removeQuantity(quantity)){

                cout << "Not enough shares available.\n";
                return false;
            }

            if (it->getQuantity() == 0){

                holdings.erase(it);
            }

            cout << "Stock sold successfully.\n";
            return true;
        }
    }

    cout << "Stock not found in portfolio.\n";
    return false;
}

void Portfolio::displayPortfolio() const{

    if (holdings.empty()){

        cout << "\nYour portfolio is empty.\n";
        return;
    }

    cout << "\n========== PORTFOLIO ==========\n";

    for (const Holding &holding : holdings){

        holding.displayHolding();
    }

    cout << "\nTotal Portfolio Value: ₹"
         << getTotalValue() << endl;
}

double Portfolio::getTotalValue() const{

    double totalValue = 0.0;

    for (const Holding &holding : holdings){
        
        totalValue += holding.getCurrentValue();
    }

    return totalValue;
}