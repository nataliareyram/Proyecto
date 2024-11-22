#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
protected:
    std::string accountNumber;
    double balance;
    std::string ownerName;
    std::string accountType;

public:
    BankAccount(std::string accountNumber, double balance, std::string ownerName, std::string accountType);

    std::string getAccountNumber() const;
    void setAccountNumber(std::string accountNumber);

    double getBalance() const;
    void setBalance(double balance);

    std::string getOwnerName() const;
    void setOwnerName(std::string ownerName);

    std::string getAccountType() const;
    void setAccountType(std::string accountType);

    void deposit(double amount);
    void withdraw(double amount);
};

#endif
