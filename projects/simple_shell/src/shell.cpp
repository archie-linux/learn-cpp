#include "shell.h"
#include "parser.h"
#include "executor.h"
#include <iostream>
#include <sstream>

namespace simple_shell {

Shell::Shell() : prompt_("$ ") {}

void Shell::run() {
    std::string line;
    while (true) {
        std::cout << prompt_;
        if (!std::getline(std::cin, line)) {
            std::cout << std::endl;  // EOF
            break;
        }
        if (line.empty()) continue;

        auto args = parse_command(line);
        if (!args.empty()) {
            execute(args);
        }
    }
}

} // namespace simple_shell
