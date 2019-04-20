#include "MyVector.h"

MyVector::MyVector()
{
    data=nullptr;
    size = 0;
}

void MyVector::push_back(int value)
{
    int* newData = new int[size+1];

    for(unsigned int i=0;i<size;++i)
        newData[i] = data[i];

    newData[size] = value;
    size ++;

    delete[] data;
    data = newData;

}

void MyVector::push_front(int value)
{
    int* newData = new int[size+1];

    for(unsigned int i=0;i<size;++i)
        newData[i+1] = data[i];

    newData[0] = value;
    size ++;

    delete[] data;
    data = newData;
}

void MyVector::insert(int value, unsigned int index)
{
    int* newData = new int[size+1];

    int offset = 0;
    for(unsigned int i=0;i<size;++i){
        if(i == index){
            offset = 1;
            newData[i] = value;
        }
        newData[i+offset] = data[i];
    }

    if(offset == 0){
        newData[size] = value;
    }

    size ++;

    delete[] data;
    data = newData;
}

void MyVector::remove(unsigned int index)
{
    int* newArray = new int[size-1];

    int offset = 0;
    size--;
    for(int i=0;i<size;++i){
        if(i == index) offset = 1;
        newArray[i] = data[i+offset];
    }

    delete[] data;
    data = newArray;
}

void MyVector::pop_back()
{
    int* newArray = new int[size-1];

    size--;
    for(int i=0;i<size;++i){
        newArray[i] = data[i];
    }

    delete[] data;
    data = newArray;
}

void MyVector::pop_front()
{
    int* newArray = new int[size-1];

    size--;
    for(int i=0;i<size;++i){
        newArray[i] = data[i+1];
    }

    delete[] data;
    data = newArray;
}

int MyVector::length() const
{
    return size;
}

int &MyVector::operator[](unsigned int index)
{
    if(size <= index)
        throw std::out_of_range("MyVector: index out of range");

    return data[index];
}

const int &MyVector::operator[](unsigned int index) const
{
    if(size <= index)
        throw std::out_of_range("MyVector: index out of range");

    return data[index];
}

std::ostream &operator<<(std::ostream &str, const MyVector &vec)
{
    str<<"[";
    for(unsigned int i=0;i<vec.length();++i){
        str<<vec[i]<<", ";
    }
    str<<"]";

    return str;
}
