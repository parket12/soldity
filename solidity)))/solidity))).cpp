#include <iostream>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initialBalance) {
        accountNumber = accNumber;
        balance = initialBalance;
        interestRate = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        else {
            std::cout << "Insufficient funds!" << std::endl;
            return false;
        }
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        return balance * interestRate * (1.0 / 12.0);
    }

    void setInterestRate(double newRate) {
        interestRate = newRate;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
        return true;
    }
    else {
        std::cout << "Transfer failed: Insufficient funds in the source account!" << std::endl;
        return false;
    }
}

int main() {
    BankAccount acc1(12345, 1000.0);
    BankAccount acc2(54321, 500.0);

    std::cout << "Initial balances:" << std::endl;
    std::cout << "Account 1: " << acc1.getBalance() << std::endl;
    std::cout << "Account 2: " << acc2.getBalance() << std::endl;

    transfer(acc1, acc2, 200.0);

    std::cout << "\nAfter transfer:" << std::endl;
    std::cout << "Account 1: " << acc1.getBalance() << std::endl;
    std::cout << "Account 2: " << acc2.getBalance() << std::endl;

    return 0;
}