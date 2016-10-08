#ifndef MARVEL_H
#define MARVEL_H

#include "Parser.h"


using namespace std;

class Marvel
{

public: 
	Marvel(){};
	Marvel(Parser p_ ){p = p_;}
	Parser p;
	void Menu();
	void update_info();
	void rename();
	void find_character();
	void create_character();
	void delete_character();
	void show_characters();
	void show_attribute();
	void quit_app();
	
	//helper funcitons
	void helper_create_character();
	string projection_rename_helper(string table_name, string function_name,string list);
};
#endif
