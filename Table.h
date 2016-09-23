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
  vector<Attribute>tuple;
  
  
  string getName();
  vector<Attribute> getAttributes() const {return att;}

  Table(string new_name, vector<Attribute> new_att, vector<string> new_id);
  Table();
<<<<<<< HEAD
  //void addAttribute(Attribute t);
=======
  Table(const Table& table);
  
>>>>>>> 7166c85a52b2a7f586080322e21a13ab67fe3e71
  istream& Read(istream& input);
  ostream& Write(ostream& output);
 
};

// input & out put operators >> << 
istream& operator >> (istream& input, Table& t); 
ostream& operator << (ostream& output, Table& t);
#endif
