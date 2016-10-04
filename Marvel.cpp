#include "Marvel.h"

#include <iostream>
#include <string>

using namespace std;


void  Marvel :: initialize()
{
	//TODO :
	//Create tables for the user
}
void  Marvel :: marvel_menu()
{
	//TODO
	//Tells the user all of the statements that the user can request 
	int request;
	
	cout << "<<<<<<<< Marvel Main Menu >>>>>>>>>>" << endl;
	
	cout << "User Options :" << endl;
	cout << "1.) View Marvel Characters" << endl;
	cout << "2.) Find Marvel Characters" << endl;
	cout << "3.) Create Marvel Characters" << endl;
	cout << "4.) Delete Marvel Characters" << endl;
	cout << "5.) Exit Database" << endl;
	cout << "Please enter the number of your desired request" << endl;
	
	cin >> request;
	
	if(request==1) 
		show_characters();
	else if(request==2) 
		find_character();
	else if(request==3) 
		create_character();
	else if(request==4) 
		delete_character();
	else if (request==5) 
		quit_app();	
	
}
void Marvel :: update_info()
{
	//TODO:
	//Updates information in the database 
}
void Marvel :: find_character()
{
	//TODO:
	//Performs searches on the database 
}
	
void Marvel :: create_character()
{
	//TODO:
	//Receive the Information to allow  a creation of a character
}
void Marvel :: delete_character()
{
	//TODO:
	//Allows the user to delete characters that they have created 
}
void Marvel :: show_characters()
{
	//TODO:
	//Shows all of the character information in the database
}
void Marvel :: quit_app()
{
	//TODO:
	//Quits the database 
}
	
	