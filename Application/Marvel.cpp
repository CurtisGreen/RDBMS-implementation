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

using namespace std;

int main()
{

    int client;
    int portNum = 5007; // NOTE that the port number is same for both client and server
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) 
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }


    cout << "\n=> Socket client has been created..." << endl;
   

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server port number: " << portNum << endl;

    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed, you are good to go...";

    cout << "\n\n=> Enter # to end the connection\n" << endl;

    // Once it reaches here, the client can send a message first.

	


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
	cout << "q.) Quit Application" << endl;

	
	char request;
	cin>>request;
	
	while(request != 'q'){
		
			

		switch(request)
		{
			case '1':
				{
				string s = db.show_characters();
				cout<<"TESTING:"<<endl;
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '2':
				{
				string s = db.show_attribute();
				cout<<"TESTING:"<<endl;
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '3':
				
				{
				string s = db.rename();
				cout<<"TESTING:"<<endl;
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '4':
				{
				string s = db.find_character();
				cout<<"TESTING:"<<endl;
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '5':
				{
				string s = db.create_character();
				cout<<"TESTING:"<<s<<endl;
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '6':
				{
				string s = db.delete_character();
				cout<<"TESTING:"<<endl;
				 send(client, s.c_str(), bufsize, 0);
				}
				break;
			case '7':
				{
				string s = db.update_info();
				cout<<"TESTING:"<<endl;
				 send(client, s.c_str(), bufsize, 0);
				}
				
				break;
			case '8':
				db.quit_app();	
				break;	
			default:
				cout << "[Error] :Invalid Request... Please try again." << endl;
				break;
		}

		//--------------------------------------
		recv(client,buffer, bufsize,0);
		//---------------------------------------
		
	
	
		
		cout<<endl;
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
	cout << "q.) Quit Application" << endl;

		cin>>request;

	}

	cout<<"--------------------------GOOD BYE----------------------------------"<<endl;

	recv(client, buffer, bufsize, 0);
	cout << buffer << endl;

    close(client);
    return 0;
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
	cout<< "List of Attributes that we can " + function_name + " for the Humans character table"<<endl;
	cout<< list <<endl;
	cout<<"Choose one or as many as you want follow by enter"<<endl;
	cout<<"Type f after you finish typing the attributes and follow by enter"<<endl;
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

string Marvel :: rename(){

	string table_name;
	string query;
	string list;
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
	cout << "1.) Raname Marvel Human Characters Attributes" << endl;
	cout << "2.) Raname Marvel Hero Characters Attributes" << endl;
	cout << "3.) Raname Group Affiliation Attributes" << endl;
	cout << "4.) GO to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Please enter the number of your desired request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1'){
			list = "id,name,height,weight,occupation";
			string query = db.projection_rename_helper("Humans", "rename",list);
			return query;
		}
		else if(request=='2'){
			list = "id,name,height,weight,abilities";
			string query = db.projection_rename_helper("Heros", "rename",list);
			return query;
		
		}
		else if(request=='3'){
			list = "id,name,purposes";
			string query = db.projection_rename_helper("Groups", "rename",list);
			return query;
		
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			//db.Menu();
		}
		
		cout<<endl;
		cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
		cout << "1.) Rename Marvel Human Characters Attributes" << endl;
		cout << "2.) Rename Marvel Hero Characters Attributes" << endl;
		cout << "3.) Rename Group Affiliation Attributes" << endl;
		cout << "4.) GO to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Please enter the number of your desired request" << endl;

		cin>>request;
	}

	db.quit_app();
	return "";

}


string  update_info_helper(string table,string type_name,string thing_to_update){


	string temp;

	cout << "Enter new value for "+ thing_to_update + ": ";
	string new_name;
	getline(cin, new_name);
	temp = "UPDATE ";
	temp += table + " " + "SET "+ thing_to_update +" = ";
	temp += "\"" + new_name + "\"" + " ";
	temp += "WHERE name == ";
	temp += "\"" + type_name + "\"" + ";";

	return temp;

}


string Marvel :: update_info() 
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
			cout << "Enter the Name of the Human you would like to update" <<endl;
			cin.ignore();
			string human_name;
			getline(cin, human_name);

			temp1 = update_info_helper(table,human_name,"name");
			temp2 = update_info_helper(table,human_name,"height");
			temp3 = update_info_helper(table,human_name,"weight");
			temp4 = update_info_helper(table,human_name,"occupation");

			string all = temp1 + "\n" + temp2 + "\n" +  temp3 + "\n" + temp4;

			return all;
			
			
			
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
			
			temp1 = update_info_helper(table,hero_name,"name");
			temp2 = update_info_helper(table,hero_name,"height");
			temp3 = update_info_helper(table,hero_name,"weight");
			temp4 = update_info_helper(table,hero_name,"abilities");

			string all = temp1 + "\n" + temp2 + "\n" +  temp3 + "\n" + temp4;

			return all;
			
			
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
			
			temp1 = update_info_helper(table,group_name,"group");
			temp2 = update_info_helper(table,group_name,"purpose");

			string all = temp1 + "\n" + temp2 + "\n";

			return all;
		}
		else if(request=='4'){
			cout << "Exiting find character Menu" << endl;
			//db.Menu();
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

	return "";
	
}

string Marvel :: find_character() 
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
			 
			
			string temp1;
			string human;
			string table = "Humans";
			cout << "Enter the Name of the Human character you would like to find" <<endl;
			cin.ignore();
			getline(cin, human);
			temp1 = human + " <- " + "select ";
			temp1 += "(name == ";
			temp1 += "\"" + human + "\"" + ") " + table + ";";
			return temp1;
		}

		else if(request=='2') 
		{
			
			string temp2;
			string hero;
			string table = "Heros";
			cout << "Enter the Name of the Hero character you would like to find" <<endl;
			cin.ignore();
			getline(cin, hero);
			temp2 = hero + " <- " + "select ";
			temp2 += "(name == ";
			temp2 += "\"" + hero + "\"" + ") " + table + ";";

			return temp2;
			
		}

		else if(request=='3') 
		{
			
			string temp3;
			string group;
			string table = "Groups";
			cout << "Enter the Name of the Group Affiliation you would like to find" <<endl;
			cin.ignore();
			getline(cin, group);
			temp3 = group + " <- " + "select ";
			temp3 += "(name == ";
			temp3 += "\"" + group + "\"" + ") " + table + ";";
			
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
	temp1 += "\"" + human_occ + "\"" + "); ";

	
	temp2 += "INSERT INTO Heros VALUES FROM (";
	temp2 += "\"" + id + "\"" + ", ";
	temp2 += "\"" + hero_name + "\"" + ", ";
	temp2 += "\"" + hero_height + "\"" + ", ";
	temp2 += "\"" + hero_weight + "\"" + ", ";
	temp2 += "\"" + hero_ab + "\"" + ") ;";
	
	temp3 += "INSERT INTO Groups VALUES FROM (";
	temp3 += "\"" + id + "\"" + ", ";
	temp3 += "\"" + group_aff + "\"" + ", ";
	temp3 += "\"" + group_aff_purp + "\"" + "); ";
	


	string all = temp1 + "\n" + temp2 + "\n" + temp3;
	

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
			query = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
			
			return query;
			
		}
		if(request=='2') {
		
			table = "Heros";
			cout << " Please enter the Super Hero name of the character that you want to delete"<< endl;
			cin.ignore();
			getline(cin, character);
			query = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
		
			return query;
		}
		if(request=='3') {
		
			table = "Groups";
			cout << " Please enter the Group Affiliation name that you want to delete"<< endl;
			cin.ignore();
			getline(cin, character);
			query = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
		
			return query;
		}
		else if(request=='4'){
			cout << "Exiting Delete Character" << endl;
			//db.Menu();
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
	return "";
}

string Marvel :: show_characters()  
{
	
	string table_name;
	string query;
	string quary1;
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
		 
			query = "SHOW Humans;";
			
			return query;
		}
		else if(request=='2'){
			
			query = "SHOW Heros;";
			//quary1 = "SHOW Hero-Humans;";
			string all = query ;
				return all;	
		}
		else if(request=='3'){
			
			query = "SHOW Groups;";
			//quary1 = "SHOW Hero-Groups;";
			string all = query;
				return all;		
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
		cout << "4.) GO to Main Menu"<<endl;
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
			list = "id,name,height,weight,occupation";
			string query = db.projection_rename_helper("Humans", "project",list);
			return query;

		}
		else if(request=='2'){
			list = "id,name,height,weight,abilities";
			string query = db.projection_rename_helper("Heros", "project",list);
			return query;
			
		}
		else if(request=='3'){
			list = "id,name,purpose";
			string query = db.projection_rename_helper("Groups", "project",list);
			return query;	
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			//db.Menu();
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
void  Marvel :: initialize_tables()
{
	
	


/*
INSERT INTO Humans VALUES FROM ("1","Peter Benjamin Parker","510",167,"Peter is an accomplished scientist, inventor, and photographer");
INSERT INTO Humans VALUES FROM ("2","Carol Danvers","511",165,"Ms.Marvel is a skilled pilot and hand to hand combat");
INSERT INTO Humans VALUES FROM ("3","Robert Bruce Banner","76",1150,"Teenager");
INSERT INTO Humans VALUES FROM ("4","Thor Ordinson","66",640,"Arts of War");
INSERT INTO Humans VALUES FROM ("5","Anthony Edward Stark","61",225,"Business Man");
INSERT INTO Humans VALUES FROM ("6","Steven Rogers","62",220,"Martial Arts");
INSERT INTO Humans VALUES FROM ("7","James Howlett","53",300,"Spy,CIA,Soldier");
INSERT INTO Humans VALUES FROM ("8","Unrevealed","510",120,"Actress");
INSERT INTO Humans VALUES FROM ("9","Johann Schmidt","61",195,"Ex military");
INSERT INTO Humans VALUES FROM ("10","Felicia Hardy","510",120,"Gymnast, Acrobat");
INSERT INTO Humans VALUES FROM ("1","Victor von doom","52",225,"Robotics genius");
INSERT INTO Humans VALUES FROM ("12","Medusalish Amaquelin Boltagon","511", 130,"None");
INSERT INTO Humans VALUES FROM ("13","Jeniffer Walters","510",140,"Lawyer");
INSERT INTO Humans VALUES FROM ("14","Dr.Stephen Vincent Strange","62",180,"MD");
INSERT INTO Humans VALUES FROM ("15","T'Challa","60",200,"Scientist");
INSERT INTO Humans VALUES FROM ("16","Mathew Murdock","60",200,"Studies law");
INSERT INTO Humans VALUES FROM ("17","Wade Wilson","62",210,"Assasination");
INSERT INTO Humans VALUES FROM ("18","Thanos","67",985,"Scientist");
INSERT INTO Humans VALUES FROM ("19","Ororo Monroe","511",127,"African priestess");
INSERT INTO Humans VALUES FROM ("20","Charles Francis Xavier","60",190,"School Founder");


INSERT INTO Heros VALUES FROM ("1","SpiderMan","510",167,"Radio active spider senses");
INSERT INTO Heros VALUES FROM ("2","Captain Marvel","511",165,"Flight,Strength,Durability, and shoot energy burst");
INSERT INTO Heros VALUES FROM ("3","Hulk","76",1150,"Super Human Ability");
INSERT INTO Heros VALUES FROM ("4","Thor","66",640,"Skilled Warrior");
INSERT INTO Heros VALUES FROM ("5","Iron Man","61",225,"Genius that invents sophisticated devices");
INSERT INTO HEROS VALUES FROM ("6","Captain America","62",220,"Martial arts");
INSERT INTO Heros VALUES FROM ("7","Wolverine","53",300,"Mastered Combat");
INSERT INTO Heros VALUES FROM ("8","Mystique","510",120,"Skilled Combat, Actress, Marksman");
INSERT INTO Heros VALUES FROM ("9","Red Skull","61",195,"Master of Disguise");
INSERT INTO Heros VALUES FROM ("10","Black Cat","510",120,"Gymnast like Combat");
INSERT INTO Heros VALUES FROM ("11","Dr. Doom","62",225,"Robotics genius, time travel");
INSERT INTO Heros VALUES FROM ("12","Medusa","511",130,"Control the rate of growth and movement of each strand of hair");
INSERT INTO Heros VALUES FROM ("13","She-Hulk","510",140,"Great strength, healing factor");
INSERT INTO Heros VALUES FROM ("14","Dr.Strange","62",180,"Mastery of magic, and trained medicine");
INSERT INTO Heros VALUES FROM ("15","Black Panther","60",200,"Scientist");
INSERT INTO Heros VALUES FROM ("16","Daredevil","60",200,"Strength, Speed, Agility, Gymnastic");
INSERT INTO Heros VALUES FROM ("17","Deadpool","62",210,"Combat, assasination technique");
INSERT INTO Heros VALUES FROM ("18","Thanos","67",985,"Invunerable to electricity, radiation, toxins, aging, and disease");
INSERT INTO Heros VALUES FROM ("19","Storm","511",127,"Control the weather");
INSERT INTO Heros VALUES FROM ("20","Professor X","60",190,"Psionic Founder");



INSERT INTO Groups VALUES FROM ("1","Avengers", "Earths mightest Heros");
INSERT INTO Groups VALUES FROM ("2","Avengers", "Earths mightest Heros");
INSERT INTO Groups VALUES FROM ("3","Avengers", "Earths mightest Heros");
INSERT INTO Groups VALUES FROM ("4","Avengers", "Earths mightest Heros");
INSERT INTO Groups VALUES FROM ("5","Avengers", "Earths mightest Heros");
INSERT INTO Groups VALUES FROM ("6","Avengers", "Earths mightest Heros");
INSERT INTO Groups VALUES FROM ("7","Xmen", "Save Lives");
INSERT INTO Groups VALUES FROM ("8","Xmen", "Save Lives");
INSERT INTO Groups VALUES FROM ("9","Scourge of the Underworld", "Evil");
INSERT INTO Groups VALUES FROM ("10","Heros for Hire", "Investigation");
INSERT INTO Groups VALUES FROM ("11","Knights of the Atomic Table", "Evil");
INSERT INTO Groups VALUES FROM ("12","Illuminati", "Evil");
INSERT INTO Groups VALUES FROM ("13","Lady Liberators", "Heros");
INSERT INTO Groups VALUES FROM ("14","Formerly Avengers", "Earth's mightest Heros");
INSERT INTO Groups VALUES FROM ("15","Formerly Fantastic Four", "Heros");
INSERT INTO Groups VALUES FROM ("16","Formerly Defenders", "Marvel Knights");
INSERT INTO Groups VALUES FROM ("17","XForce", "Heros");
INSERT INTO Groups VALUES FROM ("18","Eternals", "Heros");
INSERT INTO Groups VALUES FROM ("19","Xmen","Saves lives");
INSERT INTO Groups VALUES FROM ("20","Xmen","Saves lives");
*/
	
	
}

void Marvel :: quit_app()
{ 
	exit(0);
}

	
