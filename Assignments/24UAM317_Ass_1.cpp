#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Transaction {
    string type;
    double amount, balance;
};

void printMiniStatement(const vector<Transaction>& transactions) {
    cout << "\n----- MINI STATEMENT -----\n";
    cout << left << setw(12) << "Type" 
         << setw(12) << "Amount" 
         << setw(12) << "Balance" << endl;
    cout << "----------------------------------\n";
    
    for (const auto& txn : transactions) {
        cout << left << setw(12) << txn.type
             << setw(12) << fixed << setprecision(2) << txn.amount
             << setw(12) << txn.balance << endl;
    }
    
    cout << "----------------------------------\n";
}

int main() {
    double balance = 0.0;
    vector<Transaction> transactions;
    int choice;
    
    do {
        cout << "\nBANK MENU\n1. Deposit Money\n2. Withdraw Money\n3. Mini Statement\n4. Exit\nEnter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            double deposit;
            cout << "Enter deposit amount: ";
            cin >> deposit;
            if (deposit > 0) {
                balance += deposit;
                transactions.push_back({"Deposit", deposit, balance});
                cout << "Amount deposited successfully!\n";
            } else cout << "Invalid amount!\n";
        } 
        else if (choice == 2) {
            double withdraw;
            cout << "Enter withdrawal amount: ";
            cin >> withdraw;
            if (withdraw > 0 && withdraw <= balance) {
                balance -= withdraw;
                transactions.push_back({"Withdraw", withdraw, balance});
                cout << "Amount withdrawn successfully!\n";
            } else cout << "Invalid or insufficient balance!\n";
        } 
        else if (choice == 3) {
            printMiniStatement(transactions);
        } 
        else if (choice == 4) {
            cout << "Thank you for banking with us!\n";
        } 
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}
