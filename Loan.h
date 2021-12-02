#pragma once
#ifndef LOAN_H
#define LOAN_H

#include "Account.h"
#include "FileManage.h"
#include <string>
#include <iostream>

//class for storing loan type account

using namespace std;
class Loan : public Account, public FileManage
{
public:
	//account's loan debt
	double debt;

	//type identifier
	static const char type='l';

	//default constructor
	Loan();

	//copy constructor
	Loan(const Loan& other);

	//constructor
	Loan(string n, int p, double amount);

	//operator for checking type
	bool operator ==(char c);

	//repaying some of debt
	void transaction(double amount);

	//function to print member variables
	void print();

	// Saving to file
	void save(ostream& );
	// Loading from file
	void load(istream& );
};


#endif //LOAN_H

