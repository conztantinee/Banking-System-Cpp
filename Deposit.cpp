#include <iostream>
#include <string>
#include "Deposit.h"

using namespace std;

Deposit::Deposit()
{
	name;
	password;
	money;
}

Deposit::Deposit(string n, int p, double amount)
{
	name = n;
	password = p;
	money = amount;
}

Deposit::Deposit(const Deposit& other)
{
	name = other.name;
	password = other.password;
	money = other.money;
}

bool Deposit::operator ==(char c)
{
    if (type == c)
    {
        return true;
    }
    return false;
}

void Deposit::transaction(double amount)
{
    if (amount < money)
        money = money - amount;
    else    
        cerr << " YOU CAN NOT WITHDRAW MORE THAN YOU HAVE" << endl;
}

void Deposit::print()
{
    cout << " NAME: " << name << " PASSWORD " << password << " YOUR DEPOSIT IS: " << money << endl;
}

void Deposit::save(ostream& os)
{
    os << type <<  ';' << password << ';' << money << ';' << name << endl;
}
void Deposit::load(istream& is)
{
    string name; int password; double money; char c;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> password;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> money;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> name;
    if (is)
    {
        this->name = name;
        this->password = password;
        this->money = money;
    }
    else
    {
        cerr << "Error in input format." << endl;
    }
}
