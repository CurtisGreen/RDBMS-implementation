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
	// Expect identifier
	// expect semicolon 
	/*
	string file_name = (get relation name)
	ifstream input_file;
	input_file.open(file_name + ".db");
	if(!input_file.is_open())
	{
		throw runtime_error&("Error: Failed to Open File");
	}
	*/
	
}
void Parser :: execute_close()
{
	//TODO: finsih it 
	//close-cmd ::== CLOSE relation-name
	//expect identifier
	/*
	string table_name = (get data )
	//expect semicolon
	e.close(table_name);
	*/
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
	while (true) {
		//Check input_str against commands, if not a command then keep that value stored and call expression. Expression should retrun a table and you will rename that table to be input_str
		//Make sure to check to make sure input_str != ""	
		Token t = ts.get();
		string input_str = "";
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
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
		Table table;
		while (true) {
			Token t = ts.get();
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

