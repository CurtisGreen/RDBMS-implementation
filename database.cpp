

#ifndef _databasecpp_
#define _databasecpp_

#include "database.h"

//Database cpp
void Engine::open(){
	//TODO
}
void Engine::close(){
	//TODO
}
void Engine::write(){
	//TODO
}
void Engine::exit(){
	//TODO
}
void Engine::show(){
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

//TODO part 2: atomic expressions

#endif