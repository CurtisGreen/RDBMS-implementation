#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

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
	//TODO: need to define >> << operators
	bool table_exists; // boolean to figure out if table already exists
	
	for (int i =0; i < all_tables.size(); i++){
		if (all_tables[i].getName() == table.getName()){
			table_exists = true;
		}
	}
	// checks if table exists in all tables vector, if not adds to tables vector
	if (table_exists != true){
		all_tables.push_back(table); 
	}
	ofstream output_file(table.getName()+ ".txt");
	cout << "Writing to file " << "\n";
	//output_file << table; 
	
}

void Engine::exit_(){
	cerr << "Exiting RDBMS now" << "\n";
	exit(0);
}

void Engine::show(string table_name){
	//TODO: formatting
	//TODO:check if empty
	Table table;
	for (int i = 0; i < all_tables.size(); i++){
		if (table_name == all_tables[i].getName()){
			table = all_tables[i];
		}
	}
	cout << table.getName() <<endl;
	for (int k = 0; k < table.att[0].data.size(); k++){
		for (int i = 0; i < table.att.size(); i++){
			cout << table.att[i].data[k] << '\t';
		}
	}
}

/* This function creates a table and adds it to the database  */
void Engine::create(string name, vector<Attribute> att, vector<string> key){

	Table table(name,att,key);

	all_tables.push_back(table);  
}


void Engine::update(){
	//TODO
}

void Engine::insert(string name, vector<Attribute> new_att){
	Table table;
	for (int i = 0; i < all_tables.size(); i++){
		if (name == all_tables[i].getName()){
			table = all_tables[i];
		}
	}

	 for (int i = 0; i < table.att.size(); i++){	//Loop through comparing header & data b/c data might not be in the right order
		 for (int k = 0; k < new_att.size(); k++){
			 if (new_att[i].getName() == table.att[k].getName() && new_att[i].type == table.att[k].getType()){
				 table.att[k].getData().push_back(new_att[i].data[0]);
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
		if (all_tables[i].getName() == table_name){
		all_tables.erase(all_tables.begin()+i); 
		}
	}
	
	
}


//TODO part 2: atomic expressions
// selection-projection-renaming-union-difference-product-natural-join

/*This function identifies a set of tuples which is part of relation and then extracts the tuples.  
The operation selects the tuples that satisfy a given predicate or condition. 
It will involve logical conditions as defined in the grammar. 
*/

/*
Table Engine :: selection(Table table)
{
	//TODO

}

/* This function selects a subset of the attributes in a relation. */

Table Engine :: projection(Table table)
{
	//TODO
}

/* The function sets a union between two attributes that appear in either or both of the two relations. 
 For the set union to be valid they must have the same number of attributes */
/*
Table Engine :: set_union(string attribute_name , Table table1, Table table2 )
{
	// TODO : still working on set Union : unfinished  
	bool table_exists;
	for (int i = 0; i < all_tables.size(); i++)
	{
		if (table1.name == all_tables[i].name)
		{
			table_exists = true;
		}
	}
	if (table_exists != true)
	{
		cout << " Error: Table does not exist" << "\n";
	}
	
	// find size of attribute vector
	int table1_att = table1.att.size();
	int table2_att = table2.att.size();
	
	if (table1_att != table2_att) // if they are not equal then we cannot perform UNION
	{
		cout << "Error : The tables entered does not have the same number of attributes " << "\n";
	}
	// for (int i = 0; i < table1_att; i++)
	// {
		// if(table1[i].att.getName() != table2[i].att.getName())
		// {
			// cout << " Error: The tables attributes do not match " << "\n" ;
		// }
	// }
	
	
}

*/
/* This function forms a cartesian product of its two arguments. 
It will then check if the equality of those attributes appear in both relations.
Lastly, it removes duplicates attributes  */

Table Engine :: natural_join(Table table1, Table table2)
{
	// TODO
	//return NULL;
}

/* This function renames the attributes in a relation  */

Table Engine :: renaming(Table table)

{
	//TODO
}

/* This function should find the tuples in one relation but not in other */

Table Engine :: difference(Table table1, Table table2)
{
	//TODO
}

/* This function combines information from two relations.*/

Table Engine :: cross_product(Table table1, Table table2)
{
	//TODO
}


