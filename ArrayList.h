#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <string>

template <class T>
class ArrayList
{
public:
    struct Node
    {
        T data;
        Node *next;
        Node *previous;

        Node() : data(0), next(nullptr){};
        Node(int data) : data(data), next(nullptr), previous(nullptr){};
        Node(int data, Node *next, Node *previous) : data(data), next(next), previous(previous){};
    };

protected:
    int count;
    Node *head;
    Node *tail;

public:
    ArrayList() : count(0), head(nullptr), tail(nullptr){};
    void add(const T &e);
    void add(int index, const T &e);
    int size();
    bool empty();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    void clear();
    T removeAt(int index);
    bool removeItem(const T &item);
    std::string toString();
    std::string toStringReverse();
};

#endif