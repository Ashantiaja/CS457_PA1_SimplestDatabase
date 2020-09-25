#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include <vector>

enum commands_code
{
 createDatabase,
 dropDatabase,
 selectActiveDatabase,
 createTable,
 dropTable,
 selectColumn,
 fromTable,
 alterTable,
 addColumn,
 quitProgram,
 invalidCommand,
 comment
};

#include <iostream>

class CommandParser {
 public:
  CommandParser(const std::string& command = "");
  void processString(const std::string& command);

  commands_code getCode() const { return code; }
  std::size_t getPos() const { return commandPos; }
  std::string getArgAt(int index = 0) { return args[index]; }
  std::string getOrigCommand() const { return ogCommand; }

  void clearParser();
  // debug
  void printArgs() const;

 private:
  std::string ogCommand; // Stores the original command string
  commands_code code; // Stores the code associated w/ command, see enum above
  std::size_t commandPos; // First instance of command in string
  std::vector<std::string> args; // Stores string arguments

  void processArguments(std::string& arg);

  std::size_t strLen(const char* str) const;
  
};

#endif
