
#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Custom Exception Class
class BankingException : public exception {
public:
    const char* what() const noexcept override {
        return "Banking Exception Occurred!";
    }
};

// Insufficient Balance Exception
class InsufficientBalance : public BankingException {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient Balance!";
    }
};

// Invalid Amount Exception
class InvalidAmount : public BankingException {
public:
    const char* what() const noexcept override {
        return "Error: Invalid Transaction Amount!";
    }
};

// Bank Account Class
class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Deposit Function
    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        balance += amount;
        cout << "Amount Deposited: Rs. " << amount << endl;
    }

    // Withdraw Function
    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientBalance();
        }

        balance -= amount;
        cout << "Amount Withdrawn: Rs. " << amount << endl;
    }

    void displayBalance() {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    cout << "BANKING TRANSACTION SYSTEM" << endl;
    account.displayBalance();

    // Successful Deposit
    try {
        account.deposit(2000);
    }
    catch (const BankingException& e) {
        cout << e.what() << endl;
    }

    // Successful Withdrawal
    try {
        account.withdraw(1000);
    }
    catch (const BankingException& e) {
        cout << e.what() << endl;
    }

    // Insufficient Balance
    try {
        account.withdraw(10000);
    }
    catch (const BankingException& e) {
        cout << e.what() << endl;
    }

    // Invalid Amount
    try {
        account.deposit(-500);
    }
    catch (const BankingException& e) {
        cout << e.what() << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    account.displayBalance();

    return 0;
}
