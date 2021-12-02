#pragma once
#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Account.h"
#include "FileManage.h"
#include <string>
#include <iostream>

//class for storing deposit type account

using namespace std;
class Deposit : public Account, public FileManage
{
public:
	//money stored in account
	double money;

	//type identifier
	static const char type = 'd';

	//default constructor
	Deposit();

	//constructor
	Deposit(string n, int p, double amount);

	//copy constructor
	Deposit(const Deposit& other);

	//operator for checking type
	bool operator ==(char c);

	//withdrawing some money
	void transaction(double amount);

	//function to print member variables
	void print();

	// Saving to file
	void save(ostream& );
	// Loading from file
	void load(istream& );

};
#endif //DEPOSIT_H
