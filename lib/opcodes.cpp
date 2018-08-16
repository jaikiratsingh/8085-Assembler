#include "opcodes.h"

std::map<std::string, Rule *> *mapOpcodes() {
  std::map<std::string, Rule *> *opcodes = new std::map<std::string, Rule *>();

  // Control instructions
  opcodes->insert(std::make_pair("NOP", new Rule("NOP", "00", 0)));
  opcodes->insert(std::make_pair("HLT", new Rule("HLT", "76", 0)));
  opcodes->insert(std::make_pair("DI", new Rule("DI", "F3", 0)));
  opcodes->insert(std::make_pair("EI", new Rule("EI", "FB", 0)));
  opcodes->insert(std::make_pair("RIM", new Rule("RIM", "20", 0)));
  opcodes->insert(std::make_pair("SIM", new Rule("SIM", "30", 0)));


  // Logical Instructions
  opcodes->insert(std::make_pair("CMP B", new Rule("CMP B", "B8", 0)));
  opcodes->insert(std::make_pair("CMP C", new Rule("CMP C", "B9", 0)));
  opcodes->insert(std::make_pair("CMP D", new Rule("CMP D", "BA", 0)));
  opcodes->insert(std::make_pair("CMP E", new Rule("CMP E", "BB", 0)));
  opcodes->insert(std::make_pair("CMP H", new Rule("CMP H", "BC", 0)));
  opcodes->insert(std::make_pair("CMP L", new Rule("CMP L", "BD", 0)));
  opcodes->insert(std::make_pair("CMP M", new Rule("CMP M", "BE", 0)));
  opcodes->insert(std::make_pair("CMP A", new Rule("CMP A", "BF", 0)));

  opcodes->insert(std::make_pair("CPI", new Rule("CPI", "FE", 1)));

  opcodes->insert(std::make_pair("ANA B", new Rule("ANA B", "A0", 0)));
  opcodes->insert(std::make_pair("ANA C", new Rule("ANA C", "A1", 0)));
  opcodes->insert(std::make_pair("ANA D", new Rule("ANA D", "A2", 0)));
  opcodes->insert(std::make_pair("ANA E", new Rule("ANA E", "A3", 0)));
  opcodes->insert(std::make_pair("ANA H", new Rule("ANA H", "A4", 0)));
  opcodes->insert(std::make_pair("ANA L", new Rule("ANA L", "A5", 0)));
  opcodes->insert(std::make_pair("ANA M", new Rule("ANA M", "A6", 0)));
  opcodes->insert(std::make_pair("ANA A", new Rule("ANA A", "A7", 0)));

  opcodes->insert(std::make_pair("ANI", new Rule("ANI", "E6", 1)));

  opcodes->insert(std::make_pair("XRA B", new Rule("XRA B", "A8", 0)));
  opcodes->insert(std::make_pair("XRA C", new Rule("XRA C", "A9", 0)));
  opcodes->insert(std::make_pair("XRA D", new Rule("XRA D", "AA", 0)));
  opcodes->insert(std::make_pair("XRA E", new Rule("XRA E", "AB", 0)));
  opcodes->insert(std::make_pair("XRA H", new Rule("XRA H", "AC", 0)));
  opcodes->insert(std::make_pair("XRA L", new Rule("XRA L", "AD", 0)));
  opcodes->insert(std::make_pair("XRA M", new Rule("XRA M", "AE", 0)));
  opcodes->insert(std::make_pair("XRA A", new Rule("XRA A", "AF", 0)));

  opcodes->insert(std::make_pair("XRI", new Rule("XRI", "EE", 1)));

  opcodes->insert(std::make_pair("ORA B", new Rule("ORA B", "B0", 0)));
  opcodes->insert(std::make_pair("ORA C", new Rule("ORA C", "B1", 0)));
  opcodes->insert(std::make_pair("ORA D", new Rule("ORA D", "B2", 0)));
  opcodes->insert(std::make_pair("ORA E", new Rule("ORA E", "B3", 0)));
  opcodes->insert(std::make_pair("ORA H", new Rule("ORA H", "B4", 0)));
  opcodes->insert(std::make_pair("ORA L", new Rule("ORA L", "B5", 0)));
  opcodes->insert(std::make_pair("ORA M", new Rule("ORA M", "B6", 0)));
  opcodes->insert(std::make_pair("ORA A", new Rule("ORA A", "B7", 0)));

  opcodes->insert(std::make_pair("ORI", new Rule("ORI", "F6", 1)));

  opcodes->insert(std::make_pair("RLC", new Rule("RLC", "07", 0)));
  opcodes->insert(std::make_pair("RLC", new Rule("RRC", "0F", 0)));
  opcodes->insert(std::make_pair("RLC", new Rule("RAL", "17", 0)));
  opcodes->insert(std::make_pair("RLC", new Rule("RAR", "1F", 0)));
  opcodes->insert(std::make_pair("RLC", new Rule("CMA", "2F", 0)));
  opcodes->insert(std::make_pair("RLC", new Rule("CMC", "3F", 0)));
  opcodes->insert(std::make_pair("RLC", new Rule("STC", "37", 0)));


  // Branching Instructions
  opcodes->insert(std::make_pair("JMP", new Rule("JMP", "C3", 2)));
  opcodes->insert(std::make_pair("JC", new Rule("JC", "DA", 2)));
  opcodes->insert(std::make_pair("JNC", new Rule("JNC", "D2", 2)));
  opcodes->insert(std::make_pair("JP", new Rule("JP", "F2", 2)));
  opcodes->insert(std::make_pair("JM", new Rule("JM", "FA", 2)));
  opcodes->insert(std::make_pair("JZ", new Rule("JZ", "CA", 2)));
  opcodes->insert(std::make_pair("JNZ", new Rule("JNZ", "C2", 2)));
  opcodes->insert(std::make_pair("JPE", new Rule("JPE", "EA", 2)));
  opcodes->insert(std::make_pair("JPO", new Rule("JPO", "E2", 2)));

  opcodes->insert(std::make_pair("CALL", new Rule("CALL", "CD", 2)));
  opcodes->insert(std::make_pair("CC", new Rule("CC", "DC", 2)));
  opcodes->insert(std::make_pair("CNC", new Rule("CNC", "D4", 2)));
  opcodes->insert(std::make_pair("CP", new Rule("CP", "F4", 2)));
  opcodes->insert(std::make_pair("CM", new Rule("CM", "FC", 2)));
  opcodes->insert(std::make_pair("CZ", new Rule("CZ", "CC", 2)));
  opcodes->insert(std::make_pair("CNZ", new Rule("CNZ", "C4", 2)));
  opcodes->insert(std::make_pair("CPE", new Rule("CPE", "EC", 2)));
  opcodes->insert(std::make_pair("CPO", new Rule("CPO", "E4", 2)));

  opcodes->insert(std::make_pair("RET", new Rule("RET", "C9", 0)));
  opcodes->insert(std::make_pair("RC",  new Rule("RC" , "D8", 0)));
  opcodes->insert(std::make_pair("RNC", new Rule("RNC", "D0", 0)));
  opcodes->insert(std::make_pair("RP",  new Rule("RP" , "F0", 0)));
  opcodes->insert(std::make_pair("RM",  new Rule("RM" , "F8", 0)));
  opcodes->insert(std::make_pair("RZ",  new Rule("RZ" , "C8", 0)));
  opcodes->insert(std::make_pair("RNZ", new Rule("RNZ", "C0", 0)));
  opcodes->insert(std::make_pair("RPE", new Rule("RPE", "E8", 0)));
  opcodes->insert(std::make_pair("RPO", new Rule("RPO", "E0", 0)));

  opcodes->insert(std::make_pair("PCHL", new Rule("PCHL", "E9", 0)));

  opcodes->insert(std::make_pair("RST 0", new Rule("RST 0", "C7", 0)));
  opcodes->insert(std::make_pair("RST 1", new Rule("RST 1", "CF", 0)));
  opcodes->insert(std::make_pair("RST 2", new Rule("RST 2", "D7", 0)));
  opcodes->insert(std::make_pair("RST 3", new Rule("RST 3", "DF", 0)));
  opcodes->insert(std::make_pair("RST 4", new Rule("RST 4", "E7", 0)));
  opcodes->insert(std::make_pair("RST 5", new Rule("RST 5", "EF", 0)));
  opcodes->insert(std::make_pair("RST 6", new Rule("RST 6", "F7", 0)));
  opcodes->insert(std::make_pair("RST 7", new Rule("RST 7", "FF", 0)));


  // Arithmetic instructions
  opcodes->insert(std::make_pair("ADD B", new Rule("ADD B", "80", 0)));
  opcodes->insert(std::make_pair("ADD C", new Rule("ADD C", "81", 0)));
  opcodes->insert(std::make_pair("ADD D", new Rule("ADD D", "82", 0)));
  opcodes->insert(std::make_pair("ADD E", new Rule("ADD E", "83", 0)));
  opcodes->insert(std::make_pair("ADD H", new Rule("ADD H", "84", 0)));
  opcodes->insert(std::make_pair("ADD L", new Rule("ADD L", "85", 0)));
  opcodes->insert(std::make_pair("ADD M", new Rule("ADD M", "86", 0)));
  opcodes->insert(std::make_pair("ADD A", new Rule("ADD A", "87", 0)));

  opcodes->insert(std::make_pair("ADC B", new Rule("ADC B", "88", 0)));
  opcodes->insert(std::make_pair("ADC C", new Rule("ADC C", "89", 0)));
  opcodes->insert(std::make_pair("ADC D", new Rule("ADC D", "8A", 0)));
  opcodes->insert(std::make_pair("ADC E", new Rule("ADC E", "8B", 0)));
  opcodes->insert(std::make_pair("ADC H", new Rule("ADC H", "8C", 0)));
  opcodes->insert(std::make_pair("ADC L", new Rule("ADC L", "8D", 0)));
  opcodes->insert(std::make_pair("ADC M", new Rule("ADC M", "8E", 0)));
  opcodes->insert(std::make_pair("ADC A", new Rule("ADC A", "8F", 0)));

  opcodes->insert(std::make_pair("ADI", new Rule("ADI", "C6", 1)));

  opcodes->insert(std::make_pair("ACI", new Rule("ACI", "CE", 1)));

  opcodes->insert(std::make_pair("LXI B", new Rule("LXI B", "01", 2)));
  opcodes->insert(std::make_pair("LXI BC", new Rule("LXI BC", "01", 2)));

  opcodes->insert(std::make_pair("LXI D", new Rule("LXI D", "11", 2)));
  opcodes->insert(std::make_pair("LXI DE", new Rule("LXI DE", "11", 2)));

  opcodes->insert(std::make_pair("LXI H", new Rule("LXI H", "21", 2)));
  opcodes->insert(std::make_pair("LXI HL", new Rule("LXI HL", "21", 2)));

  opcodes->insert(std::make_pair("LXI SP", new Rule("LXI SP", "31", 2)));

  opcodes->insert(std::make_pair("DAD B" , new Rule("DAD B", "09", 0)));
  opcodes->insert(std::make_pair("DAD BC", new Rule("DAD BC", "09", 0)));

  opcodes->insert(std::make_pair("DAD D" , new Rule("DAD D", "19", 0)));
  opcodes->insert(std::make_pair("DAD DE", new Rule("DAD DE", "19", 0)));

  opcodes->insert(std::make_pair("DAD H" , new Rule("DAD H", "29", 0)));
  opcodes->insert(std::make_pair("DAD HL", new Rule("DAD HL", "29", 0)));

  opcodes->insert(std::make_pair("DAD SP", new Rule("DAD SP", "39", 0)));

  opcodes->insert(std::make_pair("SUB B", new Rule("SUB B", "90", 0)));
  opcodes->insert(std::make_pair("SUB C", new Rule("SUB C", "91", 0)));
  opcodes->insert(std::make_pair("SUB D", new Rule("SUB D", "92", 0)));
  opcodes->insert(std::make_pair("SUB E", new Rule("SUB E", "93", 0)));
  opcodes->insert(std::make_pair("SUB H", new Rule("SUB H", "94", 0)));
  opcodes->insert(std::make_pair("SUB L", new Rule("SUB L", "95", 0)));
  opcodes->insert(std::make_pair("SUB M", new Rule("SUB M", "96", 0)));
  opcodes->insert(std::make_pair("SUB A", new Rule("SUB A", "97", 0)));

  opcodes->insert(std::make_pair("SBB B", new Rule("SBB", "98", 0)));
  opcodes->insert(std::make_pair("SBB C", new Rule("SBB", "99", 0)));
  opcodes->insert(std::make_pair("SBB D", new Rule("SBB", "9A", 0)));
  opcodes->insert(std::make_pair("SBB E", new Rule("SBB", "9B", 0)));
  opcodes->insert(std::make_pair("SBB H", new Rule("SBB", "9C", 0)));
  opcodes->insert(std::make_pair("SBB L", new Rule("SBB", "9D", 0)));
  opcodes->insert(std::make_pair("SBB M", new Rule("SBB", "9E", 0)));
  opcodes->insert(std::make_pair("SBB A", new Rule("SBB", "9F", 0)));

  opcodes->insert(std::make_pair("SUI", new Rule("SUI", "D6", 1)));
  opcodes->insert(std::make_pair("SBI", new Rule("SBI", "DE", 1)));

  opcodes->insert(std::make_pair("INR B", new Rule("INR B", "04", 0)));
  opcodes->insert(std::make_pair("INR C", new Rule("INR C", "0C", 0)));
  opcodes->insert(std::make_pair("INR D", new Rule("INR D", "14", 0)));
  opcodes->insert(std::make_pair("INR E", new Rule("INR E", "1C", 0)));
  opcodes->insert(std::make_pair("INR H", new Rule("INR H", "24", 0)));
  opcodes->insert(std::make_pair("INR L", new Rule("INR L", "2C", 0)));
  opcodes->insert(std::make_pair("INR M", new Rule("INR M", "34", 0)));
  opcodes->insert(std::make_pair("INR A", new Rule("INR A", "3C", 0)));

  opcodes->insert(std::make_pair("INX B" , new Rule("INX B" , "03", 0)));
  opcodes->insert(std::make_pair("INX BC", new Rule("INX BC", "03", 0)));

  opcodes->insert(std::make_pair("INX D" , new Rule("INX D" , "13", 0)));
  opcodes->insert(std::make_pair("INX DE", new Rule("INX DE", "13", 0)));

  opcodes->insert(std::make_pair("INX H" , new Rule("INX H" , "23", 0)));
  opcodes->insert(std::make_pair("INX HL", new Rule("INX HL", "23", 0)));

  opcodes->insert(std::make_pair("INX SP", new Rule("INX SP", "33", 0)));

  opcodes->insert(std::make_pair("DCR B", new Rule("DCR B", "05", 0)));
  opcodes->insert(std::make_pair("DCR C", new Rule("DCR C", "0D", 0)));
  opcodes->insert(std::make_pair("DCR D", new Rule("DCR D", "15", 0)));
  opcodes->insert(std::make_pair("DCR E", new Rule("DCR E", "1D", 0)));
  opcodes->insert(std::make_pair("DCR H", new Rule("DCR H", "25", 0)));
  opcodes->insert(std::make_pair("DCR L", new Rule("DCR L", "2D", 0)));
  opcodes->insert(std::make_pair("DCR M", new Rule("DCR M", "35", 0)));
  opcodes->insert(std::make_pair("DCR A", new Rule("DCR A", "3D", 0)));

  opcodes->insert(std::make_pair("DCX B" , new Rule("DCX B" , "0B", 0)));
  opcodes->insert(std::make_pair("DCX BC", new Rule("DCX BC", "0B", 0)));

  opcodes->insert(std::make_pair("DCX D" , new Rule("DCX D" , "1B", 0)));
  opcodes->insert(std::make_pair("DCX DE", new Rule("DCX DE", "1B", 0)));

  opcodes->insert(std::make_pair("DCX H" , new Rule("DCX H" , "2B", 0)));
  opcodes->insert(std::make_pair("DCX HL", new Rule("DCX HL", "2B", 0)));

  opcodes->insert(std::make_pair("DCX SP", new Rule("DCX SP", "3B", 0)));

  opcodes->insert(std::make_pair("DAA", new Rule("DAA", "27", 0)));

  // DATA TRANSFER COMMANDS

  // MOV Commands
  opcodes->insert(std::make_pair("MOV B,B", new Rule("MOV B,B", "40", 0)));
  opcodes->insert(std::make_pair("MOV B,C", new Rule("MOV B,C", "41", 0)));
  opcodes->insert(std::make_pair("MOV B,D", new Rule("MOV B,D", "42", 0)));
  opcodes->insert(std::make_pair("MOV B,E", new Rule("MOV B,E", "43", 0)));
  opcodes->insert(std::make_pair("MOV B,H", new Rule("MOV B,H", "44", 0)));
  opcodes->insert(std::make_pair("MOV B,L", new Rule("MOV B,L", "45", 0)));
  opcodes->insert(std::make_pair("MOV B,M", new Rule("MOV B,M", "46", 0)));
  opcodes->insert(std::make_pair("MOV B,A", new Rule("MOV B,A", "47", 0)));

  opcodes->insert(std::make_pair("MOV C,B", new Rule("MOV C,B", "48", 0)));
  opcodes->insert(std::make_pair("MOV C,C", new Rule("MOV C,C", "49", 0)));
  opcodes->insert(std::make_pair("MOV C,D", new Rule("MOV C,D", "4A", 0)));
  opcodes->insert(std::make_pair("MOV C,E", new Rule("MOV C,E", "4B", 0)));
  opcodes->insert(std::make_pair("MOV C,H", new Rule("MOV C,H", "4C", 0)));
  opcodes->insert(std::make_pair("MOV C,L", new Rule("MOV C,L", "4D", 0)));
  opcodes->insert(std::make_pair("MOV C,M", new Rule("MOV C,M", "4E", 0)));
  opcodes->insert(std::make_pair("MOV C,A", new Rule("MOV C,A", "4F", 0)));

  opcodes->insert(std::make_pair("MOV D,B", new Rule("MOV D,B", "50", 0)));
  opcodes->insert(std::make_pair("MOV D,C", new Rule("MOV D,C", "51", 0)));
  opcodes->insert(std::make_pair("MOV D,D", new Rule("MOV D,D", "52", 0)));
  opcodes->insert(std::make_pair("MOV D,E", new Rule("MOV D,E", "53", 0)));
  opcodes->insert(std::make_pair("MOV D,H", new Rule("MOV D,H", "54", 0)));
  opcodes->insert(std::make_pair("MOV D,L", new Rule("MOV D,L", "55", 0)));
  opcodes->insert(std::make_pair("MOV D,M", new Rule("MOV D,M", "56", 0)));
  opcodes->insert(std::make_pair("MOV D,A", new Rule("MOV D,A", "57", 0)));

  opcodes->insert(std::make_pair("MOV E,B", new Rule("MOV E,B", "58", 0)));
  opcodes->insert(std::make_pair("MOV E,C", new Rule("MOV E,C", "59", 0)));
  opcodes->insert(std::make_pair("MOV E,D", new Rule("MOV E,D", "5A", 0)));
  opcodes->insert(std::make_pair("MOV E,E", new Rule("MOV E,E", "5B", 0)));
  opcodes->insert(std::make_pair("MOV E,H", new Rule("MOV E,H", "5C", 0)));
  opcodes->insert(std::make_pair("MOV E,L", new Rule("MOV E,L", "5D", 0)));
  opcodes->insert(std::make_pair("MOV E,M", new Rule("MOV E,M", "5E", 0)));
  opcodes->insert(std::make_pair("MOV E,A", new Rule("MOV E,A", "5F", 0)));

  opcodes->insert(std::make_pair("MOV H,B", new Rule("MOV H,B", "60", 0)));
  opcodes->insert(std::make_pair("MOV H,C", new Rule("MOV H,C", "61", 0)));
  opcodes->insert(std::make_pair("MOV H,D", new Rule("MOV H,D", "62", 0)));
  opcodes->insert(std::make_pair("MOV H,E", new Rule("MOV H,E", "63", 0)));
  opcodes->insert(std::make_pair("MOV H,H", new Rule("MOV H,H", "64", 0)));
  opcodes->insert(std::make_pair("MOV H,L", new Rule("MOV H,L", "65", 0)));
  opcodes->insert(std::make_pair("MOV H,M", new Rule("MOV H,M", "66", 0)));
  opcodes->insert(std::make_pair("MOV H,A", new Rule("MOV H,A", "67", 0)));

  opcodes->insert(std::make_pair("MOV L,B", new Rule("MOV L,B", "68", 0)));
  opcodes->insert(std::make_pair("MOV L,C", new Rule("MOV L,C", "69", 0)));
  opcodes->insert(std::make_pair("MOV L,D", new Rule("MOV L,D", "6A", 0)));
  opcodes->insert(std::make_pair("MOV L,E", new Rule("MOV L,E", "6B", 0)));
  opcodes->insert(std::make_pair("MOV L,H", new Rule("MOV L,H", "6C", 0)));
  opcodes->insert(std::make_pair("MOV L,L", new Rule("MOV L,L", "6D", 0)));
  opcodes->insert(std::make_pair("MOV L,M", new Rule("MOV L,M", "6E", 0)));
  opcodes->insert(std::make_pair("MOV L,A", new Rule("MOV L,A", "6F", 0)));

  opcodes->insert(std::make_pair("MOV M,B", new Rule("MOV M,B", "70", 0)));
  opcodes->insert(std::make_pair("MOV M,C", new Rule("MOV M,C", "71", 0)));
  opcodes->insert(std::make_pair("MOV M,D", new Rule("MOV M,D", "72", 0)));
  opcodes->insert(std::make_pair("MOV M,E", new Rule("MOV M,E", "73", 0)));
  opcodes->insert(std::make_pair("MOV M,H", new Rule("MOV M,H", "74", 0)));
  opcodes->insert(std::make_pair("MOV M,L", new Rule("MOV M,L", "75", 0)));
  opcodes->insert(std::make_pair("MOV M,A", new Rule("MOV M,A", "77", 0)));

  opcodes->insert(std::make_pair("MOV A,B", new Rule("MOV A,B", "78", 0)));
  opcodes->insert(std::make_pair("MOV A,C", new Rule("MOV A,C", "79", 0)));
  opcodes->insert(std::make_pair("MOV A,D", new Rule("MOV A,D", "7A", 0)));
  opcodes->insert(std::make_pair("MOV A,E", new Rule("MOV A,E", "7B", 0)));
  opcodes->insert(std::make_pair("MOV A,H", new Rule("MOV A,H", "7C", 0)));
  opcodes->insert(std::make_pair("MOV A,L", new Rule("MOV A,L", "7D", 0)));
  opcodes->insert(std::make_pair("MOV A,M", new Rule("MOV A,M", "7E", 0)));
  opcodes->insert(std::make_pair("MOA A,A", new Rule("MOA A,A", "7F", 0)));

  opcodes->insert(std::make_pair("MVI B", new Rule("MVI B", "06", 1)));
  opcodes->insert(std::make_pair("MVI C", new Rule("MVI C", "0E", 1)));
  opcodes->insert(std::make_pair("MVI D", new Rule("MVI D", "16", 1)));
  opcodes->insert(std::make_pair("MVI E", new Rule("MVI E", "1E", 1)));
  opcodes->insert(std::make_pair("MVI H", new Rule("MVI H", "26", 1)));
  opcodes->insert(std::make_pair("MVI L", new Rule("MVI L", "2E", 1)));
  opcodes->insert(std::make_pair("MVI M", new Rule("MVI M", "36", 1)));
  opcodes->insert(std::make_pair("MVI A", new Rule("MVI A", "3E", 1)));

  opcodes->insert(std::make_pair("LDA", new Rule("LDA", "3A", 2)));

  opcodes->insert(std::make_pair("LDAX B", new Rule("LDAX B", "0A", 0)));
  opcodes->insert(std::make_pair("LDAX BC", new Rule("LDAX BC", "0A", 0)));

  opcodes->insert(std::make_pair("LDAX D", new Rule("LDAX D", "1A", 0)));
  opcodes->insert(std::make_pair("LDAX DE", new Rule("LDAX DE", "1A", 0)));

  opcodes->insert(std::make_pair("LXI B", new Rule("LXI B", "01", 2)));
  opcodes->insert(std::make_pair("LXI BC", new Rule("LXI BC", "01", 2)));

  opcodes->insert(std::make_pair("LXI D", new Rule("LXI D", "11", 2)));
  opcodes->insert(std::make_pair("LXI DE", new Rule("LXI DE", "11", 2)));

  opcodes->insert(std::make_pair("LXI H", new Rule("LXI H", "21", 2)));
  opcodes->insert(std::make_pair("LXI HL", new Rule("LXI HL", "21", 2)));

  opcodes->insert(std::make_pair("LXI SP", new Rule("LXI SP", "31", 2)));

  opcodes->insert(std::make_pair("LHLD", new Rule("LHLD", "2A", 2)));

  opcodes->insert(std::make_pair("STA", new Rule("STA", "32", 2)));

  opcodes->insert(std::make_pair("STAX B", new Rule("STAX B", "02", 2)));
  opcodes->insert(std::make_pair("STAX BC", new Rule("STAX BC", "02", 2)));

  opcodes->insert(std::make_pair("STAX D", new Rule("STAX D", "12", 2)));
  opcodes->insert(std::make_pair("STAX DE", new Rule("STAX DE", "12", 2)));

  opcodes->insert(std::make_pair("SHLD", new Rule("SHLD", "22", 2)));

  opcodes->insert(std::make_pair("XCHG", new Rule("XCHG", "EB", 0)));

  opcodes->insert(std::make_pair("SPHL", new Rule("SPHL", "F9", 0)));

  opcodes->insert(std::make_pair("XTHL", new Rule("XTHL", "E3", 0)));

  opcodes->insert(std::make_pair("PUSH B", new Rule("PUSH B", "C5", 0)));
  opcodes->insert(std::make_pair("PUSH BC", new Rule("PUSH BC", "C5", 0)));

  opcodes->insert(std::make_pair("PUSH D", new Rule("PUSH D", "D5", 0)));
  opcodes->insert(std::make_pair("PUSH DE", new Rule("PUSH DE", "D5", 0)));

  opcodes->insert(std::make_pair("PUSH H", new Rule("PUSH H", "E5", 0)));
  opcodes->insert(std::make_pair("PUSH HL", new Rule("PUSH HL", "E5", 0)));

  opcodes->insert(std::make_pair("PUSH PSW", new Rule("PUSH PSW", "F5", 0)));

  opcodes->insert(std::make_pair("POP B", new Rule("POP B", "C1", 0)));
  opcodes->insert(std::make_pair("POP BC", new Rule("POP BC", "C1", 0)));

  opcodes->insert(std::make_pair("POP DE", new Rule("POP DE", "D1", 0)));
  opcodes->insert(std::make_pair("POP DE", new Rule("POP DE", "D1", 0)));

  opcodes->insert(std::make_pair("POP H", new Rule("POP H", "E1", 0)));
  opcodes->insert(std::make_pair("POP HL", new Rule("POP HL", "E1", 0)));

  opcodes->insert(std::make_pair("PUSH PSW", new Rule("POP PSW", "F1", 0)));

  opcodes->insert(std::make_pair("OUT", new Rule("OUT", "D3", 1)));
  opcodes->insert(std::make_pair("IN", new Rule("IN", "DB", 1)));

  return opcodes;
}
