#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Disk.h"
#include "Inode.h"
#include "Directory.h"
#include <string>
#include <vector>

class FileSystem {
public:
    FileSystem();
    bool createFile(const std::string& filename);
    bool deleteFile(const std::string& filename);
    bool writeFile(const std::string& filename, const char* data, size_t size);
    bool readFile(const std::string& filename, char* buffer, size_t& size);
    std::vector<std::string> listFiles() const;

private:
    Disk disk;
    std::vector<Inode> inodes;
    Directory rootDir;
    size_t allocateInode();
    void freeInode(size_t inodeIndex);
};

#endif // FILESYSTEM_H
