#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <stdio.h>

#include "NeighbourMatrix.h"
#include "NeighbourLists.h"

#include "Tests.h"
#include "Algorythms.h"

class Menu
{

    std::string mainMenu = "----Menu Glowne----\n"
                           " 1. Wczytaj z pliku\n"
                           " 2. Zapisz do pliku\n"
                           " 3. Wygeneruj losowy\n"
                           " 4. Wyswietl macierzowo\n"
                           " 5. Wyswietl listowo\n"
                           " 6. Alogrytm Djikstry\n"
                           " 7. Alogrytm Bellmana-Forda\n"
                           " 8. Algorytm Prima\n"
                           " 9. Algorytm Kruskala\n"
                           " 0. Wyjscie z programu";

    NeighbourLists graphList;
    NeighbourMatrix graphMatrix;

public:
    Menu();

    void fromFile();
    void toFile();
    void random();

    void displayMatrix();
    void displayList();

    void djiskra();
    void bellford();
    void prime();
    void kruskal();


    void run();

    void pause();
};

#endif // MENU_H
