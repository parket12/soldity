#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNum;
    double accountBalance;
    double rateInterest;

public:
    BankAccount(int num, double balance) : accountNum(num), accountBalance(balance), rateInterest(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
            cout << "Депозит успешно добавлен. Текущий баланс: " << accountBalance << endl;
        }
        else {
            cout << "Сумма должна быть больше нуля!" << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Сумма должна быть больше нуля!" << endl;
            return false;
        }
        else if (amount > accountBalance) {
            cout << "Недостаточно средств на счете!" << endl;
            return false;
        }
        accountBalance -= amount;
        cout << "Средства успешно сняты. Текущий баланс: " << accountBalance << endl;
        return true;
    }

    double getBalance() const {
        return accountBalance;
    }

    void setInterestRate(double newRate) {
        if (newRate >= 0) {
            rateInterest = newRate;
        }
        else {
            cout << "Процентная ставка не может быть отрицательной!" << endl;
        }
    }

    int getAccountNumber() const {
        return accountNum;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
        return true;
    }
    return false;
}

void showMenu() {
    cout << "\n Меню Управления Счетом\n";
    cout << "1. Показать баланс\n";
    cout << "2. Депозит\n";
    cout << "3. Снять наличные\n";
    cout << "4. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    BankAccount myAccount(1, 1000); 
    int choice;
    double amount;

    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1: 
            cout << "Текущий баланс: " << myAccount.getBalance() << endl;
            break;
        case 2: 
            cout << "Введите сумму для депозита: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 3: 
            cout << "Введите сумму для снятия: ";
            cin >> amount;
            if (!myAccount.withdraw(amount)) {
                cout << "Операция не выполнена." << endl;
            }
            break;
        case 4: 
            cout << "Выход из программы..." << endl;
            return 0;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    }

    return 0;
}
