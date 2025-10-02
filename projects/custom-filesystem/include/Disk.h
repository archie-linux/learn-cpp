#ifndef DISK_H
#define DISK_H

#include <vector>
#include <cstdint>

class Disk {
public:
    static const size_t BLOCK_SIZE = 512;
    static const size_t NUM_BLOCKS = 1024;

    Disk();
    bool allocateBlock(size_t& blockIndex);
    bool freeBlock(size_t blockIndex);
    bool readBlock(size_t blockIndex, char* buffer);
    bool writeBlock(size_t blockIndex, const char* data);
    size_t getFreeBlocks() const;

private:
    std::vector<char> disk; // Simulated disk storage
    std::vector<bool> blockMap; // Tracks allocated blocks
};

#endif // DISK_H
