#include <iostream>

using namespace std;

class Animal
{
protected:
    string name;
    int age;
    bool gender; // 0 if Male, 1 if Female
public:
    Animal() : name(""), age(0), gender(false){};
    Animal(string n, int a, bool g) : name(n), age(a), gender(g){};

    void makeSound()
    {
        cout << this->name << " is making sound" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string n, int a, bool g) : Animal(n, a, g){};
    void makeSound()
    {
        cout << "Meow Meow" << endl;
    }
};

int main()
{
    Animal a("Cat", 10, 0);
    a.makeSound();
    Cat c("Cat", 8, 1);
    c.makeSound();
    return 0;
}