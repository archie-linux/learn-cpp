class FileHandler {
public:
    FileHandler(const std::string& filename) { /* acquire resource */ }
    ~FileHandler() { /* release resource */ }  // ✅ Automatic cleanup
};
