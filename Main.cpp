
#include "Catch.h"

#include <vector>
#include <string>
#include <iostream>

#include "Table.h"
#include "Attribute.h"
#include "Engine.h"


using namespace std; 

//Testing compilation


/*
    vector<string> name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
    vector<string> ocupataion = {"students","Proffesor","Boxer"};
    vector<string> weight = {"150","160","250"};
    vector<string> height = {"5","10","8"};
    
    Attribute att_human_name("Name","string",name);
    Attribute att_human_occupation("Ocupation","string",ocupataion );
    Attribute att_human_weight("Weight","string",weight);
    Attribute att_human_height("Height","string",height);
    
    vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
    
    vector<Attribute> human_attributes;
    
    human_attributes.push_back(att_human_name);
    human_attributes.push_back(att_human_occupation);
    human_attributes.push_back(att_human_weight);
    human_attributes.push_back(att_human_height);
    
    
    
    Engine e;
    e.create ("Human identity", human_attributes,key_name);
   
    e.show("Human identity");
*/


///was commented because I was testing diference(Table,Table),Jose

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


	//-------------------------Test to see if drop table works --------------------------------//
	cout << "Pushing back tables" << "\n";
	
	e.all_tables.push_back(human_table);
	e.all_tables.push_back(hero_table);
	e.all_tables.push_back(affiliation_table);
	
	cout << "Done pushing" << "\n" ;
	

	int size1 = e.all_tables.size(); 

	cout << size1 << "\n";

	//int size1 = e.all_tables.size();
	 
	cout << "Dropping a table\n";
	cout << "Number of tables = " <<size1<<endl;

	
	//e.drop("Human");
	
	cout << "Dropped " << "\n" ;
	
	int size2 = e.all_tables.size();

	
	cout << size2 << "\n";
	//------------------------------UNION CHECKING : BEGINNING CONDITIONS CHECK ----------------------------------------------------------//
	
	

	vector<string> weight_ = {"150","160","250"};
	vector<string> height_ = {"5","10","8"};
	
	Attribute human_weight("Weight","string",weight_);
	Attribute human_height("Name","string",height_);
	
	vector<Attribute> human_atts;
	human_atts.push_back(human_weight);
	human_atts.push_back(human_height);
	
	Table human("human table", human_atts, key_name);
	
	vector<string> h_weight_ = {"150","160","250"};
	vector<string> h_height_ = {"5","10","8"};
	
	Attribute hero_weight("Weight","string",h_weight_);
	Attribute hero_height("Name","string",h_height_);
	
	vector<Attribute> hero_atts;
	hero_atts.push_back(hero_weight);
	hero_atts.push_back(hero_height);

	Table hero("hero table", hero_atts, key_hero);
	
	e.all_tables.push_back(hero);
	e.all_tables.push_back(human);
	e.set_union("height", human, hero);
	
	// table.create("SuperHero", "test_attribute",  );

	cout << "Number of tables = "<< size2<<endl;

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
	//---------------------Create test----------------------------------------
	//-----------------------------------------------------------------------
	
	// TODO: table.create("SuperHero", "test_attribute", ... );
	
	//------------------------------------------------------------------------
     //----------------------------Update function test -----------------------
     //-----------------------------------------------------------------------
     e.update ("Human identity", "Name", "Peter Parker", "Eunsu Kim");
     e.show ("Human identity");
     
//------------------------------------------------------------------------
     //----------------------------Destroy function test -----------------------
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
	
	cout << "\n Writing Test:" << "\n";
	e.write(human_table);
	

	//------------------------------------------------------------------------
	//----------------------------Open function test -----------------------
	//-----------------------------------------------------------------------
	cout << "\n Open Test:" << "\n";
	e.open("Human");
	//TODO: tests regarding engine functions
	

	
	//------------------------------------------------------------------------
	//----------------------------Open function test -----------------------
	//-----------------------------------------------------------------------
	cout << "\n Open Test:" << "\n";
	e.open("Human");
	//TODO: tests regarding engine functions


	//------------------Testing difference with a new tables ------------------------------------
	//This table is from a webiste it show the corret result after checking for difference of two table
	//

	vector<string> tuple_1g = {"7274","Robinson","37"};
	vector<string> tuple_2g = {"7432","O'Malley","39"};
	vector<string> tuple_3g = {"9824","Darkes","38"};

	//TUPLE
	Attribute t_1g(tuple_1g);
	Attribute t_2g(tuple_2g );
	Attribute t_3g(tuple_3g);

	vector<Attribute> g_att;

	g_att.push_back(t_1g);
	g_att.push_back(t_2g);
	g_att.push_back(t_3g);

	vector<string> tuple_1 = {"9297","O'Malley","56"};
	vector<string> tuple_2 = {"7432","O'Malley","39"};
	vector<string> tuple_3 = {"9824","Darkes","38"};

	//TUPLE
	Attribute t_1(tuple_1);
	Attribute t_2(tuple_2 );
	Attribute t_3(tuple_3);

	vector<Attribute> m_att;

	m_att.push_back(t_1);
	m_att.push_back(t_2);
	m_att.push_back(t_3);

	vector<string> key = {"1","2","3"};


	Table graduate_table("Graduate",g_att,key);
	Table manager_table("Manager",m_att,key);

	//e.all_tables.push_back(graduate_table);
	//e.all_tables.push_back(manager_table);
	//e.difference(graduate_table,manager_table);

	//e.set_union("Name" ,graduate_table,manager_table);

//-----------------------------------------------------------------
//-----------------------------------------------------------------


*/
    //------------------------------------------------------------------------
	//----------------------------DIFFERENCE & UNION TEST -----------------------
	//----------------------------------------------------------------------- 
	//Graduate table
    /*vector<string> number = {"7274","7432","9894","5555"};
	vector<string> surname = {"Robinson","O'Malley","Darkes","Mario"};
	vector<string> age = {"37","39","38","89"};
	vector<string> parent = {"Yes","Yes","No","No"};
	Attribute g_number("Number","Integer",number);
	Attribute g_surname("Surname","string",surname);
	Attribute g_age("Age","Integer",age);
	Attribute g_parent("Parent","String",parent);

	vector<string> key_name = {"1","2","3","4"};
	vector<Attribute> graduate_att;
	graduate_att.push_back(g_number);
	graduate_att.push_back(g_surname);
	graduate_att.push_back(g_age);
	graduate_att.push_back(g_parent);

	
	//Manager Table
	vector<string> number2 = {"9297","7432","9894","3333","111"};
	vector<string> surname2 = {"O'Malley","O'Malley","Darkes","Jose","Daniel"};
	vector<string> age2 = {"56","39","38","56","22"};
	vector<string> parent2 = {"Yes","Yes","No","No","yes"};

	Attribute m_number("Number","Integer",number2);
	Attribute m_surname("Surname","string",surname2 );
	Attribute m_age("Age","Integer",age2);
	Attribute m_parent("Parent","String",parent2);
	vector<Attribute> manager_att;
	manager_att.push_back(m_number);
	manager_att.push_back(m_surname);
	manager_att.push_back(m_age);
	manager_att.push_back(m_parent); 


	Table g("Graduate", graduate_att, key_name);
	Table m("Manager", manager_att, key_name);*/

	//e.all_tables.push_back(g);
	//e.all_tables.push_back(m);
	
	//e.all_tables.push_back(e.difference(g,m));
	//e.all_tables.push_back(e.set_union("d",g,m));


	//e.show("Graduate-Manager");
	//e.show("Graduate U Manager");
	//------------------------------------------------------------------------
//----------------------------Selection function test -----------------------
//-----------------------------------------------------------------------
 /*
 e.selection( "Human identity", "Name");
  
*/

	//------------------------------------------------------------------------
	//----------------------------Rename function test -----------------------
	//-----------------------------------------------------------------------
	/*
	
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

*/
	
	//----------------------------PROJECTION TEST----------------------------------
	
	/*
	cout << "Projection Test" << "\n";
	vector<string> names__ = {"Weight", "Love"};
	e. projection(names__, "human table");
	//e. projection(names__, "human tabl");
	
	//----------------------------PROJECTION TEST----------------------------------
	
	cout << "OPEN test" << endl;
	
	e.write(human);
	e.open("human table");
	
	
	
	manager_att.push_back(m_number);
	manager_att.push_back(m_surname);
	manager_att.push_back(m_age);


	Table t1("Gradutate",graduate_att,key_name);
	Table t2("Manager",manager_att,key_name);

	vector<string> r = e.rtn_Row(t1,0);

	
	for(int i = 0; i<r.size(); i++){
		cout<<r[i]<<" ";
	}

 	
	*/
	// cout << "RENAME TEST\n" ;
	
	
	// e.renaming("Weight", "love","human table");
	
	// cout << "MADE IT HERE \n";
	
	// e.show("human table");
	
	
	
	//----------------------------------------READ TEST-----------------------/
	/*cout << "Read test " << endl;
	
	//e.write(g);
	e.read("Graduate");
	
	//cout << e.all_tables.size();

   e.show("Graduate");*/


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
	////////////////////////////////////////////////////////////////////////
	//-----------------Cross product test---------------------------------//
	////////////////////////////////////////////////////////////////////////

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

	SCENARIO( "vectors can be sized and resized", "[vector]" ) {	//Test example 2

	    GIVEN( "A vector with some items" ) {
	        std::vector<int> v( 5 );

	        REQUIRE( v.size() == 5 );
	        REQUIRE( v.capacity() >= 5 );

	        WHEN( "the size is increased" ) {
	            v.resize( 10 );

	            THEN( "the size and capacity change" ) {
	                REQUIRE( v.size() == 10 );
	                REQUIRE( v.capacity() >= 10 );
	            }
	        }
	        WHEN( "the size is reduced" ) {
	            v.resize( 0 );

	            THEN( "the size changes but not capacity" ) {
	                REQUIRE( v.size() == 0 );
	                REQUIRE( v.capacity() >= 5 );
	            }
	        }
	        WHEN( "more capacity is reserved" ) {
	            v.reserve( 10 );

	            THEN( "the capacity changes but not the size" ) {
	                REQUIRE( v.size() == 5 );
	                REQUIRE( v.capacity() >= 10 );
	            }
	        }
	        WHEN( "less capacity is reserved" ) {
	            v.reserve( 0 );

	            THEN( "neither size nor capacity are changed" ) {
	                REQUIRE( v.size() == 5 );
	                REQUIRE( v.capacity() >= 5 );
	            }
	        }
	    }
	}

