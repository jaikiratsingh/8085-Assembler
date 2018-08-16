#include "Rule.h"

Rule::Rule(std::string opcode, std::string hexCode, int operandCnt) {
  this->opcode = opcode;
  this->hexCode = hexCode;
  this->operandCnt = operandCnt;
}
