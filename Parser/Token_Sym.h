#ifndef TOKEN_SYM_H
#define TOKEN_SYM_H


using namespace std;

#include <iostream>
#include <string>
#include <vector>

/* Token Symbol Class. We have s Token Stream class for the alpha, digits, and operators
and we have this symbol class to handle the SQL "Tokens"
*/
class Token_Sym
{
	public:
		enum TokenSymbol {IDENTIFIER, OPEN, CLOSE, WRITE, EXIT, SHOW,SELECT,LITERAL, PROJECT, RENAME,
						  OR,AND, UNION, DIFF, PRODUCT, CREATE, PKEY, UPDATE, INSERT, VALUES, RELATION,
						  DELETE, WHERE, VARCHAR, INTEGER,LARROW, TABLE, PRIMARY, KEY, SET, INTO,
						  FROM, SEMICOLON, LPAREN, RPAREN, COMMA, EQUALSIGN,EQ, NEQ, LT, GT, LEQ, GEQ,};
		
		Token_Sym(TokenSymbol symbol_, string value_); // Constructor : Token has a symbol and a value 
		Token_Sym() {};					// Default Constructor 
		TokenSymbol getSymbol(){return symbol;}		   // Returns the Enum Symbol
		string getValue();							   
		int getNumericConversion();	
		string getSymbolName();			   // Returns the string value of the Token_Symbol given
	private: 
		string value;
		TokenSymbol symbol;
};

#endif
