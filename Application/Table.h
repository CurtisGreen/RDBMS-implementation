#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>



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
  void setName(string table_name );
  vector<Attribute> getAttributes() const {return att;}

  Table(string new_name, vector<Attribute> new_att, vector<string> new_id);
  Table();

  //void addAttribute(Attribute t);
  Table(const Table& table);
  istream& Read(istream& input);
  ostream& Write(ostream& output);
  std::string to_string(Table t);

 
};

// input & out put operators >> << 
istream& operator >> (istream& input, Table& t); 
ostream& operator << (ostream& output, Table& t);
#endif
