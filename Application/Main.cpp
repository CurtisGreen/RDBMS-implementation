#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


#include "Table.h"
#include "Attribute.h"
#include "Engine.h"
#include "Parser.h"
#include "Token_stream.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main()
{
  
    int client, server;
    int portNum = 5031;
    bool isExit = false;
    int bufsize = 15000;
    char buffer[bufsize];
	struct sockaddr_in server_addr;
    socklen_t size;
	client = socket(AF_INET, SOCK_STREAM, 0);
	if (client < 0) {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }
	cout << "\n=> Socket server has been created..." << endl;
	server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);
	if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0) {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        return -1;
    }
	size = sizeof(server_addr);
    cout << "=> Looking for clients..." << endl;
	listen(client, 1);
	int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_addr,&size);
	if (server < 0) 
        cout << "=> Error on accepting..." << endl;

	
	//---------------------------------------------------------------------------------------------------------------------------------------------
	//ORIGINAL TABLES IN THE MARVEL DATABASE 
	string s1 = "CREATE TABLE Humans (name VARCHAR(20), height VARCHAR(10), weight INTEGER, occupation VARCHAR(8)) PRIMARY KEY (name);";
	string s2 = "CREATE TABLE Heroes (name VARCHAR(20), height VARCHAR(10), weight INTEGER, abilities VARCHAR(8)) PRIMARY KEY (name);";
	string s3 = "CREATE TABLE Groups (name VARCHAR(20), purpose VARCHAR(8)) PRIMARY KEY (name);";
	string s4 = "INSERT INTO Humans VALUES FROM (PPeter_Parker, 510, 167, Photographer);";
	string s5 = "INSERT INTO Humans VALUES FROM (CCarol_Danvers, 511, 165, Pilot);";
	string s6 = "INSERT INTO Humans VALUES FROM (RRobert_Banner, 66, 640, Teenager);";
	string s7 = "INSERT INTO Humans VALUES FROM (TThor_Ordison, 62, 220, War);";
	string s8 = "INSERT INTO Humans VALUES FROM (AAnthonyStark, 61, 225, BusinessMan);";
	
	string s9 = "INSERT INTO Humans VALUES FROM (OOroro_Monroe, 511, 127, African_Priestest);";
	string s10 = "INSERT INTO Humans VALUES FROM (CCharles_Xavier, 60, 190, Teacher);";
	string s11 = "INSERT INTO Humans VALUES FROM (JJean_Summers, 56, 115, Telekinestic);";
	string s12 = "INSERT INTO Humans VALUES FROM (HHenry_McCoy, 511, 402, Teachers_Assistant);";
	string s13 = "INSERT INTO Humans VALUES FROM (KKurtWagner, 59, 195, Adventurer);";
	
	string s14 = "INSERT INTO Heroes VALUES FROM (SSpider_Man, 510, 167, Spider_Senses);";
	string s15 = "INSERT INTO Heroes VALUES FROM (CCaptain_Marvel, 511, 165, Skilled_Combat);";
	string s16 = "INSERT INTO Heroes VALUES FROM (HHulk, 66, 640, Super_Human);";
	string s17 = "INSERT INTO Heroes VALUES FROM (TThor, 62, 220, War);";
	string s18 = "INSERT INTO Heroes VALUES FROM (IIronMan, 61, 225, Genius);";
	
	string s19 = "INSERT INTO Heroes VALUES FROM (SStorm, 511, 127, Control_Weather);";
	string s20 = "INSERT INTO Heroes VALUES FROM (PProfessorX, 60, 190, Psionic_Founder);";
	string s21 = "INSERT INTO Heroes VALUES FROM (JJean_Grey, 56, 115, Telepathic);";
	string s22 = "INSERT INTO Heroes VALUES FROM (BBeast, 511, 402, Super_Strength);";
	string s23 = "INSERT INTO Heroes VALUES FROM (NNightCrwaler, 59, 195, Teleportation);";
	
	string s24 = "INSERT INTO Groups VALUES FROM (AAvengers, Heroes);";
	string s25 = "INSERT INTO Groups VALUES FROM (AAvengers, Heroes);";
	string s26 = "INSERT INTO Groups VALUES FROM (AAvengers, Heroes);";
	string s27 = "INSERT INTO Groups VALUES FROM (AAvengers, Heroes);";
	string s28 = "INSERT INTO Groups VALUES FROM (AAvengers, Heroes);";
	
	string s29 = "INSERT INTO Groups VALUES FROM (XXmen, Heroes);";
	string s30 = "INSERT INTO Groups VALUES FROM (XXmen, Heroes);";
	string s31 = "INSERT INTO Groups VALUES FROM (XXmen, Heroes);";
	string s32 = "INSERT INTO Groups VALUES FROM (XXmen, Heroes);";
	string s33 = "INSERT INTO Groups VALUES FROM (XXmen, Heroes);";
	

	string all = s1+s2+s3 +s4+s5+s6 +s7+s8+s9+s10+s11+s12+s13+s14+s15+s16+s17+s18+s19+s20+s21+s22+s23+s24+s25+s26+s27+s28+s29+s30+s31+s32 +s33;
	//---------------------------------------------------------------------------------------------------------------------------------------------
	Parser p;
   	p.parse(all);
   	p.input();

    while (server > 0) 
    {
		
        strcpy(buffer, "=> Server connected...\n");
		send(server,buffer,bufsize, 0); // Connects to CLIENT
        cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << endl;
        cout << "\n=> Enter # to end the connection\n" << endl;

		while(*buffer != '*'){

		recv(server, buffer, bufsize, 0); // RECEIVES from the CLIENT 
		//cout<<"Buffer Server::::"<<buffer<<endl;
		p.parse(buffer);
		p.input();

		send(server,p.ts.output.c_str(), bufsize, 0);// SENDS what is in buffer TO CLIENT 
			p.ts.output = "";
		}
        
	}
	
	
	close(client);
    return 0;
 
}

   
