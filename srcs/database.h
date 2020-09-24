// Author  : Ash Yveth Cudiamat
// Date due: 09 24 2020

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "table.h"

class Database {
public:
  Database(std::string n);
  ~Database();

  bool addTable();
  bool removeTable();

  void setName(std::string newName);
  std::string getName();

  // vector<Table> tables;

private:
  std::string name;
};

#endif
