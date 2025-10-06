// struct: members are public by default
struct Point2D {
    double x, y;  // public by default
    void display() { std::cout << "(" << x << ", " << y << ")\n"; }
};

// class: members are private by default  
class Point3D {
    double x, y, z;  // private by default
    
public:  // Must explicitly specify public
    void setCoordinates(double newX, double newY, double newZ) {
        x = newX; y = newY; z = newZ;
    }
    
    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};
