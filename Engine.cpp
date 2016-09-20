#include <string>
#include <vector>
#include <iostream>

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
void Engine::write(Table table){

	bool table_exists; // boolean to figure out if table already exists
	for (int i =0; i < all_tables.size(); i++){
		if (all_tables[i]->getName() == table->getName()){
			all_tables[i] = table;
			table_exists = true;
		}
	}
	if (table_exists != true){ // checks if table exists in all tables vector 
		all_tables.push_back(table); // if not, adds it to tables 
	}
	write(table);
}
void Engine::exit(){
	//TODO
}

void Engine::show(string table_name){

	//TODO
}

void Engine::create(string name, vector<Attribute> att, vector<string> key){

	Table* table =  new Table(name,att,key);
	all_tables.push_back(table);
}


void Engine::update(){
	//TODO
}

///----Jose---I commented this funciton because it has a few erros. name is priviate.
///  I think type[] is used wrong 
void Engine::insert(string name, vector<Attribute> att){
	//TODO
	//Retrieve table from memory or file using 'name'
	// Table table;	//For right now just create one, will change later TODO

	// for (int i = 0; i < table.attributes.size(); i++){	//Loop through comparing header & data b/c data might not be in the right order
		// for (int k = 0; k < att.size(); k++){
			// if (att[i].getName() == table.attributes[k].getName() && att[i].type == table.attributes[k].getType()){
				// table.attributes[k].push_back(att[i].data[0]);
			// }
		// }
	// }
	
}
void Engine::destroy(){
	//TODO
}
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

