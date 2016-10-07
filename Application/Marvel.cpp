#include "Marvel.h"


#include <iostream>
#include <string>
#include <istream>

using namespace std;

 int main()
 {
	Marvel db;

	db.Menu();
	
 
 }
 
 void Marvel :: Menu(){
	Marvel db;

	cout << "<<<<<<<<<<<<<<<<<< Marvel Main Menu>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	
	cout << "User Options :" << endl;
	cout << "1.) View Marvel Characters" << endl;
	cout << "2.) View Characters attributes" << endl;
	cout << "3.) Find Marvel Characters" << endl;
	cout << "4.) Create Marvel Characters" << endl;
	cout << "5.) Delete Marvel Characters" << endl;
	cout << "6.) Update Marvel Characters" << endl;
	cout << "7.) Exit Database" << endl;
	cout << "q.) Quit Application" << endl;//FOR TESTING PURPOSES

	char request;
	cin>>request;

	while(request != 'q'){

		switch(request)
		{
			case '1':
				db.show_characters();
				break;
			case '2':
				db.show_attribute();
				break;
			case '3':
				db.find_character();
				break;
			case '4':
				db.create_character();
				break;
			case '5':
				db.delete_character();
				break;
			case '6':
				db.update_info();
				break;
			case '7':
				db.quit_app();	
				break;	
			default:
				cout << "[Error] :Invalid Request... Please try again." << endl;
				break;
		}

		cout<<endl;
		cout <<"--------------------Marvel Main Menu --------------------------" << endl;
	
		cout << "User Options :" << endl;
		cout << "1.) View Marvel Characters" << endl;
		cout << "2.) Find Marvel Characters" << endl;
		cout << "3.) Create Marvel Characters" << endl;
		cout << "4.) Delete Marvel Characters" << endl;
		cout << "5.) Update Marvel Characters" << endl;
		cout << "6.) Exit Database" << endl;
		cout << "q.) Quit Application" << endl;//FOR TESTING PURPOSES

		cin>>request;

	}

	cout<<"--------------------------GOOD BYE----------------------------------"<<endl;


}

void Marvel :: initialize_tables()
{
	//TODO:
}
void Marvel :: update_info() // Done, just need fucntion call to Parser 
{
	
	Marvel db;
	cout << "--------------------Update Info Menu --------------------------" << endl;
	
	cout << "1.) Update Marvel Human Characters" << endl;
	cout << "2.) Update Marvel Hero Characters" << endl;
	cout << "3.) Update Group Affiliation" << endl;
	cout << "4.) GO to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;
	
	while(request != 'q')
	{

		if(request=='1') 
		{
			
			string temp1;
			string temp2;
			string temp3;
			string temp4;
			string table = "Humans";
			cout << "Enter the Name of the Human character you would like to update" <<endl;
			cin.ignore();
			string human_name;
			getline(cin, human_name);
			
			
			cout << "Enter new value for Name: ";
			string new_name;
			getline(cin, new_name);
			temp1 = "UPDATE ";
			temp1 += table + " " + "SET name = ";
			temp1 += "\"" + new_name + "\"" + " ";
			temp1 += "WHERE(name == ";
			temp1 += "\"" + human_name + "\"" + ");";
			
			cout << temp1 << endl; // testing purposes
			
			
			cout << "Enter the new value for Height" <<endl;
			string new_height;
			getline(cin, new_height);
			temp2 = "UPDATE ";
			temp2 += table + " " + "SET height = ";
			temp2 += "\"" + new_height + "\"" + " ";
			temp2 += "WHERE(name == ";
			temp2 += "\"" + human_name + "\"" + ");";
			
			cout << temp2 << endl; // testing purposes
			
			cout << "Enter the new value for Weight" <<endl;
			string new_weight;
			getline(cin, new_weight);
			temp3 = "UPDATE ";
			temp3 += table + " " + "SET weight = ";
			temp3 += "\"" + new_weight + "\"" + " ";
			temp3 += "WHERE(name == ";
			temp3 += "\"" + human_name + "\"" + ");";
			
			cout << temp3 << endl; // testing purposes
			
			cout << "Enter the new value for Occupation" <<endl;
			string new_occ;
			getline(cin, new_occ);
			temp4 = "UPDATE ";
			temp4 += table + " " + "SET occupation = ";
			temp4 += "\"" + new_occ + "\"" + " ";
			temp4 += "WHERE(name == ";
			temp4 += "\"" + human_name + "\"" + ");";
			
			cout << temp4<< endl; // testing purposes
			
			

			// TODO :Call parser 3 times with input temp1, temp2, temp3
			
		}

		else if(request=='2') 
		{
			string temp1;
			string temp2;
			string temp3;
			string temp4;
			string table = "Heros";
			cout << "Enter the Name of the Hero character you would like to update" <<endl;
			cin.ignore();
			string hero_name;
			getline(cin, hero_name);
			
			
			cout << "Enter new value for Name: ";
			string new_name;
			getline(cin, new_name);
			temp1 = "UPDATE ";
			temp1 += table + " " + "SET name = ";
			temp1 += "\"" + new_name + "\"" + " ";
			temp1 += "WHERE(name == ";
			temp1 += "\"" + hero_name + "\"" + ");";
			
			cout << temp1 << endl; // testing purposes
			
			
			cout << "Enter the new value for Height" <<endl;
			string new_height;
			getline(cin, new_height);
			temp2 = "UPDATE ";
			temp2 += table + " " + "SET height = ";
			temp2 += "\"" + new_height + "\"" + " ";
			temp2 += "WHERE(name == ";
			temp2 += "\"" + hero_name + "\"" + ");";
			
			cout << temp2 << endl; // testing purposes
			
			cout << "Enter the new value for Weight" <<endl;
			string new_weight;
			getline(cin, new_weight);
			temp3 = "UPDATE ";
			temp3 += table + " " + "SET weight = ";
			temp3 += "\"" + new_weight + "\"" + " ";
			temp3 += "WHERE(name == ";
			temp3 += "\"" + hero_name + "\"" + ");";
			
			cout << temp3 << endl; // testing purposes
			
			cout << "Enter the new value for Abilities" <<endl;
			string new_ab;
			getline(cin, new_ab);
			temp4 = "UPDATE ";
			temp4 += table + " " + "SET abilities = ";
			temp4 += "\"" + new_ab+ "\"" + " ";
			temp4 += "WHERE(name == ";
			temp4 += "\"" + hero_name + "\"" + ");";
			
			cout << temp4<< endl; // testing purposes
			
			

			// TODO :Call parser 3 times with input temp1, temp2, temp3
		}

		else if(request=='3') 
		{
			string temp1;
			string temp2;
			
			string table = "Groups";
			cout << "Enter the Name of the Human character you would like to update" <<endl;
			cin.ignore();
			string group_name;
			getline(cin, group_name);
			
			
			cout << "Enter new value for Name of the Group: ";
			string new_name;
			getline(cin, new_name);
			temp1 = "UPDATE ";
			temp1 += table + " " + "SET name = ";
			temp1 += "\"" + new_name + "\"" + " ";
			temp1 += "WHERE(name == ";
			temp1 += "\"" + group_name + "\"" + ");";
			
			cout << temp1 << endl; // testing purposes
			
			
			cout << "Enter the new value for Group's Purpose" <<endl;
			string new_purp;
			getline(cin, new_purp);
			temp2 = "UPDATE ";
			temp2 += table + " " + "SET purpose = ";
			temp2 += "\"" + new_purp + "\"" + " ";
			temp2 += "WHERE(name == ";
			temp2 += "\"" + group_name + "\"" + ");";
			
			cout << temp2 << endl; // testing purposes
			
			
			
			
		}
		else if(request=='4'){
			cout << "Exiting find character Menu" << endl;
			db.Menu();
		}

		cout << "--------------------Update Info Menu --------------------------"  << endl;
	
		cout << "1.) Update Marvel Human Characters" << endl;
		cout << "2.) Update Marvel Hero Characters" << endl;
		cout << "3.) Update Group Affiliation" << endl;
		cout << "4.) GO to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Please enter the number of your desired request" << endl;

		cin>>request;

	}


	cout << "Exiting Update Menu" << endl;
	
	db.quit_app();
	
}

void Marvel :: find_character() // (Needs Help fixing  )
{
	Marvel db;

	cout << "--------------------Find Character Menu --------------------------"  << endl;

	cout << "1.) Find Marvel Human Characters" << endl;
	cout << "2.) Find Marvel Hero Characters" << endl;
	cout << "3.) Find Group Affiliation" << endl;
	cout << "4.) GO to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){
	
		if(request=='1') 
		{
			//TODO: Find Human Characters 
			
			string temp1;
			string human;
			string table = "Humans";
			cout << "Enter the Name of the Human character you would like to find" <<endl;
			cin.ignore();
			getline(cin, human);
			temp1 = human + " <- " + "select ";
			temp1 += "(name == ";
			temp1 += "\"" + human + "\"" + ") " + table + ";";
			cout << temp1 << endl;
		}

		else if(request=='2') 
		{
			//TODO: Find Hero Characters 
			string temp2;
			string hero;
			string table = "Heros";
			cout << "Enter the Name of the Hero character you would like to find" <<endl;
			cin.ignore();
			getline(cin, hero);
			temp2 = hero + " <- " + "select ";
			temp2 += "(name == ";
			temp2 += "\"" + hero + "\"" + ") " + table + ";";
			cout << temp2 << endl;
			
		}

		else if(request=='3') 
		{
			// TODO Find Group Affiliation 
			string temp3;
			string group;
			string table = "Groups";
			cout << "Enter the Name of the Group Affiliation you would like to find" <<endl;
			cin.ignore();
			getline(cin, group);
			temp3 = group + " <- " + "select ";
			temp3 += "(name == ";
			temp3 += "\"" + group + "\"" + ") " + table + ";";
			cout << temp3 << endl;
		}
		
		else if(request=='4'){
			cout << "Exiting find character Menu" << endl;
			db.Menu();
		}

		cout << "1.) Find Marvel Human Characters" << endl;
		cout << "2.) Find Marvel Hero Characters" << endl;
		cout << "3.) Find Group Affiliation" << endl;
		cout << "4.) GO to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Please enter the number of your desired request" << endl;
	
		cin>>request;
	}
	cout << "Exiting Find Menu" << endl;

	db.quit_app();
}


void Marvel :: helper_create_character(){ // Done but need Parser Call 

	string id;
	
	string temp1;
	string temp2;
	string temp3;
	
	string human_name;
	string human_height;
	string human_weight;
	string human_occ;

	string hero_name;
	string hero_height;
	string hero_weight;
	string hero_ab;
	
	string group_aff;
	string group_aff_purp;
	
	cout << "--------------------Character Creation Menu --------------------------" << endl;
	cout << "To create a character you must create 3 parts"<< endl;
	cout << "Your character must have a human and hero identity, and a group" << endl;

	
	cout << "Enter a number after 25, for your character's ID"<< endl;
	cin.ignore();
	getline(cin, id);
	cout << "Enter your character's Human Name" << endl;
	getline(cin, human_name);
	cout << "Enter your character's Human Height" << endl;
	getline(cin, human_height);
	cout << "Enter your character's Human Weight" << endl;
	getline(cin, human_weight);
	cout << "Enter your character's Human Occupation" << endl;
	getline(cin, human_occ);
	cout << "Enter your character's Hero Name" << endl;
	getline(cin, hero_name);
	cout << "Enter your character's Hero Height" << endl;
	getline(cin, hero_height);
	cout << "Enter your character's Hero Weight" << endl;
	getline(cin, hero_weight);
	cout << "Enter your character's Hero Abilities" << endl;
	getline(cin, hero_ab);
	cout << "Enter your character's Group Affiliation" << endl;
	getline(cin, group_aff);
	cout << "Enter your character's Group Affiliation Purpose" << endl;
	getline(cin, group_aff_purp);
	string temp;
	
	
	temp1 += "INSERT INTO Humans VALUES FROM (";
	temp1 += "\"" + id + "\"" + ", ";
	temp1 += "\"" + human_name + "\"" + ", ";
	temp1 += "\"" + human_height + "\"" + ", ";
	temp1 += "\"" + human_weight + "\"" + ", ";
	temp1 += "\"" + human_occ + "\"" + ") ";

	
	temp2 += "INSERT INTO Heros VALUES FROM (";
	temp2 += "\"" + id + "\"" + ", ";
	temp2 += "\"" + hero_name + "\"" + ", ";
	temp2 += "\"" + hero_height + "\"" + ", ";
	temp2 += "\"" + hero_weight + "\"" + ", ";
	temp2 += "\"" + hero_ab + "\"" + ") ";
	
	temp3 += "INSERT INTO Groups VALUES FROM (";
	temp3 += "\"" + id + "\"" + ", ";
	temp3 += "\"" + group_aff + "\"" + ", ";
	temp3 += "\"" + group_aff_purp + "\"" + ") ";
	
	cout << temp1 << endl;// testing purposes
	cout << temp2 << endl;
	cout << temp3 << endl;

	
	// Call parser using temp1 temp2 temp3 
}

void Marvel :: create_character()
{

	Marvel db;

	helper_create_character();
	
	cout << "Character was created"<<endl;

	cout<<"--------Created Character Options ------------";
	cout << "1.) I want to create another character" << endl;
	cout << "2.) I want to go to  Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;

	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1') {
		
			helper_create_character();
		
		}
		else if(request=='2'){
			cout << "Exiting Created Character" << endl;
			db.Menu();
		}

		cout << "Character was created"<<endl;

		cout<<"--------Created Character Options ------------";
		cout << "1.) I want to create another character" << endl;
		cout << "2.) I want to go to  Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;

		cin>>request;
	}

	db.quit_app();
	
}

void Marvel :: delete_character() //(Needs to be done )
{
	Marvel db;
	string quary;
	string character;
	string table;

	cout<<"<<<<<<<<<<<<<<<<<<< Delete Character Options >>>>>>>>>>>>>>>>>>"<<endl;
	cout << "1.) I want to Delete a Human character" << endl;
	cout << "2.) I want to Delete a Super Hero character" << endl;
	cout << "3.) I want to Delete a Group Affiliation" << endl;
	cout << "4.) I want to go to  Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;

	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1') {
			
			string table = "Humans";
			cout << " Please enter the Human name of the character that you want to delete"<< endl;
			cin.ignore();
			getline(cin, character);
			quary = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
			cout<<quary<<endl; //"TESTING PURPOSES"
			
		}
		if(request=='2') {
		
			table = "Heros";
			cout << " Please enter the Super Hero name of the character that you want to delete"<< endl;
			cin.ignore();
			getline(cin, character);
			quary = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
			cout<<quary<<endl; //"TESTING PURPOSES"
		}
		if(request=='3') {
		
			table = "Groups";
			cout << " Please enter the Group Affiliation name that you want to delete"<< endl;
			cin.ignore();
			getline(cin, character);
			quary = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
			cout<<quary<<endl; //"TESTING PURPOSES"
		}
		else if(request=='4'){
			cout << "Exiting Delete Character" << endl;
			db.Menu();
		}

		cout << "Character was deleted"<<endl;
		cout<<endl;

		
		cout<<"<<<<<<<<<<<<<<<<<<< Delete Character Options >>>>>>>>>>>>>>>>>>"<<endl;
		cout << "1.) I want to Delete a Human character" << endl;
		cout << "2.) I want to Delete a Super Hero character" << endl;
		cout << "3.) I want to Delete a Group Affiliation" << endl;
		cout << "4.) I want to go to  Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;

		cin>>request;
	}

	db.quit_app();
}

void Marvel :: show_characters() // Done but need Parser call 
{
	
	string table_name;
	string quary;
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<<<<<<<<<<<<< Show Character Menu >>>>>>>>>>>>>>>>>>"  << endl;
	cout << "1.) Show Marvel Human Characters" << endl;
	cout << "2.) Show Marvel Hero Characters" << endl;
	cout << "3.) Show Group Affiliation" << endl;
	cout << "4.) GO to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1') {
		 
			quary = "SHOW Humans;";
			cout<<quary<<endl;
		}
		else if(request=='2'){
			
			quary = "SHOW Heros;";
			cout<<quary<<endl;
		}
		else if(request=='3'){
			
			quary = "SHOW Groups;";
			cout<<quary<<endl;			
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			db.Menu();
		}

		cout<<endl;
		cout << "--------------------Show Character Menu --------------------------"  << endl;
		cout << "1.) Show Marvel Human Characters" << endl;
		cout << "2.) Show Marvel Hero Characters" << endl;
		cout << "3.) Show Group Affiliation" << endl;
		cout << "4.) GO to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Please enter the number of your desired request" << endl;

		cin>>request;
	}

db.quit_app();
}

void Marvel :: show_attribute(){//Projection

	//projection ::= project ( attribute-list ) atomic-expr

	string table_name;
	string quary;
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
	cout << "1.) Show Marvel Human Characters Attributes" << endl;
	cout << "2.) Show Marvel Hero Characters Attributes" << endl;
	cout << "3.) Show Group Affiliation Attributes" << endl;
	cout << "4.) GO to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1'){

			string att;
			string store_att;
			table_name = "Humans";
			cout<< "List of Attributes that we can show for the Humans character table"<<endl;
			cout<<"id,name,height,weight,occupation"<<endl;
			cout<<"Choose one or as many as you want follow by enter"<<endl;
			cout<<"Type f after you finish typing the attributes and follow by enter"<<endl;
			cout<<endl;

			cin>>att;

			while(att != "f"){
				store_att+=att + ",";
				cin>>att;
			}

			string new_att = store_att.substr(0, store_att.size()-1);
			quary = "project (" + new_att +") " + table_name+";";
			cout<<quary<<endl;//testing puposes
		}

		else if(request=='2'){

			string att;
			string store_att;
			table_name = "Heros";
			cout<< "List of Attributes that we can show for the Heros character table"<<endl;
			cout<<"id,name,height,weight,abilities"<<endl;
			cout<<"Choose one or as many as you want follow by enter"<<endl;
			cout<<"Type f after you finish typing the attributes and follow by enter"<<endl;
			cout<<endl;

			cin>>att;

			while(att != "f"){
				store_att+=att + ",";
				cin>>att;
			}

			string new_att = store_att.substr(0, store_att.size()-1);
			quary = "project (" + new_att +") " + table_name+";";
			cout<<quary<<endl;//testing puposes
		}

		else if(request=='3'){

			string att;
			string store_att;
			table_name = "Heros";
			cout<< "List of Attributes that we can show for the Group Affiliation table"<<endl;
			cout<<"name,purposes"<<endl;
			cout<<"Choose one or as many as you want follow by enter"<<endl;
			cout<<"Type f after you finish typing the attributes and follow by enter"<<endl;
			cout<<endl;

			cin>>att;

			while(att != "f"){
				store_att+=att + ",";
				cin>>att;
			}

			string new_att = store_att.substr(0, store_att.size()-1);
			quary = "project (" + new_att +") " + table_name+";";
			cout<<quary<<endl;//testing puposes
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			db.Menu();
		}
		
		cout<<endl;
		cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
		cout << "1.) Show Marvel Human Characters Attributes" << endl;
		cout << "2.) Show Marvel Hero Characters Attributes" << endl;
		cout << "3.) Show Group Affiliation Attributes" << endl;
		cout << "4.) GO to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Please enter the number of your desired request" << endl;

		cin>>request;
	}

	db.quit_app();

}



void Marvel :: quit_app()
{ 
	exit(0);
}

	
