#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"

using namespace std;

int main()
{
    ArrayList<int> my_array;
    for (int i = 0; i <= 9; i++)
        my_array.add(i * 2);
    int continueExecute = 1;
    while (continueExecute != 0)
    {
        int userChoice = 0;
        cout << "Enter what you want to do:\n";

        cout << "1. Add an element after the last item\n";
        cout << "2. Add an element to a specific position\n";
        cout << "3. Get the size of the array\n";
        cout << "4. Check if the array is empty\n";
        cout << "5. Get the value of an element from a specific position\n";
        cout << "6. Modify the value of an element at a specific position\n";
        cout << "7. Get the index of the first appearance of an element (return -1 if not exist)\n";
        cout << "8. Check if the array contains this value\n";
        cout << "9. Destroy the array\n";
        cout << "10. Remove an element at a specific position\n";
        cout << "11. Remove the first appearance of an element with a given value\n";
        cout << "12. Print out the array\n";
        cout << "13. Print out the array in reverse order\n";
        cout << '\n';
        cin >> userChoice;

        try
        {
            switch (userChoice)
            {
            case 1:
            {
                int elementToAdd = 0;
                cout << "Enter the value of the element you want to insert: ";
                cin >> elementToAdd;
                my_array.add(elementToAdd);
                cout << "Your current array: " << my_array.toString() << endl;
                break;
            }
            case 2:
            {
                int elementToAdd = 0;
                cout << "Enter the value of the element you want to insert: ";
                cin >> elementToAdd;
                int indexToAdd = 0;
                cout << "Enter the position where the element should to be inserted to: ";
                cin >> indexToAdd;
                my_array.add(indexToAdd, elementToAdd);
                cout << "Your current array: " << my_array.toString() << endl;
                break;
            }
            case 3:
            {
                cout << "Size: " << my_array.size() << endl;
                break;
            }
            case 4:
            {
                my_array.empty() ? cout << "The array is currently empty\n" : cout << "The array is not empty\n";
                break;
            }
            case 5:
            {
                int indexToGetValue = 0;
                cout << "Enter the position of the element you want to get the value: ";
                cin >> indexToGetValue;
                cout << "Your current array: " << my_array.toString() << endl;
                int result = my_array.get(indexToGetValue);
                cout << "The value at the given position is: " << result << endl;
                break;
            }
            case 6:
            {
                int indexToSetValue = 0;
                cout << "Enter the position of the element you want to set a new value: ";
                cin >> indexToSetValue;
                int newValueToSet = 0;
                cout << "Enter the new value: ";
                cin >> newValueToSet;
                my_array.set(indexToSetValue, newValueToSet);
                cout << "Your current array: " << my_array.toString() << endl;
                break;
            }
            case 7:
            {
                int valueToGetIndex = 0;
                cout << "Enter the value you want to get its position (first appearance): ";
                cin >> valueToGetIndex;
                cout << "Your current array: " << my_array.toString() << endl;
                int result = my_array.indexOf(valueToGetIndex);
                result != -1 ? cout << "Its index is: " << result : cout << "The value you gave does not exist in the array";
                cout << '\n';
                break;
            }
            case 8:
            {
                int valueToCheckIfExist = 0;
                cout << "Enter the value you want to check if it is exist in the array: ";
                cin >> valueToCheckIfExist;
                cout << "Your current array: " << my_array.toString() << endl;
                my_array.contains(valueToCheckIfExist) ? cout << "Yes, the array contains it\n" : cout << "No, your value does not exist in the array\n";
                break;
            }
            case 9:
            {
                my_array.clear();
                cout << "Your current array: " << my_array.toString() << endl;
                break;
            }
            case 10:
            {
                int indexToBeRemoved = 0;
                cout << "Enter the position of the element that you want to remove: ";
                cin >> indexToBeRemoved;
                int valueToBeRemoved = my_array.removeAt(indexToBeRemoved);
                cout << "You have deleted " << valueToBeRemoved << " successfully" << endl;
                cout << "Your current array: " << my_array.toString() << endl;
                break;
            }
            case 11:
            {
                int valueToBeRemoved = 0;
                cout << "Enter the value that you want to remove: ";
                cin >> valueToBeRemoved;
                my_array.removeItem(valueToBeRemoved) ? cout << "Done! The element with the given value was deleted from the array\n" : cout << "Did not find any occurences of the value you give\n";
                cout << "Your current array: " << my_array.toString() << endl;
                break;
            }
            case 12:
            {
                cout << "Your current array contains: " << my_array.toString() << endl;
                break;
            }
            case 13:
            {
                cout << "Your current array in reverse order: " << my_array.toStringReverse() << endl;
                break;
            }
            default:
                throw "\nOops! So sorry but your choice has run out of our services!\nPlease enter a valid number from the list of services above";
                break;
            }
        }
        catch (const char *error_message)
        {
            cout << error_message << endl;
        }
        catch (const exception &e)
        {
            cerr << e.what() << endl;
        }
        catch (...)
        {
            cout << "Exception happened\n";
        }

        cout << "\n\nDo you want to continue? (Type 1 for Yes, 0 for No): ";
        cin >> continueExecute;
        cout << "===============================================================================\n\n";
    }
    return 0;
}