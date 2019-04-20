#include <iostream>
#include <vector>
#include "MyList.h"
#include "MyVector.h"
#include "MyHeap.h"
#include "MyRedBlackTree.h"
#include "Timer.h"
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

    list.pop_front();
    list.pop_back();
    cout<<list<<endl;



    MyList list2;
    list2.push_back(0);
    list2.pop_back();

    list2.push_back(0);
    list2.pop_front();

    cout<<list2<<endl;


    list2.push_back(0);
    list2.push_back(1);
    list2.push_back(2);
    list2.remove(1);
    list2.remove(0);
    list2.remove(1);

    cout<<list2<<endl;

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

    vec.pop_front();
    vec.pop_back();
    cout<<vec<<endl;



    MyVector vec2;
    vec2.push_back(0);
    vec2.pop_back();

    vec2.push_back(1);
    vec2.pop_front();

    cout<<vec2<<endl;


    vec2.push_back(0);
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.remove(0);
    vec2.remove(1);
    vec2.remove(0);

    cout<<vec2<<endl;
}

void heapTest(){
    MyHeap h;

    h.push(2);
    h.push(10);
    h.push(11);
    h.push(100);
    h.push(12);
    h.push(13);
    h.push(1);
    h.push(35);
    h.push(25);
    h.push(36);
    h.push(89);
    h.push(17);
    h.push(14);
    h.push(19);
    h.push(122);
    h.push(26);

    cout<<h<<endl;
    /*h.popHead();
    cout<<"pop head:\n"<<h<<endl;
    h.popBack();
    cout<<"pop back:\n"<<h<<endl;*/

    h.remove(1);
    cout<<"remove 1:\n"<<h<<endl;
    h.push(89);
    cout<<"push 89:\n"<<h<<endl;
    h.remove(13);
    cout<<"remove 13:\n"<<h<<endl;
}

void RBTreeTest(){
    MyRedBlackTree tree;

    int tab[] = {100,150,50,125,124,126,99,97,125,98};

    for(int i=0;i<10;++i){
        cout<<"i. "<<i<<endl;

        tree.push(tab[i]);

        cout<<tree<<endl<<endl;

    };

    tree.pop(50);
    cout<<tree<<endl;
    tree.pop(97);
    cout<<tree<<endl;
    tree.pop(150);
    cout<<tree<<endl;
//    tree.headRotateLeft();
//    cout<<tree<<endl;
//    tree.headRotateRight();
//    cout<<tree<<endl;
}

void generateInts(int max, int min, int count){

    int m = max-min;

    cout<<count<<endl;
    for(int i=0;i<count;++i){
        cout<<(rand()%m)+min<<endl;
        cerr<<"\r generowanie liczb "<<i<<"/"<<count<<" ";
    }
    cerr<<"done."<<endl;
}

//function push all ints storaged in data (count) into obj.
//it used push function
template<typename T>
double pushFrontElements(int* data, int count, T obj){
    Timer tm;
    tm.start();
    for(int i=0;i<count;++i){
        obj.push_front(data[i]);
    }
    tm.stop();
    return tm.elapsed();
}

//function push all ints storaged in data (count) into obj.
//it used push function
template<typename T>
double pushBackElements(int* data, int count, T obj){
    Timer tm;
    tm.start();
    for(int i=0;i<count;++i){
        obj.push_back(data[i]);
    }
    tm.stop();
    return tm.elapsed();
}

double insertElements(int* data, int count, std::vector<int>& vec, int pos){
    Timer tm;
    tm.start();
    for(int i=0;i<count;++i){
        vec.insert(vec.begin() + pos, data[i]);
    }
    tm.stop();
    return tm.elapsed();
}


void runTests(){
    int count;
    cin>>count;
    int data[count];

    for(int i=0;i<count;++i)
        data[i] = count;

    cout<<"Wczytano: "<<count<<" liczb"<<endl;

    {
        MyVector vector;
        MyList list;
        MyHeap heap;
        MyRedBlackTree tree;
        std::vector<int> stdVector;

        cout<<"push front"<<endl;
        cout<<"dodawanie elementow (vector)      : "<<pushFrontElements(data, count, vector)<<"s"<<endl;
        cout<<"dodawanie elementow (std::vector) : "<<insertElements(data,count, stdVector, 0)<<"s"<<endl;
        cout<<"dodawanie elementow (list)        : "<<pushFrontElements(data, count, list)<<"s"<<endl;
        cout<<"dodawanie elementow (heap)        : "<<pushFrontElements(data, count, heap)<<"s"<<endl;
    }

    {
        MyVector vector;
        MyList list;
        MyHeap heap;
        MyRedBlackTree tree;
        std::vector<int> stdVector;

        cout<<"push back"<<endl;
        cout<<"dodawanie elementow (vector)      : "<<pushBackElements(data, count, vector)<<"s"<<endl;
        cout<<"dodawanie elementow (std::vector) : "<<pushBackElements(data, count, stdVector)<<"s"<<endl;
        cout<<"dodawanie elementow (list)        : "<<pushBackElements(data, count, list)<<"s"<<endl;
        cout<<"dodawanie elementow (heap)        : ----s"<<endl;
    }



}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    if(argc>=2){
        if(string(argv[1]) == "gen"){
            int count = stoi(argv[2]);
            generateInts(10000,0,count);
            return 0;
        }
        else if(string(argv[1]) == "test"){
            cout<<"Rozpoczynam testy"<<endl;


            runTests();

            return 0;
        }
    }

    //listTest();
    //vectorTest();
    //heapTest();

    RBTreeTest();
    return 0;
}


