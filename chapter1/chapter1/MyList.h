#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

class MyListItem{
public:
    int data;
    MyListItem* next;

    MyListItem(int value) : data(value), next(nullptr) {}
};


class MyList
{
    //list head
    MyListItem* head;

public:
    MyList();
    MyList(const MyList& obj);
    ~MyList();

    //at the and
    void push_back(int value);

    //at the beginnig
    void push_front(int value);

    //in specified index
    void insert(int value, int index);

    //in specified index
    void remove(int index);

    //at the and
    void pop_back();

    //at the beginnig
    void pop_front();

    //return list head
    const MyListItem* getHead() const;

    //check if list is empty, true when empty
    const bool isEmpty() const;

    //check if item exists. -1 when list doesnt contain item otherways index
    const int contains(int item) const;


    //return size of vector
    int length() const;

private:
    //find element at index.
    //index = 0 -> head
    //index = -1 -> tail
    //other < size() -> middle
    //other > size() -> tail
    MyListItem* findIndex(int index);
};

std::ostream& operator<<(std::ostream& str, const MyList& list);

#endif // MYLIST_H
