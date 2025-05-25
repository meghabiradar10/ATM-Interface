# 💳 ATM Interface in C

This is a simple console-based **ATM Interface** program written in C. It simulates basic ATM functionalities like balance inquiry, deposit, withdrawal, PIN change, and mini statements.

## 🛠 Features

- Card number and PIN verification
- Balance Inquiry
- Deposit Amount (limit: ₹20,000 per transaction)
- Withdraw Amount (limited by available balance)
- Change PIN securely
- Mini Statement (last 5 transactions)
- Block card after 3 incorrect PIN attempts

## 📌 Functional Flow

1. User enters a valid **card number**.
2. Enters the correct **PIN** (maximum 3 attempts allowed).
3. Once verified, the user can:
   - Check balance
   - Deposit or withdraw money
   - View the last 5 transactions
   - Change their PIN
   - Exit the session

## 🧑‍💻 Tech Used

- Language: C
- Compiler: GCC / Any C Compiler
- Platform: Terminal/Console

## 🔒 Security Note

PIN and balance are currently stored in memory and reset every time the program restarts. No persistent storage is implemented yet.

## 📷 Sample Output


