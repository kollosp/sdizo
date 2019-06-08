#ifndef ALGORYTHMS_H
#define ALGORYTHMS_H

#include <stack>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include <iomanip>

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
    static void dijkstra(const T& graph, int beginVert, std::vector<int>& predecessor, std::vector<int>& distances)
    {
        //utworzenie tablicy poprzednikow
        std::vector<int> p(graph.size(), -1);

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
                    p[i] = vert;
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

        distances = d;
        predecessor = p;
    }

    template<typename T>
    static void fromFile(T& graph, const std::string& file, bool forceBidirectional=false)
    {
        std::ifstream f;
        f.open(file, std::ios::in);

        if(f.is_open()){
            int size, edges;
            f>>size>>edges;

            graph.init(size);

            for(int i=0;i<edges;++i){
                int vert1, vert2, factor;
                f>>vert1>>vert2>>factor;

                graph.addEdge(vert1, vert2, factor, forceBidirectional);
            }
        }
    }

    template<typename T1,typename T2>
    static void copy(const T1& src, T2& dst){
        dst.init(src.size());

        std::vector<int> edges = src.edges();

        for(unsigned int i=0;i<edges.size();i+=2){
            dst.addEdge(edges[i], edges[i+1], src.edge(edges[i], edges[i+1]), false);
        }
    }

    template<typename T>
    static void toFile(const T& graph, const std::string& file){
        std::ofstream f;
        f.open(file, std::ios::trunc);

        std::vector<int> edges = graph.edges();

        if(f.is_open()){
            f<<graph.size()<<" "<<edges.size()/2<<std::endl;

            for(unsigned int i=0;i<edges.size();i+=2){
                f<<edges[i]<<" "<<edges[i+1]<<" "<<graph.edge(edges[i], edges[i+1])<<std::endl;
            }
        }
    }

    template<typename T>
    static void bellFord(const T& graph, int beginVert, std::vector<int>& predecessor, std::vector<int>& distances){
        //utworzenie tablicy poprzednikow
        std::vector<int> p(graph.size(), -1);

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

                if(d[v2] > d[v1] + graph.edge(v1,v2)){
                    d[v2] = d[v1] + graph.edge(v1,v2);
                    p[v2] = v1;
                }
            }
        }

        for(int& i:d){
            if(i == 0x0FFFFFFF)
                i = -1;
        }

        distances = d;
        predecessor = p;
    }


    template<typename T>
    static void fillGraph(T &graph, int fillFactor){
        int edges = (graph.size()*(graph.size()-1)) * fillFactor/100.0;
        int size = graph.size();

        for(int i=0;i<edges;){
            int v1 = rand()%size;
            int v2 = rand()%size;
            if(v1!=v2)
                if(graph.addEdge(v1,v2, rand()%10, false) == false) ++i;
        }
    }


    template<typename T1,typename T2>
    static void prime(const T1& src, T2& dst, int vert){
        std::vector<int> edges = src.edges();

        //przechowuje info czy ity wierzcholek zostal juz dodany do dst
        std::vector<bool> addedVerts(src.size(), false);
        addedVerts[vert] = true;

        //inicjalizacja dst
        dst.init(src.size());

        //pierwszy wierzcholek zostal juz dodany
        int vertsToBeAdded = src.size() -1;

        //stos do przechowywania przetwarzanych wierzcholkow
        std::stack<int> verts;
        int currnetVert = vert;

        while(vertsToBeAdded>0){

            std::vector<int> neighbours = src.neighbours(currnetVert);

            //najmniejsza krawedz niezwiazana z dodanym wierzcholkiem
            int v2 = -1;
            int minEdge = 0x0FFFFFFF;
            for(int i=0;i<neighbours.size();++i){
                int edge = src.edge(currnetVert, neighbours[i]);
                if(minEdge> edge && addedVerts[neighbours[i]] == false){
                    minEdge = edge;
                    v2 = neighbours[i];
                }
            }

            //jezeli krawedz juz nie istnieje to
            if(v2 == -1)
            {
                if(verts.empty()) return;

                currnetVert = verts.top();
                verts.pop();
                continue;
            }

            //dodanie krawedzi do drzewa
            verts.push(currnetVert);
            dst.addEdge(currnetVert, v2, minEdge, false);
            currnetVert = v2;
            addedVerts[v2] = true;
            vertsToBeAdded--;

        }
    }

    template<typename T1,typename T2>
    static void kruskal(const T1& src, T2& dst){
        std::vector<int> edges = sortedEdges(src);

        //przechowuje info czy ity wierzcholek zostal juz dodany, a jesli tak
        //to do ktorego podgrafu
        std::vector<int> addedVerts(src.size(), -1);

        int groupNb = 1;

        //std::cout<<edges<<std::endl;

        for(unsigned int i=0;i<edges.size();i+=2){
            int& g1 = addedVerts[edges[i]];
            int& g2 = addedVerts[edges[i+1]];

            //std::cout<<groupNb<<": ";
            //for(int&i:addedVerts) std::cout<<std::setw(3)<<i;

            //std::cout<<", k: "<<edges[i]<<" "<<edges[i+1]<<std::endl;


            //grupa nie istnieje
            if(g1 == -1 && g2 == -1){
                //std::cout<<"g1 == -1 && g2 == -1 "<<std::endl;
                g1 = g2 = groupNb;
                groupNb += 1;
                dst.addEdge(edges[i], edges[i+1], src.edge(edges[i],edges[i+1]), false);
            }
            //oba elementy sa juz w grupach (roznych)
            else if(g1 != -1 && g2 != -1 && g1 != g2){

                //std::cout<<"g1 != -1 && g2 != -1 && g1 != g2"<<std::endl;
                //zamien wartosc g2 na g1
                int min = g1 <= g2 ? g1 : g2;
                int max = g1 >  g2 ? g1 : g2;

                //std::cout<<min<<" "<<max<<std::endl;
                for(int k=0;k<addedVerts.size();++k)
                    if(addedVerts[k] == max)
                        addedVerts[k] = min;

                dst.addEdge(edges[i], edges[i+1], src.edge(edges[i],edges[i+1]), false);
            }
            //g1 nalezy do frupy a g2 nie
            else if(g1 != -1 && g2 == -1){

                //std::cout<<"g1 != -1 && g2 == -1"<<std::endl;
                g2 = g1;
                dst.addEdge(edges[i], edges[i+1], src.edge(edges[i],edges[i+1]), false);
            }
            //g2 nalezy do grupy a g1 nie
            else if(g2 != -1 && g1 == -1){

                //std::cout<<"g2 != -1 && g1 == -1"<<std::endl;
                g1 = g2;
                dst.addEdge(edges[i], edges[i+1], src.edge(edges[i],edges[i+1]), false);
            }
        }

    }

    template<typename T1>
    static std::vector<int> sortedEdges(const T1& src){
        std::vector<int> edges = src.edges();

        for(unsigned int i=0;i<edges.size();i+=2){
            for(unsigned int j=i;j<edges.size();j+=2){

                //swap
                if(src.edge(edges[i], edges[i+1]) > src.edge(edges[j], edges[j+1])){
                    std::swap(edges[i], edges[j]);
                    std::swap(edges[i+1], edges[j+1]);
                }
            }
        }

        return edges;
    }
};

#endif // ALGORYTHMS_H
