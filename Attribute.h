#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H 

#include <string>
#include <vector>
#include <iostream>


using namespace std; 

class Attribute 
{
	
	public:
	string name;
	string type;
	vector <string> data;
	void setName(string name_);
	
	Attribute();
    Attribute(vector<string> data);
	Attribute(string name_ , string type_ , vector <string> data_);
	string getName();
	string getType();
	
	vector<string> getData();
	istream& Read(istream& input); // needed to be able to print attributes to txt file
	ostream& Write(ostream& output);
};

#endif
