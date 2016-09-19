//database header

#ifndef _databaseh_
#define _databaseh_

#include "Attribute.h"

using namespace std;

class Table{
public:
  string name;
  vector<string> attributes;
};

class Database{
 
 public:
	void open();
	void close();
	void write();
	void exit();
	void show();
	void create(string, vector<Attribute>, vector<string>);
	void insert(string name, vector<Attribute> att);
	void update();
	void destroy();	//because delete is a keyword
};

#endif
