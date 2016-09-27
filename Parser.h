#ifndef PARSER_H_
#define PARSER_H_

#include "Engine.h"

#include <string>
#include <vector>

using namespace std;

class Parser{
	
	public:
	
	
	// define symbols, and keywords
	
	enum Token{
		
	lparen, rparen, larrow, plus, minus, times, equals, comma, semicolon,
	eq, neq, less_than, greater_than, leq, geq, or_, and_, 
		
	create_table, select, project, rename, open, close, write, show, exit,
	set, where, update, primary_key, insert, destroy, varchar, identifier
	
	
	};
	
	
	private:

	
	
	
	
	
};




#endif