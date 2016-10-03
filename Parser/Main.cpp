#include "MainTest.cpp"
#include "Catch.h"

#include "Parser.h"
#include "Table.h"
#include "Engine.h"
#include "Token_stream.h"
#include "Token_Sym.h"


TEST_CASE("Parser test", "[Parser]") {


	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Insert function test-----------------------------------" <<endl;
	/*
	CREATE TABLE animals (name VARCHAR(20), kind VARCHAR(8), years INTEGER) PRIMARY KEY (name, kind);
	INSERT INTO animals VALUES FROM ("Joe", "cat", 4);
	INSERT INTO animals VALUES FROM ("Spot", "dog", 10);
	INSERT INTO animals VALUES FROM ("Snoopy", "dog", 3);
	INSERT INTO animals VALUES FROM ("Tweety", "bird", 1);
	INSERT INTO animals VALUES FROM ("Joe", "bird", 2);
	*/
	
	Table new_table = parser.e.findTable("animals");
	REQUIRE(new_table.att[0].data[3] == "Kim");
	REQUIRE(new_table.att[1].data[3] == "bird");
	REQUIRE(new_table.att[2].data[3] == "2");
}


TEST_CASE("Create_test", "[create]") {

	Parser parser;
	parser.input();
	

	cout<<endl;
	cout<<endl;
	cout<< "----------------Create function test-----------------------------------" <<endl;
	/*
	CREATE TABLE animals (name VARCHAR(20), kind VARCHAR(8), years INTEGER) PRIMARY KEY (name, kind);
	CREATE TABLE dogs (name VARCHAR(20), kind VARCHAR(8), years INTEGER) PRIMARY KEY (name, kind);
	CREATE TABLE cats (name VARCHAR(20), kind VARCHAR(8), years INTEGER) PRIMARY KEY (name, kind);
	*/

	cout << parser.e.all_tables.size() << endl;
	
	Table new_table1 = parser.e.getTable("animals");
	parser.e.all_tables.push_back(new_table1);
	
	Table new_table2 = parser.e.getTable("dogs");
	parser.e.all_tables.push_back(new_table2);
	
	Table new_table3 = parser.e.getTable("cats");
	parser.e.all_tables.push_back(new_table3);
	
	cout << parser.e.all_tables.size() << endl;
	
	REQUIRE(new_table1.getName() == "animals");
	REQUIRE(new_table2.getName() == "dogs");
	REQUIRE(new_table3.getName() == "cats");
	
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

	
	Table new_table2 = parser.e.getTable("Manager");
	parser.e.all_tables.push_back(new_table2);
	
	Table union_table = parser.e.set_union(new_table1,new_table2);
	parser.e.all_tables.push_back(union_table);
	


	Table union_table1 = parser.e.getTable(union_table.getName());
	parser.e.show(union_table.getName());
	
	cout << parser.e.all_tables.size() << endl;

	
	REQUIRE(parser.e.all_tables[0].getName()== "Graduate");
	REQUIRE(parser.e.all_tables[1].getName()== "Manager");
	REQUIRE(parser.e.all_tables[2].getName()== "Name");
	REQUIRE(parser.e.all_tables.size()== 3);
	REQUIRE(union_table.getName()== "Name");
	REQUIRE(union_table.att.size()== 0);
	
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
	
	

	REQUIRE(parser.e.all_tables[0].getName()== "Graduate");
	REQUIRE(parser.e.all_tables[1].getName()== "Manager");
	REQUIRE(parser.e.all_tables[2].getName()== "Name");
	REQUIRE(parser.e.all_tables.size()== 3);
	REQUIRE(difference_table.getName()== "Name");
	REQUIRE(difference_table.att.size()== 0);

}


TEST_CASE("Product_test", "[product]") {

	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Product function test-----------------------------------" <<endl;
	
}
TEST_CASE("Natural_test", "[naturaljoin]") {

	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Natural join function test-----------------------------------" <<endl;
	
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
	
}
TEST_CASE("Renaming_test", "[renaming]") {

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
	rename (aNumber, aSurname, aAge);  
	*/
	
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
