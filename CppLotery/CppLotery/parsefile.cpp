// parsefile.cpp : parsefile fuction
//

#include <iostream>
//#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "encapsulate.h"
using namespace std;

#define TRACEPF

#define FILE_NAME "C:\\ssq.txt"

typedef vector<myarray> redBallSet;

redBallSet redset;

ifstream& open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

bool parseFile(int count)
{
	ifstream is;
	open_file(is, FILE_NAME);

	string record;
	string number;
	
	while (getline(is, record))
	{
		istringstream line(record);
		int index = 0;
		myarray redball;
		string number;
		line >> number >> number;               // first two string is date and serial number
		
		while (line >> number && index < count)
		{
			int tmp = atoi(number.c_str());     // parse string into number
			redball.setIndex(index, tmp);
            ++index;
		}
        
		redset.push_back(redball);
	}

#ifdef TRACEPF
	for (redBallSet::iterator i = redset.begin(); i != redset.end(); ++i)
	{
		for (int j = 0; j < count; ++j)
			cout << i->getIndex(j) << "\t";
		cout << endl;
	}

	cout << "size:" << redset.size() << endl;
#endif
    
	return true;
}

