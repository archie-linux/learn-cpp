enum Animal 
{
    cat,
    dog,
    bird
};

enum Transport 
{
    car,
    // cat,   // ❌ Error: 'cat' already declared!
    plane
};

int main() 
{
    // Enumerators are in global scope
    Animal pet = cat;       // ✅ Works
    Transport vehicle = car; // ✅ Works
    
    return 0;
}
