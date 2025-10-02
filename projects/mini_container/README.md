# Mini Container System in C++

A simple C++ implementation of a Docker-like container system, using Linux namespaces for process isolation.

## Prerequisites
- Linux system (e.g., Ubuntu)
- Root privileges (for namespace operations)
- g++, CMake

## Build
```bash
mkdir build && cd build
cmake ..
make
```

### Run
```bash
sudo ./mini_container /bin/sh
```

- Runs /bin/sh in an isolated namespace. Inside the shell, try ps to verify only the shell process is visible (PID namespace isolation). Type exit to leave.

- Expected Behavior on Linux: The command runs in a new PID namespace (processes outside are invisible) and a new mount namespace (isolated /proc).
