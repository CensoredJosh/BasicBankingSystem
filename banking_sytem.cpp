#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void displayMenu() { //function to display user menu
    cout << "Options:" << endl;
    cout << left << setw(3) << "1" << "Add Customer" << endl;
    cout << left << setw(3) << "2" << "Display Account Holder" << endl;
    cout << left << setw(3) << "3" << "Exit Program" << endl;
    cout << "Enter menu option: ";
}

void addRecords() { //function to enter a new customer to the file
    ofstream file("BankAccounts.txt", ios::app);
    if (!file) {
        cout << "Error opening the file" << endl;
        return;
    }

    string accNumber;
    string name;

    while (true) {
        cout << "Enter the account number (X to stop): ";
        cin >> accNumber;

        if (accNumber == "X" || accNumber == "x") {
            break;
        }

        cout << "Enter the customer's name: ";
        cin >> name;

        file << accNumber << "#" << name << endl;
    }

    file.close();
}

void displayCustomer() { //function to display customer name for given account number
    ifstream file("BankAccounts.txt");
    if (!file) {
        cout << "Error opening the file" << endl;
        return;
    }

    string accNumber;
    string fileAccNumber;
    string fileName;
    bool found = false;

    cout << "Enter the account number: ";
    cin >> accNumber;

    while (getline(file, fileAccNumber, '#') && getline(file, fileName)) {
        if (fileAccNumber == accNumber) {
            cout << "Customer name: " << fileName << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found" << endl;
    }

    file.close();
}

void initialValues() { //function to add 5 initial customers
    ofstream file("BankAccounts.txt", ios::app);
    if (!file) {
        cout << "Error opening the file" << endl;
        return;
    }

    file << "1001#Alice" << endl;
    file << "1002#Bob" << endl;
    file << "1003#Carla" << endl;
    file << "1004#Daniel" << endl;
    file << "1005#Emma" << endl;

    file.close();
}

int main () {
    initialValues();

    int choice = 0;

    while (choice != 3) {
        displayMenu();
        cin >> choice;

        switch (choice) { // switch-case to select menu option
            case 1:
                addRecords();
                break;

            case 2:
                displayCustomer();
                break;

            case 3:
                cout << "Exiting Program" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
