//�������� ��������� �� �++ � ���������� ���.
//
//������������ ������� ������� ��� ���������� ���������� � ��������.���� �������� ������� ������ �������� ������� ����� Product, �������������� �������, � ��� ����������� ������ : Electronics(�����������) � Clothing(������).
//
//����� Product :
//
//�������� �������� �������� : �������� ��������(productName), ����(price) � ���������� �� ������(quantity).
//��������� ����������� � ������ ��� ��������� ���������� � ��������.
//����� calculateTotalCost������������ ����� ��������� ���������� ���������� ���������.
//����� displayProductDetails ������� ��������� ���������� � ��������.
//����� Electronics :
//
//����������� �� ������ Product.
//��������� �������������� ��������, ����� ��� ����������� ����(warrantyPeriod) � �������������(manufacturer).
//����� extendWarranty����������� ����������� ���� �� ��������� ���������� �������.
//����� updateManufacturer ��������� �������� ������������� �����������.
//����� Clothing :
//
//����������� �� ������ Product.
//��������� ������� size(������ ������).
//����� changeSize(newSize) : �������� ������ ������ �� ���������.
//����� isSizeAvailable(newSize) : ���������, ���� �� � ������� ������ ������� �������.
//� �������� ��������� �������� ������� ������� ������ � ����������������� �� ����������������.������ ��� ��� ������� � ����� ������ ��� �������
#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;
    int quantity;

public:
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

    double totalPrice() {
        return this->price * this->quantity;
    }

    void showDetails() {
        cout << "Name: " << this->name << ", Price: $" << this->price << ", Quantity: " << this->quantity << endl;
    }
};

class Electronics : public Product {
private:
    int warrantyMonths;
    string brand;

public:
    Electronics(string n, double p, int q, int warranty, string b)
        : Product(n, p, q), warrantyMonths(warranty), brand(b) {}

    void extendWarranty(int months) {
        this->warrantyMonths += months;
    }

    void changeBrand(string newBrand) {
        this->brand = newBrand;
    }

    void showDetails() {
        Product::showDetails();
        cout << "Warranty: " << this->warrantyMonths << " months, Brand: " << this->brand << endl;
    }
};

class Clothing : public Product {
private:
    string size;

public:
    Clothing(string n, double p, int q, string sz)
        : Product(n, p, q), size(sz) {}

    void changeSize(string newSize) {
        this->size = newSize;
    }

    bool isSizeAvailable(string newSize) {
        return newSize == this->size;
    }

    void showDetails() {
        Product::showDetails();
        cout << "Size: " << this->size << endl;
    }
};

int main() {
    Product product("Smartwatch", 199.99, 10);
    Electronics electronic("Smartphone", 599.99, 15, 12, "Apple");
    Clothing clothing("Jeans", 39.99, 30, "L");

    product.showDetails();
    cout << "Total price for all 10 Smartwatches: $" << product.totalPrice() << endl << endl;

    electronic.showDetails();
    electronic.extendWarranty(6);
    electronic.changeBrand("Samsung");
    electronic.showDetails();
    cout << "Total price for all electronic items: $" << electronic.totalPrice() << endl << endl;

    clothing.showDetails();
    clothing.changeSize("XL");
    cout << "Is size XL available? " << (clothing.isSizeAvailable("XL") ? "Yes" : "No") << endl;
    cout << "Total price for all clothing items: $" << clothing.totalPrice() << endl;

    return 0;
}
