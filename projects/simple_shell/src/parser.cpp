#include "parser.h"
#include <sstream>
#include <cctype>

namespace simple_shell {

std::vector<std::string> parse_command(const std::string& input) {
    std::vector<std::string> args;
    std::stringstream ss(input);
    std::string token;

    while (ss >> token) {
        args.push_back(token);
    }

    return args;
}

} // namespace simple_shell
