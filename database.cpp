

#ifndef _databasecpp_
#define _databasecpp_

#include "database.h"

//Database cpp
<<<<<<< HEAD
void Engine::open(){
	//TODO
}
void Engine::close(){
	//TODO
}
void Engine::write(){
=======
void Database::open(string table_name){
	//TODO
}
void Database::close(string table_name){
	//TODO
}
void Database::write(Table table){
>>>>>>> f659fbb3ee6b8babdbb19d5a36bfebcf55d01a73
	//TODO
}
void Engine::exit(){
	//TODO
}
<<<<<<< HEAD
void Engine::show(){
=======
void Database::show(string table_name){
>>>>>>> f659fbb3ee6b8babdbb19d5a36bfebcf55d01a73
	//TODO
}

void Engine::create(string name, vector<Attribute> att, vector<string> key){

	Table* table = new Table(name,att,key);
	tables.push_back(table);
}


void Engine::update(){
	//TODO
}
void Engine::insert(string name, vector<Attribute> att){
	//TODO
}
void Engine::destroy(){
	//TODO
}
void Database :: drop(string table_name){
	for(int i = 0; i < all_tables.size(); i++){
		if (all_tables[i].name == table_name){
			all_tables.erase(all_tables.begin() + i);
		}
	}
}
//TODO part 2: atomic expressions
// selection-projection-renaming-union-difference-product-natural-join
#endif
