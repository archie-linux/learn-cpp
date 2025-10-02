// Explicit instantiation to control code bloat
template class SimpleVector<int>;
template class SimpleVector<std::string>;

// Extern template to avoid duplicate instantiations
extern template class std::vector<MyClass>;

// Template specialization for performance-critical types
template <>
class SimpleVector<bool> 
{
    // Specialized implementation for space efficiency
    std::vector<uint8_t> data;
    size_t bit_size;
    
public:
    class BitReference 
    {
        uint8_t& byte;
        uint8_t mask;
        
    public:
        BitReference(uint8_t& b, uint8_t m) : byte(b), mask(m) {}
        
        BitReference& operator=(bool value) 
        {
            if (value) byte |= mask;
            else byte &= ~mask;
            return *this;
        }
        
        operator bool() const 
        {
            return (byte & mask) != 0;
        }
    };
    
    BitReference operator[](size_t index) 
    {
        size_t byte_index = index / 8;
        uint8_t bit_index = index % 8;
        return BitReference(data[byte_index], 1 << bit_index);
    }
    
    bool operator[](size_t index) const 
    {
        size_t byte_index = index / 8;
        uint8_t bit_index = index % 8;
        return (data[byte_index] & (1 << bit_index)) != 0;
    }
};
