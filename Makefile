assembler: opcodes.o Instruction.o Rule.o main.o
	g++ -o assembler obj/Rule.o obj/opcodes.o obj/Instruction.o obj/main.o;

Rule.o: lib/Rule.cpp lib/Rule.h
	g++ -c -std=c++14 lib/Rule.cpp;
	mv Rule.o obj/Rule.o

opcodes.o: lib/opcodes.cpp lib/opcodes.h lib/Rule.h
	g++ -c -std=c++14 lib/opcodes.cpp;
	mv opcodes.o obj/opcodes.o

main.o: main.cpp lib/Instruction.h lib/opcodes.h
	g++ -c -std=c++14 main.cpp;
	mv main.o obj/main.o

Instruction.o: lib/Instruction.cpp lib/Instruction.h
	g++ -c -std=c++14 lib/Instruction.cpp;
	mv Instruction.o obj/Instruction.o
