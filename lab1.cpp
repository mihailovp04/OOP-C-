//Дан класс Животное с приватными(private) полями: название, тип(домашний или дикий),
//порода, вес и публичные поля : конструктор без параметров, конструктор с параметрами,
//деструктор и вспомогательные функции.Создать программу, в кот.Объявляется массив объектов
//этого класса и меню(каждый пункт меню – отдельная функция) :
//    1) Ввести элементы массива с клавиатуры;
//    2) Вывести на экран элементы массива(объекты);
//    3) Сортировать по убыванию по полю Вес;
//    4) Вывести на экран элементы, для кот.известно Порода(вводится с клавиатуры);
//    5) Добавить на первую позицию новый элемент;
//    6) Удалить последний элемент из файла;
//    7) Записать элементы массива в файл;
//    8) Вывести на экран первые n элементов из файла
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Animal {
private:
    string name;
    string type;
    string breed;
    float weight;

public:
    Animal() {}
    Animal(string n, string t, string b, float w) : name(n), type(t), breed(b), weight(w) {}
    ~Animal() {}

    void setName(string n) {
        this->name = n; 
    }
    void setType(string t) {
        this->type = t; 
    }
    void setBreed(string b) {
        this->breed = b;
    }
    void setWeight(float w) {
        this->weight = w;
    }

    string getName() const {
        return this->name;
    }
    string getType() const {
        return this->type; 
    }
    string getBreed() const {
        return this->breed; 
    }
    float getWeight() const {
        return this->weight; 
    }

    void addAnimal() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter type (domestic/wild): ";
        cin >> type;
        cout << "Enter breed: ";
        cin >> breed;
        cout << "Enter weight: ";
        cin >> weight;

    }
};

void printAnimal(const Animal& animal) {
    cout << "Name: " << animal.getName() << endl;
    cout << "Type: " << animal.getType() << endl;
    cout << "Breed: " << animal.getBreed() << endl;
    cout << "Weight: " << animal.getWeight() << " kg" << endl;
}

void displayAnimals(const vector<Animal>& animals) {
    cout << "Animals:" << endl;
    for (const auto& animal : animals) {
        printAnimal(animal);
        cout << endl;
    }
}

void bubbleSort(vector<Animal>& animals) {
    int n = animals.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (animals[j].getWeight() < animals[j + 1].getWeight()) {
                swap(animals[j], animals[j + 1]);
            }
        }
    }
}

void displayByBreed(const vector<Animal>& animals) {
    string breed;
    cout << "Enter breed: ";
    cin >> breed;

    cout << "Animals of breed " << breed << ":" << endl;
    for (const auto& animal : animals) {
        if (animal.getBreed() == breed) {
            printAnimal(animal);
            cout << endl;
        }
    }
}

//void addNewAnimal(vector<Animal>& animals) {
//    Animal newAnimal;
//    newAnimal.addAnimal(animals);
//}

void removeLastAnimal(vector<Animal>& animals) {
    if (!animals.empty()) {
        animals.pop_back();
        cout << "Last animal removed successfully." << endl;
    }
    else {
        cout << "No animals to remove." << endl;
    }
}

void writeToFile(const vector<Animal>& animals) {
    ofstream outFile("animals.txt");
    if (outFile.is_open()) {
        for (const auto& animal : animals) {
            outFile << animal.getName() << " "
                << animal.getType() << " "
                << animal.getBreed() << " "
                << animal.getWeight() << endl;
        }
        outFile.close();
        cout << "Animals written to file successfully." << endl;
    }
    else {
        cout << "Unable to open file to write." << endl;
    }
}

void displayFromFile(int n) {
    ifstream inFile("animals.txt");
    if (inFile.is_open()) {
        cout << "First " << n << " animals from file:" << endl;
        string name, type, breed;
        float weight;
        for (int i = 0; i < n && inFile >> name >> type >> breed >> weight; ++i) {
            cout << "Name: " << name << ", Type: " << type << ", Breed: " << breed << ", Weight: " << weight << " kg" << endl;
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file to read." << endl;
    }
}

int main() {
    vector<Animal> animals;
    int choice;
    int n;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add an animal" << endl;
        cout << "2. Display all animals" << endl;
        cout << "3. Sort by weight (descending)" << endl;
        cout << "4. Display animals by breed" << endl;
        cout << "5. Add a new animal" << endl;
        cout << "6. Remove last animal" << endl;
        cout << "7. Write animals to file" << endl;
        cout << "8. Display first n animals from file" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            Animal newAnimal;
            newAnimal.addAnimal();
            animals.push_back(newAnimal);
        }
        break;
        case 2:
            displayAnimals(animals);
            break;
        case 3:
            bubbleSort(animals);
            cout << "Animals sorted by weight (descending) successfully." << endl;
            break;
        case 4:
            displayByBreed(animals);
            break;
        case 6:
            removeLastAnimal(animals);
            break;
        case 7:
            writeToFile(animals);
            break;
        case 8:
            cout << "Enter number of animals to display: ";
            cin >> n;
            displayFromFile(n);
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 9);

    return 0;
}
