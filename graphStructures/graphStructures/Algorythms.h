#ifndef ALGORYTHMS_H
#define ALGORYTHMS_H

#include <vector>
#include <iostream>

#include "Pair.h"




template<typename T>
std::ostream& operator << (std::ostream& str, const std::vector<T>& v)
{
    for(T i:v)
        str<<i<<" ";
    return str;
}

template<typename T>
int vecMin (const std::vector<T>& v)
{
    if(v.size() == 0) return -1;

    T min=v[0];
    unsigned int index = 0;
    for(unsigned int i=0;i<v.size();++i)
        if(min>v[i]) {
            index = i;
            min = v[i];
        }


    return (signed)index;
}

class Algorythms
{
public:
    Algorythms();

    template<typename T>
    static std::vector<int> dijkstra(const T& graph, int beginVert)
    {
        //utowrzenie tablicy odleglosci do wszystkich wierzcholkow
        std::vector<int> d(graph.size(), 0x0FFFFFFF); // maksymalny int ktory nie jest
                                                               // interpretowany przy wyswietlaniu jako
                                                               // liczna ujemna
        d[beginVert] = 0; //odleglosc od wierzcholka poszukiwan do niego samego wynosi zero

        //cout<<d<<endl;

        //utowrzenie kolejki priorytetowej
        std::vector<Pair<int, int*> > queue;

        for(unsigned int i=0;i<d.size();++i){
            queue.push_back(Pair<int, int*>(i, &d[i]));
        }

        //znalezienie najblizszego elementu
        int minIndex = vecMin(queue);

        while(minIndex >= 0){

            //zczytanie wartosci wierzcholka
            int vert = queue[minIndex].obj1;

            //lista sasiadow danego wierzcholka
            std::vector<int> neighbours = graph.neighbours(vert);

            //cout<<"neighbours("<<vert<<"): "<<neighbours<<endl;
            for(int i : neighbours){

                if(d[i]>d[vert] + graph.edge(vert, i)){
                    //cout<<d[i]<<endl;
                    d[i] = d[vert] + graph.edge(vert, i);
                }
            }

            //cout<<queue<<"|"<<minIndex<<endl;
            //usuniecie z kolejki najblizszego elementu
            queue.erase(queue.begin()+minIndex);

            //znalezienei najbliszego elementu. jezeli kolejka pusta to minIndex = -1
            minIndex = vecMin(queue);

        }

        for(int& i:d){
            if(i == 0x0FFFFFFF)
                i = -1;
        }

        return d;
    }


    template<typename T>
    static std::vector<int> bellFord(const T& graph, int beginVert){
        //utowrzenie tablicy odleglosci do wszystkich wierzcholkow
        std::vector<int> d(graph.size(), 0x0FFFFFFF); // maksymalny int ktory nie jest
                                                               // interpretowany przy wyswietlaniu jako
                                                               // liczna ujemna
        d[beginVert] = 0; //odleglosc od wierzcholka poszukiwan do niego samego wynosi zero

        std::vector<int> edges = graph.edges();

        //przetwarzanie odleglosci powtarzamy jeden raz mniej niz wynsi ilosc wierzcholkow
        for(unsigned int i=0;i<d.size();++i){
            for(unsigned int j=0;j<edges.size();j+=2){
                int v1 = edges[j];  //wierzcholek poczatku krawedzi
                int v2 = edges[j+1];//wierzcholek konca krawedzi

                if(d[v2] > d[v1] + graph.edge(v2,v1)){
                    d[v2] = d[v1] + graph.edge(v2,v1);
                }
            }
        }

        for(int& i:d){
            if(i == 0x0FFFFFFF)
                i = -1;
        }


        return d;
    }

};

#endif // ALGORYTHMS_H
