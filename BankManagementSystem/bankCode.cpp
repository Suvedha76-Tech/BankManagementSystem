#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

// Get date-time
string getDateTime() {
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    return dt;
}

class Account {
private:
    int accNo;
    char name[50];
    double balance;

public:
    void create() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void display() {
        cout << "\nAccount No: " << accNo
             << "\nName: " << name
             << "\nBalance: " << balance << endl;
    }

    int getAccNo() { return accNo; }
    double getBalance() { return balance; }

    void deposit(double amt) {
        balance += amt;
        saveTransaction("Deposit", amt);
    }

    bool withdraw(double amt) {
        if (amt <= balance) {
            balance -= amt;
            saveTransaction("Withdraw", amt);
            return true;
        }
        cout << "Insufficient Balance!\n";
        return false;
    }

    void addInterest() {
        double interest = balance * 0.03; // 3% interest
        balance += interest;
        saveTransaction("Interest", interest);
    }

    void saveTransaction(string type, double amt) {
        ofstream file("transactions.txt", ios::app);
        file << accNo << "|" << type << "|" << amt << "|" << getDateTime() << endl;
        file.close();
    }

    void showMiniStatement() {
        ifstream file("transactions.txt");
        vector<string> lines;
        string line;

        while (getline(file, line)) {
            if (line.find(to_string(accNo)) != string::npos)
                lines.push_back(line);
        }

        cout << "\n--- Last 5 Transactions ---\n";
        int start = max(0, (int)lines.size() - 5);
        for (int i = start; i < lines.size(); i++)
            cout << lines[i] << endl;

        file.close();
    }
};

// Create account
void createAccount() {
    Account acc;
    ofstream file("accounts.dat", ios::binary | ios::app);

    acc.create();
    file.write((char*)&acc, sizeof(acc));

    file.close();
    cout << "Account Created!\n";
}

// Find account
bool findAccount(int accNo, Account &acc) {
    ifstream file("accounts.dat", ios::binary);

    while (file.read((char*)&acc, sizeof(acc))) {
        if (acc.getAccNo() == accNo) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Update account
void updateAccount(Account &acc) {
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    Account temp;

    while (file.read((char*)&temp, sizeof(temp))) {
        if (temp.getAccNo() == acc.getAccNo()) {
            int pos = -1 * sizeof(acc);
            file.seekp(pos, ios::cur);
            file.write((char*)&acc, sizeof(acc));
            break;
        }
    }
    file.close();
}

// Deposit
void depositMoney() {
    int accNo;
    double amt;
    Account acc;

    cout << "Enter Account Number: ";
    cin >> accNo;

    if (findAccount(accNo, acc)) {
        cout << "Enter amount: ";
        cin >> amt;
        acc.deposit(amt);
        updateAccount(acc);
        cout << "Deposit Successful!\n";
    } else {
        cout << "Account not found!\n";
    }
}

// Withdraw
void withdrawMoney() {
    int accNo;
    double amt;
    Account acc;

    cout << "Enter Account Number: ";
    cin >> accNo;

    if (findAccount(accNo, acc)) {
        cout << "Enter amount: ";
        cin >> amt;
        if (acc.withdraw(amt))
            updateAccount(acc);
    } else {
        cout << "Account not found!\n";
    }
}

// Transfer money ⭐
void transferMoney() {
    int fromAcc, toAcc;
    double amt;
    Account sender, receiver;

    cout << "From Account: ";
    cin >> fromAcc;
    cout << "To Account: ";
    cin >> toAcc;

    if (findAccount(fromAcc, sender) && findAccount(toAcc, receiver)) {
        cout << "Enter amount: ";
        cin >> amt;

        if (sender.withdraw(amt)) {
            receiver.deposit(amt);
            updateAccount(sender);
            updateAccount(receiver);

            cout << "Transfer Successful!\n";
        }
    } else {
        cout << "Invalid Account(s)!\n";
    }
}

// Interest ⭐
void addInterest() {
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    Account acc;

    while (file.read((char*)&acc, sizeof(acc))) {
        acc.addInterest();
        int pos = -1 * sizeof(acc);
        file.seekp(pos, ios::cur);
        file.write((char*)&acc, sizeof(acc));
        file.seekg(0, ios::cur);
    }

    file.close();
    cout << "Interest Added to All Accounts!\n";
}

// Balance
void checkBalance() {
    int accNo;
    Account acc;

    cout << "Enter Account Number: ";
    cin >> accNo;

    if (findAccount(accNo, acc))
        acc.display();
    else
        cout << "Account not found!\n";
}

// Mini statement ⭐
void miniStatement() {
    int accNo;
    Account acc;

    cout << "Enter Account Number: ";
    cin >> accNo;

    if (findAccount(accNo, acc))
        acc.showMiniStatement();
    else
        cout << "Account not found!\n";
}

// Main
int main() {
    int choice;

    do {
        cout << "\n====== ADVANCED BANK SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Balance\n";
        cout << "5. Transfer Money\n";
        cout << "6. Mini Statement\n";
        cout << "7. Add Interest\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: transferMoney(); break;
            case 6: miniStatement(); break;
            case 7: addInterest(); break;
        }

    } while (choice != 8);

    return 0;
}