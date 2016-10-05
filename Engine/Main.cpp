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
	//---------------------Create Test---------------------------------------
	//-----------------------------------------------------------------------

	TEST_CASE("Show", "[Show]") {

		cout<<endl;
		cout<<endl;
		cout<< "----------------Show function test-----------------------------------" <<endl;
		
		Engine e;
		
		vector<string> h_name = {"Spider Man","Super Man","Hulk"};
		vector<string> h_ability = {"Strenght","Fly","Strenght"};
		vector<string> h_weight = {"150","160","250"};
		vector<string> h_height = {"5","10","8"};

		Attribute att_hero_name("Name","string",h_name);
		Attribute att_hero_ability("Ability","string",h_ability );
		Attribute att_hero_weight("Weight","string",h_weight);
		Attribute att_hero_height("Height","string",h_height);

		vector<string> key_hero = {"Spider Man","Super Man","Hulk"};

		vector<Attribute> hero_attributes;
		
		hero_attributes.push_back(att_hero_name);
		hero_attributes.push_back(att_hero_ability);
		hero_attributes.push_back(att_hero_weight);
		hero_attributes.push_back(att_hero_height);

		Table t ("Super Heros",hero_attributes,key_hero);
		e.all_tables.push_back(t);
		e.show("Super Heros");
		vector<string> att_names;

		for (int i = 0; i < t.att.size(); i ++){
			att_names.push_back(t.att[i].getName());
		}

		REQUIRE(att_names[0] == "Name");
		REQUIRE(att_names[1] == "Ability");
		REQUIRE(att_names[2] == "Weight");
		REQUIRE(att_names[3] == "Height");
		
	}
	
	//-----------------------------------------------------------------------
	//---------------------Create Test---------------------------------------
	//-----------------------------------------------------------------------
	TEST_CASE("Create test", "[Create]") {

		cout<<endl;
		cout<<endl;
		cout<< "----------------Create function test-----------------------------------" <<endl;
		
		Engine e;
		
		vector<string> h_name = {"Spider Man","Super Man","Hulk"};
		vector<string> h_ability = {"Strenght","Fly","Strenght"};
		vector<string> h_weight = {"150","160","250"};
		vector<string> h_height = {"5","10","8"};

		Attribute att_hero_name("Name","string",h_name);
		Attribute att_hero_ability("Ability","string",h_ability );
		Attribute att_hero_weight("Weight","string",h_weight);
		Attribute att_hero_height("Height","string",h_height);

		vector<string> key_hero = {"Spider Man","Super Man","Hulk"};

		vector<Attribute> hero_attributes;
		
		hero_attributes.push_back(att_hero_name);
		hero_attributes.push_back(att_hero_ability);
		hero_attributes.push_back(att_hero_weight);
		hero_attributes.push_back(att_hero_height);

		Table t = e.create("Super Heros",hero_attributes,key_hero);
		e.show("Super Heros");
		vector<string> att_names;

		for (int i = 0; i < t.att.size(); i ++){
			att_names.push_back(t.att[i].getName());
		}

		REQUIRE(att_names[0] == "Name");
		REQUIRE(att_names[1] == "Ability");
		REQUIRE(att_names[2] == "Weight");
		REQUIRE(att_names[3] == "Height");
		
	}



	//-----------------------------------------------------------------------
	//---------------------Insert Test---------------------------------------
	//-----------------------------------------------------------------------
	TEST_CASE("Insert_test", "[insert]") {

		cout<<endl;
		cout<<endl;
		cout<< "----------------Insert function test-----------------------------------" <<endl;
		
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
		
		e.create("Hero",hero_attributes,key_hero);

		e.show("Hero");
		
		vector <string> insertTest = {"test_name", "test_ability", "test_weight", "test_height"};

		Table new_table = e.insert("Hero", insertTest);

		cout<<endl;
		cout<<"After calling the insert function"<<endl;
		e.show("Hero");

		REQUIRE(new_table.att[0].data[3] == "test_name");
		REQUIRE(new_table.att[1].data[3] == "test_ability");
		REQUIRE(new_table.att[2].data[3] == "test_weight");
		REQUIRE(new_table.att[3].data[3] == "test_height");
	}

	//-----------------------------------------------------------------------
	//---------------------Drop Test-----------------------------------------
	//-----------------------------------------------------------------------
	TEST_CASE("Drop"){

		cout<<endl;
		cout<<endl;
		cout<< "----------------Drop function test-----------------------------------" <<endl;

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
		
		e.create("Hero",hero_attributes,key_hero);
		e.create("Human",hero_attributes,key_hero);
		e.create("Happy",hero_attributes,key_hero);
		e.create("Hungry", hero_attributes, key_hero);

		for(int i = 0; i< e.all_tables.size(); i++){
			cout<<e.all_tables[i].getName()<<endl;
		}

		e.drop("Happy");

		cout<<endl;
		cout<<"After calling drop funciton, on Happy table"<<endl;
		
		for(int i = 0; i< e.all_tables.size(); i++){
			cout<<e.all_tables[i].getName()<<endl;
		}
		REQUIRE(e.all_tables[0].name == "Hero");
		REQUIRE(e.all_tables[1].name == "Human");
		REQUIRE(e.all_tables[2].name != "Happy");	
	}


	
   //-----------------------------------------------------------------------
   //---------------------Destroy Test--------------------------------------
   //-----------------------------------------------------------------------
   TEST_CASE("Destroy"){
    
    cout<<endl;
    cout<<endl;
    cout<< "----------------Destroy function test-----------------------------------" <<endl;
       Engine e;
 
       vector<string> name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
	   vector<string> ocupataion = {"students","Proffesor","Boxer"};
	   vector<string> weight = {"150","160","250"};
	   vector<string> height = {"5","10","8"};
 
	   Attribute att_human_name("Name","string",name);
	   Attribute att_human_occupation("Occupation","string",ocupataion );
	   Attribute att_human_weight("Weight","string",weight);
	   Attribute att_human_height("Height","string",height);
 
	   vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
 
	   vector<Attribute> human_attributes;
 
	   human_attributes.push_back(att_human_name);
	   human_attributes.push_back(att_human_occupation);
	   human_attributes.push_back(att_human_weight);
	   human_attributes.push_back(att_human_height);
        
	   Table human_table("Human",human_attributes,key_name);//crates table
 
       e.all_tables.push_back(human_table);
       
       e.show("Human");
  
 
        Table new_table = e.destroy ("Human", "Name", "Peter Parker");
       
       cout<<endl;
       cout<<"After calling destroy funciton, on Human table"<<endl;
       e.show("Human");
 
 
        REQUIRE(new_table.att[0].data[0] != "Peter Parker");
        REQUIRE(new_table.att[0].data[0] != "students");
        REQUIRE(new_table.att[0].data[0] != "150");
        REQUIRE(new_table.att[0].data[0] != "5");
 
	 }

    //-----------------------------------------------------------------------
    //---------------------Update Test---------------------------------------
    //-----------------------------------------------------------------------
    TEST_CASE("Update"){
        cout<<endl;
        cout<<endl;
        cout<< "----------------Update function test-----------------------------------" <<endl;
        Engine e;
    
        vector<string> name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
        vector<string> ocupataion = {"students","Proffesor","Boxer"};
        vector<string> weight = {"150","160","250"};
        vector<string> height = {"5","10","8"};
        
        Attribute att_human_name("Name","string",name);
        Attribute att_human_occupation("Occupation","string",ocupataion );
        Attribute att_human_weight("Weight","string",weight);
        Attribute att_human_height("Height","string",height);
        
        vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
        
        vector<Attribute> human_attributes;
        
        human_attributes.push_back(att_human_name);
        human_attributes.push_back(att_human_occupation);
        human_attributes.push_back(att_human_weight);
        human_attributes.push_back(att_human_height);
        
        Table human_table("Human",human_attributes,key_name);//crates table
    
        e.all_tables.push_back(human_table);
        e.show("Human");
        
	vector<string> att_name={"Occupation","Height","Weight"};
    	vector<string> newVal={"Scientist", "185cm","60kg"};
    	
        
        Table new_table1 = e.update("Human",att_name,newVal,"Weight","150");
        
        
        cout<<endl;
        cout<<"After calling update funciton, on Human table"<<endl;
        e.show("Human");
    
    
        REQUIRE(new_table1.att[1].data[0] == "Scientist");
        REQUIRE(new_table1.att[2].data[0] == "185cm");
        REQUIRE(new_table1.att[3].data[0] == "60kg");

        
	}

	//------------------------------------------------------------------------
	//----------------------------Write function test -----------------------
	//-----------------------------------------------------------------------
	// Not testing I/O functions
    
	
    //------------------------------------------------------------------------
	//----------------------------Selection function test --------------------
	//-----------------------------------------------------------------------

    TEST_CASE("Selection"){
     
     cout<<endl;
     cout<<endl;
     cout<< "----------------Selection function test-----------------------------------" <<endl;
	  Engine e;

	 vector<string> name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
	 vector<string> ocupataion = {"students","Proffesor","Boxer"};
	 vector<string> weight = {"150","160","250"};
	 vector<string> height = {"5","10","8"};

	 Attribute att_human_name("Name","string",name);
	 Attribute att_human_occupation("Occupation","string",ocupataion );
	 Attribute att_human_weight("Weight","string",weight);
	 Attribute att_human_height("Height","string",height);

	 vector<string> key_name = {"Peter Parker","Andrew Wills","Antonio Ramos"};

	  vector<Attribute> human_attributes;

	  human_attributes.push_back(att_human_name);
	 human_attributes.push_back(att_human_occupation);
	 human_attributes.push_back(att_human_weight);
	 human_attributes.push_back(att_human_height);

	 Table human_table("Human",human_attributes,key_name);//crates table

	 e.all_tables.push_back(human_table);
     e.show("Human");
     cout<<endl;
     cout<<"After calling selection funciton, selected (Occupation) on Human table"<<endl;
     cout<<endl;
        
	  e.selection( "Human", "Occupation");
    }
    

	/*-------------------------------------------------------------------------
	----------------------------Renaming function test ----------------------
	---------------------------------------------------------------------------*/
	
	TEST_CASE("Renaming","[Renaming]"){

		cout<<endl;
		cout<<endl;
		cout<< "----------------Renaming function test-----------------------------------" <<endl;

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
	
		Table human = e.create("human table", human_atts, key_name);

		e.show("human table");
		
		e.renaming("Weight", "Love",human);
		e.renaming("Height", "Peace",human);

		e.all_tables.push_back(human);
		e.show("human table");
		
		REQUIRE(human.att[0].getName() == "Love");
		REQUIRE(human.att[1].getName() == "Peace");
	}

	
	


	//-------------------------------------------------------------------------
	//----------------------------Projection function test --------------------
	//-------------------------------------------------------------------------
	TEST_CASE("Projection","[Projection]" ){

		cout<<endl;
		cout<<endl;
		cout<< "----------------Projection function test-----------------------------------" <<endl;
		Engine e;

		vector<string> key_name = {"1","2","3","4"};
	
		vector<string> number = {"7274","7432","9894"};
		vector<string> surname = {"Robinson","O'Malley","Darkes"};
		vector<string> age = {"37","39","38"};
		vector<string> number2 = {"9297","7432","9894",};
		vector<string> surname2 = {"O'Malley","O'Malley","Darkes"};
		vector<string> age2 = {"56","39","38",};

		Attribute g_number("Number","Integer",number);
		Attribute g_surname("Surname","string",surname);
		Attribute g_age("Age","Integer",age);
		Attribute m_number("Number","Integer",number2);
		Attribute m_surname("Surname","string",surname2 );
		Attribute m_age("Age","Integer",age2);
		
		vector<Attribute> manager_att;
		vector<Attribute> graduate_att;

		manager_att.push_back(m_number);
		manager_att.push_back(m_surname);
		manager_att.push_back(m_age);
		graduate_att.push_back(g_number);
		graduate_att.push_back(g_surname);
		graduate_att.push_back(g_age);
		
		e.create("Graduate", graduate_att, key_name);
		e.create("Manager", manager_att, key_name);

		vector<string> att_names = {"Age","Number","Age"};/// You can put the attribute name in 

		Table projection_table = e.projection(att_names,"Graduate");
		e.all_tables.push_back(projection_table);

		e.show("Graduate");
		cout<<endl;
		cout<<"AFTER CALLED PROJECTION FUNCTION"<<endl;
		e.show("Graduate Projection");

		int i_size = projection_table.att.size();
		int j_size = projection_table.att[0].data.size();
		
		vector<string> test_values;
		for(int i = 0; i < i_size; i++){
			for(int j = 0; j < j_size; j++){
				test_values.push_back(projection_table.att[i].data[j]);
			}
		}

		vector<string> test_att_name;
		for(int i = 0; i < 3; i++){
			test_att_name.push_back(projection_table.att[i].getName());
		}

		//////////----------Require outputs to be correct------------/////////
		REQUIRE( test_att_name[0]  == "Age");
		REQUIRE( test_att_name[1]  == "Number");
		REQUIRE( test_att_name[2]  == "Age");
		REQUIRE( test_values[0]  == "37");
		REQUIRE( test_values[1]  == "39");
		REQUIRE( test_values[2]  == "38");
		REQUIRE( test_values[3]  == "7274");
		REQUIRE( test_values[4]  == "7432");
		REQUIRE( test_values[5]  == "9894");
		REQUIRE( test_values[6]  == "37");
		REQUIRE( test_values[7]  ==  "39");
		REQUIRE( test_values[8]  ==  "38");
	}
	
	
	
   	
   	/*-------------------------------------------------------------------------
	----------------------------Difference function test ----------------------
	---------------------------------------------------------------------------*/
	
   	TEST_CASE( "Difference between two tables", "[difference]" ) {

	   	cout<<endl;
	   	cout<<endl;
	   	cout<< "----------------Difference function test-----------------------------------" <<endl;

		Engine e;
		//Graduate Table 
		vector<string> number = {"7274","7432","9894"};
		vector<string> surname = {"Robinson","O'Malley","Darkes"};
		vector<string> age = {"37","39","38"};
		vector<string> number2 = {"9297","7432","9894",};
		vector<string> surname2 = {"O'Malley","O'Malley","Darkes"};
		vector<string> age2 = {"56","39","38",};

		Attribute g_number("Number","Integer",number);
		Attribute g_surname("Surname","string",surname);
		Attribute g_age("Age","Integer",age);
		Attribute m_number("Number","Integer",number2);
		Attribute m_surname("Surname","string",surname2 );
		Attribute m_age("Age","Integer",age2);

		vector<string> key_name = {"1","2","3","4"};

		vector<Attribute> graduate_att;
		vector<Attribute> manager_att;

		graduate_att.push_back(g_number);
		graduate_att.push_back(g_surname);
		graduate_att.push_back(g_age);
		manager_att.push_back(m_number);
		manager_att.push_back(m_surname);
		manager_att.push_back(m_age);
		
		//Tables
		Table g = e.create("Graduate", graduate_att, key_name);
		Table m = e.create("Manager", manager_att, key_name);

		Table diff_table = e.difference(g,m);

		e.show("Graduate-Manager");

		int i_size = diff_table.att.size();
		int j_size = diff_table.att[0].data.size();

		vector<string> test_values;
		for(int i = 0; i < i_size; i++){
			for(int j = 0; j < j_size; j++){
				test_values.push_back(diff_table.att[i].data[j]);
			}
		}
		//////////----------Require outputs to be correct------------/////////
		REQUIRE( test_values[0] == "7274" );
		REQUIRE( test_values[1] == "Robinson" );
		REQUIRE( test_values[2] == "37" );
	}


   	/*-------------------------------------------------------------------------
	----------------------------set Union function test -----------------------
	---------------------------------------------------------------------------*/
	TEST_CASE( "Union between two tables", "[Union]" ) {

		cout<<endl;
		cout<<endl;
	   	cout<< "----------------Set Union function test-----------------------------------" <<endl;

		Engine e;

		vector<string> key_name = {"1","2","3","4"};
	
		vector<string> number = {"7274","7432","9894"};
		vector<string> surname = {"Robinson","O'Malley","Darkes"};
		vector<string> age = {"37","39","38"};
		vector<string> number2 = {"9297","7432","9894",};
		vector<string> surname2 = {"O'Malley","O'Malley","Darkes"};
		vector<string> age2 = {"56","39","38",};

		Attribute g_number("Number","Integer",number);
		Attribute g_surname("Surname","string",surname);
		Attribute g_age("Age","Integer",age);
		Attribute m_number("Number","Integer",number2);
		Attribute m_surname("Surname","string",surname2 );
		Attribute m_age("Age","Integer",age2);
		
		vector<Attribute> manager_att;
		vector<Attribute> graduate_att;

		manager_att.push_back(m_number);
		manager_att.push_back(m_surname);
		manager_att.push_back(m_age);
		graduate_att.push_back(g_number);
		graduate_att.push_back(g_surname);
		graduate_att.push_back(g_age);
		
		Table g = e.create("Graduate", graduate_att, key_name);
		Table m = e.create("Manager", manager_att, key_name);

		Table union_table = e.set_union("none",g,m);
		e.show("Graduate U Manager");

		int i_size = union_table.att.size();
		int j_size = union_table.att[0].data.size();

		vector<string> test_values;
		for(int i = 0; i < i_size; i++){
			for(int j = 0; j < j_size; j++){
				test_values.push_back(union_table.att[i].data[j]);
			}
		}

		//////////----------Require outputs to be correct------------/////////
		REQUIRE( test_values[0]  == "7274");
		REQUIRE( test_values[1]  == "9297");
		REQUIRE( test_values[2]  == "7432");
		REQUIRE( test_values[3]  == "9894");
		REQUIRE( test_values[4]  == "Robinson");
		REQUIRE( test_values[5]  == "O'Malley");
		REQUIRE( test_values[6]  == "O'Malley");
		REQUIRE( test_values[7]  ==  "Darkes");
		REQUIRE( test_values[8]  ==  "37");
		REQUIRE( test_values[9]  ==  "56");
		REQUIRE( test_values[10] == "39");
		REQUIRE( test_values[11] == "38");
    }
	
	
	//--------------------------------------------------------------------------------
	//-----------------Cross product test ---EXAMPLE ---------------------------------//
	//---------------------------------------------------------------------------------
	//Should look like this: https://www.tutorialspoint.com/sql/sql-cartesian-joins.htm
	
	TEST_CASE( "Cross product between 2 tables", "[cross_product]" ) {
		cout<<endl;
   		cout<< "----------------Cross Product function test-----------------------------------" <<endl;
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
	
	

	/*-------------------------------------------------------------------------
	----------------------------natural Union function test -------------------
	---------------------------------------------------------------------------*/
	/*
	TEST_CASE( "natural join between 2 tables", "[natural_product]" ) {
		Engine f;
		vector<string> employee = {"smith", "black", "white"};
		vector<string> department = {"sales", "production", "production"};
		vector<string> department2 = {"production", "sales", "notproduction"};
		vector<string> head = {"mori", "brown", "frank"};

		Attribute emp("employee", "string", employee);
		Attribute dep("department", "string", department);
		Attribute dep2("department", "string", department2);
		Attribute hed("head", "string", head);


		vector<Attribute> cross_att1= {emp, dep};
		vector<Attribute> cross_att2 = {dep2, hed};
		Table nat_table1;
		nat_table1.name = "test1";
		nat_table1.att = cross_att1;
		Table nat_table2;
		nat_table2.name = "test2";
		nat_table2.att = cross_att2;

		Table nat_out_table = f.natural_join(nat_table1, nat_table2);
		//f.show("testerino3");

		vector<string> test_values;
		for(int i = 0; i < 3; i++){
			test_values.push_back(nat_out_table.att[i].data[0]);
		}

		REQUIRE( test_values[0] == "sales" );
		REQUIRE( test_values[1] == "brown" );
		REQUIRE( test_values[3] == "smith" );
	}
*/
