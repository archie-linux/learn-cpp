#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <unordered_map>
#include <cstdint>

class Directory {
public:
    bool addFile(const std::string& filename, size_t inodeIndex);
    bool removeFile(const std::string& filename);
    size_t getInodeIndex(const std::string& filename) const;
    std::vector<std::string> listFiles() const;

private:
    std::unordered_map<std::string, size_t> entries; // Filename to inode index
};

#endif // DIRECTORY_H
