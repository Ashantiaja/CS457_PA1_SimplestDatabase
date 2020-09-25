#include "commandParser.h"

CommandParser::CommandParser(const std::string& command) {
  processString(command);
}

void CommandParser::clearParser() {
  code = invalidCommand;
  commandPos = -1;
  args.clear();
  ogCommand = "";
}

void CommandParser::processString(const std::string& command) {

  clearParser();
  ogCommand = command;
  std::string arg = ""; // Buffer for possible arguments

  // Check if comment
  if(command.find("--") == 0) {
    code = comment;
    commandPos = 0;
    return;
  }

  // Start processing commands
  if(command.find("CREATE DATABASE") != std::string::npos) {
    code = createDatabase;
    commandPos = command.find("CREATE DATABASE");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("CREATE DATABASE") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }
  
  if(command.find("DROP DATABASE") != std::string::npos) {
    code = dropDatabase;
    commandPos = command.find("DROP DATABASE");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("DROP DATABASE") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }

  if(command.find("USE") != std::string::npos) {
    code = selectActiveDatabase;
    commandPos = command.find("USE");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("USE") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }

  if(command.find("CREATE TABLE") != std::string::npos) {
    code = createTable;
    commandPos = command.find("CREATE TABLE");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("CREATE TABLE") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }

  if(command.find("DROP TABLE") != std::string::npos) {
    code = dropTable;
    commandPos = command.find("DROP TABLE");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("DROP TABLE") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }

  if(command.find("SELECT") != std::string::npos) {
    code = selectColumn;
    commandPos = command.find("SELECT");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("SELECT") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }

  if(command.find("FROM") != std::string::npos) {
    code = fromTable;
    commandPos = command.find("FROM");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("FROM") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }

  if(command.find("ALTER TABLE") != std::string::npos) {
    code = alterTable;
    commandPos = command.find("ALTER TABLE");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("ALTER TABLE") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }

  if(command.find("ADD") != std::string::npos) {
    code = addColumn;
    commandPos = command.find("ADD");

    // Process additional Arguments if existing
    try {
      arg = command.substr(strLen("ADD") + 1);
      processArguments(arg);
    }
    catch (...) {
      // No additional arguments, proceed
    }
    return;
  }

  // No Valid Command
}

void CommandParser::processArguments(std::string& arg) {
  // Version 2 of Argument Parser
  std::string remaining = "";

  // Change... the other chars to spaces...
  // Not the best idea, but it's easy to work with for now
  // Change this later
  while(arg.find('(') != std::string::npos) {
    arg[arg.find('(')] = ' ';
  }
  while(arg.find(')') != std::string::npos) {
    arg[arg.find(')')] = ' ';
  }
  while(arg.find(',') != std::string::npos) {
    arg[arg.find(',')] = ' ';
  }
  while(arg.find(';') != std::string::npos) {
    arg[arg.find(';')] = ' ';
  }

  // Ok, actually process the arguments...
  while(!arg.empty()) {
    // If first char is space, eliminate the space until first non space
    // character is reached
    if(arg.at(0) == ' ') {
      try {
	arg = arg.substr(1);
	continue;
      } catch (...) { // most likely case is out of bounds if space was the only element
	arg.clear(); 
      }
    } // end if

    // If space still remains somewhere, then assume
    // more arguments to follow
    // otherwise last argument
    if(arg.find(' ') != std::string::npos) {
      remaining = arg.substr(arg.find(' '));
      // Store current argument into vector
      arg = arg.erase(arg.find(' ')); 
      args.push_back(arg);
      // Rest of arguments stored into arg
      arg = remaining;
    } else { // last argument
      args.push_back(arg);
      arg.clear();
    } // end if

  } // end while
}

// debug
void CommandParser::printArgs() const {
  for(int i = 0; i < args.size(); i++) {
    std::cout << i << ": " << args[i] << ' ';
  }
  std::cout << std::endl;
}

std::size_t CommandParser::strLen(const char* str) const {
  size_t l = 0;
  for(; *str != 0; ++str) ++l;
  return l;
}
