#ifndef PARSER_H_
#define PARSER_H_

#include "Engine.h"
#include "Token.h"
#include "Table.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>


using namespace std;

class Parser{
	
public:
	Parser();
	Parser(vector<Token> tokens_, Engine* e_);
	
private:
	vector<Token> tokens;
	Engine* e;
	
	
	bool command(); // finds out if input is a command
	bool query(); // finds out if the input is a query
	Table atomic_expression(); // figures out if  atomic expression (UNION-JOIN-DIFFERENCE-PRODUCT)
	
	
	
	void expect(Token:: Token_Symbols symbol); // tells what to expect when executing inout
	
	
	
};




#endif