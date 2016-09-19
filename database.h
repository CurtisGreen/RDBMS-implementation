//database header

#ifndef _databaseh_
#define _databaseh_

#include <vector>
#include <iostream>

class table{
public:
  std::string name;
  std::vector<std::string> attributes;
};

class database{
 
 public:
 void create();
 void insert();
 void destoy();
 void update();
};

#endif
