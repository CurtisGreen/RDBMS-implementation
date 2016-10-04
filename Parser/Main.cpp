
#include "MainTest.cpp"
#include "Catch.h"

#include "Parser.h"
#include "Table.h"
#include "Engine.h"
#include "Token_stream.h"


TEST_CASE("Parser test", "[Parser]") {


	Parser parser;
	parser.input();

	vector<string> cross_id = {"1","2","3","4","5","6","7"};
    vector<string> cross_name = {"Ramesh", "khilan", "kaushik", "chaitali", "hardik", "komal", "muff"};
    vector<string> cross_age = {"32", "25", "23", "25", "27", "22", "24"};
    vector<string> address = {"Ahmedabad", "Delhi", "kota", "mumbai", "bhopal", "mp", "indore"};
    vector<string> salary = {"2000", "1500", "2000", "6500", "8500", "4500", "10000"};
    vector<string> oid = {"102", "100", "101", "103"};
    vector<string> date = {"2009-10", "2009-10", "2009-11", "2008-05"};
    vector<string> customer_id = {"3", "3", "2", "4"};
    vector<string> amount = {"3000", "1500", "1560", "2060"};
    
    Attribute CrossId("id", "int", cross_id);
    Attribute CrossName("name", "string", cross_name);
    Attribute CrossAge("age", "int", cross_age);
    Attribute Address("address", "string", address);
    Attribute Salary("salary", "int", salary);
    Attribute Oid("oid", "int", oid);
    Attribute Date("date", "int", date);
    Attribute Customer_id("customer_id", "int", customer_id);
    Attribute Amount("amount", "int", amount);
    
    vector<Attribute> cross_att1= {CrossId, CrossName, CrossAge, Address, Salary};
    vector<Attribute> cross_att2 = {Oid, Date, Customer_id, Amount};
    
    vector<string> cross_key = {"id" ,"name", "amount", "date"};
    
    Table cross_product1;
    cross_product1.att = cross_att1;
    Table cross_product2;
    cross_product2.att = cross_att2;
    Table cross_product_out = parser.e.cross_product(cross_product1,cross_product2);
    parser.e.show(cross_product1.name + "*" + cross_product2.name);\
	
	
	//Working on cross product^^^^^
    
    //vector<string> relations = {"", ""};
    //Table t1 = e.getTable(rel_name_1);
    //Table t2 = e.getTable(rel_name_2);
    //Table new_table = e.cross_product(t1,t2);
	
	//parser.e.cross_product(table1, table2);
	
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
	
	Table new_table = parser.e.getTable("Graduate");
	
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

	
	Table new_table1 = parser.e.getTable("Graduate");
	Table new_table2 = parser.e.getTable("Manager");
	
	
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
	
	
	new_table1 = parser.e.getTable("Graduate");

	parser.e.show(new_table1.getName());
	new_table2 = parser.e.getTable("Manager");
	
	Table union_table = parser.e.set_union(new_table1,new_table2);
	parser.e.all_tables.push_back(union_table);
	
	Table u_table = parser.e.getTable(union_table.getName());
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
	new_table1 = parser.e.getTable("Graduate");

	new_table2 = parser.e.getTable("Manager");
	
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
	
	//new_table1 = parser.e.getTable("Graduate");

	//new_table2 = parser.e.getTable("Manager");
	
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
	
	/*new_table1 = parser.e.getTable("Graduate");

	
	new_table2 = parser.e.getTable("Manager");
	
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
	
	new_table1 = parser.e.getTable("Graduate");
	
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
	
	new_table1 = parser.e.getTable("Graduate");
	
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
	
	new_table = parser.e.getTable("animals");
	
	REQUIRE(new_table.att[0].data[0]== "Kim");
	
	
	
	
}
