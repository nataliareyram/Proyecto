#include <iostream>
#include <string>
#include <limits>
#include "Bank.h"
#include "Customer.h"
#include "BankAccount.h"
#include "InvestmentAccount.h"
#include "Card.h"

// Verifier function for string inputs
void getValidatedString(const std::string& prompt, std::string& input) {
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) break; 
        std::cout << "Invalid input. Please enter a valid string.\n";
    }
}

// Verifier function for integer inputs
void getValidatedInt(const std::string& prompt, int& input) {
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (!std::cin.fail()) break; 
        std::cout << "Invalid input. Please enter a valid integer.\n";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Verifier function for double inputs
void getValidatedDouble(const std::string& prompt, double& input) {
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (!std::cin.fail()) break;
        std::cout << "Invalid input. Please enter a valid number.\n";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

int main() {
    // Create bank
    std::string bankName, location;
    std::cout << "=== Create bank ===\n";
    getValidatedString("Enter the bank's name: ", bankName);
    getValidatedString("Enter the bank's location: ", location);

    Bank bank(bankName, location);

    // Create customer
    std::string customerID, name;
    int phoneNumber;
    std::cout << "\n=== Create a client ===\n";
    getValidatedString("Enter client ID: ", customerID);
    getValidatedString("Enter client's name: ", name);
    getValidatedInt("Enter client's phone number: ", phoneNumber);

    // Create bank account
    std::string accountNumber, accountType;
    double balance;
    std::cout << "\n=== Create a bank account ===\n";
    getValidatedString("Enter account number: ", accountNumber);
    getValidatedString("Enter account type (Savings/Checking): ", accountType);
    getValidatedDouble("Enter initial balance: ", balance);

    BankAccount bankAcc(accountNumber, balance, name, accountType);

    // Create investment account
    std::string investmentAccountNumber;
    double investmentBalance, growthRate;
    std::cout << "\n=== Create an investment account ===\n";
    getValidatedString("Enter the investment account number: ", investmentAccountNumber);
    getValidatedDouble("Enter the investment account's initial balance: ", investmentBalance);
    getValidatedDouble("Enter the growth rate (ex. 0.05 for 5%): ", growthRate);

    InvestmentAccount investAcc(investmentAccountNumber, balance, name, "Investment", investmentBalance, growthRate);

    // Create card
    std::string creditCard, debitCard;
    std::cout << "\n=== Create Card ===\n";
    getValidatedString("Enter your credit card (Visa, MasterCard, American Express, None): ", creditCard);
    getValidatedString("Enter your debit card (Visa, MasterCard, American Express, None): ", debitCard);

    Card card(creditCard, debitCard);

    // Client creation
    Customer customer(customerID, name, phoneNumber, bankAcc, investAcc, card);
    bank.addCustomer(customer);

    // Task menu
    int option;
    do {
        std::cout << "\n=== Task menu ===\n";
        std::cout << "1. Deposit to main account\n";
        std::cout << "2. Withdraw from main account\n";
        std::cout << "3. Transfer to Investment Account\n";
        std::cout << "4. Apply Growth Rate to Investment Balance\n";
        std::cout << "5. Get Client Information\n";
        std::cout << "6. Leave\n";
        getValidatedInt("Select an option: ", option);
    //The functions defined previously will be applied to verify the correct completion of the tasks offered in the menu according to the corresponding data type entry and the constructors it will be assigned to.
        switch (option) {
            case 1: {
                double depositAmount;
                getValidatedDouble("Enter the desired deposit amount: ", depositAmount);
                customer.getBankAccount().deposit(depositAmount);
                std::cout << "Your deposit was successful. New balance: $" << customer.getBankAccount().getBalance() << "\n";
                break;
            }
            case 2: {
                double withdrawAmount;
                getValidatedDouble("Enter the desired withdrawal amount: ", withdrawAmount);
                try {
                    customer.getBankAccount().withdraw(withdrawAmount);
                    std::cout << "Your withdrawal was successful. New balance: $" << customer.getBankAccount().getBalance() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 3: {
                double transferAmount;
                getValidatedDouble("Enter the amount you wish to transfer to the Investment Account: ", transferAmount);
                try {
                    customer.getInvestmentAccount().transferToInvestment(transferAmount);
                    std::cout << "Successful transfer. New Investment Account balance: $"
                              << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 4: {
                customer.getInvestmentAccount().applyGrowth();
                std::cout << "Growth Rate applied. New Investment Account balance: $"
                          << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                break;
            }
            case 5: {
                std::cout << "\n=== Client Information ===\n";
                std::cout << "ID: " << customer.getCustomerID() << "\n";
                std::cout << "Name: " << customer.getName() << "\n";
                std::cout << "Phone number: " << customer.getPhoneNumber() << "\n";
                std::cout << "Main account balance: $" << customer.getBankAccount().getBalance() << "\n";
                std::cout << "Investment account balance: $" << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                std::cout << "Credit card: " << customer.getCard().getCredit() << "\n";
                std::cout << "Debit card: " << customer.getCard().getDebit() << "\n";
                break;
            }
            case 6:
                std::cout << "Goodbye! Thank you for using our services.\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while (option != 6);

    return 0;
}
