class Book {
    const std::string m_title;
public:
    Book(const std::string& title) {
        m_title = title;  // ❌ Error: can't assign to const
    }
};
