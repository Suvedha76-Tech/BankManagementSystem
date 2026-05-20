# 🏦 Advanced Bank Management System

An Advanced Bank Management System developed using C++ with file handling concepts.  
This console-based application allows users to create accounts, deposit money, withdraw money, transfer funds, view mini statements, and calculate interest.

---

# 🚀 Features

## ✅ Create Account
Users can create a new bank account by entering:
- Account Number
- Customer Name
- Initial Balance

All account details are stored permanently using binary file handling.

---

## 💰 Deposit Money
- Deposit money into an account
- Updates account balance instantly
- Saves transaction history

---

## 💸 Withdraw Money
- Withdraw money securely
- Checks available balance before withdrawal
- Prevents insufficient balance transactions

---

## 🔄 Transfer Money
- Transfer funds between two accounts
- Automatically updates sender and receiver balances
- Stores transaction details

---

## 📄 Mini Statement
Displays the last 5 transactions including:
- Deposits
- Withdrawals
- Interest credits
- Transfers

Each transaction contains:
- Account Number
- Transaction Type
- Amount
- Date & Time

---

## 📈 Interest Calculation
- Adds 3% interest to all accounts
- Automatically updates balances
- Saves interest transactions

---

## 🧾 Balance Inquiry
- Check account details
- View:
  - Account Number
  - Customer Name
  - Current Balance

---

# 🛠️ Technologies Used

- C++
- Object Oriented Programming (OOP)
- File Handling
- Binary Files
- Vectors
- Time & Date Functions
- Functions and Classes

---

# 📂 Project Structure

```bash
Advanced-Bank-System/
│
├── main.cpp
├── accounts.dat
├── transactions.txt
├── README.md
```

---

# 💡 Concepts Implemented

- Classes and Objects
- Encapsulation
- File Handling
- Binary File Storage
- Transaction Logging
- Menu Driven Programming
- Arrays & Vectors
- Date and Time Management

---

# 📦 Files Used

## accounts.dat
Stores:
- Account Number
- Customer Name
- Balance

(Binary File)

---

## transactions.txt
Stores transaction history:
- Deposits
- Withdrawals
- Transfers
- Interest Entries

---

# ▶️ How to Run

## Step 1
Open the project in:
- Code::Blocks
- VS Code
- Dev C++
- Any C++ Compiler

---

## Step 2
Compile the program

---

## Step 3
Run the executable file

---

# 📋 Menu Options

```text
====== ADVANCED BANK SYSTEM ======

1. Create Account
2. Deposit
3. Withdraw
4. Balance
5. Transfer Money
6. Mini Statement
7. Add Interest
8. Exit
```

---

# 📸 Sample Features

## Example Transaction Record

```text
1001|Deposit|5000|Tue May 20 10:30:15 2026
```

---

## Example Mini Statement

```text
--- Last 5 Transactions ---

1001|Deposit|2000|Tue May 20 10:00:12 2026
1001|Withdraw|500|Tue May 20 10:15:44 2026
1001|Interest|150|Tue May 20 11:00:10 2026
```

---

# 🔒 Security Features

- Prevents overdrawing balance
- Validates account existence
- Maintains transaction history
- Uses separate transaction logs

---

# 🔮 Future Enhancements

- ATM PIN Authentication
- Admin Login System
- GUI Banking Application
- Database Integration (MySQL)
- Online Banking Features
- Loan Management
- Mobile Banking Support
- Encryption for Account Data

---

# 👩‍💻 Developed By

Suvedha M  
1st Year CSE  
Sri Krishna College of Engineering and Technology

---

# ⭐ Learning Outcome

This project helps in understanding:
- Real-world banking operations
- Advanced C++ concepts
- File handling techniques
- Transaction management systems
- OOP implementation

---
