#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "FileManage.h"
#include <iostream>
#include <string>

//Class for storing account representation

using namespace std;
class Account : public FileManage
{
public:
	//name of account's owner
	string name;

	//4 digit  password for authorization
	int password;

//private:
	//type identifier
	 static const char type = 'a';
public:
	Account();
	//constructor 
	Account(string n, int p);
	//copy constructor 
	Account(const Account& theOther);

	//operator overloading to check password
	bool operator !=(int i);
	//operator overloading to check name
	bool operator ==(string s);
	bool operator !=(string s);

	//operator for checking type
	virtual bool operator ==(char c);

	//function to be used in derived classes
	virtual void transaction(double amount) {}

	//function to print member variables
	virtual void print();

	// Saving to file
	void save(ostream &);
	// Loading from file
	void load(istream &);
};

#endif //ACCOUNT_H
