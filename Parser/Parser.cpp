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
	else if(isdigit(value[0]))			
		return INTEGER;
	else if (isalpha(value[0]))
		return IDENTIFIER;
	
}

/*
void Parser :: initial(){
	while (true) {
		Token t = ts.get();
		string input_str = "";
		switch(t.kind){
			case '0': input_str = out_buff(); break;
			default: ts.putback(t); break;
		}
		//Check input_str against commands, if not a command then keep that value stored and call expression. Expression should retrun a table and you will rename that table to be input_str
		//Make sure to check to make sure input_str != ""
	}
}

void Parser :: input(Token_stream ts){
	try {
		Table table;
		while (true) {
			Token t = ts.get();
			if (t.value == ';')
				cout << "Finished line" << endl;	
			else
				ts.putback(t);
			initial();
		}
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		return 1;
	}
	catch(...) {
		cerr << "exception\n";
		return 2;
	}
}*/
