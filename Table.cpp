#include "Table.h"

using namespace std;

Table :: Table(string new_name, vector<Attribute> new_att, vector<string> new_id)
{
	
	name = new_name;
  	att = new_att;
  	id = new_id;
}
Table::Table(){}
string Table:: getName()
{
	return name;
}