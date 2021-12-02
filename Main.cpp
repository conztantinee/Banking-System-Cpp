#include <iostream>
#include <string>
#include <fstream>
#include "Account.h"
#include "Deposit.h"
#include "Loan.h"

using namespace std;
int main()
{

	//name of text file for storing data
	const char* fname = "data.txt";
	//opening text file
	ifstream is;// (fname);
	try {
		is.open(fname);
		if (!is)
			throw false;
	}
	catch(bool a)
	{
		cerr << "Error opening input file: " << fname << endl;
	}
	//loading all data from text file to dynamically allocated stack:
	
	//variable for storing the number of accounts;
	unsigned counter = 0;

	//first we need to now size, so we count lines (the number of total accounts) using loop
	string line;
	while (getline(is, line))
		counter++;

	//variable for storing the max number of accounts;
	const unsigned maxelement = 50;
	//dynamically allocated array for storing 
	Account* accounts[maxelement];


	//now returning to the beginning of the file
	is.clear();
	is.seekg(0, ios::beg);


	//now loading to dynamic array
	for (unsigned int i = 0; i < counter; i++)
	{
		char a;
		is >> a;
		if (a=='a')
		{
			accounts[i] = new Account;
			accounts[i]->load(is);
		}
		else if (a == 'l')
		{
			accounts[i] = new Loan;
			accounts[i]->load(is);
		}
		else if (a == 'd')
		{
			accounts[i] = new Deposit;
			accounts[i]->load(is);
		}
	}

	//closing text file
	try 
	{
		is.close();
		if (!is)
			throw false;
	}
	catch (bool a)
	{
		cerr << "Error closing input file: " << fname << endl;
	}
	
	cout << "WELCOME TO BANKING SYSTEM" << endl;	

	//variable to choose to quit the program or not
	bool quit = false;

	//loop containing menu
	while (!quit)
	{
		//variables for temporarily containing account details
		string nbuff;
		int pbuff;
		double dbuff;
		bool bbuff;
		int choice;
		//presenting menu
		cout << "1. CREATE NEW ACCOUNT" << endl << "2. LOGIN" << endl << "0. QUIT" << endl << "ENTER THE NUMBER ACCORDING THE MENU!" << endl;
		cin >> choice;
		
		//switch case to be able to choose from the menu
		switch (choice)
		{

		case 1:
			//exception handling to prevent passing limit number of accounts
			try
			{
				if (counter == maxelement)
				{
					throw false;
				}
			}
			catch (bool a)
			{
				cerr << "PROGRAM HAS REACHED THE NUMBER OF MAXIMUM ALLOWED ACCOUNTS - 50" << endl << "TRY RUNNING AGAIN AND CHOOSING DIFFERENT OPTION" << endl;
			}

			//loop to ask user enter name until user enters valid one
			while (true)
			{
				cout << "PLEASE ENTER YOUR NAME" << endl << "NO LESS THAN 2 CHARACTER OR NO MORE THAN 20 CHARACTERS" << endl;
				cin >> nbuff;
				//checking if this name already exists
				bbuff = true;
				for (unsigned i = 0; i < counter; i++)
				{
					if (*accounts[i] == nbuff)
						bbuff = false;
				}
				if (nbuff.length() > 1 && nbuff.length() <= 20 && bbuff)
					break;
				cout << "UNALLOWED NUMBER OF CHARACTERS OR , TRY AGAIN" << endl;
			}

			//loop to ask user enter password until user enters valid one
			while (true)
			{
				cout << "PLEASE ENTER YOUR PASSWORD" << endl << "NO LESS THAN 4 DIGITS OR NO MORE THAN 10 DIGITS" << endl;
				cin >> pbuff;
				if (pbuff > 999 && pbuff < 10000000000)
					break;
				cout << "PASSWORD IS TOO SHORT OR TOO LONG, TRY AGAIN" << endl;
			}

			//creating account
			accounts[counter] = new Account(nbuff, pbuff);
			if (accounts[counter]->name == nbuff && accounts[counter]->password == pbuff) 
			{
				cout << "ACCOUNT CREATED SUCCESFULLY, REDIRECTING TO MAIN MENU..." << endl;
				counter++;
			}
			else 
			{
				cout << "SOMETHING WENT WRONG, REDIRECTING TO MAIN MENU..." << endl;
				delete accounts[counter];
			}
			break;
		
		case 2:
			cout << "ENTER NAME" << endl;
			cin >> nbuff;
			unsigned i;
			//finding account by comparing entered name with every name on the list till it finds
			for (i = 0; i < counter; i++)
			{
				if (*accounts[i] == nbuff)
					break;
			}
			//using exception handling to double check  
			try
			{
				if (*accounts[i]!=nbuff)
				{
					throw false;
				}
			}
			catch (bool a)
			{
				cerr << "SUCH ACCOUNT DOES NOT EXITS" << endl;
			}
			//checking password
			cout << "ENTER PASSWORD" << endl;
			cin >> pbuff;
			if (*accounts[i] != pbuff)
			{
				cout << "WRONG PASSWORD, RETURNING TO MENU..." << endl;
				break;
			}
			accounts[i]->print();

			//menu of avaible actions for each type of accouts
			if (*accounts[i] == 'a')
			{
				cout << "1.TAKE LOAN" << endl << "2.STORE MONEY" << endl << "0. QUIT" << endl;
				cin >> choice;
				switch (choice) 
				{
				
				case 1:
					cout << "ENTER AMOUNT:" << endl;
					cin >> dbuff;
					if (dbuff<=0)
					{
						cout << "INVALID AMOUNT" << endl;
						break;
					}
					nbuff = accounts[i]->name;
					pbuff = accounts[i]->password;
					delete accounts[i];
					accounts[i] = new Loan(nbuff, pbuff, dbuff);
					cout << "LOAN WAS SUCCESSFULLY TAKEN. RETURNIN TO MENU..." << endl;
					break;
				
				case 2:
					cout << "ENTER AMOUNT:" << endl;
					cin >> dbuff;
					if (dbuff <= 0)
					{
						cout << "INVALID AMOUNT" << endl;
						break;
					}
					nbuff = accounts[i]->name;
					pbuff = accounts[i]->password;
					delete accounts[i];
					accounts[i] = new Deposit(nbuff, pbuff, dbuff);
					cout << "MONEY WAS SUCCESSFULLY STORED. RETURNING TO MENU..." << endl;
					break;
				
				case 0:
					cout << "RETURNING TO MAIN MENU..." << endl;
					break;
				
				default:
					cerr << "SUCH DECISION DOES NOT EXIST" << endl;
					break;
				}
			}
			
			if (*accounts[i] == 'd')
			{
				cout << "1. WITHDRAW MONEY" << endl << "0. QUIT" << endl;
				cin >> choice;
				switch (choice)
				{
				
				case 1:
					cout << "ENTER AMOUNT" << endl;
					cin >> dbuff;
					if (dbuff<=0)
					{
						cout << "INVALID AMOUNT" << endl;
						break;
					}
					accounts[i]->transaction(dbuff);
					cout << "RETURNING TO MAIN MENU...!" << endl;
					break;
				
				case 0:
					cout << "RETURNING TO MAIN MENU..." << endl;
					break;
				
				default:
					cerr << "SUCH DECISION DOES NOT EXIST" << endl;
					break;
				}
			}
			
			if (*accounts[i] == 'l')
			{
				cout << "1. REPAY MONEY" << endl  << "0. QUIT" << endl;
				cin >> choice;
				switch (choice)
				{
				
				case 1:
					cout << "ENTER AMOUNT" << endl;
					cin >> dbuff;
					if (dbuff <= 0)
					{
						cout << "INVALID AMOUNT" << endl;
						break;
					}
					accounts[i]->transaction(dbuff);
					cout << "RETURNING TO MAIN MENU..." << endl;
					break;
				
				case 0:
					cout << "RETURNING TO MAIN MENU..." << endl;
					break;
				
				default:
					cerr << "SUCH DECISION DOES NOT EXIST" << endl;
					break;
				}
			}
			break;
		
		case 0:
			cout << "ABORTING THE PROGRAM..., BYE!" << endl;
			quit = true;
			break;
		
		default:
			cerr << "SUCH DECISION DOES NOT EXIST" << endl;
			break;
		}
	}
	
	//process of saving data to file

	//using exception handling to avoid unopened file
	ofstream  os;
	try
	{
		os.open(fname);
		if (!os)
			throw false;
	}
	catch (bool a)
	{
		cerr << "Error opening output file: " << fname << endl;
	}
	//loop to save data 
	for (unsigned i = 0; i < counter; i++)
	{
		accounts[i]->save(os);
	}
	//using exception handling to avoid unclosed file
	try {
		os.close();
		if (!os)
			throw false;
	}
	catch (bool a)
	{
		cerr << "Error closing output file: " << fname << endl;
	}
	//freeing allocated memory
	for (unsigned i = 0; i < counter; i++)
	{
		delete accounts[i];
	}
}