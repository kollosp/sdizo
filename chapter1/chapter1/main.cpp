#include <iostream>
#include <vector>
#include <stdlib.h>

#include "Timer.h"
#include "Menu.h"
#include "TimeTests.h"

#include <unistd.h>

using namespace std;

/*
 * TODO: usuwanie w kopcu i w drzewie
 */


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
    //return;
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

    cout<<"contains(89): "<<h.contains(89)<<endl;
    cout<<"contains(13): "<<h.contains(13)<<endl;
    cout<<"contains(122): "<<h.contains(122)<<endl;
    cout<<"contains(14): "<<h.contains(14)<<endl;
    cout<<"contains(19): "<<h.contains(19)<<endl;
    cout<<"contains(70): "<<h.contains(70)<<endl;
}

void RBTreeTest(){
    MyRedBlackTree tree;

    int tab[] = {100,150,50,125,124,126,99,97,125,98};

    for(int i=0;i<10;++i){
        tree.push(tab[i]);
        //cout<<tree<<endl<<endl;
    };

    cout<<tree<<endl<<endl;
    tree.pop(50);
    cout<<"pop(50)\n"<<tree<<endl;
    tree.pop(97);
    cout<<"pop(97)\n"<<tree<<endl;
    tree.pop(150);
    cout<<"pop(150)\n"<<tree<<endl;
    cout<<"contains(100): "<<tree.contains(100)<<endl;
    cout<<"contains(124): "<<tree.contains(124)<<endl;
    cout<<"contains(126): "<<tree.contains(126)<<endl;
    cout<<"contains(99): "<<tree.contains(99)<<endl;
    cout<<"contains(56): "<<tree.contains(56)<<endl;
//    tree.headRotateLeft();
//    cout<<tree<<endl;
//    tree.headRotateRight();
//    cout<<tree<<endl;
}



void runTests(){
    int count;
    cin>>count;
    int data[count];

    for(int i=0;i<count;++i)
        data[i] = count;

    TimeTests tests;

    tests.RBTreeTests(data,count);
    //tests.heapTests(data, count);
    //tests.vectorTests(data, count);
    //tests.listTests(data, count);

}

int main(int argc, char *argv[])
{
    //heapTest();
    //return 0;

    /*Timer tm;
    tm.start();
    usleep(1000);
    tm.stop();
    cout<<tm.elapsed()<<endl;
    return 0;*/
    //RBTreeTest();
    //return 0;

    srand(time(NULL));

    if(argc>=2){
        std::string arg(argv[1]);
        if(arg == "test"){
            cout<<"Rozpoczynam testy"<<endl;

            //runTests();

            TimeTests tests;

            std::vector<int> populations = {1000,2000,5000,10000,20000,50000};
            //std::vector<int> populations = {1000,2000};

            for(int p:populations)
                tests.test(100, p);

            return 0;
        }
        else if(arg == "heaptest"){
            heapTest();
            return 0;
        }
    }

    Menu m;
    m.run();

    //listTest();
    //vectorTest();
    //heapTest();

    //RBTreeTest();
    return 0;
}


