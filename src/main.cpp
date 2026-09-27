#include <iostream>
#include "../include/Account.h"

using namespace std;

int main()
{
    Account account(1001, "Shakir", "shakir@example.com", 50000.0);

    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "       TRADING APPLICATION\n";
        cout << "================================\n";

        cout << "1. Account Information\n";
        cout << "2. Deposit Money\n";
        cout << "3. Buy Stock\n";
        cout << "4. Sell Stock\n";
        cout << "5. Portfolio\n";
        cout << "6. Transaction History\n";
        cout << "7. Exit\n";

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
            cout << "\nBuy Stock selected.\n";
            break;

        case 4:
            cout << "\nSell Stock selected.\n";
            break;

        case 5:
            cout << "\nPortfolio selected.\n";
            break;

        case 6:
            cout << "\nTransaction History selected.\n";
            break;

        case 7:
            cout << "\nExiting Trading Application...\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}