// Without compound types, this is impossible:
template <typename T>
void processLargeObject(T obj)    // ❌ Expensive copy!
{
    // Process obj...
}

// With compound types, we can do this:
template <typename T>
void processLargeObject(const T& obj)    // ✅ Efficient reference!
{
    // Process obj without copying...
}
