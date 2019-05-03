#ifndef NEIGHBOURLISTS_H
#define NEIGHBOURLISTS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

class NeighbourLists
{
    struct ListItem{
        int vert; //ktory wierzcholek
        int factor; //jaki jest koszt sciezki
    };

    std::list<ListItem> *data;
    int verts;

    NeighbourLists(const NeighbourLists&);
    NeighbourLists& operator=(const NeighbourLists&);

public:
    NeighbourLists(int verts);
    ~NeighbourLists();

    /**
     * @brief addEdge funkcja tworzy krawedz pomiedzy wyznazonymi werzcholkami
     * @param vert1
     * @param vert2
     * @param factor - wartosc (waga) polaczenia
     * @return false - krawedz nie istniala i zostala utworzona
     */
    bool addEdge(int vert1, int vert2, int factor = 1);

    int size() const;

    /**
     * @brief edge zwraca wartosc w komorce data[vert1][vert2]
     * @param vert1
     * @return
     */
    int edge(int vert1, int vert2) const;
    int edge(int vert1, int vert2);

    /**
     * @brief neighbours funckja zwraca wektor sasiadow podanego wierzcholka
     * @param vert
     * @return
     *
     *
     * Uzycie:
        cout<<"neighbours("<<vert<<"): "<<graph.neighbours(vert)<<endl;
     */
    std::vector<int> neighbours(int vert) const;


    /**
     * @brief edges funkcja zwraca wszystkie krawedzie grafu
     * @return wektor zawierajacy 2*verts komorek.
     * w komorach [i, i+1] znajduja sie numery wierzcholkow tworzacych krawedz
     */
    std::vector<int> edges() const;

    friend std::ostream& operator<<(std::ostream& str, const NeighbourLists& list);
};

std::ostream& operator<<(std::ostream& str, const NeighbourLists& list);

#endif // NEIGHBOURLISTS_H
