#include "Attribute.h"
#include <string>
#inlude <vector>
#include <iostream>

using namespace std;

Attribute :: Attribute()
{
	
	name = "Default Name";
	type = "Default Type";
	data = vector<string>();
	
}

Attribute :: Attribute (string name_, string type_, vector<string> data_)
{
	name = name_;
	type = type_;
	data = data_;
}



