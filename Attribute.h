#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H 

using namespace std;

class Attribute 
{
	private:
	string name;
	string type;
	vector <string> data;

	
	public:
	Attribute();
	Attribute (string name_ , string type_ , vector <string> data_);
	
};

#endif
