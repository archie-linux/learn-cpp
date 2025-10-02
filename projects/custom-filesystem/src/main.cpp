#include "FileSystem.h"
#include <iostream>

int main() {
    FileSystem fs;
    // Create files
    if (fs.createFile("file1.txt")) {
        std::cout << "Created file1.txt\n";
    }
    if (fs.createFile("file2.txt")) {
        std::cout << "Created file2.txt\n";
    }
    // Write to file1.txt
    const char* data = "Hello, this is a test file!";
    if (fs.writeFile("file1.txt", data, strlen(data) + 1)) {
        std::cout << "Wrote to file1.txt\n";
    }
    // Read from file1.txt
    char buffer[512];
    size_t size;
    if (fs.readFile("file1.txt", buffer, size)) {
        std::cout << "Read from file1.txt: " << buffer << "\n";
    }
    // List files
    std::cout << "Directory contents:\n";
    for (const auto& file : fs.listFiles()) {
        std::cout << "- " << file << "\n";
    }
    // Delete file1.txt
    if (fs.deleteFile("file1.txt")) {
        std::cout << "Deleted file1.txt\n";
    }
    // List files again
    std::cout << "Directory contents after deletion:\n";
    for (const auto& file : fs.listFiles()) {
        std::cout << "- " << file << "\n";
    }
    return 0;
}
