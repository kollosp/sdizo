#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "MyList.h"
#include "MyVector.h"
#include "MyHeap.h"
#include "MyRedBlackTree.h"

const std::string MAIN_MENU = "WYBIERZ strukture na ktorej chcesz operowac:\n"
                              " 1. Tablica\n"
                              " 2. Lista\n"
                              " 3. Kopiec\n"
                              " 4. Drzewo czerowno-czarne\n"
                              " 0. Wyjscie";

const std::string VECTOR_MENU = "WYBIERZ jedna z operacji na tablicy: \n"
                                " 1. wyswietlenie\n"
                                " 2. dodanie elementu (insert)\n"
                                " 3. dodanie elementu (push_back)\n"
                                " 4. dodanie elementu (push_front)\n"
                                " 5. usuniecie elementu\n"
                                " 6. wyswietlenie dlugosci\n"
                                " 0. wyjscie";

const std::string LIST_MENU = "WYBIERZ jedna z operacji na liscie: \n"
                              " 1. wyswietlenie\n"
                              " 2. dodanie elementu (insert)\n"
                              " 3. dodanie elementu (push_back)\n"
                              " 4. dodanie elementu (push_front)\n"
                              " 5. usuniecie elementu\n"
                              " 6. wyswietlenie dlugosci\n"
                              " 0. wyjscie";

const std::string HEAP_MENU = "WYBIERZ jedna z operacji na kopcu: \n"
                              " 1. wyswietlenie\n"
                              " 2. dodanie elementu\n"
                              " 3. usuniecie elementu\n"
                              " 4. usuniecie ze szczytu\n"
                              " 0. wyjscie";

const std::string TREE_MENU = "WYBIERZ jedna z operacji na drzewie: \n"
                              " 1. wyswietlenie\n"
                              " 2. dodanie elementu\n"
                              " 3. usuniecie elementu\n"
                              " 0. wyjscie";

const std::string GOOD_BYE = "Do widzenia!";

class Menu
{

public:
    Menu();


    void vectorRun();
    void listRun();
    void heapRun();
    void treeRun();
    void run();
    void pause();

    int readInt(std::string text);


};

#endif // MENU_H
