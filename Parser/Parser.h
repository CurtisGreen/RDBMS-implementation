
#ifndef PARSER_H_
#define PARSER_H_

#include "Engine.h"
#include "Token_stream.h"
#include "Token_Sym.h"

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <stdexcept>

using namespace std;

class Parser{

public: 
	
	Parser(){}; 
	void read_input(string input); // reads input until it sees an alpha numeric
	void input(Token_stream ts);
	void initial();
	vector<Token_Sym> getTokens() {return tokens;}

private:
	vector<Token_Sym> tokens;
	Token_Sym token;
	Engine e;
	
	int current_token_index; // current place in token vector
	void setToken();
	bool can_execute_program(); // calls command or query functions
	bool command();  // calls all of the different command functions 
	bool query();	// calls all of the different query-like functions

	
	
	/* All of the things that need to be executed in the Engine*/ 
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
	void expect(Token_Sym::TokenSymbol symbol);
	
};
#endif
