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

	//Constructors
	Attribute();
    Attribute(vector<string> data);
	Attribute(string name_ , string type_ , vector <string> data_);
	
	//Getters & Setters
	string getName();
	string getType();
	vector<string> getData();
	void setName(string name_);

	// output-input operators to write to file
	istream& Read(istream& input); 
	ostream& Write(ostream& output);
};

#endif
