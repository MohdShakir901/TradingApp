#include <iostream>
#include "../include/Account.h"
#include "../include/Stock.h"
#include "../include/Portfolio.h"
#include "../include/TransactionHistory.h"
#include "../include/StockMarket.h"
#include "../include/FileManager.h"

using namespace std;

int main()
{
    Account account(1001, "Shakir", "shakir@example.com", 50000.0);
    
    Portfolio portfolio;
    TransactionHistory transactionHistory;
    StockMarket market;

    std::vector<Transaction> loadedTransactions =
        FileManager::loadTransactions("data/transactions.txt");

    transactionHistory.loadTransactions(loadedTransactions);
    

    market.addStock(
        Stock(1, "TCS", "Tata Consultancy Services", 3500.00)
    );
    market.addStock(
        Stock(2, "INFY", "Infosys", 1800.00));

    market.addStock(
        Stock(3, "RELIANCE", "Reliance Industries", 2900.00));

    market.addStock(
        Stock(4, "HDFC", "HDFC Bank", 1700.00));

    market.addStock(
        Stock(5, "ITC", "ITC Limited", 450.00));

    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "       TRADING APPLICATION\n";
        cout << "================================\n";

        cout << "1. Account Information\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Available Stocks\n";
        cout << "5. Buy Stock\n";
        cout << "6. Sell Stock\n";
        cout << "7. Portfolio\n";
        cout << "8. Transaction History\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.showAccountInfo();
            break;

        case 2:
        {
            double amount;

            cout << "\nEnter amount to deposit: ";
            cin >> amount;

            account.deposit(amount);
            break;
        }

        case 3:
        {
            double amount;

            cout << "\nEnter amount to withdraw: ";
            cin >> amount;

            account.withdraw(amount);
            break;
        }
        case 4:
        {
            market.displayStocks();
            break;
        }
        case 5:
        {
            //cout << "\nBuy Stock selected.\n";
            int stockId;
            int quantity;

            market.displayStocks();

            cout << "\nEnter stock ID: ";
            cin >> stockId;

            Stock *stock = market.getStockById(stockId);

            if (stock == nullptr)
            {
                cout << "Stock not found.\n";
                break;
            }

            cout << "\nSelected Stock:\n";
            stock->displayStock();

            cout << "\nEnter quantity to buy : ";
            cin >> quantity;

            if(quantity <= 0){
                cout << "Invalid Quantity.\n";
                break;
            }

            double totalCost = quantity * stock->getPrice();

            cout << "\nTotal Cost: ₹" << totalCost << endl;

            if (totalCost > account.getBalance())
            {
                cout << "Insufficient balance.\n";
                break;
            }

            account.withdraw(totalCost);

            portfolio.addHolding(
                *stock,
                quantity,
                stock->getPrice());

            transactionHistory.addTransaction(
                "BUY",
                stock->getSymbol(),
                quantity,
                stock->getPrice());

            FileManager::saveTransactions(
                transactionHistory.getTransactions(),  "data/transactions.txt"
            );

            cout << "Stock purchased successfully!\n";

            break;
        }

        case 6:
        {
            int stockID;
            int quantity;

            market.displayStocks();

            cout << "\nEnter the stock ID: ";
            cin >> stockID;

            Stock *stock = market.getStockById(stockID);

            if (stock == nullptr)
            {
                cout << "Stock not found.\n";
                break;
            }

            cout << "\nEnter quantity to sell: ";
            cin >> quantity;

            if (quantity <= 0)
            {
                cout << "Invalid quantity.\n";
                break;
            }

            double saleAmount = quantity * stock->getPrice();

            cout << "\nSale Amount: ₹" << saleAmount << endl;

            if (portfolio.sellStock(stock->getSymbol(), quantity))
            {
                account.deposit(saleAmount);

                transactionHistory.addTransaction(
                    "SELL",
                    stock->getSymbol(),
                    quantity,
                    stock->getPrice()
                );

                FileManager::saveTransactions(
                    transactionHistory.getTransactions(),
                    "data/transactions.txt");
            }

            break;
        }
        case 7:
            portfolio.displayPortfolio();
            //cout << "\nPortfolio selected.\n";
           
            break;

        case 8:
           // cout << "\nTransaction History selected.\n";
           transactionHistory.displayHistory();
           
            break;

        case 9:
            cout << "\nExiting Trading Application...\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}