#ifndef MARVEL_H
#define MARVEL_H


using namespace std;
#include <iostream>

class Marvel
{

public: 
	Marvel(){};
	//void Menu();
	string update_info();
	string rename();
	string find_character();
	string create_character();///DONE
	string delete_character();///DONE
	string show_characters();
	string show_attribute();
	void quit_app();
	
	//helper funcitons
	string helper_create_character();
	string projection_rename_helper(string table_name, string function_name,string list);
};
#endif
