#include "Marvel.h"

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <vector>
#include <sstream>

using namespace std;

void my_print(vector<string> v);

int main()
{

    int client;
    int portNum = 5031; // NOTE that the port number is same for both client and server
    bool isExit = false;
    int bufsize = 15000;
    char buffer[bufsize];
    string temp_str;
	string buf;
	vector<string> tokens;
    char* ip = "127.0.0.1";
	struct sockaddr_in server_addr;

	//---------------------------------SOCKET-------------------------------------------//
	client = socket(AF_INET, SOCK_STREAM, 0);

	if (client < 0){
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

	cout << "\n=> Socket client has been created..." << endl;
	server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

	if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0){
        cout << "=> Connection to the server port number: " << portNum << endl;
    }

	cout << "=> Awaiting confirmation from the server..." << endl; //line 40
	recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed, you are good to go...";
	cout << "\n\n=> Enter # to end the connection\n" << endl;
	//---------------------------------SOCKET-------------------------------------------//


	
	//---------------------------------Interactive System-------------------------------------------//
    Marvel db;
	cout << "WELCOME !!!!" << endl;
	cout << "<<<<<<<<<<<<<<<<<< Marvel Main Menu>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	
	cout << "User Options :" << endl;
	cout << "1.) View Marvel Characters" << endl;
	cout << "2.) View column name in Character tables" << endl;
	cout << "3.) View Heroes and Humans table combined"<<endl;
	cout << "4.) Find Marvel Characters" << endl;
	cout << "5.) Create Marvel Characters" << endl;
	cout << "6.) Delete Marvel Characters" << endl;
	cout << "7.) Update Marvel Characters" << endl;
	cout << "8.) Exit Database" << endl;
	cout << "9.) View Heroes and Humans tables similarities" << endl;
	cout << "q.) Quit Application" << endl;

	char request;
	cin>>request;

	while(request != 'q'){
		
		switch(request)
		{
			case '1':
				{
				string s = db.show_characters();
				send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '2':
				{
				string s = db.show_attribute();
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '3':
				{
				string s = db.cross_product();
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '4':
				{
				string s = db.find_character();
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '5':
				{
				string s = db.create_character();
				send(client, s.c_str(), bufsize, 0);
	
				}
				break;
			case '6':
				{
				string s = db.delete_character();
				send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '7':
				{
				string s = db.update_info();
				send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '8':
				db.quit_app();	
				break;
			case '9':
				{
				string s = db.set_union();
				send(client, s.c_str(), bufsize, 0);
				}
				break;
			default:
				cout << "[Error] :Invalid Request... Please try again." << endl;
				break;
		}

		recv(client, buffer, bufsize, 0); // RECEIVE FROM THE SERVER 
		temp_str = buffer;
    	stringstream ss(temp_str); // Insert the string into a stream
   		while (ss >> buf){
        	tokens.push_back(buf);
		}
		temp_str = "";

		cout<<endl;
		cout<<endl;

		my_print(tokens);
		tokens.clear();

 		cout<<endl;
 		cout<<endl;
 		cout<<endl;

		cout << "<<<<<<<<<<<<<<<<<< Marvel Main Menu>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	
		cout << "User Options :" << endl;
		cout << "1.) View Marvel Characters!" << endl;
		cout << "2.) View column names in Character tables!" << endl;
		cout << "3.) View Heroes and Humans table combined!"<<endl;
		cout << "4.) Find Marvel Characters!" << endl;
		cout << "5.) Create Marvel Characters!" << endl;
		cout << "6.) Delete Marvel Characters!" << endl;
		cout << "7.) Update Marvel Characters!" << endl;
		cout << "8.) Exit Database" << endl;
		cout << "9.) View Heroes and Humans tables similarities!" << endl;
		cout << "q.) Quit Application" << endl;

		cin>>request;
	}

	cout<<"--------------------------GOOD BYE----------------------------------"<<endl;
	//-------------------------------------
	
    close(client);
    return 0;

	//--------------------------------------
}

void my_print(vector<string> v){

	int att_size = atoi(v[0].c_str());
	//cout<<"TESTING SIZE: " <<att_size<<endl;
	v.erase(v.begin());

	vector<string> tokens = v ;
	vector<string> temp;
	vector<vector<string>> rows;

	int count = 0;
	int count2 = 1;

	for(int i = 0; i<tokens.size();i++){
		if(count < att_size){
			temp.push_back(tokens[i]);
			 count++;
		}
		if(count > att_size-1){
			rows.push_back(temp);
			temp.clear();
			count = 0;
		}
	}
	for (int i = 0; i < rows.size(); i++) {
   		for (int j = 0; j < rows[i].size(); j++) {
   		    cout<<left;
   			cout.width(20);
    		cout << rows[i][j]<<"  ";
  		}
  		cout<<endl;
  		cout<<endl;
	}
	
	temp.clear();
	rows.clear();
}


 /*
 void Marvel :: Menu(){
 Marvel db;

	cout << "<<<<<<<<<<<<<<<<<< Marvel Main Menu>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	
	cout << "User Options :" << endl;
	cout << "1.) View Marvel Characters" << endl;
	cout << "2.) View Characters attributes" << endl;
	cout << "3.) Rename character attribute name"<<endl;
	cout << "4.) Find Marvel Characters" << endl;
	cout << "5.) Create Marvel Characters" << endl;
	cout << "6.) Delete Marvel Characters" << endl;
	cout << "7.) Update Marvel Characters" << endl;
	cout << "8.) Exit Database" << endl;
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
				db.rename();
				break;
			case '4':
				db.find_character();
				break;
			case '5':
				db.create_character();
				break;
			case '6':
				db.delete_character();
				break;
			case '7':
				db.update_info();
				break;
			case '8':
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
*/



string Marvel :: projection_rename_helper(string table_name, string function_name,string list){

	string att;
	string store_att;
	string query;
	cout<< "List of Column Names that we can choose from!"<<endl;
	cout<< list <<endl;
	cout<<"Choose one or as many as you want follow by enter"<<endl;
	cout<<"Type f after you finish typing the names and follow by enter"<<endl;
	cout<<endl;

	cin>>att;

	while(att != "f"){
		store_att+=att + ",";
		cin>>att;
	}

	string new_att = store_att.substr(0, store_att.size()-1);
	query = function_name+ " (" + new_att +") " + table_name +";";
	
	return query;

}

string Marvel :: cross_product(){

	
	string query = "HumansProdHeroes <- Humans * Heroes;";
	return query;

}
string Marvel :: set_union(){

	
	string query = "HumansUnionHeroes <- Humans + Heroes;";
	return query;

}


string  update_info_helper(string table,string old_value,string thing_to_update){


	string temp;


	cout << "Enter new value for "+ thing_to_update + ": ";
	string new_name;
	getline(cin, new_name);
	cout << "Enter old value for "+ thing_to_update + ": ";
	string old;
	getline(cin, old);
	temp = "UPDATE ";
	temp += table + " " + "SET "+ thing_to_update +"=";
	temp += "\"" + new_name + "\"" + " ";
	temp += "WHERE "+ thing_to_update +  "=";
	temp += "\"" + old + "\"" + ";";
	
	

	return temp;

}


string Marvel :: update_info() 
{
	
	Marvel db;
	cout << "--------------------Update Info Menu --------------------------" << endl;
	
	cout << "1.) Update Marvel Human Characters" << endl;
	cout << "2.) Update Marvel Hero Characters" << endl;
	cout << "3.) Update Group Affiliation" << endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;
	
	while(request != 'q')
	{

		if(request=='1') 
		{
			
			string human_name = "Humans";
			string temp1;
			string temp2;
			string temp3;
			string temp4;
			string table = "Humans";
			// cout << "Enter the Name of the Human you would like to update" <<endl;
			// cout << endl;
			cout << "HEY, do you need a suggestion?? TRY: Peter_Parker :old valued (510 165 Photographer)" << endl;
			cin.ignore();
			// string human_name;
			// getline(cin, human_name);

			temp1 = update_info_helper(table,human_name,"name");
			temp2 = update_info_helper(table,human_name,"height");
			temp3 = update_info_helper(table,human_name,"weight");
			temp4 = update_info_helper(table,human_name,"occupation");

			string all = temp1 + "\n" + temp2 + "\n" +  temp3 + "\n" + temp4;
			return all;	
		}

		else if(request=='2') 
		{
			string hero_name = "Heroes";
			string temp1;
			string temp2;
			string temp3;
			string temp4;
			string table = "Heroes";
			// cout << "Enter the Name of the Hero character you would like to update" <<endl;
			// cout << endl;
			cout << "HEY, do you need a suggestion?? TRY : Spider_Man : old values (510 165 Spider_Senses)" << endl;
			cin.ignore();
			// string hero_name;
			// getline(cin, hero_name);
			
			temp1 = update_info_helper(table,hero_name,"name");
			temp2 = update_info_helper(table,hero_name,"height");
			temp3 = update_info_helper(table,hero_name,"weight");
			temp4 = update_info_helper(table,hero_name ,"abilities");

			string all = temp1 + "\n" + temp2 + "\n" +  temp3 + "\n" + temp4;
			return all;
			
			
		}

		else if(request=='3') 
		{
			string temp1;
			string temp2;
			string group_name = "Groups";
			string table = "Groups";
			// cout << "Enter the Name of the Group character you would like to update" <<endl;
			// cout << endl;
			cout << "HEY, do you need a suggestion?? TRY: Avengers : old values (Avengers Heroes" << endl;
			cin.ignore();
			// string group_name;
			// getline(cin, group_name);
			
			temp1 = update_info_helper(table,group_name,"name");
			temp2 = update_info_helper(table,group_name,"purpose");

			string all = temp1 + "\n" + temp2 + "\n";
			return all;
		}
		else if(request=='4'){
			cout << "Exiting find character Menu" << endl;
			//db.Menu();
		}
		cout << "GREAT ! Your character has been updated! Take a look in the view Option" << endl;

		cout << "--------------------Update Info Menu --------------------------"  << endl;
	
		cout << "1.) Update Marvel Human Characters" << endl;
		cout << "2.) Update Marvel Hero Characters" << endl;
		cout << "3.) Update Group Affiliation" << endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Please enter the number of your desired request" << endl;

		cin>>request;

	}


	cout << "Exiting Update Menu" << endl;
	
	db.quit_app();

	return "";
	
}

string Marvel :: find_character() 
{
	Marvel db;

	cout << "--------------------Find Character Menu --------------------------"  << endl;

	cout << "1.) Find Marvel Human Characters" << endl;
	cout << "2.) Find Marvel Hero Characters" << endl;
	cout << "3.) Find Group Affiliation" << endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){
	
		if(request=='1') 
		{
			 
			
			string temp1;
			string human;
			string table = "Humans";
			cout << "Enter the Name of the Human character you would like to find" <<endl;
			cout << endl;
			cout << "HEY, do you need a suggestion?? TRY: Carol_Danvers " << endl;
			cin.ignore();
			getline(cin, human);
			temp1 = human + " <- " + " select ";
			temp1 += "(name == ";
			temp1 += "\"" + human + "\"" + ")(" + table + ");";
			//cout << "TESTING" << temp1 << endl;
			return temp1;
		}

		else if(request=='2') 
		{
			
			string temp2;
			string hero;
			string table = "Heroes";
			cout << "Enter the Name of the Hero character you would like to find" <<endl;
			cout << endl;
			cout << "HEY, do you need a suggestion?? TRY: Thor " << endl;
			cin.ignore();
			getline(cin, hero);
			temp2 = hero + " <- " + " select ";
			temp2 += "( name == ";
			temp2 += "\"" + hero + "\"" + ") " + table + ";";
			//cout << "TESTING" << temp2 << endl;
			return temp2;
			
		}

		else if(request=='3') 
		{
			
			string temp3;
			string group;
			string table = "Groups";
			cout << "Enter the Name of the Group Affiliation you would like to find" <<endl;
			cout << endl;
			cout << "HEY, do you need a suggestion?? TRY: Xmen " << endl;
			cin.ignore();
			getline(cin, group);
			temp3 = group + " <- " + " select ";
			temp3 += "( name == ";
			temp3 += "\"" + group + "\"" + ") " + table + ";";
			//cout << "TESTING" << temp3 << endl;
			return temp3;
		}
		
		else if(request=='4'){
			cout << "Exiting find character Menu" << endl;
			//db.Menu();
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
	return "";
}


string Marvel :: helper_create_character(){ 

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

	
	
	cin.ignore();
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
	
	
	temp1 += "INSERT INTO Humans VALUES FROM (";
	temp1 += "\"" + human_name + "\"" + ", ";
	temp1 += "\"" + human_height + "\"" + ", ";
	temp1 += "\"" + human_weight + "\"" + ", ";
	temp1 += "\"" + human_occ + "\"" + ");";


	temp2 += "INSERT INTO Heroes VALUES FROM (";
	temp2 += "\"" + hero_name + "\"" + ", ";
	temp2 += "\"" + hero_height + "\"" + ", ";
	temp2 += "\"" + hero_weight + "\"" + ", ";
	temp2 += "\"" + hero_ab + "\"" + ");";

	
	temp3 += "INSERT INTO Groups VALUES FROM (";
	temp3 += "\"" + group_aff + "\"" + ", ";
	temp3 += "\"" + group_aff_purp + "\"" + ");";
	

	string all = temp1 + temp2 + temp3;
	
	cout << "GREAT, your character was created, take a look in the VIEW options!!" << endl;

	return all;



	
}

string Marvel :: create_character()
{

	Marvel db;

	string str = helper_create_character();
	
	return str; 

	
   /*
	cout<<"--------Created Character Options ------------";
	cout << "1.) I want to create  character" << endl;
	cout << "2.) I want to go to  Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;

	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1') {
		
			string str = helper_create_character();
			return str; 
		
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

	*/

	db.quit_app();

	return "";
	
}

string Marvel :: delete_character() 
{
	Marvel db;
	string query;
	string character;
	string table;

	cout<<"<<<<<<<<<<<<<<<<<<< Delete Character Options >>>>>>>>>>>>>>>>>>"<<endl;
	cout << "1.) I want to Delete a Human character" << endl;
	cout << "2.) I want to Delete a Super Hero character" << endl;
	cout << "3.) I want to Delete a Group Affiliation" << endl;
	cout << "q.) Quit Application"<<endl;

	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1') {
			
			string table = "Humans";
			cout << " Please enter the Human name of the character that you want to delete"<< endl;
			cout << endl;
			cout << "HEY, do you need a suggestion?? TRY: Ororo_Monroe " << endl;
			cin.ignore();
			getline(cin, character);
			query = "DELETE FROM " + table + " WHERE name=" + "\"" + character + "\"" + ";";
			return query;
			
		}
		if(request=='2') {
		
			table = "Heroes";
			cout << " Please enter the Super Hero name of the character that you want to delete"<< endl;
			cout << endl;
			cout << "HEY, do you need a suggestion?? TRY: Hulk" << endl;
			cin.ignore();
			getline(cin, character);
			query = "DELETE FROM " + table + " WHERE name=" + "\"" + character + "\"" + ";";
			//cout << "TESTING" << query <<endl;
			return query;
		}
		if(request=='3') {
		
			table = "Groups";
			cout << " Please enter the Group Affiliation name that you want to delete"<< endl;
			cout << endl;
			cout << "HEY, do you need a suggestion?? TRY: Xmen " << endl;
			cin.ignore();
			getline(cin, character);
			query = "DELETE FROM " + table + " WHERE name=" + "\"" + character + "\"" + ";";
			return query;
		}
		else if(request=='4'){
			cout << "Exiting Delete Character" << endl;
			//db.Menu();
		}

		cout << "Character was deleted !"<<endl;
		cout<<endl;

		
		cout<<"<<<<<<<<<<<<<<<<<<< Delete Character Options >>>>>>>>>>>>>>>>>>"<<endl;
		cout << "1.) I want to Delete a Human character" << endl;
		cout << "2.) I want to Delete a Super Hero character" << endl;
		cout << "3.) I want to Delete a Group Affiliation" << endl;
		cout << "q.) Quit Application"<<endl;

		cin>>request;
	}

	db.quit_app();
	return "";
}

string Marvel :: show_characters()  
{
	
	string table_name;
	string query;
	
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<<<<<<<<<<<<< Show Character Menu >>>>>>>>>>>>>>>>>>"  << endl;
	cout << "1.) Show Marvel Human Characters" << endl;
	cout << "2.) Show Marvel Hero Characters" << endl;
	cout << "3.) Show Group Affiliation" << endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1') {
		 
			query = "SHOW Humans;";
			return query;
		}
		else if(request=='2'){
			
			query = "SHOW Heroes;";
			return query;	
		}
		else if(request=='3'){
			
			query = "SHOW Groups;";
			return query;		
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			//db.Menu();
		}

		cout<<endl;
		cout << "--------------------Show Character Menu --------------------------"  << endl;
		cout << "1.) Show Marvel Human Characters" << endl;
		cout << "2.) Show Marvel Hero Characters" << endl;
		cout << "3.) Show Group Affiliation" << endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Please enter the number of your desired request" << endl;

		cin>>request;
	}

db.quit_app();
return "";
}

string Marvel :: show_attribute(){

	

	string table_name;
	string query;
	string list;
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
	cout << "1.) Show column names in Human table" << endl;
	cout << "2.) Show column names in Hero table" << endl;
	cout << "3.) Show column names in Group table" << endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1'){
			list = "name,height,weight,occupation";
			string query = db.projection_rename_helper("Humans", "project",list);
			return query;

		}
		else if(request=='2'){
			list = "name,height,weight,abilities";
			string query = db.projection_rename_helper("Heroes", "project",list);
			return query;
			
		}
		else if(request=='3'){
			list = "name,purpose";
			string query = db.projection_rename_helper("Groups", "project",list);
			return query;	
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			//db.Menu();
		}
		
		cout<<endl;
		cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
		cout << "1.) Show column names in Human table" << endl;
		cout << "2.) Show column names in Hero table" << endl;
		cout << "3.) Show column names in Group table" << endl;
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

	
