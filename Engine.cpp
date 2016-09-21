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
	//TODO: need to define >> << operators
	bool table_exists; // boolean to figure out if table already exists
	
	for (int i =0; i < all_tables.size(); i++){
		if (all_tables[i]->getName() == table->getName()){
			table_exists = true;
		}
	}
	// checks if table exists in all tables vector, if not adds to tables vector
	if (table_exists != true){
		all_tables.push_back(table); 
	}
	ofstream output_file(table->getName()+ ".txt");
	cout << "Writing to file " << "\n";
	output_file << table; 
	
}
void Engine::exit(){
	//TODO
}

void Engine::show(string table_name){
	//TODO: formatting
	//check if empty
	Table* table;
	for (int i = 0; i < all_tables.size(); i++){
		if (table_name == all_tables[i]->getName()){
			table = all_tables[i];
		}
	}
	for (int i = 0; i < table->att.size(); i++){
		cout << table->getName() << '\t';
	}
	cout << endl;
	for (int k = 0; k < table->att[0].data.size(); k++){
		for (int i = 0; i < table->att.size(); i++){
			cout << table->att[i].data[k] << '\t';
		}
	}
}

/* This function creates a table and adds it to the database  */
void Engine::create(string name, vector<Attribute> att, vector<string> key){

	Table* table =  new Table(name,att,key);
	all_tables.push_back(table);
}


void Engine::update(){
	//TODO
}

void Engine::insert(string name, vector<Attribute> new_att){
	Table* table;
	for (int i = 0; i < all_tables.size(); i++){
		if (name == all_tables[i]->getName()){
			table = all_tables[i];
		}
	}

	 for (int i = 0; i < table->att.size(); i++){	//Loop through comparing header & data b/c data might not be in the right order
		 for (int k = 0; k < new_att.size(); k++){
			 if (new_att[i].getName() == table->att[k].getName() && new_att[i].type == table->att[k].getType()){
				 table->att[k].getData().push_back(new_att[i].data[0]);
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
	
	
}
//TODO part 2: atomic expressions
// selection-projection-renaming-union-difference-product-natural-join

