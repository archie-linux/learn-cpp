#include <iostream>
#include <string>

class Book {
private:
    const std::string m_title;      // const member - must be initialized
    const std::string m_author;     // const member - must be initialized  
    int m_pages;
    double m_price;

public:
    // ❌ This won't compile - can't assign to const members in constructor body
    /*
    Book(const std::string& title, const std::string& author, int pages, double price) {
        m_title = title;    // Error: const member
        m_author = author;  // Error: const member
        m_pages = pages;
        m_price = price;
    }
    */
    
    // ✅ Member initializer list - preferred method
    Book(const std::string& title, const std::string& author, int pages = 0, double price = 0.0)
        : m_title{title}, m_author{author}, m_pages{pages}, m_price{price} {
        // Constructor body can contain additional logic
        std::cout << "Book \"" << m_title << "\" by " << m_author << " created\n";
    }
    
    // Accessors
    const std::string& title() const { return m_title; }
    const std::string& author() const { return m_author; }
    int pages() const { return m_pages; }
    double price() const { return m_price; }
    
    // Mutators (only for non-const members)
    void setPages(int pages) { 
        if (pages >= 0) m_pages = pages; 
    }
    void setPrice(double price) { 
        if (price >= 0.0) m_price = price; 
    }
    
    void displayInfo() const {
        std::cout << "\"" << m_title << "\" by " << m_author 
                  << " (" << m_pages << " pages, $" << m_price << ")\n";
    }
};

int main() {
    Book novel{"The Great Gatsby", "F. Scott Fitzgerald", 180, 12.99};
    Book reference{"C++ Reference", "Unknown Author"};  // Uses defaults
    
    novel.displayInfo();
    reference.displayInfo();
    
    reference.setPages(500);
    reference.setPrice(49.99);
    reference.displayInfo();
    
    return 0;
}
