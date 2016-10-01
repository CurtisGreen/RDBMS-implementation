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


void Parser:: read_input(string input)
{
	//TODO
}
/*This functions allows you to use this in your helper functions to set up
what is to expected when you see a specific item */
void Parser :: expect(Token_Sym::TokenSymbol symbol) 
{
	//
}

/* Function allows input to be either put in a query category or command category */
bool Parser :: can_execute_program()
{
	if(tokens[tokens.size()-1].getSymbol() != Token_Sym ::SEMICOLON)
	{
		throw runtime_error("Statement must end with semicolon");
	}
	if (token.getSymbol() == Token_Sym ::IDENTIFIER)
	{
		query(); // go to query execution 
	}
	else
	{
		command(); // go to command execution 
	}
	return true;
}
bool Parser :: query()
{
	//TODO
}


bool Parser :: command()
{
	switch (token.getSymbol())
	{
		case Token_Sym::EXIT:
			execute_exit();
			break;

		case Token_Sym::SHOW:
		{	
			execute_show();
			break;
		}
		case Token_Sym::OPEN:
		{
			expect(Token_Sym::IDENTIFIER);
			execute_open();
			break;
		}
		case  Token_Sym::WRITE:
		{
			expect(Token_Sym::IDENTIFIER);
			execute_write();
			break;
		}
		case Token_Sym::CLOSE:
		{
			expect(Token_Sym::IDENTIFIER);
			execute_show();
			break;
		}
		case Token_Sym::CREATE:
			execute_create();
			break;

		case Token_Sym::UPDATE:
			execute_update();
			break;

		case Token_Sym::INSERT:
			execute_insert();
			break;

		case Token_Sym::DELETE:
			execute_destroy();
			break;
	}
}
Table Parser :: execute_expression()
{
	switch (token.getSymbol())
	{
		case Token_Sym::LPAREN:
			return atomic_expression();
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
}
void Parser :: execute_update()
{
	//TODO
}
void Parser :: execute_create()
{
	//TODO
}
void Parser :: execute_destroy()
{
	//TODO
}
void Parser :: execute_open()
{
	//TODO
}
void Parser :: execute_close()
{
	//TODO
}void Parser :: execute_show()
{
	//TODO
}
void Parser :: execute_exit()
{
	//TODO
}
void Parser :: execute_write()
{
	//TODO
}
Table Parser :: execute_selection()
{
	//TODO
}
Table Parser :: execute_projection()
{
	//TODO
}
Table Parser :: execute_renaming()
{
	//TODO
}
Table Parser :: atomic_expression()
{
	//TODO
}
vector <string> Parser :: attribute_list()
{
	//TODO
}


void Parser :: initial(){
	while (true) {
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
		else if(input_str == "DESTROY"){
			execute_destroy();
		}

		//TODO: finish rest of function calls
		/*int identifier = get_token(input_str);
		switch(identifier){
			case: Create :
			execute_create();
			//... fill in rest of cases here
			default: //Is a relation name so it'll be a query
		}*/
		//Check input_str against commands, if not a command then keep that value stored and call expression. Expression should retrun a table and you will rename that table to be input_str
		//Make sure to check to make sure input_str != ""
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

