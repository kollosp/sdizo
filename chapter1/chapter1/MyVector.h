#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>

class MyVector
{
    int* data;
    int size;

public:
    MyVector();

    ~MyVector();

    MyVector(const MyVector& obj);


    //at the and
    void push_back(int value);

    //at the beginnig
    void push_front(int value);

    //in specified index
    void insert(int value, unsigned int index);

    //in specified index
    void remove(unsigned int index);

    //at the and
    void pop_back();

    //at the beginnig
    void pop_front();

    //check if list is empty, true when empty
    const bool isEmpty() const;

    //check if item exists. -1 when list doesnt contain item otherways index
    const int contains(int item) const;

    //return size of vector
    int length() const;

    int& operator[](unsigned int index);
    const int& operator[](unsigned int index) const;
};

std::ostream& operator<<(std::ostream& str, const MyVector& vec);

#endif // MYVECTOR_H
