// utils.h (Common utilities for error handling)
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

void log_error(const std::string& msg) {
    std::cerr << "Error: " << msg << std::endl;
}

#endif // UTILS_H
