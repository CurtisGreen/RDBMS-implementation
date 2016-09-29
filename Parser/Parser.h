#ifndef PARSER_H_
#define PARSER_H_

#include "Engine.h"

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <stdexcept>

using namespace std;

class Parser{
	

public: // If you are trying to get a token use Parser:: Token
		enum Token {
		OPEN, CLOSE, WRITE, EXIT, SHOW, SELECT, PROJECT, RENAME,
		CREATE_TABLE, PRIMARY_KEY, UPDATE, SET, WHERE, INSERT_INTO,
		VALUES_FROM,DELETE_FROM, VARCHAR, INTEGER_SYM, INSERT, CREATE, DELETE, 
		LARROW, LPAREN, RPAREN, PLUS, MINUS, TIMES, COMMA, SEMICOLON, EQUALS,
		EQ, NEQ, LESS, GREATER, LEQ, GEQ, AND, OR,INTEGER, IDENTIFIER, LITERAL,
		};
		const char* token_strings [41] = {
		"OPEN", "CLOSE", "WRITE", "EXIT", "SHOW", "SELECT", "PROJECT", "RENAME",
		"CREATE_TABLE", "PRIMARY_KEY", "UPDATE", "SET", "WHERE", "INSERT_INTO",
		"VALUES_FROM","DELETE_FROM", "VARCHAR","LARROW", "LPAREN", "RPAREN", "PLUS",
		"MINUS", "TIMES", "COMMA", "SEMICOLON", "EQUALS","EQ", "NEQ", "LESS", "GREATER", 
		"LEQ", "GEQ", "AND", "OR","INTEGER", "IDENTIFIER", "LITERAL", "INTEGER","INSERT", "CREATE", "DELETE"
		};
	
		Parser(){}; // 
		void read_input(string input); // reads input until it sees an alpha numeric
		
		vector <Parser::Token> getToken();

private:
	 vector<Parser::Token> tokens; 
	 Token token;
	 Engine e;
		
	int current_token_index; // current place in token vector
	  
	void setToken();
	void increment(); // go through vector to get next item 
		
	bool can_execute_program(); // calls command or query functions
	bool command();  // calls all of the different command functions 
	bool query();	// calls all of the different query-like functions
		
	// Execute all of the commands depending on what is called
	Table execute_expression();
	Table atomic_expression();
	Table execute_selection();
	Table execute_projection();
	Table execute_renaming();
	void execute_exit();
	void execute_show();
	void execute_open();
	void execute_write();
	void execute_close();
	void execute_create();
	void execute_update();
        void execute_insert();
	void execute_destroy();


	// need a helper function to get all of the attributes for create function
	vector<string> attribute_list();
		
	// helper function in the Parser that allows setting up a format of entry for commands
	void expect(Token token);
	
};
#endif
