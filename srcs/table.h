// Author  : Ash Yveth Cudiamat
// Date due: 09 24 2020

#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>

#include "column.h"

class Table {
 public:
  Table();
  ~Table();

  bool addColumn();
  bool removeColumn();
  
};

#endif
