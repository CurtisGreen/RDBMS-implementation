//database header

#ifndef _databaseh_
#define _databaseh_

#include <vector>
#include <iostream>

using namespace std;

class table{
public:
  string name;
  vector<string> attributes;
};

class database{
 
 public:
	void open();
	void close();
	void write();
	void exit();
	void show();
	void create(string, vector<Attribute>, vector<string>);
	void insert();
	void update();
	void destroy();	//because delete is a keyword
};

#endif
