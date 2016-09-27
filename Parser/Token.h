#ifndef TOKEN_H
#define TOKEN_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class Token
{
	public:
		enum Token_Symbols{ lparen, rparen, larrow, plus, minus, times, equals, comma, semicolon,
							eq, neq, lt, gt, leq, geq,create, select, project, rename, open, close, 
							write, show, exit,set, where, update, pkey, insert, delete_, varchar, identifier };

							
							
							
	

		Token();
		Token (Token_Symbols symbol_, string value_); // Token is composed of symbol and string values
		
		Token_Symbols getSymbol(){return symbol;} // returns the symbol in enum class
		string getValue();	 // returns string of token symbol	 
		int getPosition();	// associates a number with token
		string getName();	// takes type and returns string
		
		
	private:
	string value;
	Token_Symbols symbol;

};

#endif