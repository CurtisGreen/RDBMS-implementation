#include "Attribute.h"
#include <string> 
#include <vector>
#include <iostream>

using namespace std;

Attribute::Attribute()
{
	
	name = "Name";
	type = "Type";
	data = vector<string>();
	
}


Attribute::Attribute(vector<string> data_)
{
	
	data = data_;
}


Attribute::Attribute(string name_, string type_, vector<string> data_)
{
	name = name_;
	type = type_;
	data = data_;
}

string Attribute::getName()
{
	return name;
}
void Attribute :: setName(string name_)
{
	name = name_;
	
}

string Attribute::getType()
{
	return type;
}

vector<string> Attribute::getData()
{
	return data;
}

istream&  Attribute ::Read(istream& input)
{
	string in_name, in_type;
	string in_data;
	input >> in_name >> in_type >> "\n";
	name = in_name;
	type = in_type;
	for (int i = 0; i < data.size(); i++){
	    input >> in_data;
	    data.push_back(in_data);
	}
}
ostream&  Attribute :: Write(ostream& output)
{
	cout << name << type << "\n";
	
	for (int i =0; i < data.size(); i++)
	{
		output << data[i] << " " ;
	}
	return output;
	
}

