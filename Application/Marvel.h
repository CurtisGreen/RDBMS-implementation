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
	void initialize_tables(); // may use this or may just create all of the tables in the input file
	void update_info();
	void find_character();
	void create_character();
	void delete_character();
	void show_characters();
	void quit_app;
	
	//helper funcitons
	void helper_create_character();
};
#endif
