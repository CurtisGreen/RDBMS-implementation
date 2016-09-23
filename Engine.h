#ifndef ENGINE_H
#define ENGINE_H

#include "Attribute.h"
#include "Table.h"

using namespace std;


class Engine{
 
 public:


 	vector <Table> all_tables; // database will contain multiple tables - Human, Superhero, Group
	

	//commands
	void open(string table_name);
	void close(string table_name);
	void write(Table table);
	void exit_();
	void show(string table_name);
	void create(string, vector<Attribute>, vector<string>);
	void insert(string name, vector<string> new_row);
	void update();
	void destroy();	//because delete is a keyword
	void drop(string table_name); // deletes table from "all tables" vector in database
	Table getTable(string table_name); // have not implemented, but think we might need it to get functions to work properly
	
	// atomic expressions
	// Inga: not sure what they return , but for now I think they can return a table
	Table selection(Table table);
	Table projection(Table table);
	Table set_union(string attribute_name , Table table1, Table table2 );
	Table natural_join(Table table1, Table table2);
	Table cross_product(Table table1, Table table2);
	Table renaming(Table table);
	Table difference(Table table1, Table table2);

	vector<string> rtn_stringRow(Table t);
	vector<string> rtn_Row(Table t,int index);
	

};

#endif
