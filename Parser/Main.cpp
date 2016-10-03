
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
	
	Table new_table = parser.e.findTable("Graduate");
	
	//REQUIRE(new_table.att[0].data[3] == "894");
	//REQUIRE(new_table.att[1].data[3] == "Darkes");
	//REQUIRE(new_table.att[2].data[3] == "38");
	
}


TEST_CASE("Create_test", "[create]") {

	Parser parser;
	parser.input();
	

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

	cout << parser.e.all_tables.size() << endl;
	
	Table new_table1 = parser.e.getTable("Graduate");
	parser.e.all_tables.push_back(new_table1);
	
	Table new_table2 = parser.e.getTable("Manager");
	parser.e.all_tables.push_back(new_table2);
	
	cout << parser.e.all_tables.size() << endl;
	
	REQUIRE(new_table1.getName() == "Graduate");
	REQUIRE(new_table2.getName() == "Manager");
	
	
}


TEST_CASE("Union_test", "[union]") {

	Parser parser;
	parser.input();

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
	
	
	Table new_table1 = parser.e.getTable("Graduate");
	parser.e.all_tables.push_back(new_table1);

	parser.e.show(new_table1.getName());
	
	Table new_table2 = parser.e.getTable("Manager");
	parser.e.all_tables.push_back(new_table2);
	
	Table union_table = parser.e.set_union(new_table1,new_table2);
	parser.e.all_tables.push_back(union_table);
	
	Table u_table = parser.e.findTable(union_table.getName());
	parser.e.show(u_table.getName());
	
	cout << parser.e.all_tables.size() << endl;
	parser.e.show(u_table.getName());

	
	REQUIRE(parser.e.all_tables[0].getName()== "Graduate");
	REQUIRE(parser.e.all_tables[1].getName()== "Manager");
	REQUIRE(parser.e.all_tables[2].getName()== "Name");
	REQUIRE(parser.e.all_tables.size() ==3);

}

TEST_CASE("Difference_test", "[difference]") {

	Parser parser;
	parser.input();

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
	Table new_table1 = parser.e.getTable("Graduate");
	parser.e.all_tables.push_back(new_table1);

	
	Table new_table2 = parser.e.getTable("Manager");
	parser.e.all_tables.push_back(new_table2);
	
	Table difference_table = parser.e.difference(new_table1,new_table2);
	parser.e.all_tables.push_back(difference_table);
	
	cout << parser.e.all_tables.size() << endl;
	parser.e.show(difference_table.getName());
	
	

	REQUIRE(parser.e.all_tables[0].getName()== "Graduate");
	REQUIRE(parser.e.all_tables[1].getName()== "Manager");
	REQUIRE(parser.e.all_tables[2].getName()== "Name");
	REQUIRE(parser.e.all_tables.size() ==3);

}


TEST_CASE("Product_test", "[product]") {

	Parser parser;
	parser.input();

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
	Table new_table1 = parser.e.getTable("Graduate");
	parser.e.all_tables.push_back(new_table1);

	
	Table new_table2 = parser.e.getTable("Manager");
	parser.e.all_tables.push_back(new_table2);
	
	Table p_table = parser.e.cross_product(new_table1,new_table2);
	parser.e.all_tables.push_back(p_table);
	
	cout << parser.e.all_tables.size() << endl;
	parser.e.show(p_table.getName());
	

	REQUIRE(parser.e.all_tables[0].getName()== "Graduate");
	REQUIRE(parser.e.all_tables[1].getName()== "Manager");
	REQUIRE(parser.e.all_tables[2].getName()== "Graduate*Manager");
	REQUIRE(parser.e.all_tables.size() ==4);
}
TEST_CASE("Natural_test", "[naturaljoin]") {

	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Natural join function test-----------------------------------" <<endl;
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
	Table new_table1 = parser.e.getTable("Graduate");
	parser.e.all_tables.push_back(new_table1);

	
	Table new_table2 = parser.e.getTable("Manager");
	parser.e.all_tables.push_back(new_table2);
	
	Table n_table = parser.e.natural_join(new_table1,new_table2);
	parser.e.all_tables.push_back(n_table);
	
	cout << parser.e.all_tables.size() << endl;
	parser.e.show(n_table.getName());
	

	REQUIRE(parser.e.all_tables[0].getName()== "Graduate");
	REQUIRE(parser.e.all_tables[1].getName()== "Manager");
	REQUIRE(parser.e.all_tables[2].getName()== "GraduateJOINManager");
	REQUIRE(parser.e.all_tables.size() ==4);
}
TEST_CASE("Projection_test", "[projection]") {

	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Projection_test function test-----------------------------------" <<endl;
	/*
	CREATE TABLE Graduate (Number INTEGER  Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	CREATE TABLE  Manager (Number INTEGER, Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	INSERT INTO Graduate VALUES FROM (7274,"Robinson",37);
	INSERT INTO Graduate VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Graduate VALUES FROM (9894,"Darkes",38);
	INSERT INTO Manager VALUES FROM (9297,"O'Malley",56);
	INSERT INTO Manager VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Manager VALUES FROM (9894,"Darkes",38);
	project (Number, Surname, Age);  
	*/
	
	Table new_table1 = parser.e.getTable("Graduate");
	parser.e.all_tables.push_back(new_table1);

	
	Table new_table2 = parser.e.getTable("Manager");
	parser.e.all_tables.push_back(new_table2);
	
	Table n_table = parser.e.natural_join(new_table1,new_table2);
	parser.e.all_tables.push_back(n_table);
	
	vector<string> names = {"Number", "Surname", "Age"};
	
	cout << parser.e.all_tables.size() << endl;
	parser.e.show(n_table.getName());
	parser.e.projection(names, new_table1.getName());
	
	//REQUIRE(parser.e.all_tables[0].att[0].getName()== "Number");
	//REQUIRE(parser.e.all_tables[0].att[1].getName()== "Surname");
	//REQUIRE(parser.e.all_tables[0].att[2].getName()== "Age");
	
	
}
TEST_CASE("Renaming_test", "[renaming]") {

	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Renaming function test-----------------------------------" <<endl;
	/*
	CREATE TABLE Graduate (Number INTEGER  Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	CREATE TABLE  Manager (Number INTEGER, Surname VARCHAR(8), Age INTEGER) PRIMARY KEY (Number, Surname);
	INSERT INTO Graduate VALUES FROM (7274,"Robinson",37);
	INSERT INTO Graduate VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Graduate VALUES FROM (9894,"Darkes",38);
	INSERT INTO Manager VALUES FROM (9297,"O'Malley",56);
	INSERT INTO Manager VALUES FROM (7432,"O'Malley",39);
	INSERT INTO Manager VALUES FROM (9894,"Darkes",38);
	rename (aNumber, aSurname, aAge);  
	*/
	
	Table new_table1 = parser.e.getTable("Graduate");
	parser.e.all_tables.push_back(new_table1);

	
	Table new_table2 = parser.e.getTable("Manager");
	parser.e.all_tables.push_back(new_table2);
	
	
	vector<string> names = {"aNumber", "aSurname", "aAge"};
	
	cout << parser.e.all_tables.size() << endl;

	//parser.e.renaming(names, new_table1.getName());
	
	//REQUIRE(parser.e.all_tables[0].att[0].getName()== "aNumber");
	//REQUIRE(parser.e.all_tables[0].att[1].getName()== "aSurname");
	//REQUIRE(parser.e.all_tables[0].att[2].getName()== "aAge");
	
	
}

TEST_CASE("Selection_test", "[selection]") {

	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Selection function test-----------------------------------" <<endl;
	
}
TEST_CASE("Update_test", "[update]") {

	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Update function test-----------------------------------" <<endl;
	
}
