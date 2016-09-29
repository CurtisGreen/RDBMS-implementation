#include "Parser.h"
#include "Engine.h"
#include "Token_stream.h"

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;


void Parser:: read_input(string input)
{
	//TODO
}
vector <Parser:: Token> Parser:: getToken()
{
	return tokens;
}
/* Setter method to set the token to equal the current position in Token vector*/
void Parser :: setToken()
{
	token = tokens[current_token_index];
}
/*This functions allows you to use this in your helper functions to set up
what is to expected when you see a specific item */
void Parser :: expect(Token t) 
{
	if(current_token_index >= tokens.size())
	{
		throw runtime_error("Parser: Invalid Input");
	}
	else if(tokens[current_token_index] == t)
	{
		current_token_index++;
	}
}
/* Function allows input to be either put in a query category or command category */

bool Parser :: can_execute_program()
{
	if(tokens[tokens.size()-1] != Parser:: Token ::SEMICOLON)
	{
		throw runtime_error("Statement must end with semicolon");
	}
	if (token == Parser:: Token ::IDENTIFIER)
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

/* Depending on the comannd it will call the specific command to execute */

bool Parser :: command()
{
	switch (token)
	{
		case Parser::Token::EXIT:
			execute_exit();
			break;

		case Parser::Token::SHOW:
		{	
			execute_show();
			break;
		}
		case Parser:: Token::OPEN:
		{
			expect(Token::IDENTIFIER);
			execute_open();
			break;
		}
		case  Parser :: Token::WRITE:
		{
			expect(Parser:: Token::IDENTIFIER);
			execute_write();
			break;
		}
		case Parser::Token::CLOSE:
		{
			expect(Parser::Token::IDENTIFIER);
			execute_show();
			break;
		}
		case Parser::Token::CREATE:
			execute_create();
			break;

		case Parser::Token::UPDATE:
			execute_update();
			break;

		case Parser::Token::INSERT:
			execute_insert();
			break;

		case Parser:: Token::DELETE:
			execute_destroy();
			break;
	}
}
Table Parser :: execute_expression()
{
	switch (token)
	{
		case Parser::Token::LPAREN:
			return atomic_expression();
			break;

		case Parser::Token::SELECT:
			return execute_selection();
			break;

		case Parser::Token::PROJECT:
			return execute_projection();
			break;

		case Parser::Token::IDENTIFIER:
			return atomic_expression();
			break;

		case Parser::Token::RENAME:
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
	//TODOD
}
void Parser :: execute_create()
{
	//TODOD
}
void Parser :: execute_destroy()
{
	//TODOD
}
void Parser :: execute_open()
{
	//TODOD
}
void Parser :: execute_close()
{
	//TODOD
}void Parser :: execute_show()
{
	//TODOD
}
void Parser :: execute_exit()
{
	//TODOD
}
void Parser :: execute_write()
{
	//TODOD
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

void Parser:: read_input( string input)
{
	//TODO
}
void  Parser:: add_token(Token token, string value)
{
	tokens.push_back(token);
	buffer.push_back(value);
}
enum Parser:: get_token(string value)	//I changed this to an enum, it doesn't seem like it returns a token
{
	if(value == "SELECT")
		return SELECT;
	else if(value == "PROJECT")
		return PROJECT;
	else if(value== "RENAME")
		return RENAME;
	else if(value == "OPEN")
		return OPEN;
	else if(value== "CLOSE")
		return CLOSE;
	else if(value == "WRITE")
		return WRITE;
	else if(value == "EXIT")
		return EXIT;
	else if(value == "SHOW")
		return SHOW;
	else if(value == "UPDATE")
		return UPDATE;
	else if(value == "SET")
		return SET;
	else if(value == "WHERE")
		return WHERE;
	else if (value == "CREATE TABLE")
		return CREATE_TABLE;
	else if (value == "PRIMARY KEY")
		return PRIMARY_KEY;
	else if (value == "INSERT INTO")
		return INSERT_INTO;
	else if (value == "DELETE FROM")
		return DELETE_FROM;
	else if(value == "VARCHAR")
		return VARCHAR;
	else if(value == "INTEGER")
		return INTEGER_SYM;
	else if(isdigit(value[0]))			
		return INTEGER;
	else if (isalpha(value[0]))
		return IDENTIFIER;
	
}


void Parser :: initial(){
	while (true) {
		Token t = ts.get();
		string input_str = "";
		switch(t.kind){
			case '0': input_str = out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: finish rest of function calls
		enum identifier = get_token(input_str);
		switch(identifier){
			case: Create execute_create();
			//... fill in rest of cases here
			default: //Is a relation name so it'll be a query
		}
		//Check input_str against commands, if not a command then keep that value stored and call expression. Expression should retrun a table and you will rename that table to be input_str
		//Make sure to check to make sure input_str != ""
	}
}

void Parser :: input(Token_stream ts){
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

