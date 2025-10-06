#include "Inode.h"
#include <stdexcept>

Inode::Inode() : size(0) {}

void Inode::setSize(size_t newSize) {
    size = newSize;
}

size_t Inode::getSize() const {
    return size;
}

void Inode::addBlock(size_t blockIndex) {
    if (blocks.size() >= MAX_BLOCKS) {
        throw std::runtime_error("Inode block limit reached");
    }
    blocks.push_back(blockIndex);
}

std::vector<size_t> Inode::getBlocks() const {
    return blocks;
}

void Inode::clearBlocks() {
    blocks.clear();
    size = 0;
}
