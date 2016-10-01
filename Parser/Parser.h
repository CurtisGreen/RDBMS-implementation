
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
	int input();
	void initial();
	vector<Token_Sym> getTokens() {return tokens;}

private:
	vector<Token_Sym> tokens;
	Token_Sym token;
	Engine e;
	Token_stream ts;
	
	bool query(string rel_name);
	
	// All of the things that need to be executed in the Engine 
	Table execute_expression();
	Table atomic_expression();
	Table execute_selection();
	Table execute_projection();
	Table execute_renaming();
	Table execute_union();
	Table execute_difference();
	void execute_exit();
	void execute_show();
	void execute_open();
	void execute_write();
	void execute_close();
	void execute_create();
	void execute_update();
    void execute_insert();
	void execute_destroy();
	void remove_spaces();


	// need a helper function to get all of the attributes for create function
	vector<string> attribute_list();
	
	// helper function in the Parser that allows setting up a format of entry for commands
	void expect(Token_Sym::TokenSymbol symbol);
	
};
#endif
