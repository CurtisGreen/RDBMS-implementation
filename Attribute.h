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
	
	Attribute();
	Attribute (string name_ , string type_ , vector <string> data_);
	string getName();
	string getType();
	vector<string> getData();
	
};

#endif
