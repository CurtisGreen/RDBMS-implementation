

#include "Parser.h"
#include "Table.h"
#include "Engine.h"
#include "Token_stream.h"
#include "Token_Sym.h"


/*
TEST_CASE("Insert_test", "[insert]") {

	cout << "================================================================"<< endl;
	cout << "==================Parser Test==================================="<< endl;

	Parser parser;
	parser.input();

	cout<<endl;
	cout<<endl;
	cout<< "----------------Insert function test-----------------------------------" <<endl;
	/*INSERT INTO animals VALUES FROM ("Joe", "cat", 4);
	INSERT INTO animals VALUES FROM ("Spot", "dog", 10);
	INSERT INTO animals VALUES FROM ("Snoopy", "dog", 3);
	INSERT INTO animals VALUES FROM ("Tweety", "bird", 1);
	INSERT INTO animals VALUES FROM ("Joe", "bird", 2);*/
/*
	Table new_table = parser.e.findTable("animals");

	REQUIRE(new_table.att[0].data[3] == "Tweety");
	REQUIRE(new_table.att[1].data[3] == "bird");
	REQUIRE(new_table.att[2].data[3] == "1");
}
*/
int main()
{
	Parser p;
	p.initial();
}




