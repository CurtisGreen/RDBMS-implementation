#include "Marvel.h"


#include <iostream>
#include <string>

using namespace std;

 int main()
 {
//TODO:
	//Tells the user all of the statements that the user can request 
	Marvel db;

	db.Menu();
	
 
 }
 
 void Marvel :: Menu(){//MENU


	Marvel db;

	cout << "<<<<<<<< Marvel Main Menu >>>>>>>>>>" << endl;
	
	cout << "User Options :" << endl;
	cout << "1.) View Marvel Characters" << endl;
	cout << "2.) Find Marvel Characters" << endl;
	cout << "3.) Create Marvel Characters" << endl;
	cout << "4.) Delete Marvel Characters" << endl;
	cout << "5.) Update Marvel Characters" << endl;
	cout << "6.) Exit Database" << endl;
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
				db.find_character();
				break;
			case '3':
				db.create_character();
				break;
			case '4':
				db.delete_character();
				break;
			case '5':
				db.update_info();
				break;
			case '6':
				db.quit_app();	
				break;	
			default:
				cout << "[Error] :Invalid Request... Please try again." << endl;
				break;
		}

		cout<<endl;
		cout << "<<<<<<<< Marvel Main Menu >>>>>>>>>>" << endl;
	
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

	cout<<"----------------GOOD BYE----------------------------------"<<endl;


}

void Marvel :: initialize_tables()
{
	//TODO:
}
void Marvel :: update_info()
{
	//TODO:
	//Updates information in the database 
	cout << "<<<<<<<< Update Info Menu >>>>>>>>>>" << endl;
	
	cout << "1.) Update Marvel Human Characters" << endl;
	cout << "2.) Update Marvel Hero Characters" << endl;
	cout << "3.) Update Group Affiliation" << endl;
	cout << "Please enter the number of your desired request" << endl;
	
	int request =0;
	cin >> request;
	
	if(request==1) 
	
	{
		//TODO: Update Human Characters 
		cout << "Enter the Name of the Human character you would like to update" <<endl;
	}
	else if(request==2) 
		
	{
		//TODO: Update Hero Characters 	
		cout << "Enter the Name of the Hero character you would like to update" <<endl;
	}
	else if(request==3) 
	{
		// TODOD Update Group Affiliation 
		cout << "Enter the Name of the Group Affiliation you would like to update" <<endl;
	}
	
	cout << "Exiting Update Menu" << endl;
	
	
}
void Marvel :: find_character()
{
	//TODO:
	//Performs searches on the database 
	cout << "<<<<<<<< Find Character Menu >>>>>>>>>>" << endl;
	
	cout << "1.) Find Marvel Human Characters" << endl;
	cout << "2.) Find Marvel Hero Characters" << endl;
	cout << "3.) Find Group Affiliation" << endl;
	cout << "Please enter the number of your desired request" << endl;
	
	int request =0;
	cin >> request;
	
	if(request==1) 
	
	{
		//TODO: Find Human Characters 
		cout << "Enter the Name of the Human character you would like to find" <<endl;
	}
	else if(request==2) 
		
	{
		//TODO: Find Hero Characters 	
		cout << "Enter the Name of the Hero character you would like to find" <<endl;
	}
	else if(request==3) 
	{
		// TODOD Find Group Affiliation 
		cout << "Enter the Name of the Group Affiliation you would like to find" <<endl;
	}
	cout << "Exiting Find Menu" << endl;
	

}
	
void Marvel :: create_character()
{
	//TODO:
	//Receive the Information to allow  a creation of a character
	
	string human_age;
	string hero_age;
	string human_name;
	string human_occ;
	string hero_name;
	string hero_ab;
	string group_aff;
	string group_aff_purp;
	
	cout << "<<<<<<<< Character Creation Menu >>>>>>>>>>" << endl;
	cout << "To create a character you must create 3 parts"<< endl;
	cout << "Your character must have a human and hero identity, and a group" << endl;
	cout << "<<<<<<<<< Let's get started >>>>>>>" << endl;
	
	cout << "Enter your character's Human Name" << endl;
	getline(cin, human_name);
	cout << "Enter your character's Human Age" << endl;
	getline(cin, human_age);
	cout << "Enter your character's Human Occupation" << endl;
	getline(cin, human_name);
	cout << "Enter your character's Hero Name" << endl;
	getline(cin, hero_name);
	cout << "Enter your character's Hero Age" << endl;
	getline(cin, hero_age);
	cout << "Enter your character's Hero Abilities" << endl;
	getline(cin, hero_ab);
	cout << "Enter your character's Group Affiliation" << endl;
	getline(cin, group_aff);
	cout << "Enter your character's Group Affiliation Purpose" << endl;
	getline(cin, group_aff_purp);
	
	//TODO  convert to create characters and insert them  command
	
	
	
}
void Marvel :: delete_character()
{
	//TODO:
	//Allows the user to delete characters that they have created 
	cout << "<<<<<<<<<<< Character Deletion Menu >>>>>>>>>>" << endl;
	
	cout << " Please enter the Human name of the character that you want to delete"<< endl;
	string human_name;
	getline(cin, human_name);
	
	//TODO: Write delete sql grammar 
	
	
}
void Marvel :: show_characters()
{
	//TODO:
	//Shows all of the character information in the database

	string table_name;
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<< Character Show Menu >>>>>>>>>>" << endl;
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
			//TODO: Show Human Characters : SQL grammar 
			string str = "SHOW human;";
			cout<<"PRINTING TABLE human"<<endl;//TESTING PURPOSES
		
		}
		else if(request=='2'){
			//TODO: Show Hero Characters  : SQL grammar 
			string str = "SHOW hero;";
			cout<<"PRINTING TABLE hero"<<endl;//TESTING PURPOSES
			
		}
		else if(request=='3'){
			// TODOD Show Group Affiliation	: SQL grammar	
			string str = "SHOW affiliation;";
			cout<<"PRINTING TABLE affiliation"<<endl;//TESTING PURPOSES
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			db.Menu();
		}

		cout<<endl;
		cout << "<<<<<<<< Character Show Menu >>>>>>>>>>" << endl;
		cout << "1.) Show Marvel Human Characters" << endl;
		cout << "2.) Show Marvel Hero Characters" << endl;
		cout << "3.) Show Group Affiliation" << endl;
		cout << "4.) GO to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Please enter the number of your desired request" << endl;

		cin>>request;
	}

db.quit_app()
}
void Marvel :: quit_app()
{
	//TODO:
	//Quits the database 
	exit(0);
}

	
