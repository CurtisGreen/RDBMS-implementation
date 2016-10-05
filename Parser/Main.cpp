
#include "MainTest.cpp"
#include "Catch.h"

#include "Parser.h"
#include "Table.h"
#include "Engine.h"
#include "Token_stream.h"


TEST_CASE("Parser test", "[Parser]") {


	Parser parser;
	parser.input();
	
	
	cout<<endl;
	cout<<endl;
	cout<< "----------------Insert function test-----------------------------------" <<endl;
	/*
	CREATE TABLE Graduate (Number INTEGER, Surname VARCHAR(20), Age INTEGER) PRIMARY KEY (Number, Surname);
	CREATE TABLE Manager (Number INTEGER, Surname VARCHAR(20), Age INTEGER) PRIMARY KEY (Number, Surname);
	INSERT INTO Graduate VALUES FROM (74,Robinson,37);
	INSERT INTO Graduate VALUES FROM (7432,OMalley,39);
	INSERT INTO Graduate VALUES FROM (9894,Darkes,38);
	INSERT INTO Manager VALUES FROM (9297,OMalley,56);
	INSERT INTO Manager VALUES FROM (7432,OMalley,39);
	INSERT INTO Manager VALUES FROM (9894,Darkes,38);
	Graduate + Manager;  
	*/
	
	Table new_table = parser.e.get_table("Graduate");
	
	REQUIRE(new_table.att[0].data[2] == "9894");
	REQUIRE(new_table.att[1].data[2] == "Darkes");
	REQUIRE(new_table.att[2].data[2] == "38");    
	
	
	cout<<endl;
	cout<<endl;
	cout<< "----------------Create function test-----------------------------------" <<endl;
	/*
	CREATE TABLE Graduate (Number INTEGER, Surname VARCHAR(20), Age INTEGER) PRIMARY KEY (Number, Surname);
	CREATE TABLE Manager (Number INTEGER, Surname VARCHAR(20), Age INTEGER) PRIMARY KEY (Number, Surname);
	INSERT INTO Graduate VALUES FROM (74,Robinson,37);
	INSERT INTO Graduate VALUES FROM (7432,OMalley,39);
	INSERT INTO Graduate VALUES FROM (9894,Darkes,38);
	INSERT INTO Manager VALUES FROM (9297,OMalley,56);
	INSERT INTO Manager VALUES FROM (7432,OMalley,39);
	INSERT INTO Manager VALUES FROM (9894,Darkes,38);
	Graduate + Manager;  
	*/

	
	Table new_table1 = parser.e.get_table("Graduate");
	Table new_table2 = parser.e.get_table("Manager");
	
	
	REQUIRE(new_table1.getName() == "Graduate");
	REQUIRE(new_table2.getName() == "Manager");
	


	cout<<endl;
	cout<<endl;
	cout<< "----------------Union function test-----------------------------------" <<endl;
	/*
	CREATE TABLE Graduate (Number INTEGER, Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	CREATE TABLE  Manager (Number INTEGER, Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	INSERT INTO Graduate VALUES FROM (7274,"Robinson",37);
	INSERT INTO Graduate VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Graduate VALUES FROM (9894,"Darkes",38);
	INSERT INTO Manager VALUES FROM (9297,"O'Malley",56);
	INSERT INTO Manager VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Manager VALUES FROM (9894,"Darkes",38);
	Graduate + Manager;  
	*/
	
	
	new_table1 = parser.e.get_table("Graduate");

	parser.e.show(new_table1.getName());
	new_table2 = parser.e.get_table("Manager");
	
	Table union_table = parser.e.set_union(new_table1,new_table2);
	parser.e.all_tables.push_back(union_table);
	
	Table u_table = parser.e.get_table(union_table.getName());
	parser.e.show(u_table.getName());

	
	REQUIRE(u_table.getName()== "Graduate + Manager");
	REQUIRE(u_table.att[1].data[0] == "Robinson");
	REQUIRE(u_table.att[2].data[1]== "56");	


	cout<<endl;
	cout<<endl;
	cout<< "----------------Difference function test-----------------------------------" <<endl;
	/*
	CREATE TABLE Graduate (Number INTEGER  Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	CREATE TABLE  Manager (Number INTEGER, Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	INSERT INTO Graduate VALUES FROM (7274,"Robinson",37);
	INSERT INTO Graduate VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Graduate VALUES FROM (9894,"Darkes",38);
	INSERT INTO Manager VALUES FROM (9297,"O'Malley",56);
	INSERT INTO Manager VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Manager VALUES FROM (9894,"Darkes",38);
	Graduate - Manager;  
	*/
	new_table1 = parser.e.get_table("Graduate");

	new_table2 = parser.e.get_table("Manager");
	
	Table difference_table = parser.e.difference(new_table1,new_table2);
	parser.e.all_tables.push_back(difference_table);
	
	parser.e.show(difference_table.getName());
	

	REQUIRE(difference_table.att[1].data[0]== "Robinson");
	REQUIRE(difference_table.name == "Graduate-Manager");

	cout<<endl;
	cout<<endl;
	cout<< "----------------Product function test-----------------------------------" <<endl;
	/*
	CREATE TABLE Graduate (Number INTEGER  Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	CREATE TABLE  Manager (Number INTEGER, Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	INSERT INTO Graduate VALUES FROM (7274,"Robinson",37);
	INSERT INTO Graduate VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Graduate VALUES FROM (9894,"Darkes",38);
	INSERT INTO Manager VALUES FROM (9297,"O'Malley",56);
	INSERT INTO Manager VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Manager VALUES FROM (9894,"Darkes",38);
	Graduate - Manager;  
	*/
	
	//new_table1 = parser.e.get_table("Graduate");

	//new_table2 = parser.e.get_table("Manager");
	
	//Table p_table = parser.e.cross_product(new_table1,new_table2);
	//parser.e.all_tables.push_back(p_table);
	
	//parser.e.show(p_table.getName());
	

	/*REQUIRE(parser.e.all_tables[0].getName()== "Graduate");
	REQUIRE(parser.e.all_tables[1].getName()== "Manager");
	REQUIRE(parser.e.all_tables[2].getName()== "Graduate*Manager");
	REQUIRE(parser.e.all_tables.size() ==4);*/ //FIX


	cout<<endl;
	cout<<endl;
	cout<< "----------------Natural join function test-----------------------------------" <<endl;
	
	/*new_table1 = parser.e.get_table("Graduate");

	
	new_table2 = parser.e.get_table("Manager");
	
	Table n_table = parser.e.natural_join(new_table1,new_table2);
	parser.e.all_tables.push_back(n_table);

	parser.e.show(n_table.getName());*/
	

	/*REQUIRE(parser.e.all_tables[0].getName()== "Graduate");
	REQUIRE(parser.e.all_tables[1].getName()== "Manager");
	REQUIRE(parser.e.all_tables[2].getName()== "GraduateJOINManager");
	REQUIRE(parser.e.all_tables.size() ==4);*/


	cout<<endl;
	cout<<endl;
	cout<< "----------------Projection_test function test-----------------------------------" <<endl;
	
	new_table1 = parser.e.get_table("Graduate");
	
	vector<string> names = {"Number", "Surname", "Age"};
	
	parser.e.projection(names, new_table1.getName());
	parser.e.show(new_table1.getName());
	
	
	REQUIRE(new_table1.att[1].data[0]== "Robinson");
	//REQUIRE(parser.e.all_tables[0].att[1].getName()== "Surname");
	//REQUIRE(parser.e.all_tables[0].att[2].getName()== "Age");
	
	

	cout<<endl;
	cout<<endl;
	cout<< "----------------Renaming function test-----------------------------------" <<endl;
	/*
	rename (aNumber, aSurname, aAge);  
	*/
	
	new_table1 = parser.e.get_table("Graduate");
	
	names = {"aNumber", "aSurname", "aAge"};

	//parser.e.renaming(names, new_table1);
	
	//REQUIRE(parser.e.all_tables[0].att[0].getName()== "aNumber");
	//REQUIRE(parser.e.all_tables[0].att[1].getName()== "aSurname");
	//REQUIRE(parser.e.all_tables[0].att[2].getName()== "aAge");
	


	cout<<endl;
	cout<<endl;
	cout<< "----------------Selection function test-----------------------------------" <<endl;
	

	cout<<endl;
	cout<<endl;
	cout<< "----------------Update function test-----------------------------------" <<endl;
	/*UPDATE animals SET name="Kim" WHERE name="Joe";*/
	
	new_table = parser.e.get_table("animals");
	
	REQUIRE(new_table.att[0].data[0]== "Kim");
	
	
	
	
}
