#include "../include/Account.h"

#include<iostream>
using namespace std;

Account::Account(int id, std::string name, std::string email, double balance)
    : accountId(id),
      name(name),
      email(email),
      balance(balance)
{
}

void Account::showAccountInfo() const{
    cout << "\n========== ACCOUNT INFORMATION ==========\n";
    cout << "Account ID : " << accountId << endl;
    cout << "Name       : " << name << endl;
    cout << "Email      : " << email << endl;
    cout << "Balance    : $" << balance << endl;
};


void Account::deposit(double amount){
    if(amount <= 0){
        cout << "Invalid deposit amount.\n";
        return;
    }
    balance += amount;

    cout << "Deposit successful!\n";
    cout << "New Balance: ₹" << balance << endl;
}

void Account::withdraw(double amount){
    if(amount <= 0){
        cout << "Invalid withdrawal amount.\n";
        return;
    }
    if(amount > balance){
        cout << "Insufficient balance.\n";
        return;
    }

    balance -= amount;

    cout << "Withdrawal successful!\n";
    cout << "New Balance: $" << balance << endl;
}

double Account::getBalance() const
{
    return balance;
}