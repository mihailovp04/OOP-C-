#include <iostream>
#include <string>
using namespace std;

class Rectangle {
public:
    double length, width;

    Rectangle(double len, double w) : length(len), width(w) {}

    double area() const {
        return length * width;
    }
};

class Closet : public Rectangle {
public:
    string material;
    int shelves;
    double height;

    Closet(double len, double w, double h, string mat, int sh) 
        : Rectangle(len, w), height(h), material(mat), shelves(sh) {}

    double cost() const {
        double baseCost = 10;
        if (material == "wood") {
            baseCost *= 1.5;
        }
        else if (material == "metal") {
            baseCost *= 2;
        }
        return baseCost * (length + width + height);
    }

    double capacity() const {
        return (height / shelves) * area();
    }

    void display() const {
        cout << "Closet characteristics:\n"  
            << "Length: " << length << "\n"
            << "Width: " << width << "\n"
            << "Height: " << height << "\n"
            << "Material: " << material << "\n"
            << "Shelves: " << shelves << "\n"
            << "Cost:" << cost() << "\n"
            << "Capacity: " << capacity() << " cubic units" << endl;
    }
};

int main() {
    Closet closet(2.0, 1.0, 2.0, "wood", 3);  
    closet.display();

    return 0;
}
