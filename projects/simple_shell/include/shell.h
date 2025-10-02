#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <vector>

namespace simple_shell {

class Shell {
public:
    Shell();
    void run();  // Main shell loop: read, parse, execute

private:
    std::string prompt_;  // Shell prompt (e.g., "$ ")
};

} // namespace simple_shell

#endif // SHELL_H
