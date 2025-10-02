// ✅ DO: Always check stream operations
std::ifstream file("data.txt");
if (!file.is_open()) {
    throw std::runtime_error("Cannot open file");
}

// ✅ DO: Use binary mode for binary data
std::ofstream file("data.bin", std::ios::binary);

// ✅ DO: Buffer output for performance
std::ostringstream buffer;
for (const auto& item : items) {
    buffer << item << "\n";
}
std::cout << buffer.str();

// ✅ DO: Use appropriate precision for floating-point
std::cout << std::fixed << std::setprecision(2) << value;

// ✅ DO: Clear stream errors when needed
if (stream.fail()) {
    stream.clear();
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
