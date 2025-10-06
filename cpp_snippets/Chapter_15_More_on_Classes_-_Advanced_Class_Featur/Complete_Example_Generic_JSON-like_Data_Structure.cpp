#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <variant>
#include <memory>

// Modern C++ JSON-like variant type
class JsonValue 
{
public:
    using JsonObject = std::map<std::string, JsonValue>;
    using JsonArray = std::vector<JsonValue>;
    using ValueType = std::variant<std::nullptr_t, bool, int, double, std::string, JsonArray, JsonObject>;
    
private:
    ValueType value;
    
public:
    // Constructors for different types
    JsonValue() : value(nullptr) {}
    JsonValue(std::nullptr_t) : value(nullptr) {}
    JsonValue(bool b) : value(b) {}
    JsonValue(int i) : value(i) {}
    JsonValue(double d) : value(d) {}
    JsonValue(const char* s) : value(std::string(s)) {}
    JsonValue(const std::string& s) : value(s) {}
    JsonValue(std::string&& s) : value(std::move(s)) {}
    JsonValue(const JsonArray& arr) : value(arr) {}
    JsonValue(JsonArray&& arr) : value(std::move(arr)) {}
    JsonValue(const JsonObject& obj) : value(obj) {}
    JsonValue(JsonObject&& obj) : value(std::move(obj)) {}
    
    // Type checking
    bool isNull() const { return std::holds_alternative<std::nullptr_t>(value); }
    bool isBool() const { return std::holds_alternative<bool>(value); }
    bool isInt() const { return std::holds_alternative<int>(value); }
    bool isDouble() const { return std::holds_alternative<double>(value); }
    bool isString() const { return std::holds_alternative<std::string>(value); }
    bool isArray() const { return std::holds_alternative<JsonArray>(value); }
    bool isObject() const { return std::holds_alternative<JsonObject>(value); }
    
    // Value getters with type safety
    template <typename T>
    T get() const 
    {
        if constexpr (std::is_same_v<T, bool>) 
        {
            return std::get<bool>(value);
        }
        else if constexpr (std::is_same_v<T, int>) 
        {
            return std::get<int>(value);
        }
        else if constexpr (std::is_same_v<T, double>) 
        {
            return std::get<double>(value);
        }
        else if constexpr (std::is_same_v<T, std::string>) 
        {
            return std::get<std::string>(value);
        }
        else if constexpr (std::is_same_v<T, JsonArray>) 
        {
            return std::get<JsonArray>(value);
        }
        else if constexpr (std::is_same_v<T, JsonObject>) 
        {
            return std::get<JsonObject>(value);
        }
        else 
        {
            static_assert(sizeof(T) == 0, "Unsupported type for JsonValue::get()");
        }
    }
    
    // Array access
    JsonValue& operator[](size_t index) 
    {
        return std::get<JsonArray>(value)[index];
    }
    
    const JsonValue& operator[](size_t index) const 
    {
        return std::get<JsonArray>(value)[index];
    }
    
    // Object access
    JsonValue& operator[](const std::string& key) 
    {
        return std::get<JsonObject>(value)[key];
    }
    
    const JsonValue& operator[](const std::string& key) const 
    {
        return std::get<JsonObject>(value).at(key);
    }
    
    // Pretty printing with visitor pattern
    class PrintVisitor 
    {
    private:
        mutable int indent_level = 0;
        
        void print_indent() const 
        {
            for (int i = 0; i < indent_level; ++i) std::cout << "  ";
        }
        
    public:
        void operator()(std::nullptr_t) const 
        {
            std::cout << "null";
        }
        
        void operator()(bool b) const 
        {
            std::cout << (b ? "true" : "false");
        }
        
        void operator()(int i) const 
        {
            std::cout << i;
        }
        
        void operator()(double d) const 
        {
            std::cout << d;
        }
        
        void operator()(const std::string& s) const 
        {
            std::cout << '"' << s << '"';
        }
        
        void operator()(const JsonArray& arr) const 
        {
            std::cout << "[\n";
            ++indent_level;
            
            for (size_t i = 0; i < arr.size(); ++i) 
            {
                print_indent();
                std::visit(*this, arr[i].value);
                if (i < arr.size() - 1) std::cout << ",";
                std::cout << "\n";
            }
            
            --indent_level;
            print_indent();
            std::cout << "]";
        }
        
        void operator()(const JsonObject& obj) const 
        {
            std::cout << "{\n";
            ++indent_level;
            
            size_t count = 0;
            for (const auto& [key, val] : obj) 
            {
                print_indent();
                std::cout << '"' << key << "\": ";
                std::visit(*this, val.value);
                if (++count < obj.size()) std::cout << ",";
                std::cout << "\n";
            }
            
            --indent_level;
            print_indent();
            std::cout << "}";
        }
    };
    
    void print() const 
    {
        std::visit(PrintVisitor{}, value);
        std::cout << std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const JsonValue& json) 
    {
        std::visit(PrintVisitor{}, json.value);
        return out;
    }
};

void demonstrateJsonExample() 
{
    std::cout << "\n=== JSON-like Data Structure Demo ===\n";
    
    // Create complex JSON structure
    JsonValue json = JsonValue::JsonObject{
        {"name", "John Doe"},
        {"age", 30},
        {"height", 175.5},
        {"married", true},
        {"children", JsonValue::JsonArray{
            "Alice", "Bob"
        }},
        {"address", JsonValue::JsonObject{
            {"street", "123 Main St"},
            {"city", "Springfield"},
            {"zipcode", 12345}
        }},
        {"hobbies", JsonValue::JsonArray{
            "reading", "swimming", "coding"
        }}
    };
    
    std::cout << "Complete JSON structure:\n";
    json.print();
    
    // Access specific values
    std::cout << "\nName: " << json["name"].get<std::string>() << '\n';
    std::cout << "Age: " << json["age"].get<int>() << '\n';
    std::cout << "First child: " << json["children"][0].get<std::string>() << '\n';
    std::cout << "City: " << json["address"]["city"].get<std::string>() << '\n';
    
    // Modify values
    json["age"] = 31;
    json["married"] = false;
    
    std::cout << "\nAfter modifications:\n";
    std::cout << "Age: " << json["age"].get<int>() << '\n';
    std::cout << "Married: " << json["married"].get<bool>() << '\n';
}

int main() 
{
    demonstrateCRTP();
    demonstratePolicyDesign();
    demonstrateErrorHandling();
    demonstrateDebugging();
    demonstrateJsonExample();
    
    PerformanceTest::compareCopyVsMove();
    PerformanceTest::testRVO();
    
    return 0;
}
