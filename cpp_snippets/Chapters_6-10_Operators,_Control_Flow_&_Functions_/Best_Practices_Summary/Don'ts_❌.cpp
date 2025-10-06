int globalCounter;  // ❌ Avoid global state
void increment() { globalCounter++; }  // ❌ Hidden dependency
