

#ifndef _databasecpp_
#define _databasecpp_

#include "database.h"

//Database cpp
void Database::open(string table_name){
	//TODO
}
void Database::close(string table_name){
	//TODO
}
void Database::write(Table table){
	//TODO
}
void Database::exit(){
	//TODO
}
void Database::show(string table_name){
	//TODO
}
void Database::create(string name, vector<Attribute> att, vector<string> key){
	//TODO
}
void Database::update(){
	//TODO
}
void Database::insert(string name, vector<Attribute> att){
	//TODO
	//Retrieve table from memory or file using 'name'
	Table table;	//For right now just create one, will change later TODO

	for (int i = 0; i < table.attributes.size(); i++){	//Loop through comparing header & data b/c data might not be in the right order
		for (int k = 0; k < att.size(); k++){
			if (att[i].name == table.attributes[k] && att[i].type == table.type[k]){
				table.attributes[k].push_back(att[i].data[0]);
			}
		}
	}
}
void Database::destroy(){
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
