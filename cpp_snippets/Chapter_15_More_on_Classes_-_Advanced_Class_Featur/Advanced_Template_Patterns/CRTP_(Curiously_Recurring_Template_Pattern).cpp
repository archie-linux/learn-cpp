#include <iostream>

// Base template using CRTP
template <typename Derived>
class Printable 
{
public:
    void print() const 
    {
        static_cast<const Derived*>(this)->printImpl();
    }
    
    void printTwice() const 
    {
        print();
        print();
    }
};

// Derived classes implement printImpl
class Document : public Printable<Document> 
{
private:
    std::string title;
    std::string content;
    
public:
    Document(const std::string& t, const std::string& c) : title(t), content(c) {}
    
    void printImpl() const 
    {
        std::cout << "Document: " << title << "\nContent: " << content << '\n';
    }
};

class Image : public Printable<Image> 
{
private:
    std::string filename;
    int width, height;
    
public:
    Image(const std::string& f, int w, int h) : filename(f), width(w), height(h) {}
    
    void printImpl() const 
    {
        std::cout << "Image: " << filename << " (" << width << "x" << height << ")\n";
    }
};

// CRTP for compile-time polymorphism
template <typename T>
class Comparable 
{
public:
    bool operator<(const T& other) const 
    {
        return static_cast<const T*>(this)->compare(other) < 0;
    }
    
    bool operator>(const T& other) const 
    {
        return static_cast<const T*>(this)->compare(other) > 0;
    }
    
    bool operator==(const T& other) const 
    {
        return static_cast<const T*>(this)->compare(other) == 0;
    }
    
    bool operator!=(const T& other) const 
    {
        return !(*this == other);
    }
};

class Version : public Comparable<Version> 
{
private:
    int major, minor, patch;
    
public:
    Version(int maj, int min, int p) : major(maj), minor(min), patch(p) {}
    
    int compare(const Version& other) const 
    {
        if (major != other.major) return major - other.major;
        if (minor != other.minor) return minor - other.minor;
        return patch - other.patch;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Version& v) 
    {
        return out << v.major << '.' << v.minor << '.' << v.patch;
    }
};

void demonstrateCRTP() 
{
    std::cout << "\n=== CRTP Demo ===\n";
    
    Document doc("My Document", "This is the content");
    Image img("photo.jpg", 1920, 1080);
    
    doc.print();
    std::cout << '\n';
    img.printTwice();
    
    Version v1(2, 1, 0);
    Version v2(2, 0, 5);
    
    std::cout << v1 << " > " << v2 << ": " << (v1 > v2) << '\n';
    std::cout << v1 << " == " << v2 << ": " << (v1 == v2) << '\n';
}
