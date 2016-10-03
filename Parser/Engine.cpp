#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>


#include "Engine.h"
#include "Attribute.h"
#include "Table.h"

using namespace std;
//Just returns table reference if found
Table& Engine :: findTable(string table_name)
{
	for (Table& t: all_tables)
	{
		if(t.getName() == table_name)
		{
			return t;
		}
		else
		{
			cout << "Error: [Engine]: Table not found !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << table_name << endl;
		}
	}	
}
void Engine ::insertIntoTable(string table_name, vector<string> values)
{
	Table& t = findTable(table_name);
	//t.insert(values); // Need an insert in table class 
}

void Engine:: insertIntoTable(string table_name, Table t)
{
	Table& table = findTable(table_name);
	if(table.getAttributes().size() != t.getAttributes().size())
	{
		cout << "Error : [Engine] tables do not have the same number of columns" << endl;
	}
	else{
		for (int i = 0; i < t.att.size(); i++){
			if (t.att[i].name == table.att[i].name){
				for (int k = 0; k < t.att[i].data.size(); k++){
					table.att[i].data.push_back(t.att[i].data[k]);
				}
			}
		}
	}
	
	
}

Table Engine :: getTable(string table_name)
{
	bool found = false;
	for( int i = 0; i < all_tables.size();i++)
	{
		if(all_tables[i].getName() == table_name)
		{
			found = true;
			return all_tables[i];
		}
	}
	if (!found){
		cout << "Error: [Engine]: table does not exist"<< endl;
	}
	Table t;
	t.setName(table_name);
	return t;
}
/*-------------------------------------------------------------------------------
This function loads a relation from a database file, and returns error 
message if the table does not exist 
---------------------------------------------------------------------------------*/
void Engine::open(string table_name){
	
	ifstream input_file(table_name + ".db");

	if(!input_file.is_open()){
		cout << "Error: [Engine]: Could not open file" << "\n";
	}
	else{
		cout << "Error: [Engine]: Table is already open" << endl;
	}
}
/*----------------------------------------------------------------------------
This function closes a file that was open 
------------------------------------------------------------------------------*/
void Engine::close(string table_name){
   
    ifstream close_file(table_name + ".db");
    
    if(!close_file.is_open()) {
        cout << "Error:[Engine]: Could not close file" << "\n";
    }
    else{
        cout << "Error:[Engine]: Table is already closed" << endl;
    }
    close_file.close();
}
/*-----------------------------------------------------------------------------------
This function reads a table into the database.
-------------------------------------------------------------------------------------*/
void Engine::read(string table_name){
	
	Table table;
	bool found = false;
	
	for (int i = 0; i < all_tables.size(); i++){ // checks if table exists
	    if (table_name == all_tables[i].getName()){
	    	found = true;
			table = all_tables[i];
	    }
	}
	
	ifstream input_file(table_name +".db");
	
	if(!input_file.is_open()){
		cout << "Error:[Engine]: Could not open file" << endl;
	}
	else{
		Table new_table = Table();
		new_table.Read(input_file);
		if(true){
			all_tables.push_back(new_table);
		}
		else{
			cout << "Error: [Engine] : Table already open" << endl;
		}
	}
}

/*------------------------------------------------------------------------------
This function writes table data to a disk file
--------------------------------------------------------------------------------*/
void Engine::write(Table table){
	
	//TODO : fix formating, but function works
	bool table_exists;  
	
	for (int i =0; i < all_tables.size(); i++){
		if (all_tables[i].getName() == table.getName()){
			table_exists = true;
		}
	}
	
	if (table_exists != true){ //if table doesn't exist , add table to datbase
		cout << "Error:[Engine] : Adding table to database" << endl;
		all_tables.push_back(table); 
	}
	
	ofstream output_file(table.getName()+ ".db");
	output_file << table; // write table to txt file 
	output_file.close();
}
/*-----------------------------------------------------------------------------------
This function exists the database after tables have been added 
--------------------------------------------------------------------------------------*/
void Engine::exit_(){
cerr << " [Engine] : Exiting RDBMS now" << endl;
	exit(0);
}

void Engine::show(string table_name){
	//TODO: formatting
	Table table;
	bool found = false;
	
	for (int i = 0; i < all_tables.size(); i++){
		//cout << "table name = " << all_tables[i].getName() << endl;	//Writes all table names
	    if (table_name == all_tables[i].getName()){
	    	found = true;
		table = all_tables[i];
	    }
	}
	if (found){
	    if (table.att.size() != 0){
		cout << '\n' << table.getName() <<endl;
		cout << table.att[0].data.size() << "x" << table.att.size() << endl;
		cout << "\n";
		for (int i = 0; i < table.att.size(); i ++){
            cout<<left;
            cout.width(20);
			cout << table.att[i].getName();
		}
		cout << "\n";
		for (int k = 0; k < table.att[0].data.size(); k++){
		    cout << '\n';
		    for (int i = 0; i < table.att.size(); i++){
                cout<<left;
                cout.width(20);
				cout << table.att[i].data[k];
		    }
		}
		cout<<endl;
	    }
	    else{
		cout << " Error: [Engine]: Table is empty" << endl;
	    }
	}
	else{
	    cout << "Table "<< table_name<< " not found, cannot show" << endl;
	}
}

/* ---------------------------------------------------------------------------------
This function creates a table and adds it to the database  
------------------------------------------------------------------------------------*/
Table Engine::create(string name, vector<Attribute> att, vector<string> key){

	Table table(name,att,key);
	all_tables.push_back(table); 

	return table; 
}

/*--------------------------------------------------------------------------------------
This function changes data to new value in Attribute
---------------------------------------------------------------------------------------*/
Table Engine::update(string table_name, string att_name_1, string newVal,string att_name_2,string data){
    
    Table* table;
    bool status_table = false;
    bool status_att=false;
    for (int i = 0; i < all_tables.size(); i++){
        if (table_name == all_tables[i].getName()){
            status_table = true;
            table = &(all_tables[i]);
        }
    }
    if (status_table == true){
        for (int i = 0; i < table->att.size(); i++){
            if ( (table->att[i].getName()) == att_name_2) //getting attribute name
            {
                status_att=true;
                if (status_att == true)
                {
                    for (int j = 0; j < table->att[i].data.size(); j++)
                    {
                        if( (table->att[i].data[j]) == data)    //getting row by data name
                        {
                            for (int i = 0; i < table->att.size(); i++)
                            {
                                if ( (table->att[i].getName()) == att_name_1)	//searching attribute for new data by row.
                                {
                                    table->att[i].data[j]=newVal;		//set new data.
                                    
                                }
                                
                            }
                        }
                    }
                }
            }
            
        }
        if (status_att == false)
            cout<<" Error: [Engine]: Attribute not found!!"<<endl;
    }else
        cout<<"Error: [Engine]: Table not found!! cannot update!!"<<endl;
    return *table;
}


/*----------------------------------------------------------------------------------
This function inserts data into the Table
------------------------------------------------------------------------------------*/
Table Engine::insert(string table_name, vector<string> new_row){
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
	cout << "Error: [Engine]:Table not found, cannot insert " << table_name << endl;
	}
	return *table;
 }
 
/*------------------------------------------------------------------------------------
This function deletes record (rows) from a table 
--------------------------------------------------------------------------------------*/
Table Engine::destroy(string table_name,string att, string key){
    Table* table;
    bool status_table = false;
    
    for (int i = 0; i < all_tables.size(); i++){
        if (table_name == all_tables[i].getName()){ //getting table name to delete some rows.
            status_table = true;
            table = &(all_tables[i]);
        }
    }
    if (status_table == true){
        for (  int w = 0; w < table->att[0].data.size(); w++ ){
            for (int i = 0; i < table->att.size(); i++){
                if (table->att[i].getName() == att)     //checking attribute name
                {
                    for(int j=0; j<table->att[i].data.size(); j++)
                    {
                        if (table->att[i].data[j] == key)
                        {
                            for (int k = 0; k < table->att.size(); k++)
                            {
                                table->att[k].data.erase(table->att[k].data.begin()+j);
                            }
                        }
                    }
                }
            }
        }
    }else
        cout<<" Error: [Engine]: Table not found, cannot delete a row"<<endl;
    
    return *table;
}


/*------------------------------------------------------------------------------------------------
This function deletes table from the database of tables
---------------------------------------------------------------------------------------------------*/
void Engine::drop(string table_name){
	
	for(int i = 0; i < all_tables.size(); i++){
		if (all_tables[i].getName() == table_name){
		all_tables.erase(all_tables.begin()+i); 
		}
	}
}
/*-------------------------------------------------------------------------------------------------
This function identifies a set of tuples which is part of relation and then extracts the tuples.  
The operation selects the tuples that satisfy a given predicate or condition. 
It will involve logical conditions as defined in the grammar. 
----------------------------------------------------------------------------------------------------*/
void select_helper(int col, int row, Table* table, Table* new_table){
	for (int i = 0; i < table->att.size(); i++){
		new_table->att[i].data.push_back(table->att[i].data[row]);
	}
}

Table Engine :: selection(string table_name, string att_name, string op, string condition)   {
    Table* table;
    Table new_table;
    bool found = false;
    for (int i = 0; i < all_tables.size(); i++){
        if (table_name == all_tables[i].getName()){
            found = true;
            table = &(all_tables[i]);
        }
    }
    if (found){
    	for (int i = 0; i < table->att.size(); i++){
    		Attribute attr;
    		attr.name = table->att[i].name;
    		attr.type = table->att[i].type;
    		new_table.att.push_back(attr);
    	}
        for (int i = 0; i < table->att.size(); i++){
            if( (table->att[i].getName()) == att_name){
                cout<<table->att[i].getName()<<endl<<endl;
                for (int j = 0; j < table->att[i].data.size(); j++){
                	if (op == "=="){
                		if (table->att[i].data[j] == condition){
                			select_helper(i, j, table, &new_table);
                		}
                	}
                	else if (op == "!="){
						if (table->att[i].data[j] != condition){
							select_helper(i, j, table, &new_table);
						}
                	}
                	else if (op == ">"){
						if (table->att[i].data[j] > condition){
							select_helper(i, j, table, &new_table);
						}
                	}
                	else if (op == ">="){
						if (table->att[i].data[j] >= condition){
							select_helper(i, j, table, &new_table);
						}
                	}
               		else if (op == "<"){
						if (table->att[i].data[j] < condition){
							select_helper(i, j, table, &new_table);
						}
                	}
                	else if (op == "<="){
						if (table->att[i].data[j] <= condition){
							select_helper(i, j, table, &new_table);
						}
                	}
             		else{
             			cout << "invalid conditional operator in selection:" << op << endl;
             		}
                }
            }
        }
    }
    return new_table;
}
//searching column information.

/*-----------------------------------------------------------------------------------------
This function selects a subset of the attributes in a relation. 
------------------------------------------------------------------------------------------*/
Table Engine :: projection(vector <string> att_names, string table_name){///UPDATE BY JOSE R.

	Table table;

	vector<string> key_name = {"1","2","3"};//TODO: not use yet 
	
	bool table_exists = false; // checks if table exists
	vector<string> v;
	vector<Attribute> attributes;
	string att_name;
	string att_type;

	for (int i = 0; i < all_tables.size(); i++){
		if (table_name == all_tables[i].name){
			table_exists = true;
			table = all_tables[i];
		}
	}

	if (table_exists != true){
		cout << "Error:[Engine]: Table does not exist" << endl;
	}

	for (int i = 0; i < att_names.size(); i++){
		for(int k = 0;k < table.att.size();k++ ){
			if(att_names[i] == table.att[k].getName()){
				for(int j = 0; j < table.att[0].data.size(); j++){
					v.push_back(table.att[k].data[j]);
				}
				att_name = table.att[k].getName();
    			att_type = table.att[k].getType();
      			Attribute att(att_name,att_type,v);
      			attributes.push_back(att);
      			v.clear();
			}
		}
	}

	string name = table_name + " Projection";
	Table new_Table = create(name,attributes, key_name);

	return new_Table;
}



/*-------------------------------------------------------------------------------------------
This helper function checks if both table are the same size, have the same attributes names
--------------------------------------------------------------------------------------------*/
bool Engine::verify_Tables(Table table1, Table table2){

	bool first_table = false;
	bool second_table = false;
	bool check_size = false;
	bool list_size = true;
	bool same_attributes = false;


	for(int i = 0; i < all_tables.size(); i++){////CHECKS IF TABLE EXIST

		

		if (all_tables[i].name == table1.name){
			first_table = true;
		}
		if (all_tables[i].name == table2.name){
			second_table = true;
		}
	}

	if(first_table == false){//PRINTS OUT WHICH TABLE DOES NOT EXIST

		cout << "Error:"<<table1.name<< " does not exist" << "\n";
	}
	if(second_table == false){//PRINTS OUT WHICH TABLE DOES NOT EXIST
		cout << " Error:"<<table2.name<<" does not exist" << "\n";
	}

	if (table1.att.size() == table2.att.size()){///CHECKS IF BOTH TABLES HAVE THE SAME SIZE 
		check_size = true;
		if(check_size == false){
			cout << "Error :[Engine]: The tables entered does not have the same number of attributes " << "\n";
		}
	}

	for(int i = 0 ;i<table1.att.size();i++ ){//CHECKS IF BOTH TABLES HAVE THE SAME NUMBER OF ITEM IN EACH ATTRIBUTE
		if(table1.att[i].data.size() != table2.att[i].data.size()){
			list_size = false;
		}
	}
	if(list_size == false){//PRINTS IF NUMBER OF ITEMS IN EACH ATTRIBUTE NOT THE SAME
			cout<<"Error: [Engine] : number of items in attributes not the same"<<endl;
		}
	
	for(int i = 0; i < table1.att.size(); i++){//CHECKS IF ATTRIBUTES NAMES ARE THE SAME FOR BOTH TABLES
		if(table1.att[i].getName() == table2.att[i].getName()){
			same_attributes = true;
		}
		if(same_attributes == false){
		cout << "Error:[Engine] :The tables' attributes do not match " << "\n" ;
		}
	}
	//RETURN TRUE IF TABLES ARE THE SAME IN EVERY ASPECT
	if(( first_table == true) && (second_table == true) && (check_size == true) && (same_attributes == true) && list_size == true){
		return true;
	}

	return false;
}


/*------------------------------------------------------------------------------------------
The function sets a union between two attributes that appear in either or both of the 
two relations. For the set union to be valid they must have the same number of attributes 
--------------------------------------------------------------------------------------------*/
Table Engine::set_union(Table table1, Table table2 ){

	bool execute = verify_Tables(table1,table2);

	if(execute == true){//IF VERIFY RETURN TRUE, UNION TABLES 
		vector<vector<string>> store_union;
		int size = table1.att[0].data.size();
		bool first_pass = false;
		bool second_pass = false;
	
		for(int i = 0; i< size; i++ ){
			for(int j = 0; j< size; j++){
				if(rtn_Row(table1,i) == rtn_Row(table2,j)){//COMPARES  ROW
				   first_pass = true;
		    	}
		   	    if(rtn_Row(table2,i) == rtn_Row(table1,j)){//COMPARE ROW
			   	   second_pass = true;
		   	    }
       		 }
       	     if(first_pass == false){//IF ROW(TABLE1) NOT IN TABLE 2, ADD TO THE UNION TABLE
        		store_union.push_back(rtn_Row(table1,i));
             }
      	     if(first_pass == true){//IF ROW(TABLE 1)  IN TABLE 2, ADD TO THE UNION TABLE ONLY ONCE
        		store_union.push_back(rtn_Row(table1,i));
        		first_pass = false;
             }
             if(second_pass == false){//IF ROW(TABLE 2) NOT IN TABLE 1, ADD TO THE UNION TABLE
        	    store_union.push_back(rtn_Row(table2,i));
             }
             if(second_pass == true){//IF ROW(TABLE 2)  IN TABLE 1, NO NOT ADD BECAUSE IT HAS BEEN ADDED BY FIRST_PASS
        		second_pass = false;
             }
	    }
 		string table_name = table1.name + " + " + table2.name;
 		Table m = makeTable(table1,table_name,store_union);
 		all_tables.push_back(m);
		return m;//RETURN UNION TABLE, 
	}
	Table new_Table;
	return new_Table;
}

/*-----------------------------------------------------------------------------------------
This function forms a cartesian product of its two arguments. 
It will then check if the equality of those attributes appear in both relations.
Lastly, it removes duplicates attributes 
------------------------------------------------------------------------------------------*/
Table Engine::natural_join(Table table1, Table table2){
	//TODO: check if tables are empty first
	Table new_table;
	vector<int> indices;	//stores places where table finds matching column
	vector<int> new_table_indices;
	vector<string> relations;
	vector<pair<int,int>> related_columns;
	vector<pair<int,int>> non_related_columns;

	for (int i = 0; table1.att.size(); i++){
		relations.push_back(table1.att[i].name);
	}
	for (int i = 0; table2.att.size(); i++){
		for (int k = 0; k < table1.att.size(); k++){
			if (table2.att[i].name == table1.att[k].name){
				pair<int,int> a(i,k);
				related_columns.push_back(a);
			}
			else{
				pair<int,int> a(i,k);
				non_related_columns.push_back(a);
			}
		}
	}
	for (int i = 0; non_related_columns.size(); i++){
		relations.push_back(table2.att[non_related_columns[i].second].name);
	}
	for (int i = 0; i < table1.att.size(); i++){	//Create columns matching table 1
		for (int k = 0; k < relations.size(); k++){
			if (relations[k] == table1.att[i].name){
				Attribute temp_att;
				temp_att.name = table1.att[i].name;
				temp_att.type = table1.att[i].type;
				new_table.att.push_back(temp_att);
			}
		}
	}
	for (int i = 0; i < table2.att.size(); i++){	//create columns matching table 2
		for (int k = 0; k < relations.size(); k++){
			if (relations[k] == table2.att[i].name){
				Attribute temp_att;
				temp_att.name = table2.att[i].name;
				temp_att.type = table2.att[i].type;
				new_table.att.push_back(temp_att);
				indices.push_back(i);
				new_table_indices.push_back(k);
			}
		}
	}
	if (related_columns.size() == 0){	//no common attributes, do cartesian product
		for (int i = 0; i < table1.att.size(); i++){	//Populate table from cartesian product starting with table 1
			if (i < new_table.att.size() && table1.att[i].name == new_table.att[i].name){
				for (int z = 0; z < table1.att[i].data.size(); z++){
					for (int q = 0; q < table2.att[0].data.size(); q++){
						new_table.att[i].data.push_back(table1.att[i].data[z]);
					}
				}
			}
		}
		for (int k = indices.size()-1; k >= 0; k--){	//Then table 2
			for (int z = 0; z < table1.att[0].data.size(); z++){
				for (int q = 0; q < table2.att[indices[k]].data.size(); q++){
					new_table.att[new_table_indices[k]].data.push_back(table2.att[indices[k]].data[q]);
				}
			}
		}
	}
	else{	//common attributes found, do natural join
		for (int i = 0; i < table1.att.size(); i++){	//Populate table from cartesian product starting with table 1
			if (i < new_table.att.size() && table1.att[i].name == new_table.att[i].name){
				for (int z = 0; z < table1.att[i].data.size(); z++){
					new_table.att[i].data.push_back(table1.att[i].data[z]);
				}
			}
		}
		for (int k = indices.size()-1; k >= 0; k--){	//Then table 2
			for (int z = 0; z < table1.att[0].data.size(); z++){
				for (int q = 0; q < table2.att[indices[k]].data.size(); q++){
					for (int j = 0; j < related_columns.size(); j++){
						if (related_columns[j].first == k && related_columns[j].second == q && table1.att[k].data[z] == table2.att[indices[k]].data[q])
							new_table.att[new_table_indices[k]].data.push_back(table2.att[indices[k]].data[q]);
					}
					
				}
			}
		}
	}
	
	new_table.name = table1.name + "JOIN" + table2.name;
	all_tables.push_back(new_table);
	return new_table;
}

/*-------------------------------------------------------------------------------------------
 This function renames the attributes in a relation  
--------------------------------------------------------------------------------------------*/
void Engine::renaming(vector<string> att_name,  Table& table_name){
	
	bool table_exists = false;
	
	cout << "looking for: " << table_name.getName() << endl;
	for (int i = 0; i < all_tables.size(); i++){
		cout << "renaming out table " << all_tables[i].getName() << endl;
		if (table_name.getName() == all_tables[i].name){
			table_exists = true;
		}
	}
	if (table_exists != true){
		cout << " Error:[Engine]: Table does not exist" << "\n";
	}
	for (int i = 0; i < att_name.size() ;i++){
	
			table_name.att[i].setName(att_name[i]);
	}
	
}

/*---------------------------------------------------------------------------------------
This function should find the tuples in one relation but not in other
creates a vector of tuples,I was trying to figure out how  to compare rows(tuples)
return row.
-----------------------------------------------------------------------------------------*/
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

/*-----------------------------------------------------------------------------------------
This helper function  is for difference and union,  and creates a table 
-------------------------------------------------------------------------------------------*/
Table Engine::makeTable(Table table,string name, vector<vector<string>> difference){

	vector<string> key_name = {"1","2","3"};//TODO: not use yet 
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

/*---------------------------------------------------------------------------------------
This function should find the tuples in one relation but not in other
-----------------------------------------------------------------------------------------*/
Table Engine::difference(Table table1, Table table2){



	bool execute = verify_Tables(table1,table2);

	if(execute == true){

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
		Table d = makeTable(table1,table_name,diff);
		all_tables.push_back(d);
		return 	d;
	}

	Table t_default;
	return t_default;
}


/* ----------------------------------------------------------------------------------------------
This function combines information from two relations by performing the cartesian product on them
-------------------------------------------------------------------------------------------------*/
Table Engine::cross_product(Table table1, Table table2)
{
	//TODO: check if tables are empty first
	Table new_table;
	vector<int> indices;	//stores places where table finds matching column
	vector<int> new_table_indices;
	vector<string> relations;
	for (int i = 0; table1.att.size(); i++){
		relations.push_back(table1.att[i].name);
	}
	for (int i = 0; table2.att.size(); i++){
		relations.push_back(table2.att[i].name);
	}
	for (int i = 0; i < table1.att.size(); i++){	//Create columns matching table 1
		for (int k = 0; k < relations.size(); k++){
			if (relations[k] == table1.att[i].name){
				Attribute temp_att;
				temp_att.name = table1.att[i].name;
				temp_att.type = table1.att[i].type;
				new_table.att.push_back(temp_att);
			}
		}
	}
	for (int i = 0; i < table2.att.size(); i++){	//create columns matching table 2
		for (int k = 0; k < relations.size(); k++){
			if (relations[k] == table2.att[i].name){
				Attribute temp_att;
				temp_att.name = table2.att[i].name;
				temp_att.type = table2.att[i].type;
				new_table.att.push_back(temp_att);
				indices.push_back(i);
				new_table_indices.push_back(k);
			}
		}
	}
	for (int i = 0; i < table1.att.size(); i++){	//Populate table from cartesian product starting with table 1
		if (i < new_table.att.size() && table1.att[i].name == new_table.att[i].name){
			for (int z = 0; z < table1.att[i].data.size(); z++){
				for (int q = 0; q < table2.att[0].data.size(); q++){
					new_table.att[i].data.push_back(table1.att[i].data[z]);
				}
			}
		}
	}
	for (int k = indices.size()-1; k >= 0; k--){	//Then table 2
		for (int z = 0; z < table1.att[0].data.size(); z++){
			for (int q = 0; q < table2.att[indices[k]].data.size(); q++){
				new_table.att[new_table_indices[k]].data.push_back(table2.att[indices[k]].data[q]);
			}
		}
	}
	new_table.name = table1.name + "*" + table2.name;
	cout << "New Table Name is: " << new_table.name << endl;
	all_tables.push_back(new_table);
	return new_table;


}



