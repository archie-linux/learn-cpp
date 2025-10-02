#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

namespace simple_shell {

std::vector<std::string> parse_command(const std::string& input);  // Tokenize input into args

} // namespace simple_shell

#endif // PARSER_H
