#include "Token.h"

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;



Token :: Token(Token_Symbols symbol_, string value_)
{
	symbol = symbol_;
	value = value_;
}

string Token:: getValue()
{
	return value;
}

int Token :: getPosition()
{
	return atoi(value.c_str());
}
string Token:: getName()
{
	Token_Symbols symbols = this->symbol;
	
	
	if (symbol == lparen) return "lparen";
	else if (symbol == rparen) return "rparen";
	else if (symbol == larrow) return "larrow";
	else if (symbol == plus) return "plus";
	else if (symbol == minus) return "minus";
	else if (symbol == times) return "times";
	else if (symbol == equals) return "equals";
	else if (symbol == comma) return "comma";
	else if (symbol == semicolon) return "semicolon";
	else if (symbol == eq) return "eq";
	else if (symbol == neq) return "neq";
	else if (symbol == lt) return "lt";
	else if (symbol == gt) return "gt";
	else if (symbol == leq) return "leq";
	else if (symbol == geq) return "geq";
	else if (symbol == create) return "create";
	else if (symbol == select) return "select";
	else if (symbol == project) return "project";
	else if (symbol == rename) return "rename";
	else if (symbol == open) return "open";
	else if (symbol == close) return "close";
	else if (symbol == write) return "write";
	else if (symbol == show) return "show";
	else if (symbol == exit) return "exit";
	else if (symbol == set) return "set";
	else if (symbol == where) return "where";
	else if (symbol == update) return "update";
	else if (symbol == pkey) return "pkey";
	else if (symbol == insert) return "insert";
	else if (symbol == delete_) return "delete";
	else if (symbol == rparen) return "rparen";
	else if (symbol == varchar) return "varchar";
	else if (symbol == rparen) return "identifier";
	else return "[Error]: Unrecognized Token Symbol.";	
	
}
