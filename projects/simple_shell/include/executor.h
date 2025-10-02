#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <vector>
#include <string>

namespace simple_shell {

void execute(const std::vector<std::string>& args);  // Run command (built-in or external)

} // namespace simple_shell

#endif // EXECUTOR_H
