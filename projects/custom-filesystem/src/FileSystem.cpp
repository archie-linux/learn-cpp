#include "FileSystem.h"
#include <stdexcept>
#include <cstring>

FileSystem::FileSystem() : inodes(100) {} // Support up to 100 inodes

size_t FileSystem::allocateInode() {
    for (size_t i = 0; i < inodes.size(); ++i) {
        if (inodes[i].getSize() == 0) { // Assuming empty inode has size 0
            return i;
        }
    }
    throw std::runtime_error("No free inodes");
}

void FileSystem::freeInode(size_t inodeIndex) {
    if (inodeIndex < inodes.size()) {
        inodes[inodeIndex].clearBlocks();
    }
}

bool FileSystem::createFile(const std::string& filename) {
    size_t inodeIndex = allocateInode();
    if (!rootDir.addFile(filename, inodeIndex)) {
        freeInode(inodeIndex);
        return false; // File already exists
    }
    return true;
}

bool FileSystem::deleteFile(const std::string& filename) {
    size_t inodeIndex = rootDir.getInodeIndex(filename);
    if (inodeIndex == SIZE_MAX) {
        return false; // File not found
    }
    for (size_t blockIndex : inodes[inodeIndex].getBlocks()) {
        disk.freeBlock(blockIndex);
    }
    freeInode(inodeIndex);
    return rootDir.removeFile(filename);
}

bool FileSystem::writeFile(const std::string& filename, const char* data, size_t size) {
    size_t inodeIndex = rootDir.getInodeIndex(filename);
    if (inodeIndex == SIZE_MAX) {
        return false; // File not found
    }
    Inode& inode = inodes[inodeIndex];
    // Free existing blocks
    for (size_t blockIndex : inode.getBlocks()) {
        disk.freeBlock(blockIndex);
    }
    inode.clearBlocks();
    // Allocate new blocks
    size_t numBlocks = (size + Disk::BLOCK_SIZE - 1) / Disk::BLOCK_SIZE;
    for (size_t i = 0; i < numBlocks; ++i) {
        size_t blockIndex;
        if (!disk.allocateBlock(blockIndex)) {
            return false; // Disk full
        }
        size_t offset = i * Disk::BLOCK_SIZE;
        size_t bytesToWrite = std::min(Disk::BLOCK_SIZE, size - offset);
        char block[Disk::BLOCK_SIZE] = {0};
        std::memcpy(block, data + offset, bytesToWrite);
        disk.writeBlock(blockIndex, block);
        inode.addBlock(blockIndex);
    }
    inode.setSize(size);
    return true;
}

bool FileSystem::readFile(const std::string& filename, char* buffer, size_t& size) {
    size_t inodeIndex = rootDir.getInodeIndex(filename);
    if (inodeIndex == SIZE_MAX) {
        return false; // File not found
    }
    Inode& inode = inodes[inodeIndex];
    size = inode.getSize();
    size_t offset = 0;
    for (size_t blockIndex : inode.getBlocks()) {
        char block[Disk::BLOCK_SIZE];
        if (!disk.readBlock(blockIndex, block)) {
            return false;
        }
        size_t bytesToRead = std::min(Disk::BLOCK_SIZE, size - offset);
        std::memcpy(buffer + offset, block, bytesToRead);
        offset += bytesToRead;
    }
    return true;
}

std::vector<std::string> FileSystem::listFiles() const {
    return rootDir.listFiles();
}
