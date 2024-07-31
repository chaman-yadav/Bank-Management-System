# Bank Management System in C++

## Overview

The Bank Management System is a console-based application implemented in C++ that allows users to manage bank accounts. It supports operations such as creating new accounts, depositing and withdrawing funds, modifying account details, and viewing account information. The system also handles account deletion and displays a list of all accounts.

## Features

- **Create Account**: Add a new account with details including account number, name, type (Current/Savings), and initial deposit.
- **Deposit Amount**: Deposit funds into an existing account.
- **Withdraw Amount**: Withdraw funds from an existing account.
- **Balance Enquiry**: View the balance and details of a specific account.
- **View All Accounts**: List all accounts with details.
- **Close Account**: Delete an account from the system.
- **Modify Account**: Update account information including name, type, and balance.

## File Descriptions

- `.cpp`: The main program file containing the implementation of the bank management system.
- `account.dat`: A binary file used to store account information.


## Compilation and Execution

1. **Compile**: Use a C++ compiler to compile the `code.cpp` file. For example:
   ```sh
   g++ code.cpp -o Bank-Management-System


# How to Use

1. **Start the Program**: Run the compiled executable to start the Bank Management System.

2. **Main Menu**: You will see a main menu with various options. Enter the number corresponding to the operation you wish to perform.

3. **Follow Prompts**: Depending on your choice, follow the on-screen prompts to provide necessary details (e.g., account number, deposit amount).

4. **Perform Operations**:
   - **New Account**: Select option 1 to create a new account and enter the required details.
   - **Deposit/Withdraw**: Choose options 2 or 3 to deposit or withdraw funds, respectively. Provide the account number and amount.
   - **Balance Enquiry**: Choose option 4 to view account details and balance.
   - **View All Accounts**: Choose option 5 to list all accounts.
   - **Close Account**: Select option 6 to delete an account by providing the account number.
   - **Modify Account**: Choose option 7 to update account details.
   - **Exit**: Select option 8 to exit the application.

## Input Validation

The application performs input validation to ensure that user inputs are correct:

- **Account Number**: Must be a valid integer.
- **Name**: Can include spaces and special characters.
- **Account Type**: Must be 'C' for Current or 'S' for Savings. The application handles invalid input by prompting the user to re-enter the correct value.
- **Deposit/Withdraw Amount**: Must be a positive integer. The application ensures that the amount is non-negative and handles cases where the balance is insufficient for withdrawals.

## Error Handling

- **File Operations**: The application checks if files can be opened for reading or writing. If a file operation fails, an error message is displayed.
- **Invalid Input**: The application handles invalid inputs by prompting the user to re-enter the correct information.

## Contribution

Contributions are welcome! If you have suggestions for improvements or new features, please submit an issue or a pull request. For significant changes, open an issue to discuss the changes before submitting a pull request. Contributions could include:

- Bug fixes
- Feature enhancements
- Code optimizations
- Documentation improvements

## Acknowledgments

- Inspired by traditional banking systems and designed for educational purposes.
- Developed to enhance understanding of file operations, data management, and basic C++ programming.



