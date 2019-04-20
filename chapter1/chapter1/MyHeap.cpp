#include "MyHeap.h"

MyHeap::MyHeap()
{
    heapSize = 0;
}

void MyHeap::push(int item)
{
    if(heapSize < HEAP_MAX_SIZE-1){
        data[heapSize] = item;
        heapSize ++;
    }

    fixFromBottom();
}

void MyHeap::fixFromBottom(int index)
{
    int i;
    if(index == -1)
        i = heapSize-1;
    else i = index;

    do{
        int parent = (i-1)/2;

        if(data[parent] < data[i])
            std::swap(data[parent], data[i]);
        i = parent;

    }while(i!=0);
}

void MyHeap::fixFromTop(int index)
{
    int i = index;

    do{
        int lSon = 2*i+1;
        int rSon = 2*i+2;

        if(data[i] < data[lSon])
            if(data[lSon] < data[rSon]){
                std::swap(data[rSon], data[i]);
                i=rSon;
            }
            else{
                std::swap(data[lSon], data[i]);
                i=lSon;
            }
        else if(data[i] < data[rSon]){
            std::swap(data[rSon], data[i]);
            i=rSon;
        }
        else i=heapSize;

    }while(2*i+2 < heapSize);
}

int MyHeap::popHead(){
    std::swap(data[heapSize-1], data[0]);
    heapSize--;

    fixFromTop();
    return data[heapSize];
}

int MyHeap::popBack(){
    heapSize--;
    return data[heapSize];
}


void MyHeap::remove(int index)
{
    if(heapSize == 0){
        popHead();
        return;
    }

    std::swap(data[index], data[heapSize-1]);
    heapSize--;

    if(data[index] > data[(index-1)/2])
        fixFromBottom(index);
    else fixFromTop(index);
}

int &MyHeap::operator[](unsigned int index)
{
    return data[index];
}

const int &MyHeap::operator[](unsigned int index) const
{
    return data[index];
}

std::ostream &operator<<(std::ostream &str, const MyHeap &heap)
{

    if(heap.size() == 0) str<<"heap empty";

    for(int i=0;i<heap.size();++i){
        str<<heap[i];
        if(((i+1) & (i+2)) == 0) str<<std::endl;
        else str<<", ";
    }

    return str;
}
