#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H 

#include <vector>

class Attribute 
{
	private:
	string name;
	string type;
	vector <string> data;
	Attribute (string name , string type , vector <string> data);
	
	public:
	Attribute();
	~Attribute();
	
};

#endif