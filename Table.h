#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include <iostream>

using namespace std;

#include "Attribute.h"

class Table
{
public:

  string name;
  vector<string> id;
  vector<Attribute> att;
  
  
  string getName();

  Table(string new_name, vector<Attribute> new_att, vector<string> new_id);
  Table();
 
};

#endif
