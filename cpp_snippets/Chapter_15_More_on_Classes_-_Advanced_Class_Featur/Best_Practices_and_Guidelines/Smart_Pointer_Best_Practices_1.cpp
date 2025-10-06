std::unique_ptr<Resource> createResource(); // ✅ Clear ownership transfer
std::shared_ptr<Resource> createResource(); // ❌ Unclear why sharing is needed
