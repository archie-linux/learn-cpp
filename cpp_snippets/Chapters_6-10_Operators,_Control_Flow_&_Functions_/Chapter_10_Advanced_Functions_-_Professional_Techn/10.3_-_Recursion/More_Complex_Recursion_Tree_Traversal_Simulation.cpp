#include <iostream>
#include <string>

// Simulate a simple directory structure traversal
void printIndentation(int depth) 
{
    for (int i = 0; i < depth; ++i) 
    {
        std::cout << "  ";
    }
}

void traverseDirectory(const std::string& name, int depth = 0) 
{
    printIndentation(depth);
    std::cout << name << "/\n";
    
    // Base case - simulate maximum depth
    if (depth >= 3) 
    {
        return;
    }
    
    // Simulate subdirectories (recursive calls)
    if (name == "root") 
    {
        traverseDirectory("home", depth + 1);
        traverseDirectory("etc", depth + 1);
        traverseDirectory("var", depth + 1);
    } 
    else if (name == "home") 
    {
        traverseDirectory("user1", depth + 1);
        traverseDirectory("user2", depth + 1);
    } 
    else if (name == "user1") 
    {
        printIndentation(depth + 1);
        std::cout << "documents.txt\n";
        printIndentation(depth + 1);
        std::cout << "photos.jpg\n";
    }
}

// Tower of Hanoi puzzle solution
void towerOfHanoi(int disks, char source, char destination, char auxiliary) 
{
    // Base case
    if (disks == 1) 
    {
        std::cout << "Move disk 1 from " << source << " to " << destination << '\n';
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(disks - 1, source, auxiliary, destination);
    
    // Move the bottom disk from source to destination
    std::cout << "Move disk " << disks << " from " << source << " to " << destination << '\n';
    
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(disks - 1, auxiliary, destination, source);
}

int main() 
{
    std::cout << "Directory traversal simulation:\n";
    traverseDirectory("root");
    
    std::cout << "\nTower of Hanoi solution (3 disks):\n";
    towerOfHanoi(3, 'A', 'C', 'B');
    
    return 0;
}
