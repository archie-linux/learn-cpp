#include "container.h"
#include "namespaces.h"
#include "executor.h"
#include <unistd.h>
#include <stdexcept>

namespace mini_container {

Container::Container(const std::string& command) : command_(command) {}

void Container::run() {
    // Fork to create a new process for the container
    pid_t pid = fork();
    if (pid < 0) {
        throw std::runtime_error("Failed to fork");
    } else if (pid == 0) {
        // Child process: Set up container environment
        setup_namespaces();
        setup_filesystem();
        execute_command(command_);
        _exit(1); // Should not reach here
    } else {
        // Parent process: Wait for child
        int status;
        waitpid(pid, &status, 0);
    }
}

} // namespace mini_container
