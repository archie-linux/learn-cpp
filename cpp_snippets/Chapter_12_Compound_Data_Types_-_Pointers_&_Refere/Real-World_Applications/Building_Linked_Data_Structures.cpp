#include <iostream>
#include <memory>

template <typename T>
struct Node 
{
    T data;
    std::unique_ptr<Node<T>> next;
    
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList 
{
private:
    std::unique_ptr<Node<T>> head;
    
public:
    void push_front(T value) 
    {
        auto newNode = std::make_unique<Node<T>>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
    }
    
    void print() const 
    {
        Node<T>* current = head.get();  // Raw pointer for traversal
        while (current != nullptr) 
        {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "null\n";
    }
};

int main() 
{
    LinkedList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.print();  // Prints: 1 -> 2 -> 3 -> null
    
    return 0;
}
