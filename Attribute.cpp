#include "Attribute.h"
#include <string> 
#include <vector>
#include <iostream>

using namespace std;

Attribute::Attribute(){
	name = "Name";
	type = "Type";
	data = vector<string>();
}

Attribute::Attribute(vector<string> data_){
	data = data_;
}

Attribute::Attribute(string name_, string type_, vector<string> data_){
	name = name_;
	type = type_;
	data = data_;
}

string Attribute::getName(){
	return name;
}

void Attribute :: setName(string name_){
	name = name_;	
}

string Attribute::getType(){
	return type;
}

vector<string> Attribute::getData(){
	return data;
}

istream&  Attribute ::Read(istream& input)
{
	string temp_string;
	getline(input, name, '\n');
	getline(input, type, '\n');
	data = vector<string>();

	while(1){
		getline(input, temp_string, ' ');
		if(temp_string == "."){
			break;
		}
		else	{
			data.push_back(temp_string);
		}
	}
	return input;
}

ostream&  Attribute :: Write(ostream& output){
	output << name  << endl;
	output << type << endl;
	
	for (int i =0; i < data.size(); i++){
		output << data[i] << " " ;
	}
	output << "." << " \n";
	return output;
}

