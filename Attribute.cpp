

#ifndef _attributecpp_
#define _attributecpp_

#include "Attribute.h"

Attribute::Attribute()
{
	
	name = "Name";
	type = "Type";
	data = vector<string>();
	
}

Attribute::Attribute (string name_, string type_, vector<string> data_)
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


#endif


