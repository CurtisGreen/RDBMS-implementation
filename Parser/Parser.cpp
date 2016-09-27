#include "Parser.h"
#include "Engine.h"
#include "Token.h"

using namespace std;


Parser:: Parser(vector<Token> tokens_, Engine* e_)
{
	tokens = tokens_;
	e = e_;
}

bool Parser :: command()
{
	//TODO:
}

bool Parser :: query()
{
	//TODO:
}

Table Parser :: atomic_expression()
{
	//TODO:
}

void Parser :: expect(Token:: Token_Symbols symbol)
{
	//TODO:
}