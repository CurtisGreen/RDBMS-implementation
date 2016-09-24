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
	//TODO : Need help finishing this last line, but otherwise works.
	bool table_exists; // boolean to figure out if table already exists
	
	for (int i =0; i < all_tables.size(); i++){
		if (all_tables[i].getName() == table_name){
			table_exists = true;
		}
	}
	if (table_exists != true){
		cout << " Error: Table does not exist" << "\n";
	}
	
	ifstream input_file(table_name + ".txt");
	
	if(!input_file.is_open())
	{
		cout << "Error: Could not open file" << "\n";
	}
	else
	{
		Table new_table = Table();
		new_table.Read(input_file);
		all_tables.push_back(new_table);
		
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
	// checks if table exists in all tables vector, if not adds to tables vector
	if (table_exists != true){
		all_tables.push_back(table); 
	}
	
	ofstream output_file(table.getName()+ ".txt");
	
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
			cout << table.att[i].getName() <<  table.att[i].data[k] << '\t';
		    }
		}
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


void Engine::update(){
	//TODO
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

Table Engine::set_union(string attribute_name , Table table1, Table table2 )
{
	//TODO : still working on set Union : unfinished  
	bool table_exists = false;
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

	for (int i = 0; i < table1_att; i++)
	{
		if(table1.att[i].getName() != table2.att[i].getName())
		{
			cout << "Error: The tables' attributes do not match " << "\n" ;
		}
		
	}



	Table rtn_table = Table(); /// stores the difference of tuples

	vector<string> t_1 = rtn_stringRow(table1); 
	vector<string> t_2 = rtn_stringRow(table2); 
	
	vector<string> stored;
	string str;
	int count = 0;
	int count2=0;
	int count3 =0;


	for(int i = 0; i< t_1.size(); i++ ){

		for(int j = 0; j< t_2.size(); j++){

			
			if(t_1[i] == t_2[j]){
				count++;
		    }
		    if(t_1[i] == t_2[j]){
				count2++;
		    }
		
		    if(t_2[i] == t_1[j]){
		    
				count3++;
		    }
        }

        
        if(count == 0){
        	stored.push_back(t_1[i]);
        	count=0;
        }
        if(count2 == 1){
        	stored.push_back(t_1[i]);
        	count2=0;
        }
	

        if(count3 == 0){
        	stored.push_back(t_2[i]);
        	count3=0;
        }
	}



	for(int i = 0; i< stored.size(); i++){
		cout<<stored[i]<<endl;
	}

	return rtn_table;
	
	
	
	
	
	
	
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

vector<string> Engine::rtn_stringRow(Table t){//return a string, needs to return a tuple(vector<attributes>)

	vector<string> tuples;
	string str;

	for(int i = 0; i< t.att.size(); i++){

		for(int j = 0; j< t.att.size(); j++){

			str += t.att[i].data[j];
		}
		tuples.push_back(str);
		str ="";
	}

	return tuples; //return a vector of tuples 
}

//return row
vector<string> Engine::rtn_Row(Table t, int index){

	int size = t.att[0].data.size();
	vector<string> row;
	vector<vector<string>> rows;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < t.att.size(); j++){
			row.push_back(t.att[j].data[i]);
		}
		rows.push_back(row);
		row.clear();
	}
	vector<string> rtn_row;
	for (int i = 0; i <rows[i].size(); i++){		
	  rtn_row.push_back(rows[index][i]);
	}
   	 return rtn_row;
}

//TODO, needs to return a Table, right now prints a string for testing purposes
Table Engine::difference(Table table1, Table table2)
{
	//TODO : finish difference
	bool table_exists = false;
	for (int i = 0; i < all_tables.size(); i++){
		if (table1.name == all_tables[i].name){
			table_exists = true;
		}
		else{
			cout << " Error: Table does not exist"<<endl;
		}
	}
	
	if (table1.att.size() != table2.att.size()){//checks size
		cout << "Error : The tables entered does not have the same number of attributes"<<endl;;
	}


 	//cout<<t1.att[0].data.size()<<endl;///4

 	//cout<<t1.att.size()<<endl;////3

/*

	int count = 0;

	for(int i = 0; table1.att[0].data.size() ; i++){

		for(int j = 0; table2.att.size() ; j++){

			if(rtn_Row(table1,i) == rtn_Row(table2,j)){
				count++;
			}

		}

						
	}

	
*/





 //return the diference but in string format
	Table rtn_table = Table(); /// stores the difference of tuples
/*
	vector<string> table1 = rtn_stringRow(table1); 
	vector<string> table2 = rtn_stringRow(table2); 
	
	vector<string> stored;
	string str;
	int count = 0;

	for(int i = 0; i< table1.size(); i++ ){
		for(int j = 0; j< table2.size(); j++){
			if(table1[i] == table2[j]){
				count++;
			}
        }
        if(count == 0){
        	cout<<table[i]<<endl;
        }
	}
	for(int i = 0; i< stored.size(); i++){
		cout<<stored[i]<<endl;
	}
	*/
	return rtn_table;

	
}


/* This function combines information from two relations. And removes duplicates*/
Table Engine::cross_product(Table table1, Table table2)
{
	//TODO
}



