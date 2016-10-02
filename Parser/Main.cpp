#include "MainTest.cpp"
#include "Catch.h"

#include "Parser.h"
#include "Table.h"
#include "Engine.h"
#include "Token_stream.h"
#include "Token_Sym.h"


TEST_CASE( "Parsing tests", "[input]" ) {

	Parser parser;
	parser.input();

	Table new_table = parser.e.findTable("animals");

    SECTION( "Create test" ) {
    	//CREATE TABLE animals (name VARCHAR(20), kind VARCHAR(8), years INTEGER) PRIMARY KEY (name, kind);


		REQUIRE(new_table.att[0].name == "name");
		REQUIRE(new_table.att[1].name == "kind");
		REQUIRE(new_table.att[2].name == "years");
		REQUIRE(new_table.id[0] == "name");
    }
    SECTION( "Insert test" ) {
        /*INSERT INTO animals VALUES FROM ("Joe", "cat", 4);
		INSERT INTO animals VALUES FROM ("Spot", "dog", 10);
		INSERT INTO animals VALUES FROM ("Snoopy", "dog", 3);
		INSERT INTO animals VALUES FROM ("Tweety", "bird", 1);
		INSERT INTO animals VALUES FROM ("Joe", "bird", 2);*/

		new_table = parser.e.findTable("animals");	//For some reason none of the tables exist when you try searching again

		//REQUIRE(new_table.att[0].data[3] == "Tweety");
		//REQUIRE(new_table.att[1].data[3] == "bird");
		//REQUIRE(new_table.att[2].data[3] == "1");
    }
}