#include "Directory.h"

bool Directory::addFile(const std::string& filename, size_t inodeIndex) {
    if (entries.find(filename) != entries.end()) {
        return false; // File already exists
    }
    entries[filename] = inodeIndex;
    return true;
}

bool Directory::removeFile(const std::string& filename) {
    return entries.erase(filename) > 0;
}

size_t Directory::getInodeIndex(const std::string& filename) const {
    auto it = entries.find(filename);
    return it != entries.end() ? it->second : SIZE_MAX; // SIZE_MAX indicates not found
}

std::vector<std::string> Directory::listFiles() const {
    std::vector<std::string> files;
    for (const auto& entry : entries) {
        files.push_back(entry.first);
    }
    return files;
}
