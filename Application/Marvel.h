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
	string cross_product();
	string set_union(); 
	string find_character();
	string create_character();
	string delete_character();
	string show_characters();
	string show_attribute(); 
	void quit_app();
	
	//helper funcitons
	string helper_create_character();
	string projection_rename_helper(string table_name, string function_name,string list);
};
#endif
