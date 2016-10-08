#include "Marvel.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <istream>

using namespace std;

 int main()
 {
	Marvel db;

	db.Menu();
	//--------------------------- Client Socket Code ----------------------------//
	/*
	int client, server;
    int portNum = 5001;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    socklen_t size;

  
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) 
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }


    cout << "\n=> Socket server has been created..." << endl;

  
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);


    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0) 
    {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        return -1;
    }

    

    size = sizeof(server_addr);
    cout << "=> Looking for clients..." << endl;

 
    listen(client, 1);

   

    int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_addr,&size);

    // first check if it is valid or not
    if (server < 0) 
        cout << "=> Error on accepting..." << endl;

    while (server > 0) 
    {
        strcpy(buffer, "=> Server connected...\n");
        send(server, buffer, bufsize, 0);
        cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << endl;
        cout << "\n=> Enter # to end the connection\n" << endl;


        cout << "Client: ";
        do {
            recv(server, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != '*');

        do {
            cout << "\nServer: ";
            do {
                cin >> buffer;
                send(server, buffer, bufsize, 0);
                if (*buffer == '#') {
                    send(server, buffer, bufsize, 0);
                    *buffer = '*';
                    isExit = true;
                }
            } while (*buffer != '*');

            cout << "Client: ";
            do {
                recv(server, buffer, bufsize, 0);
                cout << buffer << " ";
                if (*buffer == '#') {
                    *buffer == '*';
                    isExit = true;
                }
            } while (*buffer != '*');
        } while (!isExit);

        
        cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
        close(server);
        cout << "\nGoodbye..." << endl;
        isExit = false;
        exit(1);
    }

    close(client);
    return 0;
	//-----------------------------------------------------------------------------------------//
	*/
 
 }
 
 void Marvel :: Menu(){ // Marvel Main Menu that displays user options 
	Marvel db;

	cout << "<<<<<<<<<<<<<<<<<< Marvel Main Menu >>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	
	cout << "User Options :" << endl;
	cout << "1.) View Marvel Characters" << endl;
	cout << "2.) View Characters attributes" << endl;
	cout << "3.) Rename character attributes"<<endl;
	cout << "4.) Find Marvel Characters" << endl;
	cout << "5.) Create Marvel Characters" << endl;
	cout << "6.) Delete Marvel Characters" << endl;
	cout << "7.) Update Marvel Characters" << endl;
	cout << "8.) Exit Database" << endl;
	cout << "q.) Quit Application" << endl;// for testing purposes 

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
		cout <<"<<<<<<<<<<<<<<<<<<<<< Marvel Main Menu >>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	
		cout << "User Options :" << endl;
		cout << "1.) View Marvel Characters" << endl;
		cout << "2.) Find Marvel Characters" << endl;
		cout << "3.) Create Marvel Characters" << endl;
		cout << "4.) Delete Marvel Characters" << endl;
		cout << "5.) Update Marvel Characters" << endl;
		cout << "6.) Exit Database" << endl;
		cout << "q.) Quit Application" << endl;// for testing purposes
		cin>>request;

	}

	cout<<"--------------------------GOOD BYE----------------------------------"<<endl;


}
string Marvel :: projection_rename_helper(string table_name, string function_name,string list){ // projection/rename helper functions that manipulates attributes

	string att;
	string store_att;
	string query;
	cout<< "List of Attributes that we can " + function_name + " for the Humans character table"<<endl;
	cout<< list <<endl;
	cout<<"Choose one or as many as you want and press ENTER"<<endl;
	cout<<"To rename , enter the new names in the same order" << endl;
	cout<<"Type f after you finish typing the attributes and press ENTER"<<endl;
	cout<<endl;

	cin>>att;

	while(att != "f"){
		store_att+=att + ",";
		cin>>att;
	}

	string new_att = store_att.substr(0, store_att.size()-1);
	query = function_name+ " (" + new_att +") " + table_name +";";
	cout<<query<<endl;//testing puposes
	return query;

}

void Marvel :: rename(){ // Rename Menu allows user to rename attributes 

	//projection ::= project ( attribute-list ) atomic-expr
	string table_name;
	string query;
	string list;
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
	cout << "1.) Rename Marvel Human Characters Attributes" << endl;
	cout << "2.) Rename Marvel Hero Characters Attributes" << endl;
	cout << "3.) Rename Group Affiliation Attributes" << endl;
	cout << "4.) Go to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Enter the number of your request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1'){
			list = "id,name,height,weight,occupation";
			string query = db.projection_rename_helper("Humans", "rename",list);
		}
		else if(request=='2'){
			list = "id,name,height,weight,abilities";
			string query = db.projection_rename_helper("Heros", "rename",list);
			
		}
		else if(request=='3'){
			list = "id,name,purpose";
			string query = db.projection_rename_helper("Groups", "rename",list);	
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			db.Menu();
		}
		
		cout<<endl;
		cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
		cout << "1.) Rename Marvel Human Characters Attributes" << endl;
		cout << "2.) Rename Marvel Hero Characters Attributes" << endl;
		cout << "3.) Rename Group Affiliation Attributes" << endl;
		cout << "4.) Go to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Enter the number of your request" << endl;

		cin>>request;
	}

	db.quit_app();

}


string  update_info_helper(string table,string type_name,string thing_to_update){ // helper function to update characters for user 


	string temp;

	cout << "Enter new value for "+ thing_to_update + ": ";
	string new_name;
	getline(cin, new_name);
	temp = "UPDATE ";
	temp += table + " " + "SET "+ thing_to_update +" = ";
	temp += "\"" + new_name + "\"" + " ";
	temp += "WHERE(name == ";
	temp += "\"" + type_name + "\"" + ");";
			
	cout << temp << endl; // testing purposes

return temp;

}


void Marvel :: update_info() // update Menu. allows users to update info in the database 
{
	Marvel db;
	cout << "--------------------Update Info Menu --------------------------" << endl;
	
	cout << "1.) Update Marvel Human Characters" << endl;
	cout << "2.) Update Marvel Hero Characters" << endl;
	cout << "3.) Update Group Affiliation" << endl;
	cout << "4.) Go to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Enter the number of your request" << endl;
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
			
			temp1 = update_info_helper(table,hero_name,"name");
			temp2 = update_info_helper(table,hero_name,"height");
			temp3 = update_info_helper(table,hero_name,"weight");
			temp4 = update_info_helper(table,hero_name,"abilities");
			
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
			
			temp1 = update_info_helper(table,group_name,"group");
			temp2 = update_info_helper(table,group_name,"purpose");
		}
		else if(request=='4'){
			cout << "Exiting Find character Menu" << endl;
			db.Menu();
		}

		cout << "--------------------Update Info Menu --------------------------"  << endl;
	
		cout << "1.) Update Marvel Human Characters" << endl;
		cout << "2.) Update Marvel Hero Characters" << endl;
		cout << "3.) Update Group Affiliation" << endl;
		cout << "4.) Go to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Enter the number of your request" << endl;

		cin>>request;

	}


	cout << "Exiting Update Menu" << endl;
	
	db.quit_app();
	
}

void Marvel :: find_character() // Find menu supports the select function in SQL 
{
	Marvel db;

	cout << "--------------------Find Character Menu --------------------------"  << endl;

	cout << "1.) Find Marvel Human Characters" << endl;
	cout << "2.) Find Marvel Hero Characters" << endl;
	cout << "3.) Find Group Affiliation" << endl;
	cout << "4.) Go to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Enter the number of your request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){
	
		if(request=='1') 
		{
			cout << "Need some suggestions??" << endl;
			cout << "Try: Peter Benjamin Parker or Carol Danvers !" << endl << endl ;
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
			cout << "Need some suggestions??" << endl;
			cout << "Try: Spider-Man or Thor!" << endl << endl ;
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
			cout << "Need some suggestions??" << endl;
			cout << "Try: Avengers or X-men !" << endl << endl ;
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
			cout << "Exiting Find character Menu" << endl;
			db.Menu();
		}

		cout << "1.) Find Marvel Human Characters" << endl;
		cout << "2.) Find Marvel Hero Characters" << endl;
		cout << "3.) Find Group Affiliation" << endl;
		cout << "4.) Go to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Enter the number of your request" << endl;
	
		cin>>request;
	}
	cout << "Exiting Find Menu" << endl;

	db.quit_app();
}


void Marvel :: helper_create_character(){ // Helper function to allow user to create a character in the database 

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

	
	cout << "Enter a number after 40, for your character's ID"<< endl;
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
	temp1 += "\"" + human_occ + "\"" + ");";

	
	temp2 += "INSERT INTO Heros VALUES FROM (";
	temp2 += "\"" + id + "\"" + ", ";
	temp2 += "\"" + hero_name + "\"" + ", ";
	temp2 += "\"" + hero_height + "\"" + ", ";
	temp2 += "\"" + hero_weight + "\"" + ", ";
	temp2 += "\"" + hero_ab + "\"" + "); ";
	
	temp3 += "INSERT INTO Groups VALUES FROM (";
	temp3 += "\"" + id + "\"" + ", ";
	temp3 += "\"" + group_aff + "\"" + ", ";
	temp3 += "\"" + group_aff_purp + "\"" + "); ";
	
	cout << temp1 << endl;// testing purposes
	cout << temp2 << endl;
	cout << temp3 << endl;

	
	// Call parser using temp1 temp2 temp3 
}

void Marvel :: create_character() // Creater Character menu supports insert into/ create functions in SQL 
{

	Marvel db;

	helper_create_character();
	
	cout << "Awesome, Your character was created !"<<endl;

	cout<<"--------Created Character Options ------------";
	cout << "1.) I want to create another character" << endl;
	cout << "2.) Go to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Enter the number of your request" << endl;

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
		cout << "2.) Go to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Enter the number of your request" << endl;

		cin>>request;
	}

	db.quit_app();
	
}

void Marvel :: delete_character() //Delete Menu allows user to delete characters from the database 
{
	Marvel db;
	string query;
	string character;
	string table;

	cout<<"<<<<<<<<<<<<<<<<<<< Delete Character Options >>>>>>>>>>>>>>>>>>"<<endl;
	cout << "1.) I want to Delete a Human character" << endl;
	cout << "2.) I want to Delete a Super Hero character" << endl;
	cout << "3.) I want to Delete a Group Affiliation" << endl;
	cout << "4.) Go toMain Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Enter the number of your request" << endl;

	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1') {
			
			string table = "Humans";
			cout << " Enter the Human name that you want to delete"<< endl;
			cin.ignore();
			getline(cin, character);
			query = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
			cout<<query<<endl; //testing purposes
			
		}
		if(request=='2') {
		
			table = "Heros";
			cout << " Enter the Super Hero name that you want to delete"<< endl;
			cin.ignore();
			getline(cin, character);
			query = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
			cout<<query<<endl; //testing purposes
		}
		if(request=='3') {
		
			table = "Groups";
			cout << " Enter the Group name that you want to delete"<< endl;
			cin.ignore();
			getline(cin, character);
			query = "DELETE FROM " + table + " WHERE(name == " + "\"" + character + "\"" + ");";
			cout<<query<<endl; //testing purposes
		}
		else if(request=='4'){
			cout << "Exiting Delete Character Menu" << endl;
			db.Menu();
		}

		cout << "Awesome, Your character was deleted !"<<endl;
		cout<<endl;

		
		cout<<"<<<<<<<<<<<<<<<<<<< Delete Character Options >>>>>>>>>>>>>>>>>>"<<endl;
		cout << "1.) I want to Delete a Human character" << endl;
		cout << "2.) I want to Delete a Super Hero character" << endl;
		cout << "3.) I want to Delete a Group Affiliation" << endl;
		cout << "4.) Go to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Enter the number of your request" << endl;

		cin>>request;
	}

	db.quit_app();
}

void Marvel :: show_characters() // Show Menu allows user to see all of the characters in the database
{	
	string table_name;
	string query1;
	string query2;
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<<<<<<<<<<<<< Show Character Menu >>>>>>>>>>>>>>>>>>"  << endl;
	cout << "1.) Show Marvel Human Characters" << endl;
	cout << "2.) Show Marvel Hero Characters" << endl;
	cout << "3.) Show Group Affiliation" << endl;
	cout << "4.) Go to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Enter the number of your request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1') {
		 
			query1 = "SHOW Humans;";
			query2 = "SHOW Hero-Humans;";
			cout<<query1<<endl;
			cout<<query2<<endl;	
		}
		else if(request=='2'){
			
			query1 = "SHOW Heros;";
			cout<<query1<<endl;
		}
		else if(request=='3'){
			
			query1 = "SHOW Groups;";
			query2 = "SHOW Hero-Groups;";
			cout<<query1<<endl;	
			cout<<query2<<endl;	
		}
		else if(request=='4'){
			cout << "Exiting Show Menu" << endl;
			db.Menu();
		}

		cout<<endl;
		cout << "<<<<<<<<<<<<<<<<<<< Show Character Menu >>>>>>>>>>>>>>>>>>"   << endl;
		cout << "1.) Show Marvel Human Characters" << endl;
		cout << "2.) Show Marvel Hero Characters" << endl;
		cout << "3.) Show Group Affiliation" << endl;
		cout << "4.) Go to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Enter the number of your request" << endl;

		cin>>request;
	}
	
	db.quit_app();
}



void Marvel :: show_attribute(){//Projection SQL function Support 


	string table_name;
	string query;
	string list;
	Marvel db;
	
	cout<<endl;
	cout << "<<<<<<<<<<<<<<<<<<< Show Character Attributes Menu >>>>>>>>>>>>>>>>>>"  << endl;
	cout << "1.) Show Marvel Human Characters Attributes" << endl;
	cout << "2.) Show Marvel Hero Characters Attributes" << endl;
	cout << "3.) Show Group Affiliation Attributes" << endl;
	cout << "4.) Go to Main Menu"<<endl;
	cout << "q.) Quit Application"<<endl;
	cout << "Enter the number of your request" << endl;
	
	char request;
	cin >> request;

	while(request != 'q'){

		if(request=='1'){
			list = "id,name,height,weight,occupation";
			string query = db.projection_rename_helper("Humans", "project",list);
		}
		else if(request=='2'){
			list = "id,name,height,weight,abilities";
			string query = db.projection_rename_helper("Heros", "project",list);
			
		}
		else if(request=='3'){
			list = "id,name,purpose";
			string query = db.projection_rename_helper("Groups", "project",list);	
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
		cout << "4.) Go to Main Menu"<<endl;
		cout << "q.) Quit Application"<<endl;
		cout << "Enter the number of your request" << endl;

		cin>>request;
	}

	db.quit_app();

}

void Marvel :: quit_app()
{ 
	exit(0);
}

	
