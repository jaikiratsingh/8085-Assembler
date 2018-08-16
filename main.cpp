#include <iostream>
#include <vector>
#include "lib/Instruction.h"
#include "lib/opcodes.h"

// converts char * to string
std::string toString(char *str);
std::string increaseAddress(std::string label);

int main(int argc, char **argv) {
  // checking if file name is specified
  if(argc == 1) {
    std::cout << "Please Enter the File Name" << std::endl;
    return 0;
  }

  std::string startingAddress;

  if(argc == 2) {
    startingAddress = "2000";
  }else {
    startingAddress = toString(argv[2]);
    startingAddress = startingAddress.substr(0, 4);

    for(int i = 0; i < 4; i++) {
      startingAddress[i] = toupper(startingAddress[i]);
    }
  }

  std::map<std::string, Rule *> *mp = mapOpcodes();
  std::map<std::string, std::string> *labels = new std::map<std::string, std::string>();

  // opening file
  char *fileName = argv[1];
  freopen(fileName, "r", stdin);

  // vector of Instructions
  std::vector<Instruction *> instructions;

  // reading till the end of file
  std::string line;
  while(getline(std::cin, line)) {
    // convert full line to UpperCase
    for(int i = 0; i < line.size(); i++) {
      line[i] = toupper(line[i]);
    }
    instructions.push_back(new Instruction(line));
  }

  // parsing each instruction individually
  for(int i = 0; i < (int)instructions.size(); i++) {
    instructions[i]->parseInstruction();
  }

  // currAddress is the address of the current instruction
  std::string currAddress = startingAddress;

  // storing labels in the whole input file
  std::map<std::string, Rule *>::iterator it;
  for(int i = 0; i < (int)instructions.size(); i++) {
    it = mp->find(instructions[i]->OpCode);

    if(it == mp->end()) continue;

    if(instructions[i]->label != "") {
      labels->insert(std::make_pair(instructions[i]->label, currAddress));
    }

    if((it->second)->operandCnt == 0) {
      currAddress = increaseAddress(currAddress);
    }else if((it->second)->operandCnt == 1) {
      currAddress = increaseAddress(currAddress);
      currAddress = increaseAddress(currAddress);
    }else if((it->second)->operandCnt == 2) {
      currAddress = increaseAddress(currAddress);
      currAddress = increaseAddress(currAddress);
      currAddress = increaseAddress(currAddress);
    }
  }

  currAddress = startingAddress;

  // printing text for each instructions
  for(int i = 0; i < (int)instructions.size(); i++) {
    it = mp->find(instructions[i]->OpCode);

    if(it == mp->end()) continue;

    std::cout << (it->second)->hexCode << std::endl;

    if((it->second)->operandCnt == 0) {
      currAddress = increaseAddress(currAddress);
    }else if((it->second)->operandCnt == 1) {
      currAddress = increaseAddress(currAddress);
      currAddress = increaseAddress(currAddress);
      std::cout << (instructions[i]->operands[0]).substr(0, 2) << std::endl;
    }else if((it->second)->operandCnt == 2) {
      currAddress = increaseAddress(currAddress);
      currAddress = increaseAddress(currAddress);
      currAddress = increaseAddress(currAddress);
      // either LABEL or ADDRESS
      std::map<std::string, std::string>::iterator label = labels->find(instructions[i]->operands[0]);
      if(label != labels->end()) {
        // if label
        std::string op1 = (label->second).substr(0, 2);
        std::string op2 = (label->second).substr(2, 2);

        std::cout << op2 << std::endl;
        std::cout << op1 << std::endl;
      }else {
        // if address by checking if operan exists in Label
        std::string op1 = (instructions[i]->operands[0]).substr(0, 2);
        std::string op2 = (instructions[i]->operands[0]).substr(2, 2);

        std::cout << op2 << std::endl;
        std::cout << op1 << std::endl;
      }
    }
  }

  return 0;
}

// converts char * to string
std::string toString(char *str) {
  int n = strlen(str);

  std::string retString = "";

  for(int i = 0; i < n; i++) {
    retString += str[i];
  }

  return retString;
}

// increase the value of label
std::string increaseAddress(std::string label) {
  int index = 3;

  while(1) {
    if(label[index] == 'F') {
      label[index] = '0';
      index--;
      continue;
    }else {
      if(label[index] == '9') {
        label[index] = 'A';
      }else {
        label[index] = (char)(label[index] + 1);
      }

      break;
    }
  }

  return label;
}
