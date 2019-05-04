#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <vector>
#include "NeighbourLists.h"
#include "NeighbourMatrix.h"
#include "Algorythms.h"
#include "Timer.h"

class Tests{
public:
    template<typename T>
    static void fillGraph(T &graph, int fillFactor);

    template<typename T>
    static double testDjiskra(T &graph, const std::vector<int>& sourceVerts);

    template<typename T>
    static double testBellFord(T &graph, const std::vector<int>& sourceVerts);
};

template<typename T>
void Tests::fillGraph(T &graph, int fillFactor)
{
    int edges = (graph.size()*(graph.size()-1) / 2.0) * fillFactor/100.0;
    int size = graph.size();

    for(int i=0;i<edges;){
        int v1 = rand()%size;
        int v2 = rand()%size;
        if(v1!=v2)
            if(graph.addEdge(v1,v2) == false) ++i;
    }

}

template<typename T>
double Tests::testDjiskra(T &graph, const std::vector<int>& sourceVerts)
{
    Timer t;
    t.start();


    for(int i:sourceVerts){
        //std::cout<<Algorythms::dijkstra(graph, i)<<std::endl;
        Algorythms::dijkstra(graph, i);
    }

    t.stop();
    return t.elapsed();
}

template<typename T>
double Tests::testBellFord(T &graph, const std::vector<int>& sourceVerts)
{
    Timer t;
    t.start();


    for(int i:sourceVerts){
        //std::cout<<Algorythms::bellFord(graph, i)<<std::endl;
        Algorythms::bellFord(graph, i);
    }

    t.stop();
    return t.elapsed();
}


#endif // TESTS_H
