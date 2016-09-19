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
 void create(string, vector<attributes>, vector<string>);
 void insert();
 void destoy();
 void update();
};

#endif
