#include <iostream>
#include <vector>
using namespace std;

// ---------------- Transaction ----------------
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

// ---------------- Account ----------------
class Account {
public:
    int accNo;
    double balance;
    vector<Transaction> history;

    Account(int n) {
        accNo = n;
        balance = 0;
    }

    void deposit(double amt) {
        balance += amt;
        history.push_back(Transaction("Deposit", amt));
        cout << "Deposited Successfully!\n";
    }

    void withdraw(double amt) {
        if (amt > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }
        balance -= amt;
        history.push_back(Transaction("Withdraw", amt));
        cout << "Withdraw Successful!\n";
    }

    void showBalance() {
        cout << "Balance: " << balance << endl;
    }

    void showHistory() {
        cout << "\n--- Transactions ---\n";
        for (auto &t : history) {
            cout << t.type << " : " << t.amount << endl;
        }
    }
};

// ---------------- MAIN ----------------
int main() {
    Account acc(101);
    int choice;
    double amt;

    while (true) {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View Balance\n";
        cout << "4. View Transactions\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount: ";
            cin >> amt;
            acc.deposit(amt);
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amt;
            acc.withdraw(amt);
            break;

        case 3:
            acc.showBalance();
            break;

        case 4:
            acc.showHistory();
            break;

        case 0:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }
}