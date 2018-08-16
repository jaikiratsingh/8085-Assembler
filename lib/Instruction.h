#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include "Rule.h"

class Instruction {
  private :
    bool isComment(); // checks if the line is just a comment
    bool isEmpty(); // checks if the line is an empty line
    bool hasLabel();  //checks if the line has a label or not
    void extractLabel();  // extracts the label out of the line, if there is one
    void extractOpcode(); // extracts the opcode from the line
    void extractOperands(); // extracts operands from the line
    void handleRegisterCases();
    std::set<std::string> registers;
    std::set<std::string> registerPairs;
  public :
    std::string OpCode;
    std::vector<std::string> operands;
    std::string comment;
    std::string label;
    std::string rawLine;
    bool error;

    Instruction(std::string rawLine);
    void parseInstruction();
};

#endif
