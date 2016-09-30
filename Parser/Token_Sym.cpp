#include "Token_Sym.h"

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;


Token_Sym :: Token_Sym(TokenSymbol symbol_, string value_)
{
	symbol = symbol_;
	value = value_;
}

string Token_Sym:: getValue()
{
	return value;
}



int Token_Sym :: getNumericConversion()
{
	return atoi(value.c_str()); 
}


string Token_Sym::getSymbolName()
{
	TokenSymbol symbol = this->symbol;

	if (symbol == DIFF) return "DIFF";
	else if (symbol == PRODUCT) return "PRODUCT";
	else if (symbol == UNION) return "UNION";
	else if (symbol == LPAREN) return "LPAREN";
	else if (symbol == RPAREN) return "RPAREN";
	else if (symbol == LARROW) return "LARROW";
	else if (symbol == EQ) return "EQ";
	else if (symbol == NEQ) return "NEQ";
	else if (symbol == LT) return "LT";
	else if (symbol == GT) return "GT";
	else if (symbol == LEQ) return "LEQ";
	else if (symbol == GEQ) return "GEQ";
	else if (symbol == OR) return "OR";
	else if (symbol == AND) return "AND";
	else if (symbol == SELECT) return "SELECT";
	else if (symbol == PROJECT) return "PROJECT";
	else if (symbol == RENAME) return "RENAME";
	else if (symbol == OPEN) return "OPEN";
	else if (symbol == CLOSE) return "CLOSE";
	else if (symbol == WRITE) return "WRITE";
	else if (symbol == PRIMARY) return "PRIMARY";
	else if (symbol == EXIT) return "EXIT";
	else if (symbol == SHOW) return "SHOW";
	else if (symbol == CREATE) return "CREATE";
	else if (symbol == TABLE) return "TABLE";
	else if (symbol == PRIMARY) return "PRIMARY";
	else if (symbol == KEY) return "KEY";
	else if (symbol == UPDATE) return "UPDATE";
	else if (symbol == SET) return "SET";
	else if (symbol == WHERE) return "WHERE";
	else if (symbol == INSERT) return "INSERT";
	else if (symbol == INTO) return "INTO";
	else if (symbol == VALUES) return "VALUES";
	else if (symbol == FROM) return "FROM";
	else if (symbol == RELATION) return "RELATION";
	else if (symbol == DELETE) return "DELETE";
	else if (symbol == VARCHAR) return "VARCHAR";
	else if (symbol == INTEGER) return "INTEGER";
	else if (symbol == LITERAL) return "LITERAL";
	else if (symbol == IDENTIFIER) return "IDENTIFIER";
	else if (symbol == SEMICOLON) return "SEMICOLON";
	else if (symbol == COMMA) return "COMMA";
	else if (symbol == EQUALSIGN) return "EQUALSIGN";
	else return "Bad Token.";
}
