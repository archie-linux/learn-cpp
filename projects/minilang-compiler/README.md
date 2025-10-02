### Compile & Test

- make

- Test the compiler with a sample input:
    - ./minilang_compiler tests/simple.minilang output.asm
    - nasm -f elf64 output.asm -o output.o
    - ld output.o -o output
    - ./output

### Prompt

Compiler for a custom language
This is a challenging, expert-level project that demonstrates a complete understanding of a program's lifecycle. 
What it shows:
Compiler Theory: An understanding of lexical analysis (scanning), parsing, semantic analysis, and code generation.
Data Structures: Heavy use of trees, specifically Abstract Syntax Trees (ASTs), for representing and analyzing code.
Systems Programming: Knowledge of how code is translated into a lower-level, executable format. 

## AI Agent: Grok
