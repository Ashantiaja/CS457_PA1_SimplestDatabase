#include "database.h"

Database::Database(std::string n) {
  name = n;
}

Database::~Database() { }

bool Database::addTable() {
  return true;
}

bool Database::removeTable() {
  return true;
}

void Database::setName(std::string newName) {
  name = newName;
}

std::string Database::getName() {
  return name;
}
