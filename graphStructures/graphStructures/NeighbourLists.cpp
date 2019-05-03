#include "NeighbourLists.h"

NeighbourLists::NeighbourLists(int verts)
{
    this->verts = verts;

    data = new std::list<ListItem>[verts];

}

NeighbourLists::~NeighbourLists()
{

}

bool NeighbourLists::addEdge(int vert1, int vert2, int factor)
{

    bool exist = false;
    for(ListItem& i: data[vert1]){
        if(i.vert == vert2){
            exist = true;
            i.factor = factor;
        }
    }

    if(exist==false)
        data[vert1].push_back(ListItem{vert2, factor});

    //polaczenia symetryczne wiec trzeba wywolac procedure jeszze dla odwroconyh argumentow


    exist = false;
    for(ListItem& i: data[vert2]){
        if(i.vert == vert1){
            exist = true;
            i.factor = factor;
        }
    }

    if(exist==false)
        data[vert2].push_back(ListItem{vert1, factor});

    return exist;
}

int NeighbourLists::size() const
{
    return verts;
}

int NeighbourLists::edge(int vert1, int vert2) const
{
    for(ListItem& i: data[vert1]){
        if(i.vert == vert2){
            return i.factor;
        }
    }

    throw("Przekroczenie zakresu. Nie istnieje podana krawedz. w int NeighbourLists::edge(int vert1, vert2)");
}

int NeighbourLists::edge(int vert1, int vert2)
{
    for(ListItem& i: data[vert1]){
        if(i.vert == vert2){
            return i.factor;
        }
    }

    throw("Przekroczenie zakresu. Nie istnieje podana krawedz. w int NeighbourLists::edge(int vert1, vert2)");

}

std::vector<int> NeighbourLists::neighbours(int vert) const
{
    std::vector<int> nei;
    for(ListItem& i: data[vert]){
        nei.push_back(i.vert);
    }

    return nei;
}

std::vector<int> NeighbourLists::edges() const
{
    std::vector<int> edges;
    for(int j=0;j<verts;++j){
        for(ListItem& i: data[j]){
            edges.push_back(j);
            edges.push_back(i.vert);
        }
    }

    return edges;
}

std::ostream &operator<<(std::ostream &str, const NeighbourLists &list)
{
    for(int j=0;j<list.size();++j){
        str<<std::setw(3)<<j<<".";
        for(NeighbourLists::ListItem& i: list.data[j]){
            str<<std::setw(6)<<i.vert<<":"<<i.factor;
        }
        str<<std::endl;
    }


    return str;
}
