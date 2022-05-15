#include <stdexcept>
#include <sstream>
#include "ArrayList.h"

using std::out_of_range;
using std::string;
using std::stringstream;

template <class T>
string ArrayList<T>::toString()
{
    stringstream ss;
    ss << "[";
    Node *ptr = this->head;
    while (ptr != this->tail)
    {
        ss << ptr->data << ",";
        ptr = ptr->next;
    }
    if (this->count > 0)
        ss << ptr->data << "]";
    else
        ss << "]";
    return ss.str();
}

template <class T>
string ArrayList<T>::toStringReverse()
{
    stringstream ss;
    ss << "[";
    Node *ptr = this->tail;
    while (ptr != this->head)
    {
        ss << ptr->data << ",";
        ptr = ptr->previous;
    }
    if (this->count > 0)
        ss << ptr->data << "]";
    else
        ss << "]";
    return ss.str();
}

template <class T>
void ArrayList<T>::add(const T &e)
{
    Node *newNode = new Node(e);
    if (this->count == 0)
        this->head = newNode;
    else
    {
        this->tail->next = newNode;
        newNode->previous = this->tail;
    }
    this->tail = newNode;
    this->count++;
}

template <class T>
void ArrayList<T>::add(int index, const T &e)
{
    if (this->count == 0 || index >= this->count)
    {
        this->add(e);
        return;
    }
    Node *newNode = new Node(e);
    if (index <= 0)
    {
        newNode->next = this->head;
        this->head->previous = newNode;
        this->head = newNode;
    }
    else
    {
        Node *currentNode = this->head;
        for (int i = 0; i < index - 1; i++)
            currentNode = currentNode->next;
        newNode->next = currentNode->next;
        newNode->previous = currentNode;
        (currentNode->next)->previous = newNode;
        currentNode->next = newNode;
    }
    this->count++;
}

template <class T>
int ArrayList<T>::size()
{
    return this->count;
}

template <class T>
bool ArrayList<T>::empty()
{
    return (this->count == 0);
}

template <class T>
T ArrayList<T>::get(int index)
{
    if (this->count == 0 || index < 0 || index >= this->count)
        throw out_of_range("The position you gave is out of range!!!");
    if (index == 0)
        return this->head->data;
    if (index == this->count - 1)
        return this->tail->data;
    Node *currentNode = this->head->next;
    bool isTraverseInReverse = false;
    if (index > this->count / 2)
    {
        currentNode = this->tail->previous;
        isTraverseInReverse = true;
    }
    if (isTraverseInReverse == false)
    {
        for (int i = 1; i < index; i++)
            currentNode = currentNode->next;
    }
    else
    {
        for (int i = this->count - 2; i > index; i--)
            currentNode = currentNode->previous;
    }
    return currentNode->data;
}

template <class T>
void ArrayList<T>::set(int index, const T &e)
{
    if (this->count == 0 || index < 0 || index >= this->count)
        throw out_of_range("The position you gave is out of range!!!");
    if (index == 0)
        this->head->data = e;
    else if (index == this->count - 1)
        this->tail->data = e;
    else
    {
        Node *currentNode = this->head->next;
        bool isTraverseInReverse = false;
        if (index > this->count / 2)
        {
            currentNode = this->tail->previous;
            isTraverseInReverse = true;
        }
        if (isTraverseInReverse == false)
        {
            for (int i = 1; i < index; i++)
                currentNode = currentNode->next;
        }
        else
        {
            for (int i = this->count - 2; i > index; i--)
                currentNode = currentNode->previous;
        }
        currentNode->data = e;
    }
}

template <class T>
int ArrayList<T>::indexOf(const T &item)
{
    if (this->count == 0)
        return -1;
    if (item == this->head->data)
        return 0;
    if (item == this->tail->data)
        return this->count - 1;
    Node *currentNode = this->head->next;
    for (int i = 1; i < this->count - 1; i++)
    {
        if (currentNode->data == item)
            return i;
        currentNode = currentNode->next;
    }
    return -1;
}

template <class T>
bool ArrayList<T>::contains(const T &item)
{
    int indexOfItem = this->indexOf(item);
    return (indexOfItem != -1);
}

template <class T>
void ArrayList<T>::clear()
{
    if (this->count == 0)
        return;
    while (this->head != nullptr)
    {
        Node *deleteNode = this->head;
        this->head = this->head->next;
        delete deleteNode;
    }
    this->tail = nullptr;
    this->count = 0;
}

template <class T>
T ArrayList<T>::removeAt(int index)
{
    if (this->count == 0 || index < 0 || index >= this->count)
        throw out_of_range("The position you gave is out of range!!!");
    Node *currentNode = this->head;
    if (index == 0)
    {
        this->head = this->head->next;
        this->head->previous = nullptr;
    }
    else if (index == this->count - 1)
    {
        currentNode = this->tail;
        this->tail = this->tail->previous;
        this->tail->next = nullptr;
    }
    else
    {
        currentNode = this->head->next;
        bool isTraverseInReverse = false;
        if (index > this->count / 2)
        {
            currentNode = this->tail->previous;
            isTraverseInReverse = true;
        }
        if (isTraverseInReverse == false)
        {
            for (int i = 1; i < index; i++)
                currentNode = currentNode->next;
        }
        else
        {
            for (int i = this->count - 2; i > index; i--)
                currentNode = currentNode->previous;
        }
        (currentNode->next)->previous = currentNode->previous;
        (currentNode->previous)->next = currentNode->next;
    }

    if (this->count == 1) // the array's size before delete operation is 1
        this->head = this->tail = nullptr;
    int deletedValue = currentNode->data;
    delete currentNode;
    this->count--;
    return deletedValue;
}

template <class T>
bool ArrayList<T>::removeItem(const T &item)
{
    if (this->count == 0)
        return false;
    Node *currentNode = this->head;
    if (this->head->data == item)
    {
        this->head = this->head->next;
        delete currentNode;
        this->count--;
        if (this->count == 0)
            this->head = this->tail = nullptr;
        else
            this->head->previous = nullptr;
        return true;
    }
    currentNode = this->head->next;
    while (currentNode != nullptr)
    {
        if (currentNode->data == item)
        {
            if (currentNode != this->tail)
            {
                (currentNode->next)->previous = currentNode->previous;
                (currentNode->previous)->next = currentNode->next;
            }
            else
            {
                this->tail = currentNode->previous;
                this->tail->next = nullptr;
            }
            delete currentNode;
            this->count--;
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}