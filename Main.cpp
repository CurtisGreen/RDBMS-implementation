#include "MainTest.cpp"
#include "Catch.h"

#include <vector>
#include <string>
#include <iostream>

#include "Table.h"
#include "Attribute.h"
#include "Engine.h"


using namespace std; 




     //-----------------------------------------------------------------------
     //------------------Human Identity Table---------------------------------
     //-----------------------------------------------------------------------

	/*
	vector<string> name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
	vector<string> ocupataion = {"students","Proffesor","Boxer"};
	vector<string> weight = {"150","160","250"};
	vector<string> height = {"5","10","8"};

	Attribute att_human_name("Name","string",name);
	Attribute att_human_occupation("Ocupation","string",ocupataion );
	Attribute att_human_weight("Weight","string",weight);
	Attribute att_human_height("Name","string",height);

	vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};

	vector<Attribute> human_attributes;

	human_attributes.push_back(att_human_name);
	human_attributes.push_back(att_human_occupation);
	human_attributes.push_back(att_human_weight);
	human_attributes.push_back(att_human_height);

	Table human_table("Human",human_attributes,key_name);//crates table 

      //-----------------------------------------------------------------------
      //-----------------Hero Indentity Table----------------------------------
      //-----------------------------------------------------------------------
	vector<string> h_name = {"Spider Man","Super Man","Hulk"};
	vector<string> h_ability = {"Strenght","Fly","Strenght"};
	vector<string> h_weight = {"150","160","250"};
	vector<string> h_height = {"5","10","8"};

	Attribute att_hero_name("Name","string",h_name);
	Attribute att_hero_ability("Ability","string",h_ability );
	Attribute att_hero_weight("Weight","string",h_weight);
	Attribute att_hero_height("Name","string",h_height);

	vector<string> key_hero = {"Spider Man","Super Man","Hulk"};

	vector<Attribute> hero_attributes;

	hero_attributes.push_back(att_hero_name);
	hero_attributes.push_back(att_hero_ability);
	hero_attributes.push_back(att_hero_weight);
	hero_attributes.push_back(att_hero_height);

	Table hero_table("Hero",hero_attributes,key_hero);//creates table 


      //-----------------------------------------------------------------------
      //-------------Group Affiliation Table------------------------------------ 
      //-----------------------------------------------------------------------
	vector<string> universe = {"Earth","Mars","Earth"};
	vector<string> group_purpose = {"life saver","life saver","life saver"};
	vector<string> group_gname = {"Marvel","DC","Marvel"};

	Attribute att_universe("Uiverse","string", universe);
	Attribute  att_purpose("Purpose","string", group_purpose);
	Attribute att_group_name("Uiverse","string", group_gname);

	vector<string> key_affiliation = {"Marvel","DC","Marvel"};

	vector<Attribute> affiliatin_attibutes;

	affiliatin_attibutes.push_back(att_universe);
	affiliatin_attibutes.push_back(att_purpose);
	affiliatin_attibutes.push_back(att_purpose);
	
	Table affiliation_table("Affiliation",affiliatin_attibutes,key_affiliation);//crates table 


       //-----------------------------------------------------------------------
       //-------------Drop Function Taest--------------------------------------
       //-----------------------------------------------------------------------
	cout << "Drop Function Test" << "\n";

	
	TEST_CASE("Drop") 
	{
		Engine e;
		
		vector<string> h_name = {"Spider Man","Super Man","Hulk"};
		vector<string> h_ability = {"Strenght","Fly","Strenght"};
		vector<string> h_weight = {"150","160","250"};
		vector<string> h_height = {"5","10","8"};

		Attribute att_hero_name("Name","string",h_name);
		Attribute att_hero_ability("Ability","string",h_ability );
		Attribute att_hero_weight("Weight","string",h_weight);
		Attribute att_hero_height("Name","string",h_height);

		vector<string> key_hero = {"Spider Man","Super Man","Hulk"};

		vector<Attribute> hero_attributes;

		hero_attributes.push_back(att_hero_name);
		hero_attributes.push_back(att_hero_ability);
		hero_attributes.push_back(att_hero_weight);
		hero_attributes.push_back(att_hero_height);

		Table hero_table("Hero",hero_attributes,key_hero);
		
		vector<string> h_name = {"Spider Man","Super Man","Hulk"};
		vector<string> h_ability = {"Strenght","Fly","Strenght"};
		vector<string> h_weight = {"150","160","250"};
		vector<string> h_height = {"5","10","8"};

		Attribute att_hero_name("Name","string",h_name);
		Attribute att_hero_ability("Ability","string",h_ability );
		Attribute att_hero_weight("Weight","string",h_weight);
		Attribute att_hero_height("Name","string",h_height);

		vector<string> key_hero = {"Spider Man","Super Man","Hulk"};

		vector<Attribute> hero_attributes;

		hero_attributes.push_back(att_hero_name);
		hero_attributes.push_back(att_hero_ability);
		hero_attributes.push_back(att_hero_weight);
		hero_attributes.push_back(att_hero_height);

		Table human_table("Human",hero_attributes,key_hero);
		
		vector<string> h_name = {"Spider Man","Super Man","Hulk"};
		vector<string> h_ability = {"Strenght","Fly","Strenght"};
		vector<string> h_weight = {"150","160","250"};
		vector<string> h_height = {"5","10","8"};

		Attribute att_hero_name("Name","string",h_name);
		Attribute att_hero_ability("Ability","string",h_ability );
		Attribute att_hero_weight("Weight","string",h_weight);
		Attribute att_hero_height("Name","string",h_height);

		vector<string> key_hero = {"Spider Man","Super Man","Hulk"};

		vector<Attribute> hero_attributes;

		hero_attributes.push_back(att_hero_name);
		hero_attributes.push_back(att_hero_ability);
		hero_attributes.push_back(att_hero_weight);
		hero_attributes.push_back(att_hero_height);

		Table happy_table("Happy",hero_attributes,key_hero);
		
		all_tables.push_back(hero_table);
		
		all_tables.push_back(human_table);
		
		all_tables.push_back(happy_table);
		
		e.drop("Happy");
		

		REQUIRE(all_tables[0].name) == "Hero");
		REQUIRE(all_tables[1].name) == "Human");
		REQUIRE(all_tables[2].name) == 0);	
	}

	//-----------------------------------------------------------------------
	//---------------------Show Test----------------------------------------
	//-----------------------------------------------------------------------
	cout << endl;
	cout << "Show test:"<< endl;
	e.show("Human");
	cout << "\n" << endl;
	e.show("Hero");
	cout << "\n" << endl;
	e.show("Affiliation");
	
      //-----------------------------------------------------------------------
     //----------------------------Update function test -----------------------
     //-----------------------------------------------------------------------
	     e.update ("Human identity", "Name", "Peter Parker", "Eunsu Kim");
	     e.show ("Human identity");
		     
	 //------------------------------------------------------------------------
	 //----------------------------Destroy function test ----------------------
	 //-----------------------------------------------------------------------
	     e.destroy("Human identity",1);
	     e.show ("Human identity");

	//-----------------------------------------------------------------------
	//---------------------Insert Test---------------------------------------
	//-----------------------------------------------------------------------
	cout << "\n\n" << endl;
	cout << "Insert test:"<< endl;
	vector <string> insert_test = {"test_name", "test_ability", "test_weight", "test_height"};
	e.insert("Hero", insert_test);
	e.show("Hero");

	//------------------------------------------------------------------------
	//----------------------------Write function test -----------------------
	//-----------------------------------------------------------------------
	
	cout << "\n Write function Test:" << "\n";
	
	TEST_CASE("Write") 
	{
		Engine e;
		
		vector<string> new_names = {"love","happiness"};
	
		vector<string> weight_ = {"150","160","250"};
		vector<string> height_ = {"5","10","8"};
	
		Attribute human_weight("Weight","string",weight_);
		Attribute human_height("Height","string",height_);
	
		vector<Attribute> human_atts;
	
		human_atts.push_back(human_weight);
		human_atts.push_back(human_height);
		
		vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
	
		Table human("human table", human_atts, key_name);
	
	
		e.all_tables.push_back(human);
		e.write(humans);
		
	
		REQUIRE(e.write(humans) == "Table not found, cannot insert");	
		REQUIRE(e.write(human) == human.db);	
	}
*/
        //------------------------------------------------------------------------
	//----------------------------Selection function test --------------------
	//-----------------------------------------------------------------------
	 
	// e.selection( "Human identity", "Name");
	  
	

	//------------------------------------------------------------------------
	//----------------------------Rename function test -----------------------
	//-----------------------------------------------------------------------
/*
	
	cout << "Rename function" << endl;
	
	TEST_CASE("Renaming") 
	{
		Engine e;
		
		vector<string> new_names = {"love","happiness"};
	
		vector<string> weight_ = {"150","160","250"};
		vector<string> height_ = {"5","10","8"};
	
		Attribute human_weight("Weight","string",weight_);
		Attribute human_height("Height","string",height_);
	
		vector<Attribute> human_atts;
	
		human_atts.push_back(human_weight);
		human_atts.push_back(human_height);
		vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
	
		Table human("human table", human_atts, key_name);
	
	
		e.all_tables.push_back(human);
		
		e.renaming(Weight", "Love", "human table");
		e.renaming(Height", "Peace", "human table");
		
	
		REQUIRE(human_table.att[0].getName() == "Love");
		REQUIRE(human_table.att[1].getName() == "Peace")
	}

	*/
	


	//-------------------------------------------------------------------------
	//----------------------------Projection function test --------------------
	//-------------------------------------------------------------------------
	
	/*
	cout << "Projection Test" << endl;
	
	TEST_CASE("Projection") 
	{
		Engine e;
		
		vector<string> new_names = {"love","happiness"};
	
		vector<string> weight_ = {"150","160","250"};
		vector<string> height_ = {"5","10","8"};
	
		Attribute human_weight("Weight","string",weight_);
		Attribute human_height("Height","string",height_);
	
		vector<Attribute> human_atts;
	
		human_atts.push_back(human_weight);
		human_atts.push_back(human_height);
		vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
	
		Table human("human table", human_atts, key_name);
		
		vector <string> temps = {"Weight", "Height", "Size"};
		
		Table new_table = e.projection(temps,"human table);
		
		REQUIRE(new_table.att[0].getName() == "Weight" );
		REQUIRE(new_table.att[1].getName() == "Height" );
	}
	
	//-------------------------------------------------------------------------
	//----------------------------Open function test -------------------------
	//-------------------------------------------------------------------------
	
	
	cout << "Open test" << endl;
	TEST_CASE("Open") 
	{
		Engine e;
		
		vector<string> new_names = {"love","happiness"};
	
		vector<string> weight_ = {"150","160","250"};
		vector<string> height_ = {"5","10","8"};
	
		Attribute human_weight("Weight","string",weight_);
		Attribute human_height("Height","string",height_);
	
		vector<Attribute> human_atts;
	
		human_atts.push_back(human_weight);
		human_atts.push_back(human_height);
		vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
	
		Table human("human table", human_atts, key_name);
	
	
		e.all_tables.push_back(human);
		
		e.write(human);
		
	
		REQUIRE(e.open("human table") == "Error: Table is already open");	
		REQUIRE(e.open("humans table") == "Error: Could not open file");	
	}
	
	manager_att.push_back(m_number);
	manager_att.push_back(m_surname);
	manager_att.push_back(m_age);


	Table t1("Gradutate",graduate_att,key_name);
	Table t2("Manager",manager_att,key_name);

	vector<string> r = e.rtn_Row(t1,0);

	
	for(int i = 0; i<r.size(); i++){
		cout<<r[i]<<" ";
	}

	 //-------------------------------------------------------------------------
	//----------------------------Read function test --------------------------
	//-------------------------------------------------------------------------
	/*cout << "Read test " << endl;
	
	//e.write(g);
	e.read("Graduate");
	
	//cout << e.all_tables.size();

   	e.show("Graduate");*/
   	
   	//-------------------------------------------------------------------------
	//----------------------------Difference function test ---------------------
	//-------------------------------------------------------------------------
	
   	TEST_CASE( "Difference between two tables", "[difference]" ) {

	Engine e;

	//Graduate Table 
	 vector<string> number = {"7274","7432","9894"};
	vector<string> surname = {"Robinson","O'Malley","Darkes"};
	vector<string> age = {"37","39","38"};
	
	Attribute g_number("Number","Integer",number);
	Attribute g_surname("Surname","string",surname);
	Attribute g_age("Age","Integer",age);

	vector<string> key_name = {"1","2","3","4"};
	vector<Attribute> graduate_att;
	graduate_att.push_back(g_number);
	graduate_att.push_back(g_surname);
	graduate_att.push_back(g_age);

	//Manager Table
	vector<string> number2 = {"9297","7432","9894",};
	vector<string> surname2 = {"O'Malley","O'Malley","Darkes"};
	vector<string> age2 = {"56","39","38",};
	
	Attribute m_number("Number","Integer",number2);
	Attribute m_surname("Surname","string",surname2 );
	Attribute m_age("Age","Integer",age2);
	
	vector<Attribute> manager_att;
	manager_att.push_back(m_number);
	manager_att.push_back(m_surname);
	manager_att.push_back(m_age);
	
	Table g("Graduate", graduate_att, key_name);
	Table m("Manager", manager_att, key_name);

	e.all_tables.push_back(g);
	e.all_tables.push_back(m);
	e.all_tables.push_back(e.difference(g,m));
	e.show("Graduate-Manager");




	vector<string> test_values;
	for(int i = 0; i < e.difference(g,m).att.size(); i++){
		test_values.push_back(e.difference(g,m).att[i].data[0]);
	}
		
	//////////----------Require outputs to be correct------------/////////
		
	REQUIRE( test_values[0] == "7274" );
	REQUIRE( test_values[1] == "Robinson" );
	REQUIRE( test_values[2] == "37" );


}

	//-----------------------------------------------------------------------
	//----------------------------Union function test ----------------------
	//-----------------------------------------------------------------------

	TEST_CASE( "Union between two tables", "[Union]" ) {

	Engine e;

	//Graduate Table 
    	vector<string> number = {"7274","7432","9894"};
	vector<string> surname = {"Robinson","O'Malley","Darkes"};
	vector<string> age = {"37","39","38"};
	
	Attribute g_number("Number","Integer",number);
	Attribute g_surname("Surname","string",surname);
	Attribute g_age("Age","Integer",age);

	vector<string> key_name = {"1","2","3","4"};
	vector<Attribute> graduate_att;
	graduate_att.push_back(g_number);
	graduate_att.push_back(g_surname);
	graduate_att.push_back(g_age);

	//Manager Table
	vector<string> number2 = {"9297","7432","9894",};
	vector<string> surname2 = {"O'Malley","O'Malley","Darkes"};
	vector<string> age2 = {"56","39","38",};
	
	Attribute m_number("Number","Integer",number2);
	Attribute m_surname("Surname","string",surname2 );
	Attribute m_age("Age","Integer",age2);
	
	vector<Attribute> manager_att;
	manager_att.push_back(m_number);
	manager_att.push_back(m_surname);
	manager_att.push_back(m_age);
	
	Table g("Graduate", graduate_att, key_name);
	Table m("Manager", manager_att, key_name);

	e.all_tables.push_back(g);
	e.all_tables.push_back(m);
	e.all_tables.push_back(e.set_union("none",g,m));

	e.show("Graduate U Manager");

	vector<string> test_values;
	for(int i = 0; i < e.set_union("none",g,m).att.size(); i++){
		test_values.push_back(e.set_union("none",g,m).att[i].data[0]);
	}
		
	//////////----------Require outputs to be correct------------/////////
		
	REQUIRE( test_values[0] == "7274" );
	REQUIRE( test_values[1] == "Robinson" );
	REQUIRE( test_values[2] == "37" );


}

   /*
	unsigned int Factorial( unsigned int number ) {	//Test example 1
	  return number > 1 ? Factorial(number-1)*number : 1;
	}

	TEST_CASE( "Factorials are computed", "[factorial]" ) {	//Test example 1
	    REQUIRE( Factorial(0) == 1 );
	    REQUIRE( Factorial(1) == 1 );
	    REQUIRE( Factorial(2) == 2 );
	    REQUIRE( Factorial(3) == 6 );
	    REQUIRE( Factorial(10) == 3628800 );
	}
	//--------------------------------------------------------------------------------
	//-----------------Cross product test ---EXAMPLE ---------------------------------//
	//---------------------------------------------------------------------------------

	//Should look like this: https://www.tutorialspoint.com/sql/sql-cartesian-joins.htm
	
	TEST_CASE( "Cross product between 2 tables", "[cross_product]" ) {
		Engine e; 
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

		vector<string> cross_key = {"id", "name", "amount", "date"};

		Table cross_product1;
		cross_product1.att = cross_att1;
		Table cross_product2;
		cross_product2.att = cross_att2;
		Table cross_product_out = e.cross_product(cross_product1,cross_product2,cross_key);
		e.show(cross_product1.name + "*" + cross_product2.name);


		vector<string> test_values;
		for(int i = 0; i < cross_product_out.att.size(); i++){
			test_values.push_back(cross_product_out.att[i].data[0]);
		}
		

		//////////----------Require outputs to be correct------------/////////
		
		REQUIRE( test_values[0] == "1" );
		REQUIRE( test_values[1] == "Ramesh" );
		REQUIRE( test_values[2] == "3000" );
		REQUIRE( test_values[3] == "2009-10" );
	}
	*/

