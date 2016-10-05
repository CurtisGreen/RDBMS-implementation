#include "Table.h"


using namespace std;

Table :: Table(string new_name, vector<Attribute> new_att, vector<string> new_id){
	name = new_name;
  	att = new_att;
  	id = new_id;
}
Table::Table(){
	name = "Name";
	att = vector<Attribute>();
	id = vector<string>();
}

string Table:: getName(){
	return name;
}


Table::Table (const Table& table){
	name = table.name;
	att = table.att;
	id = table.id;
	
}

ostream& Table :: Write(ostream& output){
	output << name << endl;

	for (int i =0; i < att.size(); i++){
		att[i].Write(output);	 // writes the output of each attribute 
	}
	output << "END-OF-TABLE" ; // tag to let user know it is the end of the table 
	output << "END" << endl;
	return output;
 }

istream& Table :: Read(istream& input){

	string temp_string;
	Attribute temp_attribute;
	getline (input, name, '\n'); // reads the attributes and their names
	att = vector<Attribute>();
	
	while(1){
		temp_attribute.Read(input);
		att.push_back(temp_attribute);
		input >> temp_string;
		if(temp_string == "END-OF-TABLE"){ // stops reading when reaches the end of table tag 
			break;
		}
		else{
			for (int i = 0; i < temp_string.size(); i++){
				input.putback(temp_string.c_str()[temp_string.size()-i-1]); 
			}
		}
	}
	return input;
}


istream& operator >> (istream& input, Table& table){ // defined operator that reads input
	table.Read(input);
	return input;
}

ostream& operator << (ostream& output, Table& table){ // defined operator that write output
	table.Write(output);
	return output;
}
