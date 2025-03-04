// First Assignment for CIS17B - Bank Project
// Kevin Grissom
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

struct Account {
    string name;
    double balance;
};

map<string, Account> accounts;

void menu();
void create();
void deposit();
void withdraw();
void checkBalance();
void load();
void save();

int main() {
    load();
    int pick;

    do {
        menu();
        cin >> pick;
        cin.ignore();

        switch (pick) {
            case 1: create(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: cout << "Thank you for using Simple Bank System!\n"; break;
            default: cout << "Invalid Choice! Please Try Again\n"; break;
        }
    } while (pick != 5);

    save(); // Save before exiting program
    return 0;
}
// this is what outputs the main menu
void menu() {
    cout << "\nWelcome to Simple Bank System!\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n";
    cout << "5. Save Accounts & Exit\n";
    cout << "Enter your choice: ";
}

void create() {
    string name;
    double initialDeposit;

    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter initial deposit: ";
    cin >> initialDeposit;
    cin.ignore(); // Flush newline after numeric input

    if (initialDeposit < 0) {
        cout << "Initial deposit cannot be negative!\n";
        return;
    }
// stores input from user to account
    accounts[name] = {name, initialDeposit};
    cout << "Account created successfully!\n";

    save(); // Save immediately
}

// Storres deposit info and uses the .find to look for the name of user entered
void deposit() {
    string name;
    double amount;

    cout << "Enter account name: ";
    cin.ignore();
    getline(cin, name);

    if (accounts.find(name) == accounts.end()) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter amount to deposit: ";
    cin >> amount;
    cin.ignore();

    if (amount < 0) {
        cout << "Deposit amount cannot be negative!\n";
        return;
    }

    accounts[name].balance += amount;
    cout << "Deposit successful! New balance: $" << accounts[name].balance << "\n";

    save(); // Save
}

void withdraw() {
    string name;
    double amount;

    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, name);

    if (accounts.find(name) == accounts.end()) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter amount to withdraw: ";
    cin >> amount;
    cin.ignore();

    if (amount < 0) {
        cout << "Withdrawal amount cannot be negative!\n";
        return;
    }

    if (accounts[name].balance < amount) {
        cout << "Insufficient funds!\n";
        return;
    }

    accounts[name].balance -= amount;
    cout << "Withdrawal successful! New balance: $" << accounts[name].balance << "\n";

    save(); // Save
}

void checkBalance() {
    string name;

    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, name);

    if (accounts.find(name) == accounts.end()) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Current balance: $" << accounts[name].balance << "\n";
}
// this looks for the accounts.tt file and if cannt find it will create it for us.
void load() {
    ifstream file("accounts.txt");
    if (!file.is_open()) {
        cout << "No account file found.\n";
        return;
    }

    string name;
    double balance;

    accounts.clear(); // Prevent duplicates

    while (file >> name >> balance) {
        accounts[name] = {name, balance};
    }

    file.close();
}

void save() {
    ofstream file("accounts.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to save accounts.\n";
        return;
    }

    for (auto &entry : accounts) {
        file << entry.second.name << " " << entry.second.balance << "\n";
    }

    file.close();
    cout << "Accounts successfully saved!\n";
}
