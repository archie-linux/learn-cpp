#ifndef INODE_H
#define INODE_H

#include <cstdint>
#include <vector>

class Inode {
public:
    static const size_t MAX_BLOCKS = 12; // Direct block pointers

    Inode();
    void setSize(size_t size);
    size_t getSize() const;
    void addBlock(size_t blockIndex);
    std::vector<size_t> getBlocks() const;
    void clearBlocks();

private:
    size_t size; // File size in bytes
    std::vector<size_t> blocks; // Direct block pointers
};

#endif // INODE_H
