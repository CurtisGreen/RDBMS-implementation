#include "Parser.h"
#include "Engine.h"

using namespace std;

void Parser:: read_input( string input)
{
	//TODO
}
void  Parser:: add_token(Token token, string value)
{
	tokens.push_back(token);
	buffer.push_back(value);
}
Parser:: Token Parser:: get_token(string value)
{
	if(value == "SELECT")
		return SELECT;
	else if(value == "PROJECT")
		return PROJECT;
	else if(value== "RENAME")
		return RENAME;
	else if(value == "OPEN")
		return OPEN;
	else if(value== "CLOSE")
		return CLOSE;
	else if(value == "WRITE")
		return WRITE;
	else if(value == "EXIT")
		return EXIT;
	else if(value == "SHOW")
		return SHOW;
	else if(value == "UPDATE")
		return UPDATE;
	else if(value == "SET")
		return SET;
	else if(value == "WHERE")
		return WHERE;
	else if (value == "CREATE TABLE")
		return CREATE_TABLE;
	else if (value == "PRIMARY KEY")
		return PRIMARY_KEY;
	else if (value == "INSERT INTO")
		return INSERT_INTO;
	else if (value == "DELETE FROM")
		return DELETE_FROM;
	else if(value == "VARCHAR")
		return VARCHAR;
	else if(value == "INTEGER")
		return INTEGER_SYM;
	else if(isdigit(value[0]))			///to_string(stoi(s)) == s
		return INTEGER;
	else if(isalpha(value[0]))
		return IDENTIFIER;
	else
		return "Error Invalid Token";	
	
}
