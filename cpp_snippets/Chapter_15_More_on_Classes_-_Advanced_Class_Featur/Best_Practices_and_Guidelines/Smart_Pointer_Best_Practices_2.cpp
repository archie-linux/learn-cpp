struct Parent 
{
    std::vector<std::shared_ptr<Child>> children;
};

struct Child 
{
    std::weak_ptr<Parent> parent;  // ✅ Breaks circular reference
};
