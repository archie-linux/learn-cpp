// Problematic raw pointer usage
void problematicCode() {
    int* data = new int[1000];  // Manual allocation
    
    // ... complex logic that might throw exceptions
    
    if (someCondition) {
        return;  // ❌ Memory leak! Forgot to delete[]
    }
    
    delete[] data;  // ❌ Only reached if no early return
}

void dangerousSharing() {
    int* ptr = new int(42);
    
    processData(ptr);    // Who owns ptr now?
    delete ptr;          // ❌ Double delete if processData also deletes?
    
    *ptr = 100;          // ❌ Use after free!
}
