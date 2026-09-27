#include <iostream>
#include "../include/Account.h"
#include "../include/stock.h"

using namespace std;

int main()
{
    Account account(1001, "Shakir", "shakir@example.com", 50000.0);
    Stock tcs(1, "TCS", "Tata Consultancy Services", 3500.00);

    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "       TRADING APPLICATION\n";
        cout << "================================\n";

        cout << "1. Account Information\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Buy Stock\n";
        cout << "5. Sell Stock\n";
        cout << "6. Portfolio\n";
        cout << "7. Transaction History\n";
        cout << "8. Exit\n";

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
            double amount;

            cout << "\nEnter amount to withdraw: ";
            cin >> amount;

            account.withdraw(amount);
            break;

        case 4:
            tcs.displayStock();
            cout << "\nBuy Stock selected.\n";
            
            break;

        case 5:
            cout << "\nSell Stock selected.\n";
            
            break;

        case 6:
            cout << "\nPortfolio selected.\n";
           
            break;

        case 7:
            cout << "\nTransaction History selected.\n";
           
            break;

        case 8:
            cout << "\nExiting Trading Application...\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}