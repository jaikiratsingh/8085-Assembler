# Introduction
8085-Assembler is a simple tool that helps converting an 8085 code to its equivalent hex code.
This tool is useful for those who practice 8085 programming on a kit (i.e. Students)

# Usage
Follow the instructions below to use this tool
```
git clone https://github.com/jaikiratsingh/8085-Assembler.git
cd 8085-Assembler
make
./assembler [address of .asm file here] [starting address (optional)]
```

# Example
Converting the code Add.asm stored on my desktop, I will follow these steps
```
git clone https://github.com/jaikiratsingh/8085-Assembler.git
cd 8085-Assembler
make
./assembler /Users/jaikirat/Desktop/Add.asm 2002h
```
This will convert the Add.asm file on my desktop, assuming that the address start at address 2002h

# Contributers
[Jaikirat Singh Sandhu](https://github.com/jaikiratsingh)
