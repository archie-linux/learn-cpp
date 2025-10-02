#include "executor.h"
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <iostream>
#include <sstream>

namespace simple_shell {

void execute(const std::vector<std::string>& args) {
    if (args.empty()) return;

    const std::string& cmd = args[0];

    // Built-in: exit
    if (cmd == "exit") {
        exit(0);
    }

    // Built-in: cd
    if (cmd == "cd") {
        std::string path = args.size() > 1 ? args[1] : std::string(getenv("HOME"));
        if (chdir(path.c_str()) != 0) {
            std::cerr << "cd: No such file or directory: " << path << std::endl;
        }
        return;
    }

    // Built-in: pwd
    if (cmd == "pwd") {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            std::cout << cwd << std::endl;
        } else {
            std::cerr << "pwd: Failed to get cwd" << std::endl;
        }
        return;
    }

    // External command: fork and exec
    pid_t pid = fork();
    if (pid == 0) {
        // Child: Prepare args for execvp
        std::vector<char*> argv;
        for (const auto& arg : args) {
            argv.push_back(const_cast<char*>(arg.c_str()));
        }
        argv.push_back(nullptr);

        execvp(cmd.c_str(), argv.data());
        // If execvp fails
        std::cerr << "Command not found: " << cmd << std::endl;
        exit(1);
    } else if (pid > 0) {
        // Parent: Wait for child
        int status;
        waitpid(pid, &status, 0);
    } else {
        std::cerr << "Fork failed" << std::endl;
    }
}

} // namespace simple_shell
