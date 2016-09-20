
#ifndef ENGINE_H
#define ENGINE_H

#include "Attribute.h"
#include "Table.h"

using namespace std;


class Engine{
 
 public:
 	
	//void open();
	//void close();
	//void write();

 	vector <Table*> all_tables; // database will contain multiple tables - Human, Superhero, Group
	void open(string table_name);
	void close(string table_name);
	void write(Table* table);

	void exit();
	void show(string table_name);
	void create(string, vector<Attribute>, vector<string>);
	void insert(string name, vector<Attribute> att);
	void update();
	void destroy();	//because delete is a keyword
	void drop(string table_name); // deletes table from "all tables" vector in database
	Table getTable(string table_name); // have not implemented, but think we might need it to get functions to work properly
};

#endif
