#include "Disk.h"
#include <cstring>
#include <stdexcept>

// Define static const members
const size_t Disk::BLOCK_SIZE;
const size_t Disk::NUM_BLOCKS;

Disk::Disk() : disk(NUM_BLOCKS * BLOCK_SIZE, 0), blockMap(NUM_BLOCKS, false) {
    // Initialize disk with zeros and mark all blocks as free
}

bool Disk::allocateBlock(size_t& blockIndex) {
    for (size_t i = 0; i < NUM_BLOCKS; ++i) {
        if (!blockMap[i]) {
            blockMap[i] = true;
            blockIndex = i;
            return true;
        }
    }
    return false; // No free blocks
}

bool Disk::freeBlock(size_t blockIndex) {
    if (blockIndex >= NUM_BLOCKS || !blockMap[blockIndex]) {
        return false; // Invalid or already free
    }
    blockMap[blockIndex] = false;
    std::memset(&disk[blockIndex * BLOCK_SIZE], 0, BLOCK_SIZE); // Clear block
    return true;
}

bool Disk::readBlock(size_t blockIndex, char* buffer) {
    if (blockIndex >= NUM_BLOCKS || !blockMap[blockIndex]) {
        return false; // Invalid or unallocated block
    }
    std::memcpy(buffer, &disk[blockIndex * BLOCK_SIZE], BLOCK_SIZE);
    return true;
}

bool Disk::writeBlock(size_t blockIndex, const char* data) {
    if (blockIndex >= NUM_BLOCKS || !blockMap[blockIndex]) {
        return false; // Invalid or unallocated block
    }
    std::memcpy(&disk[blockIndex * BLOCK_SIZE], data, BLOCK_SIZE);
    return true;
}

size_t Disk::getFreeBlocks() const {
    size_t count = 0;
    for (bool allocated : blockMap) {
        if (!allocated) ++count;
    }
    return count;
}
