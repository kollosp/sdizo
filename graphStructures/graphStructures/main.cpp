#include <iostream>
#include <vector>
#include <functional>
#include <queue>

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

int main(void)
{

    srand(time(NULL));
    //neighbourMatrixTest();
    //neighbourListTest();

    NeighbourMatrix m(5);
    Tests::fillGraph(m,100);
    std::vector<int> vec = {1,2};
    cout<<Tests::testDjiskra(m, vec)<<endl;
    return 0;
}
