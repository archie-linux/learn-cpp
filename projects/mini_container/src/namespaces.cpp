#include "namespaces.h"
#include <stdexcept>
#include <string> // Added for std::string
#include <iostream>

#ifdef __linux__
#include <sched.h>
#include <sys/mount.h>
#include <string.h> // For strerror
#include <errno.h>
#endif

namespace mini_container {

void setup_namespaces() {
#ifdef __linux__
    // Create new PID and mount namespaces
    if (unshare(CLONE_NEWPID | CLONE_NEWNS) == -1) {
        throw std::runtime_error("unshare failed: " + std::string(strerror(errno)));
    }
#else
    // macOS doesn't support Linux namespaces
    std::cerr << "Warning: Namespace isolation not supported on this platform (non-Linux)." << std::endl;
#endif
}

void setup_filesystem() {
#ifdef __linux__
    // Mount proc to isolate process tree (basic)
    if (mount("none", "/proc", "proc", 0, nullptr) == -1) {
        throw std::runtime_error("mount proc failed: " + std::string(strerror(errno)));
    }
#else
    // macOS doesn't support this mount style
    std::cerr << "Warning: Filesystem isolation not supported on this platform (non-Linux)." << std::endl;
#endif
}

} // namespace mini_container
