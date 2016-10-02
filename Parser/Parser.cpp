#include "Parser.h"

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;


void Parser:: remove_spaces(){	//removes spaces following up to a character
	Token t('a');
	t = ts.get();
	while(t.value == ' '){
		t = ts.get();
	}
	if(t.value != '"'){
		ts.putback(t);
	}
}
bool Parser :: query(string rel_name)
{
	//TODO
	//query ::= relation-name <- expr ;
	string input_str = "";
	Table table;
	Token t('a');
	remove_spaces();
	t = ts.get();
	if(t.value != '-'){
		cout << "Query missing <-" << endl;
	}
	else{
		table = execute_expression();
	}
	table.name = rel_name;
	e.all_tables.push_back(table);
}

Table Parser :: execute_expression()
{
	Token t('a');
	while (t.value != ';' && t.value != '`') {
		t = ts.get();
		//cout << "value = " << t.value << endl;
		string input_str = "";
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//cout << input_str << endl;
		if (input_str == "select"){
			execute_selection();
		}
		else if(input_str == "project"){
			execute_projection();
		}
		else if(input_str == "rename"){
			execute_update();
		}
		else{	//Must be a relation name
			remove_spaces();
			switch(t.value){
				case '*': cout << "product"<< endl; break;
				case '-': cout << "difference"<< endl; break;
				case '+': cout << "union"<< endl; break;
				case 'J': cout << "natural join"<< endl; break;	//needs to iterate through the rest of the word
				default: cout << "not product, diff, union, or join" << endl;

			}
		}
	}
}
void Parser :: execute_insert()
{
	//TODO
	//insert-cmd ::= INSERT INTO relation-name VALUES FROM ( literal { , literal } )
    //	| INSERT INTO relation-name VALUES FROM RELATION expr
	vector<string> data;
	string rel_name;
	string input_str = "";
	remove_spaces();
	while (input_str != "INTO") {	//checks for TABLE
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not into
	}
	remove_spaces();
	Token t = ('a');
	while (t.value != ' ') {	//checks for relation-name
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		if (t.value == ' '){
			rel_name = input_str;
		}
	}
	remove_spaces();
	while (input_str != "VALUES") {	//checks for TABLE
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not VALUES
	}
	remove_spaces();
	while (input_str != "FROM") {	//checks for TABLE
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not FROM
	}
	remove_spaces();
	t = ts.get();
	switch(t.kind){
		case '0': input_str = ts.out_buff(); break;
		default: ts.putback(t); break;
	}
	switch(t.kind){
		case 'A': case '8': {	//TODO List of literals
			ts.out_buff();	//remove parentheses
			remove_spaces();
			while (t.value != ')') {	//pass back data
				input_str = "";
				t = ts.get();
				switch(t.kind){
					case '0': input_str = ts.out_buff(); break;
					default: {
						if (t.value != '"'){
							ts.putback(t); 
						}
						break;
					}
				}
				if (t.value == ',' || t.value == ')'){	//Get attribute name
					data.push_back(input_str); 
					remove_spaces();
				}
			}
			for (int i = 0; i < data.size(); i++){
				//cout << data[i] << endl;
			}
			e.insert(rel_name, data);
			e.show(rel_name);
			break;
		}	
		default: {	//Expression
			while (input_str != "RELATION") {	//checks for TABLE
			Token t = ts.get();
			switch(t.kind){
				case '0': input_str = ts.out_buff(); break;
				default: ts.putback(t); break;
			}
			//TODO: add error if not RELATION
			}
			remove_spaces();
			Table table = execute_expression();
		}
	}
}
void Parser :: execute_update()
{
	//TODO
	//update-cmd ::= UPDATE relation-name SET attribute-name = literal { , attribute-name = literal } WHERE condition
}
void Parser :: execute_create()
{
	//create-cmd ::= CREATE TABLE relation-name ( typed-attribute-list ) PRIMARY KEY ( attribute-list )
	vector<Attribute> type_att_list;
	string rel_name;
	string input_str = "";
	vector<string> keys;
	remove_spaces();
	while (input_str != "TABLE") {	//checks for TABLE
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not table
	}
	remove_spaces();
	Token t = ('a');
	while (t.value != ' ') {	//checks for relation-name
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		if (t.value == ' '){
			rel_name = input_str;
		}
	}
	while (t.value != '('){		//go into parentheses
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
	}
	remove_spaces();
	int paren_count = 1;
	while (paren_count != 0) {	//checks for attribute-list and types
		input_str = "";
		t = ts.get();
		if (t.value == '('){
			paren_count++;
		}
		else if(t.value == ')'){
			paren_count--;
		}
		if (paren_count == 0){
			input_str = ts.out_buff();
		}
		else{
			switch(t.value){
				case ',': case ' ': input_str = ts.out_buff(); remove_spaces(); break;
				default: ts.putback(t); break;
			}
		}
		if (t.value == ' '){	//Get attribute name
			Attribute att;
			att.name = input_str;
			type_att_list.push_back(att);
			remove_spaces();
		}
		else if(t.value == ',' || (t.value == ')' && paren_count == 0)){	//Get attribute type 
			type_att_list[type_att_list.size()-1].type = input_str;
			remove_spaces();
		}
	}
	remove_spaces();
	input_str = "";
	while (input_str != "PRIMARY") {	//check for PRIMARY
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not PRIMARY
	}
	remove_spaces();
	while (input_str != "KEY") {	//check for KEY
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//TODO: add error if not KEY
	}
	//Call space removing functions
	remove_spaces();
	ts.out_buff();	//remove parentheses
	remove_spaces();
	while (t.value != ')') {	//pass back keys
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		if (t.value == ','){	//Get attribute name
			keys.push_back(input_str); 
			remove_spaces();
		}
	}
	for (int i = 0; i < type_att_list.size(); i++){
		//cout << type_att_list[i].name << type_att_list[i].type << endl;
	}
	e.create(rel_name, type_att_list, keys);
	e.show(rel_name);
}

void Parser :: execute_destroy()
{
    //compiled but I did not check this.
    //delete-cmd ::= DELETE FROM relation-name WHERE condition
    string rel_name;
    int row;
    string input_str = "";
    while (input_str != "FROM") {
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        //TODO: add error if not table
    }
    Token t = ts.get();
    while (t.value != ';') {
        input_str = "";
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        t = ts.get();
        if (t.value == ' '){
            rel_name = input_str;
        }
    }
    while (input_str != "WHERE") {
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        //TODO: add error if not table
    }
    
    while (t.value != ';') {
        input_str = "";
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        t = ts.get();
        if (t.value == ' '){
            row = atoi(input_str.c_str());
        }
    }
    
    e.destroy(rel_name,row);
    
}
void Parser :: execute_open()
{

	//TODO : Not sure it works- need to be tested with file written 
	//open-cmd ::== OPEN relation-name
	string file_name;
	string input_str = "";
	Token t = ts.get();
	while (t.value != ';') { // check for relation name 
        input_str = "";
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        t = ts.get();
        if (t.value == ' '){
            file_name = input_str;
        }
    }
	ifstream input_file;
	input_file.open(file_name + ".db");
	if(!input_file.is_open()) // checks if able to open file 
	{
		throw runtime_error("Error: [Parser]: Failed to Open File");
	}
	string new_line;
	getline(input_file, new_line);
	if(input_str == new_line)
	{
		throw runtime_error("Error :[Parser]: Table is already open");
	}
	
	
	
}
void Parser :: execute_close()
{
	//TODO:
	//close-cmd ::== CLOSE relation-name
	string table_name;
	string input_str = "";
	remove_spaces();
	Token t = ('a');
	while (t.value != ';') {	//checks for relation-name
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		if (t.value == ' '){
			table_name = input_str;
		}
	}
	e.close(table_name);
	
	
}

void Parser :: execute_show()
{
	//TODO: Finish it 
	//show-cmd ::== SHOW atomic-expr
	
	Table t = atomic_expression();
	string table_name = t.getName();
	e.show(table_name);
	
}
void Parser :: execute_exit()
{
	//TODO:
	//exit-cmd ::== EXIT 
	e.exit_();

}
void Parser :: execute_write()
{
	//TODO : 
	//write-cmd ::== WRITE relation-name
	string table_name;
	string input_str = "";
	remove_spaces();
	Token t = ('a');
	while (t.value != ';') {	//checks for relation-name
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		if (t.value == ' '){
			table_name = input_str;
		}
	}
	Table table = e.getTable(table_name);
	e.write(table);
	
}
Table Parser :: execute_selection()
{
	//TODO
	//selection ::= select ( condition ) atomic-expr
}
Table Parser :: execute_projection()
{
	//TODO
	//projection ::= project ( attribute-list ) atomic-expr
}
Table Parser :: execute_renaming()
{
	//TODO
	//renaming ::= rename ( attribute-list ) atomic-expr
}
Table Parser :: atomic_expression()
{
	//TODO
	//atomic-expr ::= relation-name | ( expr )
}
Table Parser :: execute_union()
{
	//TODO
	// union ::= atomic-expr + atomic-expr
}
Table  Parser:: execute_difference()
{
	//TODO
	// difference ::= atomic-expr - atomic-expr
}
vector <string> Parser :: attribute_list()
{
	//TODO
	//attribute-list ::= attribute-name { , attribute-name }
}

void Parser :: initial(){
	Token t('a');
	while (t.value != ';' && t.value != '`' && t.value != '\n') {
		//Check input_str against commands, if not a command then keep that value stored and call expression. Expression should retrun a table and you will rename that table to be input_str
		//Make sure to check to make sure input_str != ""	
		t = ts.get();
		//cout << "value = " << t.value << endl;
		string input_str = "";
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		//cout << input_str << endl;
		if (input_str == "CREATE"){
			cout << "Executing (CREATE)" << endl;
			execute_create();
		}
		else if(input_str == "INSERT"){
			cout << "Executing (INSERT)" << endl;
			execute_insert();
		}
		else if(input_str == "UPDATE"){
			cout << "Executing (UPDATE)" << endl;
			execute_update();
		}
		else if(input_str == "OPEN"){
			cout << "Executing (OPEN)" << endl;
			execute_open();
		}
		else if(input_str == "CLOSE"){
			cout << "Executing (CLOSE)" << endl;
			execute_close();
		}
		else if(input_str == "WRITE"){
			cout << "Executing (WRITE)" << endl;
			execute_write();
		}
		else if(input_str == "EXIT"){
			cout << "Executing (EXIT)" << endl;
			execute_exit();
		}
		else if(input_str == "SHOW"){
			cout << "Executing (SHOW)" << endl;
			execute_show();
		}
		else if(input_str == "DELETE"){
			cout << "Executing (DELETE/DESTROy) " << endl;
			execute_destroy();
		}
		else if (input_str != "" && t.value == ' ' && t.value != '\n' && t.value != '`'){	//Must be a query
			query(input_str);
		}
	}
}
int Parser :: input(){
	try {
		Token t('a');
		while (t.value != '`') {
			t = ts.get();
			if (t.value == ';' || t.value == '\n')
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
}

