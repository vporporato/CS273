/**
*  Program Name: PR4_Banking Application
*  Last modified: Fall 2014
*  Authors: Whitworth CS Department
*/

#include <iostream>
#include <string>
#include <vector>
#include "Bank.h"
#include "readint.h"

//using namespace std;

/**
This is where we add a new account in the bank
If it is a new customer, we also need to get additional information
to add a new customer record in the bank.

@param bank	Bank object to which we will be adding accounts
*/
void Add_Account(Bank &bank)
{
	std::string name;
	std::cout << "Please enter your name: ";
	std::cin.ignore();
	getline(std::cin, name);

	int acct_type;
	std::string	menu_string = "Type of account: \n";
	menu_string += "   0 - Savings\n";
	menu_string += "   1 - Checking\n";
	menu_string += "Enter: ";
	acct_type = read_int(menu_string, 0, 1);

	std::string acct_type_str;
	if (acct_type == 0)
		acct_type_str = "savings";
	else
		acct_type_str = "checking";

	Account *acct = bank.add_account(name, acct_type_str); // attempt to add an account
	if (acct == NULL) { // case for new user
		std::cout << "You appear to be a new user.  We will need more information.\n";
		// get all the required information for a new user
        std::cout << "Address: ";
		std::string address;
		std::cin.ignore();
		getline(std::cin, address);
		std::string telephone;
		std::cout << "Telephone Number: ";
		getline(std::cin, telephone);
		std::cout << "Age: ";
		int age;
		std::cin >> age;

		int cust_type;
		std::string	menu_string = "Type of customer: \n";
		menu_string += "   0 - Adult\n";
		menu_string += "   1 - Senior\n";
		menu_string += "   2 - Student\n";
		menu_string += "Enter: ";
		cust_type = read_int(menu_string, 0, 2);

		std::string cust_type_str;
		if (cust_type == 0)
			cust_type_str = "adult";
		else if (cust_type == 1)
			cust_type_str = "senior";
		else
			cust_type_str = "student";
		acct = bank.add_account(name, address, telephone, age, cust_type_str, acct_type_str);
	}
	if (acct) {
		std::cout << "Your new account ID is " << acct->get_account() << std::endl;
	}
	else {
		std::cout << "Sorry.  We failed to create an account for you\n";
	}
}

/**
The is where we list all the accounts owned by a customer (if he/she exists)

@param bank Bank object in which accounts are located
*/
void List_Account(Bank &bank)
{
	std::cout << "Please enter your name: ";
	std::string name;
	std::cin.ignore();
	getline(std::cin, name);

	std::vector<int> list = bank.get_account(name);
	std::cout << std::endl;
	for (size_t i = 0; i < list.size(); i++) {
		Account *acct = bank.get_account(list[i]);
		if (acct)
			std::cout << acct->to_string();
		std::cout << "---------------------------\n";
	}
	std::cout << "Total " << list.size() << " accounts found\n";
}

/**
This is where we make a deposit in an account, identified by its account ID

@param bank Bank object in which account is located
*/
void Make_Deposit(Bank &bank)
{
	int acct_id;
	std::cout << "Please enter your account ID: ";
	std::cin >> acct_id;
	double amt;
	std::cout << "Amount to deposit: ";
	std::cin >> amt;
	bank.make_deposit(acct_id, amt);
}

/**
This is where we make a withdrawal in an account, identified by its ID

@param bank Bank object in which account is located
*/
void Make_Withdrawal(Bank &bank)
{
	int acct_id;
	std::cout << "Please enter your account ID: ";
	std::cin >> acct_id;
	double amt;
	std::cout << "Amount to withdraw: ";
	std::cin >> amt;
	bank.make_withdrawal(acct_id, amt);
}

int main()
{
	Bank bank; // We create the bank

			   // Display menu for banking activites
	std::cout << "Welcome to the CS273 Banking Application!\n";
	std::cout << "Thank you for your hard work!\n";
	char choice;
	do {
		std::cout << std::endl;
		int select;
		std::string	menu_string = "Please choose an action below:\n";
		menu_string += "0 - Add Account\n";
		menu_string += "1 - List Accounts\n";
		menu_string += "3 - Make withdrawal\n";
		menu_string += "4 - Quit\n";
		menu_string += "Enter: ";
		select = read_int(menu_string, 0, 4);

		// Perform the banking activity based on the user selection
		switch (select) {
		case 0:
			Add_Account(bank);
			break;
		case 1:
			List_Account(bank);
			break;
		case 2:
			Make_Deposit(bank);
			break;
		case 3:
			Make_Withdrawal(bank);
			break;
		default:
			std::cout << "Goodbye!  Thank you for visiting.\n";
			return 0;
		}

		std::cout << "Do you wish to perform another transaction? (y or n): ";
		std::cin >> choice;
	} while (choice != 'n');

    std::cout << "Goodbye!  Thank you for visiting.\n";
}




