#include <iostream>
#include <fstream>
#include "lexer.h"
#include "parser.h"
#include "semantic.h"
#include "codegen.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " input.minilang output.asm" << std::endl;
        return 1;
    }

    std::ifstream in(argv[1]);
    std::string source((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    try {
        Lexer lexer(source);
        auto tokens = lexer.tokenize();

        Parser parser(tokens);
        auto program = parser.parse();

        SemanticAnalyzer semantic;
        semantic.analyze(program.get());

        CodeGenerator codegen(argv[2]);
        codegen.generate(program.get());

        std::cout << "Compilation successful!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
