#include <vector>
#include <string>
#include <iostream>

#include "Table.h"
#include "Attribute.h"
#include "Engine.h"


using namespace std; 

//Testing compilation

int main(){

	Engine e; 

///was commented because I was testing diference(Table,Table),Jose
/*
	//-----------------------------------------------------------------------
	//------------------Human Identity Table---------------------------------
	//-----------------------------------------------------------------------
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


*/
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

	e.all_tables.push_back(graduate_table);
	e.all_tables.push_back(manager_table);


	e.difference(graduate_table,manager_table);
		
	

	
}

