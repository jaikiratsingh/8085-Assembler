#ifndef _RULE_H_
#define _RULE_H_
#include <string>

class Rule {
  // private :
  public :
    std::string opcode;
    std::string hexCode;
    int operandCnt;
    Rule(std::string opcode, std::string hexCode, int operandCnt);
};

#endif
