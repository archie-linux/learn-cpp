#include "executor.h"
#include <unistd.h>
#include <stdexcept>
#include <string.h>

namespace mini_container {

void execute_command(const std::string& command) {
    // Execute the command using execvp (simple shell for demo)
    const char* argv[] = {command.c_str(), nullptr};
    if (execvp(command.c_str(), const_cast<char* const*>(argv)) == -1) {
        throw std::runtime_error("execvp failed: " + std::string(strerror(errno)));
    }
}

} // namespace mini_container
