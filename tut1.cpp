#include <iostream>

using namespace std;

// oop:
// encapsulation
// inheritance
// abstraction
// polymorphism

class Student
{
protected:       // access specifier: private, protected and public
    string name; // atributes or properties
    string major;
    int age;
    int id;

public:
    Student() // constructor
    {
        age = 0;
        id = 0;
        name = "";
        major = "";
    }

    Student(int a, int i, string n, string m)
    {
        age = a;
        id = i;
        name = n;
        major = m;
    }

    Student(int a, int i)
    {
        age = a;
        id = i;
        name = "";
        major = "";
    }

    Student(string n, string m)
    {
        age = 0;
        id = 0;
        name = n;
        major = m;
    }

    // getter and setter name
    string getName()
    {
        return name;
    }

    void setName(string n)
    {
        name = n;
    }

    // getter and setter major
    string getMajor()
    {
        return major;
    }

    void setMajor(string m)
    {
        major = m;
    }

    // getter and setter age
    int getAge()
    {
        return age;
    }

    void setAge(int a)
    {
        age = a;
    }

    // getter and setter id
    int getId()
    {
        return id;
    }

    void setId(int i)
    {
        id = i;
    }

    void printInfo()
    {
        cout << age << ' ' << id << ' ' << major << ' ' << name << endl;
    }

    void work()
    {
        cout << name << " is working" << endl;
    }

    void study()
    {
        cout << name << " is studying" << endl;
    }
};

int main()
{
    Student st1(20, 191, "Minh", "DDT");
    cout << st1.getAge() << endl;
    cout << st1.getMajor() << endl;
    st1.printInfo();
    return 0;
}