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

    while(2*i+1 < heapSize){
        int lSon = 2*i+1;
        int rSon = 2*i+2;


        //if right son does not exists
        if(rSon >= heapSize){
            if(data[i] < data[lSon]){
                std::swap(data[i], data[lSon]);
                i = lSon;
            }
            break;
        }

        //when both sons exist
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
    }
}

int MyHeap::popHead(){
    if(heapSize == 0) return 0;

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
    if(index < 0) return;
    if(heapSize == 0){
        popHead();
        return;
    }
    std::cout<<"+++++++++++++++++++"<<std::endl;

    std::swap(data[index], data[heapSize-1]);
    heapSize--;
    //std::cout<<*this<<std::endl;

    if(data[index] > data[(index-1)/2])
        fixFromBottom(index);
    else fixFromTop(index);

    //std::cout<<"+++++++++++++++++++"<<std::endl;
}

int &MyHeap::operator[](unsigned int index)
{
    return data[index];
}

const int &MyHeap::operator[](unsigned int index) const
{
    return data[index];
}

int MyHeap::contains(int item, int startIndex)
{
    int lSon = 2*startIndex+1;
    int rSon = 2*startIndex+2;

    int fromLeft = -1;
    int fromRight = -1;

    if(data[startIndex] == item) return startIndex;

    if(lSon < heapSize){
        if(data[lSon] >= item){
            fromLeft = contains(item, lSon);
        }
    }

    if(rSon < heapSize){
        if(data[rSon] >= item){
            fromRight = contains(item, rSon);
        }
    }

    if(fromLeft != -1)
        return fromLeft;

    if(fromRight != -1)
        return fromRight;

    return -1;
}

void MyHeap::display(std::ostream &str, unsigned int index, int indent) const
{
    if(index < heapSize){
        if(2*index + 2 < heapSize) display(str, 2*index + 2, indent+4);

        if (indent) {
            str<< std::setw(indent) << ' ';
        }

        if(2*index + 2 < heapSize) str<<" /\n" << std::setw(indent) << ' ';

        str<<data[index]<<"\n ";


        if(2*index + 1 < heapSize) {
            str << std::setw(indent) << ' ' <<" \\\n";
            display(str, 2*index+1, indent+4);
        }

    }
}

std::ostream &operator<<(std::ostream &str, const MyHeap &heap)
{

    if(heap.size() == 0) str<<"heap empty";

    /*for(int i=0;i<heap.size();++i){
        str<<heap[i];
        if(((i+1) & (i+2)) == 0) str<<std::endl;
        else str<<", ";
    }*/
    heap.display(str, 0, 0);

    return str;
}




/*
 * void Heap::print() {

    const int width = 62;

    int treeLevel = 1;
    int nodeNumberOnLevel = 0;
    int howManyNodesOnCurrentLevel = 1;

    for(int i = 0; i <= this->heapPointer; i ++) {


        int spaceBetweenNodes = width / howManyNodesOnCurrentLevel;

        if (nodeNumberOnLevel != 0)
            for (int j = 0; j < spaceBetweenNodes; j++) {
                std::cout << " ";
            }
        else {
            for (int j = 0; j < spaceBetweenNodes/2; j++) {
                std::cout << " ";
            }
        }

        std::cout << heapData[i];


        nodeNumberOnLevel++;

        if(nodeNumberOnLevel >= howManyNodesOnCurrentLevel) {
            nodeNumberOnLevel = 0;
            howManyNodesOnCurrentLevel *= 2;
            treeLevel ++;

            std::cout << std::endl;
        }
    }


    std::cout << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << std::endl;
}*/
