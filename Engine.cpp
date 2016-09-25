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
	
	ifstream input_file(table_name + ".db");

	if(!input_file.is_open())
	{
		cout << "Error: Could not open file" << "\n";
	}
	else
	{
		cout << "Error: Table is already open" << endl;
	}
}
void Engine::close(string table_name){
	//TODO
}

void Engine::read(string table_name){
	// Table table;
	// bool found = false;
	
	// for (int i = 0; i < all_tables.size(); i++){
	    // if (table_name == all_tables[i].getName()){
	    	// found = true;
		// table = all_tables[i];
	    // }
	// }
	
	// if (!table_exists){
		// all_tables.push_back(table);
	// }
	//TODO: check to make sure file exists
	// ifstream input_file(table.getName()+".txt");
	// output_file >> table;
}

void Engine::write(Table table){
	
	//TODO : fix formating, but function works
	bool table_exists; // boolean to figure out if table already exists
	
	for (int i =0; i < all_tables.size(); i++){
		if (all_tables[i].getName() == table.getName()){
			table_exists = true;
		}
	}
	
	if (table_exists != true){
		all_tables.push_back(table); 
	}
	
	ofstream output_file(table.getName()+ ".db");
	
	
	output_file << table.getName() << endl;
	output_file << table; 
	
}

void Engine::exit_(){
	cerr << "Exiting RDBMS now" << "\n";
	exit(0);
}

void Engine::show(string table_name){
	//TODO: formatting
	Table table;
	bool found = false;
	
	for (int i = 0; i < all_tables.size(); i++){
	    if (table_name == all_tables[i].getName()){
	    	found = true;
		table = all_tables[i];
	    }
	}
	if (found){
	    if (table.att.size() != 0){
		cout << '\n' << table.getName() <<endl;
		cout << table.att[0].data.size() << "x" << table.att.size() << endl;
		for (int k = 0; k < table.att[0].data.size(); k++){
		    cout << '\n';
		    for (int i = 0; i < table.att.size(); i++){
			cout << table.att[i].getName() <<" "<<  table.att[i].data[k] << '\t';
		    }

		}
		cout<<endl;
	    }
	    else{
	    	cout << "Table is empty" << endl;
	    }
	}
	else{
	    cout << "Table not found, cannot show" << endl;
	}
}

/* This function creates a table and adds it to the database  */
void Engine::create(string name, vector<Attribute> att, vector<string> key){

	Table table(name,att,key);
	all_tables.push_back(table);  
}

//can change data to new vlue in Attribute.
void Engine::update(string table_name, string att_name, string data, string newVal){
    Table* table;
    bool found = false;
    for (int i = 0; i < all_tables.size(); i++){
        if (table_name == all_tables[i].getName()){
            found = true;
            table = &(all_tables[i]);
        }
    }
    if (found){
        for (int i = 0; i < table->att.size(); i++){
            if ( (table->att[i].getName()) == att_name)
           {
               for (int j = 0; j < table->att[i].data.size(); j++)
               {
                   if( (table->att[i].data[j]) == data)
                       table->att[i].data.at(j)=newVal;
               }
           }
        }
    }
    
}

void Engine::insert(string table_name, vector<string> new_row){
	Table* table;
	bool found = false;
	for (int i = 0; i < all_tables.size(); i++){
	    if (table_name == all_tables[i].getName()){
	    	found = true;
		table = &(all_tables[i]);
	    }
	}
	if (found){
	    for (int i = 0; i < table->att.size(); i++){	//Assume data is passed in correct order
	        table->att[i].data.push_back(new_row[i]); 
	     }
	}
	else{
	    cout << "Table not found, cannot insert" << endl;
	}
 }
/* This function deletes record from a table  
 you can type table name and row number you want to delete*/
void Engine::destroy(string table_name,int row){
    Table* table;
    bool found = false;
    for (int i = 0; i < all_tables.size(); i++){
        if (table_name == all_tables[i].getName()){
            found = true;
            table = &(all_tables[i]);
        }
    }
    if (found){
        for (int i = 0; i < table->att.size(); i++){
            table->att[i].data.erase((table->att[i].data.begin())+(row-1));     //accessing data each attribute and delete.
        }
    }
    
    
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


Table Engine :: projection(vector <string> att_names, string table_name)

{
	// TODO: Inga : it works. 
	
	Table table;
	
	bool table_exists = false;
	
	for (int i = 0; i < all_tables.size(); i++)
	{
		if (table_name == all_tables[i].name)
		{
			table_exists = true;
			table = all_tables[i];
		}
	}
	if (table_exists != true)
	{
		cout << "Error: Table does not exist" << endl;
	}
	cout << table.getName() << endl;
	
	for (int i =0; i < table.att.size(); i++)
	{
		if(att_names[i] == table.att[i].getName())
		{
			cout << table.att[i].getName() << endl;
			
			for(int j =0; j < table.att[0].data.size(); j++)
			{
				cout << table.att[i].data[j] << endl;
			}
		}
	}
	return table;
	
}

/* The function sets a union between two attributes that appear in either or both of the two relations. 
 For the set union to be valid they must have the same number of attributes */

bool Engine::verify_Tables(Table table1, Table table2){

	bool next_step = true;

	for(int i = 0; i < all_tables.size(); i++){
		if (table1.name != all_tables[i].name){
			cout << "Error:"<<table1.name<< " does not exist" << "\n";
			next_step = false;
		}
		if (table2.name != all_tables[i].name){
			cout << " Error:"<<table2.name<<" does not exist" << "\n";
			next_step = false;
		}
	}
	if (table1.att.size() != table2.att.size()){
		cout << "Error : The tables entered does not have the same number of attributes " << "\n";
		next_step = false;
	}
	for(int i = 0; i < table1.att.size(); i++){
		if(table1.att[i].getName() != table2.att[i].getName()){
			cout << "Error: The tables' attributes do not match " << "\n" ;
			next_step = false;
		}
	}
	return next_step;
}

Table Engine::set_union(string attribute_name , Table table1, Table table2 ){

	//bool execute = verify_Tables(table1,table2);

	vector<vector<string>> store_union;
	int size = table1.att[0].data.size();
	bool first_pass = false;
	bool second_pass = false;
	
	for(int i = 0; i< size; i++ ){
		for(int j = 0; j< size; j++){
			if(rtn_Row(table1,i) == rtn_Row(table2,j) ){
				first_pass = true;
		    }
		    if(rtn_Row(table2,i) == rtn_Row(table1,j)){
			    second_pass = true;
		    }
        }

        if(first_pass == false){
        	store_union.push_back(rtn_Row(table1,i));
        }
        if(first_pass == true){
        	store_union.push_back(rtn_Row(table1,i));
        	first_pass = false;
        }
        if(second_pass == false){
        	store_union.push_back(rtn_Row(table2,i));
        }
        if(second_pass == true){
        	second_pass = false;
        }
	}

 	string table_name = table1.name + " U " + table2.name;

	return 	makeTable(table1,table_name,store_union);
	
}


/* This function forms a cartesian product of its two arguments. 
It will then check if the equality of those attributes appear in both relations.
Lastly, it removes duplicates attributes  */

Table Engine::natural_join(Table table1, Table table2)
{
	// TODO
	//return NULL;
}

/* This function renames the attributes in a relation  */

void Engine::renaming( string old_attr, string new_attr, string table_name){
	
	//TODO : It works !! HOORAY !!
	bool table_exists = false;
	
	Table* table;
	for (int i = 0; i < all_tables.size(); i++)
	{
		if (table_name == all_tables[i].name)
		{
			table_exists = true;
			table = &(all_tables[i]);
		}
	}
	if (table_exists != true)
	{
		cout << " Error: Table does not exist" << "\n";
	}
	
	for (int i = 0; i < table->att.size(); i++)
	{
		if (table->att[i].getName() == old_attr)
		{
			table->att[i].setName(new_attr);
		}
	}
}


/* This function should find the tuples in one relation but not in other */
///creates a vector of tuples,I was trying to figure out how  to compare rows(tuples)
//return row
vector<string> Engine::rtn_Row(Table t, int index){

	int size = t.att[0].data.size();
	vector<string> row;
	vector<vector<string>> rows;
	vector<string> rtn_row;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < t.att.size(); j++){
			row.push_back(t.att[j].data[i]);
		}
		rows.push_back(row);
		row.clear();
	}

	for (int i = 0; i <rows[0].size(); i++){		
	  rtn_row.push_back(rows[index][i]);
	}
   	 return rtn_row;
}

////Helper function for difference and union
Table Engine::makeTable(Table table,string name, vector<vector<string>> difference){

	vector<string> key_name = {"1","2","3"};
	vector<Attribute> attributes;
	vector<string> v;
	string att_name;
	string att_type;

	for (int i = 0; i < difference[0].size(); i++){
    	for (int j = 0; j < difference.size(); j++) {
		  v.push_back( difference[j][i]); 
    	}
    	att_name = table.att[i].getName();
    	att_type = table.att[i].getType();
      	Attribute att(att_name,att_type,v);
      	attributes.push_back(att);
      	v.clear();
	}
	Table new_Table(name,attributes, key_name);
	return new_Table;
}

//returns a table
Table Engine::difference(Table table1, Table table2){
	
	vector<vector<string>> diff; 
	bool exist = false;
	int size = table1.att[0].data.size();

	for(int i = 0; i<size; i++){
		for(int j = 0; j < size; j++){
			if(rtn_Row(table1,i) == rtn_Row(table2,j)){
				exist = true;
			}
		}
		if(exist == false){
			diff.push_back(rtn_Row(table1,i));
		}
		exist = false;
	}
	string table_name = table1.name + "-" + table2.name;

	return 	makeTable(table1,table_name,diff);
}


/* This function combines information from two relations. And removes duplicates*/
Table Engine::cross_product(Table table1, Table table2)
{
	//TODO
}



