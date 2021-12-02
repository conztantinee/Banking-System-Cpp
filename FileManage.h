#ifndef FILEMANAGE_H
#define FILEMANAGE_H

#include <iostream>

using namespace std;

// abstract class for file management operations
class FileManage
{
public:
	
	//pure virtual function for saving data to file
	virtual void save(ostream &) = 0;

	//pure virtual function for loading data from file
	virtual void load(istream &) = 0;

};

#endif // FILEMANAGE_H
