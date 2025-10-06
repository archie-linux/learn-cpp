template <typename Key, typename Value>
class SimpleHashMap 
{
private:
    struct Entry 
    {
        Key key;
        Value value;
        bool occupied = false;
        
        Entry() = default;
        Entry(const Key& k, const Value& v) : key(k), value(v), occupied(true) {}
    };
    
    std::vector<Entry> buckets;
    size_t bucket_count;
    size_t size_;
    
    size_t hash(const Key& key) const 
    {
        return std::hash<Key>{}(key) % bucket_count;
    }
    
public:
    explicit SimpleHashMap(size_t initial_size = 16) 
        : buckets(initial_size), bucket_count(initial_size), size_(0) {}
    
    void insert(const Key& key, const Value& value) 
    {
        size_t index = hash(key);
        size_t original_index = index;
        
        do 
        {
            if (!buckets[index].occupied) 
            {
                buckets[index] = Entry(key, value);
                ++size_;
                return;
            }
            if (buckets[index].key == key) 
            {
                buckets[index].value = value;
                return;
            }
            index = (index + 1) % bucket_count;
        } 
        while (index != original_index);
        
        throw std::runtime_error("HashMap is full");
    }
    
    Value* find(const Key& key) 
    {
        size_t index = hash(key);
        size_t original_index = index;
        
        do 
        {
            if (!buckets[index].occupied) 
            {
                return nullptr;
            }
            if (buckets[index].key == key) 
            {
                return &buckets[index].value;
            }
            index = (index + 1) % bucket_count;
        } 
        while (index != original_index);
        
        return nullptr;
    }
    
    size_t size() const { return size_; }
};
