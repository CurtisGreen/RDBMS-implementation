#include "Parser.h"

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;


void Parser:: setToken()
{
	token = tokens[current_token_index]; // set token to be current token in vector 
}

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
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
	}
	int paren_count = 1;
	while (paren_count != 0) {	//checks for attribute-list and types
		input_str = "";
		t = ts.get();
		if (t.value == '('){
			paren_count++;
		}
		else if(t.value == ')'){
			paren_count--;
		}
		if (paren_count == 0){
			input_str = ts.out_buff();
		}
		else{
			switch(t.value){
				case ',': case ' ': input_str = ts.out_buff(); break;
				default: ts.putback(t); break;
			}
		}
		if (t.value == ' '){	//Get attribute name
			Attribute att;
			att.name = input_str;
			type_att_list.push_back(att);
		}
		else if(t.value == ',' || (t.value == ')' && paren_count == 0)){	//Get attribute type //TODO: will need to check if extra spaces are there anyways
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
		t = ts.get();
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
	for (int i = 0; i < type_att_list.size(); i++){
		//cout << type_att_list[i].name << type_att_list[i].type << endl;
	}
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
    string rel_name;
    string input_str = "";
    Token t = ts.get();
    while (t.value != ';') {
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
    
    e.open(rel_name);
}
void Parser :: execute_close()
{
    //TODO: finsih it
    //close-cmd ::== CLOSE relation-name
    string rel_name;
    string input_str = "";
    Token t = ts.get();
    while (t.value != ';') {
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
    
    e.close(rel_name);
    
}
void Parser :: execute_show()
{
	//TODO: Finish it 
	//show-cmd ::== SHOW atomic-expr
	/*
	Table t  = atomic_expression();
	//expect semicolon
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
	//TODO
	//write-cmd ::== WRITE relation-name
	/*
	//expect identifier
	string table_name = (get data)
	//expect semicolon
	e.write(table_name);
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
		//cout << "value = " << t.value << endl;
		string input_str = "";
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//cout << input_str << endl;
		if (input_str == "CREATE"){
			cout << "executing create" << endl;
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
		Token t('a');
		while (t.value != ';' && t.value != '`') {
			t = ts.get();
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

