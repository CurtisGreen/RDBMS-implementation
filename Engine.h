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
	void read(string table_name);
	void write(Table table);
	void exit_();
	void show(string table_name);
	void create(string, vector<Attribute>, vector<string>);
	void insert(string name, vector<string> new_row);
	void update();
	void destroy();	//because delete is a keyword
	void drop(string table_name); // deletes table from "all tables" vector in database

	
	// atomic expressions
	// Inga: not sure what they return , but for now I think they can return a table
	Table selection(Table table);
	Table projection(vector<string> att_names, string table_name);
	Table set_union(string attribute_name , Table table1, Table table2 );
	Table natural_join(Table table1, Table table2);
	Table cross_product(Table table1, Table table2);
<<<<<<< HEAD
	Table renaming(Table table);
=======
	void renaming(string old_attr, string new_attr, string table_name);
	vector<string> createTuples(Table t);
>>>>>>> 7166c85a52b2a7f586080322e21a13ab67fe3e71
	Table difference(Table table1, Table table2);

	vector<string> rtn_stringRow(Table t);
	vector<string> rtn_Row(Table t,int index);
	

};

#endif
