#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <stdio.h>

#include "NeighbourMatrix.h"
#include "NeighbourLists.h"

#include "Tests.h"
#include "Algorythms.h"

using namespace std;




void neighbourMatrixTest(){
    NeighbourMatrix m(5);
    m.addEdge(0,1);
    m.addEdge(2,1);
    m.addEdge(2,3);
    m.addEdge(3,4);
    //m.addEdge(4,3);
    //m.addEdge(2,4);

    cout<<"macierz sasiedztwa. poszukiwania dla wezla 4"<<endl;
    cout<<m<<endl;
    cout<<"dijkstra: "<<Algorythms::dijkstra(m, 4)<<endl;
    cout<<"bellFord: "<<Algorythms::bellFord(m, 4)<<endl;
}

void neighbourListTest(){
    NeighbourLists m(5);
    m.addEdge(0,1);
    m.addEdge(2,1);
    m.addEdge(2,3);
    m.addEdge(3,4);

    cout<<"lista sasiadow. poszukiwania dla wezla 4"<<endl;
    cout<<m<<endl;
    cout<<"dijkstra: "<<Algorythms::dijkstra(m, 4)<<endl;
    cout<<"bellFord: "<<Algorythms::bellFord(m, 4)<<endl;
}


void test(int size, int factor, int testCount){

    std::vector<double> listTimes;
    std::vector<double> matrixTimes;


    NeighbourLists nl(size);
    NeighbourMatrix nm(size);


    Tests::fillGraph(nl,factor);
    Tests::fillGraph(nm,factor);

    std::vector<int> tests;
    for(int i=0;i<testCount;++i)
        tests.push_back(rand()%size);

    listTimes.push_back(Tests::testBellFord(nl, tests));
    matrixTimes.push_back(Tests::testBellFord(nm, tests));


    for(double&k : listTimes)
        k/=testCount;

    for(double&k : matrixTimes)
        k/=testCount;

    cout<<std::fixed<<listTimes<<", "<<matrixTimes<<endl;

}

int main(int argc, char**argv)
{

    srand(time(NULL));

    std::vector<int> sizes = {100,200,300,400,500};
    std::vector<int> factors = {25,50,75,100};


    //cout<<"ls, "<<listTimes<<", "<<matrixTimes<<endl;

    for(int s:sizes){
        for(int f:factors){
            test(s,f,100);
        }
    }

    //neighbourMatrixTest();
    //neighbourListTest();

  /*  if(argc < 3){
        std::cout<<"wprowadz wielkosc struktury i procent wypelnienia"<<std::endl;
        return 0;
    }

    int size = stoi(argv[1]);
    int factor = stoi(argv[2]);

    NeighbourLists m(size);
    Tests::fillGraph(m,factor);

    //wektor testowy
    std::vector<int> vec;
    for(int i=0;i<size;++i)
        vec.push_back(rand()%size);

    cout<<m<<endl;
    cout<<"-------------pomiar-------------"<<endl;
    cout<<"wielkosc: "<<size<<endl;
    cout<<"procent wypelnienia: "<<factor<<endl;
    double time = Tests::testBellFord(m, vec);
    cout<<"Djiskra: "<<std::fixed<<time<<" s"<<endl;

    cerr << size<<", "<<factor/100.0<<", "<<std::fixed<<time<<endl;
*/
    //time = Tests::testBellFord(m, vec);
    //time = Tests::testDjiskra(m, vec);



    return 0;
}
