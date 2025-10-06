std::vector<std::string> vec;
vec.emplace_back("Hello");        // ✅ Direct construction
vec.push_back(std::string("Hi")); // ❌ Temporary object created
