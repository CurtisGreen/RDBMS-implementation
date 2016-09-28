#ifndef PARSER_H_
#define PARSER_H_

#include "Engine.h"

#include <string>
#include <vector>
#include <iostream>



using namespace std;

class Parser{
	

public:
		enum Token {
		
		// If we need to add more we can, most of them are here I think
		OPEN, CLOSE, WRITE, EXIT, SHOW, SELECT, PROJECT, RENAME,
		CREATE_TABLE, PRIMARY_KEY, UPDATE, SET, WHERE, INSERT_INTO,
		VALUES_FROM,DELETE_FROM, VARCHAR, INTEGER_SYM,
		
		// <-  
		LARROW, LPAREN, RPAREN, PLUS, MINUS, TIMES, COMMA, SEMICOLON, EQUALS,
		
		//== 
		EQ, NEQ, LESS, GREATER, LEQ, GEQ, AND, OR,
		
		// Identifier - starts with alpha, digit, or "_"
		INTEGER, IDENTIFIER, LITERAL
		};
		
		//changes won't be made to the string, so using pointer
		const char* token_strings [38] = {
		"OPEN", "CLOSE", "WRITE", "EXIT", "SHOW", "SELECT", "PROJECT", "RENAME",
		"CREATE_TABLE", "PRIMARY_KEY", "UPDATE", "SET", "WHERE", "INSERT_INTO",
		"VALUES_FROM","DELETE_FROM", "VARCHAR","LARROW", "LPAREN", "RPAREN", "PLUS",
		"MINUS", "TIMES", "COMMA", "SEMICOLON", "EQUALS","EQ", "NEQ", "LESS", "GREATER", 
		"LEQ", "GEQ", "AND", "OR","INTEGER", "IDENTIFIER", "LITERAL", "INTEGER"
			
		};
	
	
private:

	
	vector<Token> tokens;
	vector<string> buffer;
	Engine e;
	
	
	void read_input(string input); //reads input until it sees an alpha numeric
	void add_token(Token token, string value); // pushes token into buffer
	Token get_token(string value); // returns token from string value 

	
};




#endif