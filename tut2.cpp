#include <iostream>

using namespace std;

class Box
{
private:
    long long length;
    long long breadth;
    long long height;

public:
    Box()
    {
        length = height = breadth = 0;
    }
    Box(int length, int breadth, int height)
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }
    Box(Box &B)
    {
        this->length = B.length;
        this->breadth = B.breadth;
        this->height = B.height;
    }
    int getLength()
    {
        return length;
    }
    int getBreadth()
    {
        return breadth;
    }
    int getHeight()
    {
        return height;
    }
    long long CalculateVolume()
    {
        return length * height * breadth;
    }
    bool operator<(Box &b)
    {
        if (this->length < b.length)
            return true;
        if (this->breadth < b.breadth && this->length == b.length)
            return true;
        if (this->height < b.height && this->length == b.length && this->breadth == b.breadth)
            return true;
        return false;
    }

    friend ostream &operator<<(ostream &out, const Box &b);
};

ostream &operator<<(ostream &out, const Box &b)
{
    out << b.length << " " << b.breadth << " " << b.height;
    return out;
}

int main()
{
    Box A(7, 10, 20);
    Box B(8, 10, 5);
    Box C(B);
    cout << C.getBreadth();
    return 0;
}
