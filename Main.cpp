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
	vector<Attribute> header; 
	header.data = {"Name", "Occupation", "Weight", "Height"};
	vector<string> key = {"Name", "Occupation"};
	vector<string> name = {"Peter Parker","Andrew Wills","Antonio Ramos"};
	vector<string> occupation = {"students","Proffesor","Boxer"};
	vector<string> weight = {"150","160","250"};
	vector<string> height = {"5","10","8"};
	

	vector<string> hname = {"Spider Man","Super Man","Hulk"};
	vector<string> hability = {"Strenght","Fly","Strenght"};
	vector<string> hweight = {"150","160","250"};
	vector<string> hheight = {"5","10","8"};
	

	vector<string> universe = {"Earth","Mars","Earth"};
	vector<string> purpose = {"life saver","life saver","life saver"};
	vector<string> gname = {"Marvel","DC","Marvel"};


<<<<<<< HEAD
	// Attribute att_human_name("Name","string",name);
	// Attribute att_human_name("ocupation","string",name);
	// Attribute att_human_name("weight","string",name);
	// Attribute att_human_name("Name","string",name);
=======
	Attribute att_human_name("Name","string",name);
	
	//e.create("Superhero", header, key);
	//e.insert("superhero", header)
	
	Attribute att_human_name("ocupation","string",name);
	Attribute att_human_name("weight","string",name);
	//Attribute att_human_name("Name","string",name);
>>>>>>> 62f96614f1e9a6b163bff3416c7be4510859bc29

	
	



	//Attribute test_attribute;








	cout << "This is just a test ";
	/// table.create("SuperHero", "test_attribute",  );

	//TODO: tests regarding engine functions
}

