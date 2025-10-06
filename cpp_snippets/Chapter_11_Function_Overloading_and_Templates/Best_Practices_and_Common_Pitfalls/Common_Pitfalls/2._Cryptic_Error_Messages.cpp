template <typename T>
T badFunction(T x) 
{
    return x.nonexistentMethod(); // Will generate confusing errors
}
