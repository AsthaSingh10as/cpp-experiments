

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Base Class
class BankAccount
{
private:
    int accountNumber;
    double balance;

protected:
    string accountHolder;

public:
    // Constructor
    BankAccount(int accNo, string name, double amount)
    {
        accountNumber = accNo;
        accountHolder = name;
        balance = amount;
    }

    // Deposit function
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully!" << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully!" << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Getter function
    double getBalance()
    {
        return balance;
    }

    // Display function
    void displayDetails()
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

// Derived Class 1
class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double amount,
                   double rate)
        : BankAccount(accNo, name, amount)
    {
        interestRate = rate;
    }

    void addInterest()
    {
        double interest = getBalance() * interestRate / 100;
        deposit(interest);

        cout << "Interest added: Rs. " << interest << endl;
    }

    void displaySavings()
    {
        cout << "\n--- Savings Account ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Balance: Rs. " << getBalance() << endl;
    }
};

// Derived Class 2
class CurrentAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNo, string name, double amount,
                   double limit)
        : BankAccount(accNo, name, amount)
    {
        overdraftLimit = limit;
    }

    void withdrawWithOverdraft(double amount)
    {
        if (amount > 0 &&
            amount <= getBalance() + overdraftLimit)
        {
            deposit(0); // Demonstrates access through a public member
            cout << "Withdrawal of Rs. " << amount
                 << " is permitted by the overdraft facility."
                 << endl;

            // Withdraw available balance first.
            double available = getBalance();

            if (amount <= available)
            {
                withdraw(amount);
            }
            else
            {
                withdraw(available);
                cout << "Overdraft used: Rs. "
                     << amount - available << endl;
            }
        }
        else
        {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void displayCurrent()
    {
        cout << "\n--- Current Account ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Overdraft Limit: Rs. " << overdraftLimit << endl;
        cout << "Balance: Rs. " << getBalance() << endl;
    }
};

// Main Function
int main()
{
    cout << fixed << setprecision(2);

    // Creating Savings Account object
    SavingsAccount savings(101, "Rahul", 10000, 5);

    cout << "===== BANK ACCOUNT MANAGEMENT =====" << endl;

    savings.displayDetails();

    savings.deposit(2000);
    savings.withdraw(1000);
    savings.addInterest();

    savings.displaySavings();

    // Creating Current Account object
    CurrentAccount current(102, "Amit", 5000, 3000);

    current.displayDetails();

    current.withdrawWithOverdraft(7000);

    current.displayCurrent();

    cout << "\nProgram executed successfully!" << endl;

    return 0;
}

