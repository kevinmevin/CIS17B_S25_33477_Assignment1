// First Assignment for CIS17B - Bank Project
// Kevin Grissom
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Each account needs a name and a balance assigned to it. We set that up here. Name will be string because of text
// balance needs to be double because we are dealing with numbers that represent dollars and change.
struct Account {
    string name;
    double balance;
};
// This container holds key-value pairs. Easy way to lookup account add and delete value
map<string, Account> accounts;

void menu();
void create();
void deposit();
void withdraw();
void checkBalance();
void load();
void save();

// Start the main program loop
int main() {
    load();
    int pick;

    do {
        menu();
        cin >> pick;
        cin.ignore();

        switch (pick) {
            case 1:create(); break;
            case 2:deposit(); break;
            case 3:withdraw(); break;
            case 4:load(); break;
            case 5: cout << "Thank you for using Simple Bank System!\n"; break;
            default: cout << "Invalid Choice! Please Try Again\n"; break;
        }
    } while (pick !=5);
    save();
    return 0;

}
void menu() {
    cout << "\nWelcome to Simple Bank System!\n";
    cout << "1. Create Account\n"
   cout << "2. Deposit\n"
    cout<< "3. Withdraw\n"
    cout<< "4. Load\n"
    cout<< "5. Save Account & Exit\n"
    cout<< "Enter your choice: ";
}