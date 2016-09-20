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

string Attribute::getType()
{
	return type;
}

vector<string> Attribute::getData()
{
	return data;
}



