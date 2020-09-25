// Author  : Ash Yveth Cudiamat
// Date due: 09 24 2020

#include <iostream>
#include <string>

#include "database.h"
#include "commandParser.h"

int main(int argc, char *argv[]) {

  std::string command = "";
  CommandParser parser = CommandParser();
  Database* activeDatabase = nullptr;

  while(command != ".EXIT") {
    
    std::cout << ">>";
    std::getline(std::cin,command);

    parser.processString(command);
    /*std::cout << "Code: " << parser.getCode() << std::endl
	      << "Command Position: " << parser.getPos() << std::endl
	      << "Args: ";*/

    switch(parser.getCode()) {
    case invalidCommand:
      std::cout << "Invalid command." << std::endl;
      break;
    case comment:
      break;
    }
  }

  return 0;
}
