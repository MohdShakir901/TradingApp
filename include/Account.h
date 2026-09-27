#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>

class Account{
    private:
    int accountId;
    std::string name;
    std::string email;
    double balance;

    public:
    Account(int id, std::string name, std::string email, double balance);

    void showAccountInfo() const;
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;    
};
#endif