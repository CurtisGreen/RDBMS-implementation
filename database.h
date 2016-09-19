//database header

#ifndef _database.h_
#define _database.h_

#include <vector>
#include <iostream>

class table{
  std::vector<std::string> headers;
  std::vector<std::vector<std::string>> data;
};

#endif
