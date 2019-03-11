#include <iostream>
#include "MyList.h"
#include "MyVector.h"
using namespace std;

void listTest(){
    cout<<"=======List test======="<<endl;

    MyList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    cout<<list<<endl;

    list.push_front(-1);
    list.push_front(-2);
    list.push_front(-3);

    cout<<list<<endl;

    list.insert(0,2);

    cout<<list<<endl;

    cout<<"Test contains -1: "<<list.contains(-1)<<endl;
    cout<<"Test contains 10: "<<list.contains(10)<<endl;
}

void vectorTest(){

    cout<<"=======Vector test======="<<endl;
    MyVector vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    cout<<vec<<endl;

    vec.push_front(-1);
    vec.push_front(-2);
    vec.push_front(-3);

    cout<<vec<<endl;

    vec.insert(0,3);
    vec.insert(0,-2);
    vec.insert(0,0);
    cout<<vec<<endl;
}


int main(int argc, char *argv[])
{
    listTest();
    vectorTest();
    return 0;
}

