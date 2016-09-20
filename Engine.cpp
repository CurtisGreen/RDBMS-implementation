#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Engine.h"
#include "Attribute.h"
#include "Table.h"

using namespace std;

void Engine::open(string table_name){
	//TODO
}
void Engine::close(string table_name){
	//TODO
}
void Engine::write(Table* table){
bool table_exists; // boolean to figure out if table already exists
	
	for (int i =0; i < all_tables.size(); i++){
		if (all_tables[i]->getName() == table->getName()){
			table_exists = true;
		}
	}
	// checks if table exists in all tables vector
	if (table_exists != true){
		all_tables.push_back(table); // if not, adds it to tables 
	}
	ofstream output_file(table->getName()+ ".txt");
	cout << "Writing to file " << "\n";
	output_file << table;
	// Inga: compiles, but going to check if it works later
}
void Engine::exit(){
	//TODO
}

void Engine::show(string table_name){

	//TODO
}

/* This function creates a table and adds it to the database  */
void Engine::create(string name, vector<Attribute> att, vector<string> key){

	Table* table =  new Table(name,att,key);
	all_tables.push_back(table);
}


void Engine::update(){
	//TODO
}

void Engine::insert(string name, vector<Attribute> attributes){
	Table* table;
	for (int i = 0; i < all_tables.size(); i++){
		if (name == all_tables[i]->getName()){
			table = all_tables[i];
		}
	}

	 for (int i = 0; i < table->att.size(); i++){	//Loop through comparing header & data b/c data might not be in the right order
		 for (int k = 0; k < attributes.size(); k++){
			 if (attributes[i].getName() == table->att[k].getName() && attributes[i].type == table->att[k].getType()){
				 table->att[k].getData().push_back(attributes[i].data[0]);
			 }
		 }
	 }
	
}
/* This function deletes record from a table  */
void Engine::destroy(){
	//TODO
}
/* This function deletes table from the database of tables  */
void Engine::drop(string table_name){
	
	for(int i = 0; i < all_tables.size(); i++){
		if (all_tables[i]->getName() == table_name){
		delete (all_tables[i]); // trying to delete table from vector of pointer to table?
		}
	}
	//Inga: compiles, not sure if it works yet or if we are definitely using pointers
	
}
//TODO part 2: atomic expressions
// selection-projection-renaming-union-difference-product-natural-join

