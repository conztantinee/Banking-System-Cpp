#include <iostream>
#include <string>
#include "Loan.h"

using namespace std;

Loan::Loan()
{
	name;
	password;
	debt;
}

Loan::Loan(string n, int p, double amount)
{
	name = n;
	password = p;
	debt = amount;
}

Loan::Loan(const Loan& other) 
{
	name = other.name;
	password = other.password;
	debt = other.debt;
}

bool Loan::operator ==(char c)
{
    if (type == c)
    {
        return true;
    }
    return false;
}

void Loan::transaction(double amount)
{
    if(amount<debt)
        debt = debt - amount;
    else
        cerr << " YOU CAN NOT REPAY MORE THAN DEBT" << endl;
}

void Loan::print()
{
    cout << " NAME: " << name << " PASSWORD " << password <<" YOUR DEBT IS: "<< debt << endl;
}

void Loan::save(ostream& os)
{
	os << type<<  ';' << password << ';' << debt << ';' << name << endl;
}
void Loan::load(istream& is)
{
    string name; int password; double debt ; char c;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> password;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> debt;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> name;
    if (is)
    {
        this->name = name;
        this->password = password;
        this->debt = debt;
    }
    else
    {
        cerr << "Error in input format." << endl;
    }
}
