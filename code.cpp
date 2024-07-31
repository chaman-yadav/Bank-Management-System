#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <limits>

using namespace std;

class Account {
    int acno;
    char name[50];
    int deposit;
    char type;

public:
    void create_account();
    void show_account() const;
    void modify();
    void dep(int);
    void draw(int);
    void report() const;
    int retacno() const;
    int retdeposit() const;
    char rettype() const;
};

void Account::create_account() {
    cout << "\n\t\t\tEnter the Account No. : ";
    while (!(cin >> acno)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cout << "\n\n\t\t\tEnter the Name of the Account holder : ";
    cin.ignore();  // Clear newline character left in buffer
    cin.getline(name, 50);  // Read full name with spaces
    cout << "\n\t\t\tEnter Type of the Account, Current or Savings (C/S) : ";
    cin >> type;
    type = toupper(type);
    while (type != 'C' && type != 'S') {
        cout << "Invalid input. Please enter 'C' for Current or 'S' for Savings: ";
        cin >> type;
        type = toupper(type);
    }
    cout << "\n\t\t\tEnter The Initial amount : ";
    while (!(cin >> deposit) || deposit < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a non-negative number: ";
    }
    cout << "\n\n\t\t\tAccount Created..";
}

void Account::modify() {
    cout << "\n\t\t\tAccount No. : " << acno;
    cout << "\n\t\t\tModify Account Holder Name : ";
    cin.ignore();  // Clear newline character left in buffer
    cin.getline(name, 50);  // Read full name with spaces
    cout << "\n\t\t\tModify Type of Account : ";
    cin >> type;
    type = toupper(type);
    while (type != 'C' && type != 'S') {
        cout << "Invalid input. Please enter 'C' for Current or 'S' for Savings: ";
        cin >> type;
        type = toupper(type);
    }
    cout << "\n\t\t\tModify Balance amount : ";
    while (!(cin >> deposit) || deposit < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a non-negative number: ";
    }
}

void Account::show_account() const {
    cout << "\n\t\t\tAccount No. : " << acno;
    cout << "\n\t\t\tAccount Holder Name : " << name;
    cout << "\n\t\t\tType of Account : " << type;
    cout << "\n\t\t\tBalance amount : " << deposit;
}

void Account::dep(int x) {
    deposit += x;
}

void Account::draw(int x) {
    deposit -= x;
}

void Account::report() const {
    cout << setw(10) << acno << setw(20) << name << setw(10) << type << setw(10) << deposit << endl;
}

int Account::retacno() const {
    return acno;
}

int Account::retdeposit() const {
    return deposit;
}

char Account::rettype() const {
    return type;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void show_main_menu();
void clear_screen();

int main() {
    char ch;
    int num;
    do {
        clear_screen();
        show_main_menu();
        cin >> ch;

        switch (ch) {
        case '1':
            write_account();
            break;
        case '2':
        case '3':
            clear_screen();
            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, (ch == '2') ? 1 : 2);
            break;
        case '4':
            clear_screen();
            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            clear_screen();
            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            delete_account(num);
            break;
        case '7':
            clear_screen();
            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            modify_account(num);
            break;
        case '8':
            clear_screen();
            cout << "\n\n\t\t\t--------------Created By CHAMAN----------------";
            cout << "\n\n\t\t\t THANK YOU FOR USING BANK MANAGEMENT SYSTEM";
            cout << "\n\n\t\t\tPress Enter TO EXIT";
            break;
        default:
            cout << "Invalid option. Please choose from the given options only." << endl;
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}

void clear_screen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

void show_main_menu() {
    cout << "\n\n\t\t\t\t======================\n";
    cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
    cout << "\n\t\t\t\t======================\n";
    cout << "\t\t\t\t-----MAIN MENU------\n";
    cout << "\n\t\t\t\t1. NEW ACCOUNT";
    cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
    cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
    cout << "\n\t\t\t\t4. BALANCE ENQUIRY";
    cout << "\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
    cout << "\n\t\t\t\t6. CLOSE AN ACCOUNT";
    cout << "\n\t\t\t\t7. MODIFY AN ACCOUNT";
    cout << "\n\t\t\t\t8. EXIT";
    cout << "\n\n\t\t\t\tSelect Your Option (1-8): ";
}

void write_account() {
    Account ac;
    ofstream outFile("account.dat", ios::binary | ios::app);
    if (!outFile) {
        cerr << "File could not be opened! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    ac.create_account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
}

void display_sp(int n) {
    Account ac;
    bool flag = false;
    ifstream inFile("account.dat", ios::binary);
    if (!inFile) {
        cerr << "File could not be opened! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\t\t\tBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account))) {
        if (ac.retacno() == n) {
            ac.show_account();
            flag = true;
            break;  // Exit loop early if the account is found
        }
    }
    inFile.close();
    if (!flag)
        cout << "\n\n\t\t\tAccount number does not exist";
}

void modify_account(int n) {
    bool found = false;
    Account ac;
    fstream File("account.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cerr << "File could not be opened! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (File.read(reinterpret_cast<char *>(&ac), sizeof(Account))) {
        if (ac.retacno() == n) {
            ac.show_account();
            cout << "\n\n\t\t\tEnter The New Details of account" << endl;
            ac.modify();
            int pos = static_cast<int>(File.tellg()) - static_cast<int>(sizeof(Account));
            File.seekp(pos, ios::beg);
            File.write(reinterpret_cast<char *>(&ac), sizeof(Account));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
            break;  // Exit loop early if the account is found
        }
    }
    File.close();
    if (!found)
        cout << "\n\n\t\t\tRecord Not Found";
}

void delete_account(int n) {
    Account ac;
    ifstream inFile("account.dat", ios::binary);
    if (!inFile) {
        cerr << "File could not be opened! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile("Temp.dat", ios::binary);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account))) {
        if (ac.retacno() != n) {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    cout << "\n\nRecord Deleted..";
}

void display_all() {
    clear_screen();
    Account ac;
    ifstream inFile("account.dat", ios::binary);
    if (!inFile) {
        cerr << "File could not be opened! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\t\tACCOUNT HOLDER LIST\n";
    cout << "===================================================================\n";
    cout << setw(10) << "Account No." << setw(20) << "Name" << setw(10) << "Type" << setw(10) << "Balance" << endl;
    cout << "===================================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account))) {
        ac.report();
    }
    inFile.close();
}

void deposit_withdraw(int n, int option) {
    int amt;
    bool found = false;
    Account ac;
    fstream File("account.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cerr << "File could not be opened! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (File.read(reinterpret_cast<char *>(&ac), sizeof(Account))) {
        if (ac.retacno() == n) {
            ac.show_account();
            if (option == 1) {  // Deposit
                cout << "\n\n\t\t\tTO DEPOSIT AMOUNT";
                cout << "\n\n\t\t\tEnter the amount to be deposited: ";
                while (!(cin >> amt) || amt < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a positive number: ";
                }
                ac.dep(amt);
            } else if (option == 2) {  // Withdraw
                cout << "\n\n\t\t\tTO WITHDRAW AMOUNT";
                cout << "\n\n\t\t\tEnter the amount to be withdrawn: ";
                while (!(cin >> amt) || amt < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a positive number: ";
                }
                int balance = ac.retdeposit() - amt;
                if (balance < 0) {
                    cout << "Insufficient balance";
                } else {
                    ac.draw(amt);
                }
            }
            int pos = static_cast<int>(File.tellg()) - static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::beg);
            File.write(reinterpret_cast<char *>(&ac), sizeof(Account));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
            break;  // Exit loop early if the account is found and updated
        }
    }
    File.close();
    if (!found) {
        cout << "\n\n\t\t\tRecord Not Found";
    }
}
