#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point() : x(0.0), y(0.0){};
    Point(double x, double y) : x(x), y(y){};

    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
    double getX()
    {
        return this->x;
    }
    double getY()
    {
        return this->y;
    }
    double getDistance(Point b)
    {
        // return distance between two point
        return sqrt(pow(this->x - b.getX(), 2) + pow(this->y - b.getY(), 2));
    }
    double getAngle(Point b)
    {
        Point O(0, 0);
        double OA = this->getDistance(O);
        double OB = O.getDistance(b);
        double AB = this->getDistance(b);
        return (OA * OA + OB * OB - AB * AB) / (2 * OA * OB);
    }
    // bool isPassOrigin(Point b)
    // {
    //     // return true if the vector created by this Point and Point p passes the Origin O(0,0)
    //     if ((this->x == b.getX() && this->x == 0) || this->y == b.getY() && this->y == 0)
    //         return true;

    //     if (
    //         (double)(this->x - (int)this->x) == 0 && (double)(this->y - (int)this->y) == 0 &&
    //         (double)(b.getX() - (int)b.getX()) == 0 && (double)(b.getY() - (int)b.getY() == 0))
    //     {
    //         if (this->x == this->y && b.getX() == b.getY())
    //             return true;
    //         if (this->x == this->y * -1 && b.getX() == b.getY() * -1)
    //             return true;
    //     }
    //     return false;
    // }
};

int main()
{
    cout << fixed << setprecision(2);
    Point A(1, 1);
    Point B(1, -1);

    bool exe = true;
    while (exe == true)
    {
        int selection = 0;
        cout << "1. Calculate distance between two point.\n";
        cout << "2. Calculate the angel between two points.\n";
        // cout << "3. Check if the vector of two point passes by the Origin(0,0).\n";
        cout << "Make your choice: ";
        cin >> selection;
        cout << "\nResult: ";
        switch (selection)
        {
        case 1:
            cout << "Distance = " << A.getDistance(B) << endl;
            break;
        case 2:
            cout << "Cos = " << A.getAngle(B) << endl;
            break;
        // case 3:
        //     if (A.isPassOrigin(B))
        //         cout << "Yes, it is :)\n";
        //     else
        //         cout << "No, it isn't :(\n";
        //     break;
        default:
            cout << "Wrong choice, you fool!!\n";
            break;
        }

        cout << "\n\nDo you want to remake? (type 1 for YES, 0 for NO): ";
        cin >> exe;
        cout << "==============================================\n\n";
    }

    return 0;
}