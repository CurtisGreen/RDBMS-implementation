#include "Parser.h"

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

bool Parser :: query(string rel_name)
{
	//TODO
	//query ::= relation-name <- expr ;
}

Table Parser :: execute_expression()
{
	switch (token.getSymbol())
	{
		case Token_Sym::LPAREN:
			return execute_expression();	//Was atomic expression, but atomic expression should only be relation name/attribute name
			break;

		case Token_Sym::SELECT:
			return execute_selection();
			break;

		case Token_Sym::PROJECT:
			return execute_projection();
			break;

		case Token_Sym::IDENTIFIER:
			return atomic_expression();
			break;

		case Token_Sym::RENAME:
			return execute_renaming();
			break;
	}	
}
void Parser :: execute_insert()
{
	//TODO
	//insert-cmd ::= INSERT INTO relation-name VALUES FROM ( literal { , literal } )
          //| INSERT INTO relation-name VALUES FROM RELATION expr
}
void Parser :: execute_update()
{
	//TODO
	//update-cmd ::= UPDATE relation-name SET attribute-name = literal { , attribute-name = literal } WHERE condition
}
void Parser :: execute_create()
{
	//TODO
	//create-cmd ::= CREATE TABLE relation-name ( typed-attribute-list ) PRIMARY KEY ( attribute-list )
	vector<Attribute> type_att_list;
	string rel_name;
	string input_str = "";
	vector<string> keys;
	while (input_str != "TABLE") {	//checks for TABLE
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not table
	}
	Token t = ts.get();
	while (t.value != ' ') {	//checks for relation-name
		input_str = "";
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		t = ts.get();
		if (t.value == ' '){
			rel_name = input_str;
		}
	}
	while (t.value != '('){		//go into parentheses
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
	}
	while (t.value != ')') {	//checks for attribute-list and types
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		if (t.value == ' '){	//Get attribute name
			Attribute att;
			att.name = input_str;
			type_att_list.push_back(att);
		}
		else if(t.value == ','){	//Get attribute type //TODO: will need to check if extra spaces are there anyways
			type_att_list[type_att_list.size()-1].type = input_str;
		}
	}
	while (input_str != "PRIMARY") {	//check for PRIMARY
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not PRIMARY
	}
	while (input_str != "KEY") {	//check for KEY
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not KEY
	}
	//Call space removing functions
	while (t.value != '('){		//go into parentheses
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
	}
	while (t.value != ')') {	//pass back keys
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		if (t.value == ','){	//Get attribute name
			keys.push_back(input_str); 
		}
	}
	cout << "actually here" << endl;
	e.create(rel_name, type_att_list, keys);
	e.show(rel_name);
}
void Parser :: execute_destroy()
{
	//TODO
	//delete-cmd ::= DELETE FROM relation-name WHERE condition
}
void Parser :: execute_open()
{
	//TODO : finish it 
	//open-cmd ::== OPEN relation-name
	/*
	string file_name;
	string input_string = "";
	Token t = ts.get();
	while (t.value != ' ') {	
		input_string = "";
		switch(t.kind){
			case '0': input_string = ts.out_buff(); 
			break;
			default: ts.putback(t); break;
		}
		t = ts.get();
		if (t.value == ' '){
			file_name = input_string;
		}
	}
	ifstream input_file;
	input_file.open(file_name + ".db");
	if(!input_file.is_open())
	{
		throw runtime_error("Error: Failed to Open File");
	}
	else
	{
		cout << "Opening :" << file_name << endl;
	}
	*/
	
}
void Parser :: execute_close()
{
	//TODO: finsih it 
	//close-cmd ::== CLOSE relation-name
	//expect identifier
	/*
	string table_name;
	string input_string = "";
	Token t = ts.get();
	while (t.value != ' ') {	
		input_string = "";
		switch(t.kind){
			case '0': input_string = ts.out_buff(); 
			break;
			default: ts.putback(t); break;
		}
		t = ts.get();
		if (t.value == ' '){
			table_name = input_string;
		}
	}
	e.close(table_name);
	*/
	
}
void Parser :: execute_show()
{
	//TODO: Finish it 
	//show-cmd ::== SHOW atomic-expr
	/*
	Table t = atomic_expression();
	string table_name = t.getName();
	e.show(table_name);
	*/
}
void Parser :: execute_exit()
{
	//TODO : Done
	//exit-cmd ::== EXIT 
	e.exit_();

}
void Parser :: execute_write()
{
	//TODO : Finish it 
	//write-cmd ::== WRITE relation-name
	/*
	string table_name;
	string input_string = "";
	Token t = ts.get();
	while (t.value != ' ') {	
		input_string = "";
		switch(t.kind){
			case '0': input_string = ts.out_buff(); 
			break;
			default: ts.putback(t); break;
		}
		t = ts.get();
		if (t.value == ' '){
			table_name = input_string;
		}
	}
	Table table = e.getTable(table_name);
	e.write(table);
	*/
	

}
Table Parser :: execute_selection()
{
	//TODO
	//selection ::= select ( condition ) atomic-expr
}
Table Parser :: execute_projection()
{
	//TODO
	//projection ::= project ( attribute-list ) atomic-expr
}
Table Parser :: execute_renaming()
{
	//TODO
	//renaming ::= rename ( attribute-list ) atomic-expr
}
Table Parser :: atomic_expression()
{
	//TODO
	//atomic-expr ::= relation-name | ( expr )
}
Table Parser :: execute_union()
{
	//TODO
	// union ::= atomic-expr + atomic-expr
}
Table  Parser:: execute_difference()
{
	//TODO
	// difference ::= atomic-expr - atomic-expr
}
vector <string> Parser :: attribute_list()
{
	//TODO
	//attribute-list ::= attribute-name { , attribute-name }
}

void Parser :: initial(){
	Token t('a');
	while (t.value != ';' && t.value != '`') {
		//Check input_str against commands, if not a command then keep that value stored and call expression. Expression should retrun a table and you will rename that table to be input_str
		//Make sure to check to make sure input_str != ""	
		t = ts.get();
		string input_str = "";
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		cout << input_str << endl;
		if (input_str == "CREATE"){
			execute_create();
		}
		else if(input_str == "INSERT"){
			execute_insert();
		}
		else if(input_str == "UPDATE"){
			execute_update();
		}
		else if(input_str == "OPEN"){
			execute_open();
		}
		else if(input_str == "CLOSE"){
			execute_close();
		}
		else if(input_str == "WRITE"){
			execute_write();
		}
		else if(input_str == "EXIT"){
			execute_exit();
		}
		else if(input_str == "SHOW"){
			execute_show();
		}
		else if(input_str == "DELETE"){
			execute_destroy();
		}
		else{	//Must be a query
			query(input_str);
		}
	}
}
int Parser :: input(){
	try {
		cout << "inside input" << endl;
		Token t('a');
		while (t.value != ';' && t.value != '`') {
			t = ts.get();
			cout << t.value << endl;
			if (t.value == ';')
				cout << "Finished line" << endl;	
			else
				ts.putback(t);
			initial();
		}
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		return 1;
	}
	catch(...) {
		cerr << "exception\n";
		return 2;
	}
}

