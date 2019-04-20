#ifndef MYHEAP_H
#define MYHEAP_H

#include <iostream>

//const int HEAP_MAX_SIZE = 511; //9 layers. 2^10-1
const int HEAP_MAX_SIZE = 262143; //2^18 -1

class MyHeap
{

    int data[HEAP_MAX_SIZE];
    int heapSize;


public:
    MyHeap();


    //for tests
    //special function to unify all classes
    void push_front(int value){push(value);}
    //end for tests


    void push(int item);
    void pop(int index);

    void fix();

    //fix after add new element
    void fixFromBottom(int index=-1);

    //fix from top - after removing
    void fixFromTop(int index=0);

    //delete element at the position index
    void remove(int index);

    //remove head
    int popHead();

    //remove back
    int popBack();

    //for stream
    int& operator[](unsigned int index);
    const int& operator[](unsigned int index) const;

    int maxSize() const {return HEAP_MAX_SIZE;}
    int size() const {return heapSize;}
};


std::ostream& operator<<(std::ostream& str, const MyHeap& heap);

#endif // MYHEAP_H
