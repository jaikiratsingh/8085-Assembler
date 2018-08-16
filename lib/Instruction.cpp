#include "Instruction.h"

Instruction::Instruction(std::string rawLine) {
  this->rawLine = rawLine;
  this->OpCode = "";
  this->comment = "";
  this->label = "";
  (this->registers).insert("CMP");
  (this->registers).insert("ANA");
  (this->registers).insert("XRA");
  (this->registers).insert("ORA");
  (this->registers).insert("ADD");
  (this->registers).insert("ADC");
  (this->registers).insert("SUB");
  (this->registers).insert("SBB");
  (this->registers).insert("INR");
  (this->registers).insert("DCR");
  (this->registers).insert("MVI");

  (this->registerPairs).insert("LXI");
  (this->registerPairs).insert("INX");
  (this->registerPairs).insert("DCX");
  (this->registerPairs).insert("DAD");
  (this->registerPairs).insert("LDAX");
  (this->registerPairs).insert("STAX");
  (this->registerPairs).insert("PUSH");
  (this->registerPairs).insert("POP");
}

// this function will parse the instruction stored in the instruction
void Instruction::parseInstruction() {
  // adding an extra space at the end to save the edge cases
  this->rawLine += ' ';

  // check if the line is a comment
  if(isComment() || isEmpty()) {
    return ;
  }

  // check if the line has a label
  if(hasLabel()) {
    extractLabel();
  }

  extractOpcode();
  extractOperands();

  handleRegisterCases();
}

// checks if the line is comment or not
bool Instruction::isComment() {
  int index = 0;
  for(; index < (this->rawLine).length(); index++) {
    char thisChar = (this->rawLine)[index];

    if(thisChar >= 'A' && thisChar <= 'Z') return false;
    if(thisChar >= 'a' && thisChar <= 'z') return false;
    if(thisChar == ';') return true;
  }
  return false;
}

// checks if the line is just an empty line
bool Instruction::isEmpty() {
  int index = 0;
  for(; index < (this->rawLine).length(); index++) {
    char thisChar = (this->rawLine)[index];

    if(thisChar != 32 && thisChar != 9) return false;
  }

  return true;
}

// checks if the line has a Label or not
bool Instruction::hasLabel() {
  int index = 0;
  for(; index < (this->rawLine).length(); index++) {
    char thisChar = (this->rawLine)[index];

    if(thisChar == ':') return true;
  }

  return false;
}

// extract the label from the line. This function will only be called if hasLabel() has returned true
void Instruction::extractLabel() {
  std::string tempLabel = "";
  int index = 0;

  int colonIndex = -1;  // index where colon exists

  for(; index < (this->rawLine).length(); index++) {
    char thisChar = (this->rawLine)[index];
    if(thisChar == ':') {
      colonIndex = index;
      break;
    }
    if(thisChar != 32 && thisChar != 9) {
      tempLabel += thisChar;
    }
  }

  // changing label to all Upper Case
  for(int i = 0; i < (int)tempLabel.length(); i++) {
    char thisChar = tempLabel[i];
    if(thisChar >= 'a' && thisChar <= 'z') {
      thisChar = (char)(thisChar - 'a' + 'A');
    }
    tempLabel[i] = thisChar;
  }

  this->label = tempLabel;

  if(colonIndex+1 >= (this->rawLine).length()) {
    //ERROR
  }

  this->rawLine = (this->rawLine).substr(colonIndex+1, ((this->rawLine).length() - colonIndex));
}

//extract the opcode from the line
void Instruction::extractOpcode() {
  std::string tempOpcode = "";

  int index = 0;

  // traverse till the string has spaces or tabs
  for(; index < (this->rawLine).length(); index++) {
    char thisChar = (this->rawLine)[index];

    if(thisChar != 32 && thisChar != 9) {
      break;
    }
  }

  int opCodeEnd = -1; // index where opCode ends

  for(; index < (this->rawLine).length(); index++) {
    char thisChar = (this->rawLine)[index];

    if(thisChar == 32 || thisChar == 9) {
      opCodeEnd = index;
      break;
    }else {
      tempOpcode += thisChar;
    }
  }

  // changing label to all Upper Case
  for(int i = 0; i < (int)tempOpcode.length(); i++) {
    char thisChar = tempOpcode[i];
    if(thisChar >= 'a' && thisChar <= 'z') {
      thisChar = (char)(thisChar - 'a' + 'A');
    }
    tempOpcode[i] = thisChar;
  }

  if(opCodeEnd+1 >= (this->rawLine).length()) {
    //ERROR
  }

  this->OpCode = tempOpcode;
  this->rawLine = (this->rawLine).substr(opCodeEnd, (this->rawLine).length() - opCodeEnd);
}

// extracts operands from the given rawLine
void Instruction::extractOperands() {
  int index = 0;
  for(; index < (this->rawLine).length(); index++) {
    char thisChar = (this->rawLine)[index];

    if(thisChar != 32 && thisChar != 9) {
      break;
    }
  }

  while(index < (this->rawLine).length()) {
    int start = index;  // operand starts here
    int stop = index;
    while(index < (this->rawLine).length()) {
      char thisChar = (this->rawLine)[index];

      if(thisChar == 9 || thisChar == 32 || thisChar == ',') {
        stop = index-1;
        break;
      }else {
        index++;
      }
    }

    std::string presentOperand = (this->rawLine).substr(start, stop - start + 1);
    (this->operands).push_back(presentOperand);

    index++;

    // traverse forward to delete all spaces and tabs
    while(index < (this->rawLine).length()) {
      char thisChar = (this->rawLine)[index];

      if(thisChar != 9 && thisChar != 32 && thisChar != ',') {
        break;
      }
      index++;
    }
  }
}

void Instruction::handleRegisterCases() {
  if((this->registers).find(this->OpCode) != (this->registers).end()){
    this->OpCode += ' ';
    this->OpCode += (this->operands)[0];
    (this->operands).erase((this->operands).begin(), next((this->operands).begin()));
  }else if((this->registerPairs).find(this->OpCode) != (this->registerPairs).end()) {
    this->OpCode += ' ';
    this->OpCode += (this->operands)[0];
    (this->operands).erase((this->operands).begin(), next((this->operands).begin()));
  }else if((this->OpCode) == "MOV") {
    this->OpCode += ' ';
    this->OpCode += (this->operands)[0];
    this->OpCode += ',';
    this->OpCode += (this->operands)[1];
    (this->operands).erase((this->operands).begin(), next(next((this->operands).begin())));
  }
}
