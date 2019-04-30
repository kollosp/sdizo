#include "MyVector.h"

MyVector::MyVector()
{
    data=nullptr;
    size = 0;
}

MyVector::~MyVector()
{
    if(data)
        delete[] data;
}

MyVector::MyVector(const MyVector &obj)
{
    data = new int[obj.size];
    size = obj.size;
    for(int i=0;i<size;++i){
        data[i] = obj.data[i];
    }
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
    if(size == 0) return;

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
    if(size == 0) return;

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
    if(size == 0) return;

    int* newArray = new int[size-1];

    size--;
    for(int i=0;i<size;++i){
        newArray[i] = data[i+1];
    }

    delete[] data;
    data = newArray;
}

const int MyVector::contains(int item) const
{
    for(int i=0;i<size;++i){
        if(data[i] == item)
            return i;
    }

    return -1;
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
