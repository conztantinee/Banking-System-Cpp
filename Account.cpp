#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

Account::Account()
{
	name;
	password;
}

Account::Account(string n, int p) 
{
	name = n;
	password = p;
}

Account::Account(const Account& theOther) 
{
	name = theOther.name;
	password = theOther.password;
}

bool Account::operator !=(int i)
{
	if (password == i)
	{
		return false;
	}
	return true;
}

bool Account::operator ==(string s)
{
	if (name == s)
	{
		return true;
	}
	return false;
}
bool Account::operator !=(string s)
{
	if (name == s)
	{
		return false;
	}
	return true;
}

bool Account::operator ==(char c) 
{
	if (type==c)
	{
		return true;
	}
	return false;
}

void Account::print()
{
	cout << " NAME: " << name << " PASSWORD " << password << endl;
}

void Account::save(ostream& os)
{
    os << type <<  ';' << password << ';' << name << endl;
}
void Account::load(istream& is)
{
    string name; int password; char c;
	is >> c;
	if (c != ';') is.clear(ios::failbit);
    is >> password;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> name;
    if (is)
    {
        this->name = name;
        this->password = password;
    }
    else
    {
        cerr << "Error in input format." << endl;
    }
}