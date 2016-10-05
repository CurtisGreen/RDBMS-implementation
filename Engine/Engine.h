#ifndef ENGINE_H
#define ENGINE_H

#include "Attribute.h"
#include "Table.h"

using namespace std;


class Engine{
 
 public:

	// Holds all tables in the database
 	vector <Table> all_tables; 
	Table get_table(string table_name); // returns a table from the database vector 
	
	
	//-----Insert Functions for Table-----//
	void insert_into_table(string table_name, Table t);
	
	// Database Commands 
	void open(string table_name);
	void close(string table_name);
	void read(string table_name);
	void write(Table table);
	void exit_();
	void show(string table_name);
	Table create(string, vector<Attribute>, vector<string>);
	Table insert(string name, vector<string> new_row);
	Table update(string table_name, vector<string> att_name_1, vector<string> newVal,string att_name_2,string key);
    	Table destroy(string table_name,string att, string key); //because delete is a keyword
	void drop(string table_name); // deletes table from "all tables" vector in database

	// Atomic expressions
	Table selection(string table_name, string att_name, string op, string condition);
	Table projection(vector<string> att_names, string table_name);
	Table set_union(Table table1, Table table2 );
	Table difference(Table table1, Table table2);
	Table natural_join(Table table1, Table table2);

	Table cross_product(Table table1, Table table2);
	
	
	void renaming(vector<string> att_name, Table& table_name);

	
	// Helper functions
	vector<string> createTuples(Table t);
	vector<string> rtn_Row(Table t,int index);
	Table make_table(Table table,string name, vector<vector<string>> difference);
	bool verify_Tables(Table table1, Table table2);
};

#endif
