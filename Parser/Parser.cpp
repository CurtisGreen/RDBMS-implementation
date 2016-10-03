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
    e.show(rel_name);
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
        if (input_str == "SELECT"){
            execute_selection();
        }
        else if(input_str == "PROJECT"){
            execute_projection();
        }
        else if(input_str == "RENAME"){
            execute_update();
        }
        else{	//Must be a relation name
            remove_spaces();
            switch(t.value){
                case '*': execute_product(); break;
                case '-': execute_difference(); break;
                case '+': execute_union(); break;
                case 'J': execute_join(); break;	//needs to iterate through the rest of the word
                default: {  //Relation name
                    while (t.value != ';' && t.value != '`') {
                        t = ts.get();
                        //cout << "value = " << t.value << endl;
                        input_str = "";
                        switch(t.kind){
                            case '0': input_str = ts.out_buff(); break;
                            default: ts.putback(t); break;
                        }
                    }
                    return e.findTable(input_str);
                } 

               
            }
        }
    }
}
void Parser :: execute_insert()
{
    //insert-cmd ::= INSERT INTO relation-name VALUES FROM ( literal { , literal } )
    //	| INSERT INTO relation-name VALUES FROM RELATION expr
    vector<string> data;
    string rel_name;
    string input_str = "";
    remove_spaces();
    bool correct = true;
    while (input_str != "INTO") {	//checks for TABLE
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected INTO in Insert" << endl;
            correct = false;
        }
    }
    remove_spaces();
    Token t = ('a');
    while (t.value != ' ' && correct) {	//checks for relation-name
        input_str = "";
        t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ' '){
            rel_name = input_str;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected relation-name in Insert" << endl;
            correct = false;
        }
    }
    remove_spaces();
    while (input_str != "VALUES" && correct) {	//checks for TABLE
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected VALUES in Insert" << endl;
            correct = false;
        }
    }
    remove_spaces();
    while (input_str != "FROM" && correct) {	//checks for TABLE
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected FROM in Insert" << endl;
            correct = false;
        }
    }
    remove_spaces();
    t = ts.get();
    switch(t.kind){
        case '0': input_str = ts.out_buff(); break;
        default: ts.putback(t); break;
    }
    switch(t.kind){
        case 'A': case '8': {	//List of literals
            ts.out_buff();	//remove parentheses
            remove_spaces();
            while (t.value != ')' && correct) {	//pass back data
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
                if (t.value == ';' || t.value == '`'){
                    cout << "Error: [Parser]: Expected literals in Insert" << endl;
                    correct = false;
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
            while (input_str != "RELATION" && correct) {	//checks for TABLE
                Token t = ts.get();
                switch(t.kind){
                    case '0': input_str = ts.out_buff(); break;
                    default: ts.putback(t); break;
                }
                if (t.value == ';' || t.value == '`'){
                    cout << "Error: [Parser]: Expected RELATION in Insert" << endl;
                    correct = false;
                }
            }
            remove_spaces();
            Table table = execute_expression();
            e.insertIntoTable(rel_name, table);
            e.show(rel_name);
            break;
        }
    }
}
void Parser :: execute_update()
{
    //update-cmd ::= UPDATE relation-name SET attribute-name = literal { , attribute-name = literal } WHERE condition
    
    //this is not working after SET.
    //and this is my test grammar --UPDATE animals SET “name”=“Kim” WHERE “Joe”;--
    string att_name;
    string rel_name;
    string data;
    string newVal;
    string input_str = "";
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
    while (input_str != "SET") {	//checks for TABLE
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        //TODO: add error if not VALUES
        
    }
    /*---------correct untill here--------*/
    t = ts.get();
    switch(t.kind){
        case 'A': case '8':case'a':  {	//TODO List of literals
            remove_spaces();
            while (t.value != '=') {
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
                if (t.value == '=' ){	//Get attribute name
                    att_name=input_str;
                    
                    remove_spaces();
                }
            }
            
            remove_spaces();
            while (t.value != ' ') {
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
                if (t.value == ' '){	//Get new value.
                    newVal=input_str;
                    
                }
            }
            
            remove_spaces();
            while (input_str != "WHERE") {
                Token t = ts.get();
                switch(t.kind){
                    case '0': input_str = ts.out_buff(); break;
                    default: ts.putback(t); break;
                }
                //TODO: add error check
            }
            
            remove_spaces();
            while (t.value != ';' && t.value != '`') {
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
                if (t.value == ';'){	//Get previous data
                    data=input_str;
                    
                }
            }
            
            //e.update(rel_name,att_name,data,newVal);
            e.show(rel_name);
            break;
        }
        default: {	//Expression
            Table table = execute_expression();
        }
    }
}
void Parser :: execute_create()
{
    //create-cmd ::= CREATE TABLE relation-name ( typed-attribute-list ) PRIMARY KEY ( attribute-list )
    vector<Attribute> type_att_list;
    string rel_name;
    string input_str = "";
    vector<string> keys;
    remove_spaces();
    bool correct = true;
    while (input_str != "TABLE" && correct) {	//checks for TABLE
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected TABLE in Create" << endl;
            correct = false;
        }
    }
    remove_spaces();
    Token t = ('a');
    while (t.value != ' ' && correct) {	//checks for relation-name
        input_str = "";
        t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ' '){
            rel_name = input_str;
            cout<<"TESTING: "<<rel_name<<endl;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected relation-name in Create" << endl;
            correct = false;
        }
    }
    while (t.value != '(' && correct){		//go into parentheses
        t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected open-parentheses in Create" << endl;
            correct = false;
        }
    }
    remove_spaces();
    int paren_count = 1;
    while (paren_count != 0 && correct) {	//checks for attribute-list and types
        input_str = "";
        t = ts.get();
        if (t.value == '('){
            paren_count++;
            //cout<<"PA:"<<t.value<<endl;
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
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected closing-parentheses in Create" << endl;
            correct = false;
        }
    }
    remove_spaces();
    input_str = "";
    while (input_str != "PRIMARY" && correct) {	//check for PRIMARY
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected PRIMARY in Create" << endl;
            correct = false;
        }
    }
    remove_spaces();
    while (input_str != "KEY" && correct) {	//check for KEY
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected KEY in Create" << endl;
            correct = false;
        }
    }
    //Call space removing functions
    remove_spaces();
    ts.out_buff();	//remove parentheses
    remove_spaces();
    t = ('a');
    while (t.value != ')' && correct) {	//pass back keys
        input_str = "";
        t = ts.get();
        //cout << "t= " << t.value << endl;
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ','){	//Get attribute name
            keys.push_back(input_str);
            remove_spaces();
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected closing-parentheses in Create" << endl;
            correct = false;
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
    //it is working and deleted by row but have to be deleted by some conditons.
    //delete-cmd ::= DELETE FROM relation-name WHERE condition
    string rel_name;
    string att_name;
    string key;
    string input_str = "";
    remove_spaces();
    while (input_str != "FROM") {
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
    while (input_str != "WHERE") {
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        //TODO: add error if not table
    }
    t = ts.get();
    switch(t.kind){
        case 'A': case '8':case'a':  {	//TODO List of literals
            remove_spaces();
            while (t.value != '=') {
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
                if (t.value == '=' ){	//Get attribute name for new setting
                    att_name=input_str;
                    remove_spaces();
                }
            }
            
            remove_spaces();
            while (t.value != ';') {
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
                if (t.value == ';'){	//Get new value.
                    key=input_str;
                    
                }
            }
            
            e.destroy(rel_name,att_name,key);
            e.show(rel_name);
            break;
        }
        default: {	//Expression
            Table table = execute_expression();
        }
    }
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
    string table_name;
    string input_str = "";
    Token t  = ('a');
    remove_spaces();
    while (t.value != ' ') {	//checks atomic expression
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
    e.show(table_name);
    
}
void Parser :: execute_exit()
{
    //TODO:
    //exit-cmd ::== EXIT
    e.exit_();
    
}
void Parser :: execute_drop()
{

    string rel_name;
    string input_str = "";
  
    remove_spaces();
    Token t('a');
    while (input_str != "TABLE") {   //checks for TABLE
        Token t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected TABLE in DROP" << endl;
            
        }
    }

    remove_spaces();
    while (t.value != ' ') {    //check for relation name
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

    e.drop(rel_name);


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
Table Parser ::selection_helper(string table_name){
    bool first = true;
    Token t = ts.get();
    string att_name = "";
    string input_str = "";
    string op = "";
    string condition = "";
    Table table;
    Table temp;
    string conjunction = "";
    if (t.value == '('){
        return selection_helper(table_name);
    }
    else{
    while (t.value != '\n'){
        while(t.value != ' '){  //Get relation name
            if(first){
                first = false;
            }
            else{
                t = ts.get();
            }
            switch(t.kind){
                case '0': input_str = ts.out_buff(); break;
                default: ts.putback(t); break;
            }
            att_name = input_str;
        }
        remove_spaces();
        while(t.value != ' '){  //Get operator
            t = ts.get();
            switch(t.value){
                case ' ': input_str = ts.out_buff(); break;
                default: ts.putback(t); break;
            }
            op = input_str;
        }
        remove_spaces();
        while(t.value != ' ' && t.value != ')'){  //Get condition
            t = ts.get();
            switch(t.value){
                case ' ': input_str = ts.out_buff(); break;
                default: ts.putback(t); break;
            }
            condition = input_str;
        }
        remove_spaces();
        t = ts.get();
        if (t.value == ')'){
            return e.selection(table_name, att_name, op, condition);
        }
        else{   //Has conjunction
            table = e.selection(table_name, att_name, op, condition);
            while (t.value != ' '){
                switch(t.value){
                    case ' ': input_str = ts.out_buff(); break;
                    default: ts.putback(t); break;
                }
                conjunction = input_str;
            }
            temp = selection_helper(table_name);
            if (conjunction == "&&"){
                return e.difference(table, temp);
            }
            else if (conjunction == "||"){
                return e.set_union(table, temp);
            }
        }
    }
}
}
Table Parser :: execute_selection()
{
    //selection ::= select ( condition ) atomic-expr
    remove_spaces();
    int paren_count = 1;
    string conditional = "";
    string expression = "";
    bool correct = true;
    Token t = ('a');
    while (paren_count != 0 && correct) {   //checks for attribute-list and types
        t = ts.get();
        if (t.value == '('){
            paren_count++;
            //cout<<"PA:"<<t.value<<endl;
        }
        else if(t.value == ')'){
            paren_count--;
        }
        if (paren_count == 0){
            conditional = ts.out_buff();
        }
        else{
            ts.putback(t);
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected closing-parentheses in Select" << endl;
            correct = false;
        }
    }
    remove_spaces();
    while (t.value != ';' && correct){
        t = ts.get();
        if(t.value == ';'){
            expression = ts.out_buff();
        }
        else{
            ts.putback(t);
        }
        if (t.value == ';' || t.value == '`'){
            cout << "Error: [Parser]: Expected semicolon in Select" << endl;
            correct = false;
        }
    }
    for (int i = expression.size()-1; i >= 0; i--){
        cin.putback(expression[i]);
    }
    Table table = execute_expression();
    for (int i = conditional.size()-1; i >= 0; i--){
        cin.putback(conditional[i]);
    }
    remove_spaces();

    Table testerino = selection_helper(table.name);
    e.all_tables.push_back(testerino);
    e.show (testerino.name);
    return testerino;

}

Table Parser :: execute_projection()
{
    //TODO
    //projection ::= project ( attribute-list ) atomic-expr
	vector<string> data;
	string rel_name;
	string atomic_ex;
	string input_str = "";
	remove_spaces();
	while (input_str != "project") {//CHECKS FOR THE EXPRESSION TYPE
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		
	}
	atomic_ex = input_str;///Expression type
	//cout<<atomic_ex<<endl;

	Token t('a');
	while (t.value != '('){ //DOES NOT LOOK AT THE OPEN PARANTHIS
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
	}

	switch(t.kind){
		case '0':  {	
			remove_spaces();
			while (t.value != ')'){//DOES NOT LOOK AT the CLOSING PARENTHESIS
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
				if (t.value == ',' || t.value == ')' ){	//Get attribute name
					data.push_back(input_str); 
					remove_spaces();
				}
			}
			//for (int i = 0; i < data.size(); i++){
				//cout << data[i] << endl;
			//}
			break;
		}	
	}

	remove_spaces();
	while (t.value != ';' && t.value != '`') {	//CHECKS FOR RELATION-NAME
		input_str = "";
		t = ts.get();

		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
			rel_name = input_str;
	}


	    ///TESTING PUPOSES CALLING PROJECTION FROM ENGINE and PASSING THE PARSE INPUT
		Table newTable = e.projection(data,rel_name);

		return newTable;

}


Table Parser :: execute_renaming()
{
    //TODO
    //renaming ::= rename ( attribute-list ) atomic-expr
	vector<string> data;
	string rel_name;
	string atomic_ex;
	string input_str = "";
	remove_spaces();
	while (input_str != "rename") {//CHECKS FOR THE EXPRESSION TYPE
		Token t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		
	}
	atomic_ex = input_str;///Expression type
	//cout<<atomic_ex<<endl;

	Token t('a');
	while (t.value != '('){ //DOES NOT LOOK AT THE OPEN PARANTHIS
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
	}

	switch(t.kind){
		case '0':  {	
			remove_spaces();
			while (t.value != ')'){//DOES NOT LOOK AT the CLOSING PARENTHESIS
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
				if (t.value == ',' || t.value == ')' ){	//Get attribute name
					data.push_back(input_str); 
					remove_spaces();
				}
			}
			//for (int i = 0; i < data.size(); i++){FOR TESTING PURPOSES
				//cout << data[i] << endl;
			//}
			break;
		}	
	}

	remove_spaces();
	while (t.value != ';' && t.value != '`') {	//CHECKS FOR RELATION-NAME
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
			rel_name = input_str;
	}

    ///TESTING PUPOSES CALLING PROJECTION FROM ENGINE and PASSING THE PARSE INPUT
	Table get_table = e.getTable(rel_name);
    e.renaming(data,get_table);
    e.all_tables.push_back(get_table);
	//e.show(get_table.getName());

	return get_table;

}
Table Parser :: atomic_expression()
{
    //TODO
    //atomic-expr ::= relation-name | ( expr )
}
Table Parser :: execute_product()
{
	//TODO :: CROSS PRODUCT NEEDS WORK 
	// product ::= atomic-expr * atomic-expr
	string rel_name_1;
	string rel_name_2;
	string input_str = "";
	Token t  = ('a');

	remove_spaces();
	while (t.value != ' ') {	//checks for relation name 
		input_str = "";
		t = ts.get();
		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
		if (t.value == ' '){
			rel_name_1 = input_str;
		}
	}
	remove_spaces();
	while (t.value != ';' && t.value != '`') {	//check for relation name 
		input_str = "";
		t = ts.get();

		switch(t.kind){
			case '0': input_str = ts.out_buff(); break;
			default: ts.putback(t); break;
		}
			rel_name_2 = input_str;
	}
		
		Table t1 = e.getTable(rel_name_1);
		Table t2 = e.getTable(rel_name_2);
		
		Table new_table = e.cross_product(t1,t2);
		//e.show(new_table.getName());
		return new_table;
	
}
Table Parser :: execute_join()
{
    // join ::= atomic-expr JOIN  atomic-expr
    string rel_name_1;
    string rel_name_2;
    string input_str = "";
    Token t  = ('a');
    
    remove_spaces();
    while (t.value != ' ') {	//checks for relation name
        input_str = "";
        t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ' '){
            rel_name_1 = input_str;
        }
    }
    remove_spaces();
    while (t.value != ';' && t.value != '`') {	//check for relation name
        input_str = "";
        t = ts.get();
        
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        rel_name_2 = input_str;
    }
    Table t1 = e.getTable(rel_name_1);
    Table t2 = e.getTable(rel_name_2);
    Table new_table = e.natural_join(t1,t2);
    e.show(new_table.getName());
    return new_table;
    
    
}
Table Parser :: execute_union()
{
    // union ::= atomic-expr + atomic-expr
    // difference ::= atomic-expr - atomic-expr
    
    string rel_name_1;
    string rel_name_2;
    string input_str = "";
    Token t  = ('a');
    
    remove_spaces();
    while (t.value != ' ') {	//check for relation name
        input_str = "";
        t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ' '){
            rel_name_1 = input_str;
        }
    }
    remove_spaces();
    while (t.value != ';' && t.value != '`') {	//checks for relation name
        input_str = "";
        t = ts.get();
        
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        rel_name_2 = input_str;
    }
    
    Table t1 = e.getTable(rel_name_1);
    Table t2 = e.getTable(rel_name_2);
    Table new_table = e.set_union(t1,t2);
    //e.show(new_table.getName());
    
    return new_table;

}

Table  Parser:: execute_difference()
{
    // difference ::= atomic-expr - atomic-expr
    string rel_name_1;
    string rel_name_2;
    string input_str = "";
    Token t  = ('a');
    
    remove_spaces();
    while (t.value != ' ') {	//Checks for relation name
        input_str = "";
        t = ts.get();
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        if (t.value == ' '){
            rel_name_1 = input_str;
        }
    }
    remove_spaces();
    while (t.value != ';' && t.value != '`') {	//checks for relation name
        input_str = "";
        t = ts.get();
        
        switch(t.kind){
            case '0': input_str = ts.out_buff(); break;
            default: ts.putback(t); break;
        }
        rel_name_2 = input_str;
    }
    
    Table t1 = e.getTable(rel_name_1);//GETS THE FIRST TABLE
    Table t2 = e.getTable(rel_name_2);//GETS THE SECOND TABLE
    Table newTable = e.difference(t1,t2);
    //e.show(newTable.getName());//FOR TESTING PURPOSES
    
    return newTable;
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
            cout << "Executing (DELETE/DESTROY) " << endl;
            execute_destroy();
        }
         else if(input_str == "DROP"){
            cout << "Executing (DROP) " << endl;
            execute_drop();
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

