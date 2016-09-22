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
	//-----------------Hero Indentiry Table----------------------------------
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

	Table hero_table("Hero",hero_attributes,key_hero);//crates table 


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

	//TODO: tests regarding engine functions
	
	
	
	//Attribute test_attribute;

	//cout << "This is just a test ";
}

