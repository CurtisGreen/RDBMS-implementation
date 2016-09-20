

#ifndef _databasecpp_
#define _databasecpp_

#include "database.h"

//Database cpp

void Engine::open(string table_name){
	//TODO
}
void Engine::close(string table_name){
	//TODO
}
void Engine::write(Table table){

	//TODO
}
void Engine::exit(){
	//TODO
}

void Engine::show(string table_name){

	//TODO
}

void Engine::create(string name, vector<Attribute> att, vector<string> key){

	Table* table = new Table(name,att,key);
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
	//Table table;	//For right now just create one, will change later TODO
/*
	for (int i = 0; i < table.attributes.size(); i++){	//Loop through comparing header & data b/c data might not be in the right order
		for (int k = 0; k < att.size(); k++){
			if (att[i].getName() == table.attributes[k].getName() && att[i].type == table.attributes[k].getType()){
				table.attributes[k].push_back(att[i].data[0]);
			}
		}
	}
	*/
}
void Engine::destroy(){
	//TODO
}
void Engine::drop(string table_name){
	/*
	for(int i = 0; i < all_tables.size(); i++){
		if (all_tables[i].name == table_name){
			all_tables.erase(all_tables.begin() + i);
		}
	}
	*/
}
//TODO part 2: atomic expressions
// selection-projection-renaming-union-difference-product-natural-join
#endif
