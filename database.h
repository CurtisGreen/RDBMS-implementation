//database header

#ifndef _databaseh_
#define _databaseh_

#include <vector>
#include <iostream>

class table{

  std::string name;
  std::vector<std::string> headers;
  std::vector< std::vector<std::string> > data;


};

#endif
