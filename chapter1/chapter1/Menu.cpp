#include "Menu.h"

Menu::Menu()
{

}

void Menu::vectorRun()
{

    int choise = 0;
    MyVector vector;

    do{

        system("clear");
        std::cout<<VECTOR_MENU<<std::endl;
        std::cin >> choise;

        int value, pos;

        switch(choise){
        case 1:
            std::cout<<vector<<std::endl;
            pause();
            break;

        case 2:
            value = readInt(" Podaj wartosc: ");
            pos = readInt(" Podaj pozycje: ");
            vector.insert(value, pos);
            std::cout<<vector<<std::endl;
            pause();
            break;

        case 3:
            value = readInt(" Podaj wartosc: ");
            vector.push_back(value);
            std::cout<<vector<<std::endl;
            pause();
            break;

        case 4:
            value = readInt(" Podaj wartosc: ");
            vector.push_front(value);
            std::cout<<vector<<std::endl;
            pause();
            break;

        case 5:
            pos = readInt(" Podaj pozycje: ");
            vector.remove(pos);
            std::cout<<vector<<std::endl;
            pause();
            break;

        case 6:
            std::cout<<"Aktualna dlugosc tablicy wynosi: "<<vector.length()<<std::endl;
            pause();
            break;
        }


    }while(choise != 0);

}

void Menu::listRun()
{

    int choise = 0;


    MyList list;

    do{

        system("clear");
        std::cout<<LIST_MENU<<std::endl;
        std::cin >> choise;

        int value, pos;

        switch(choise){
        case 1:
            std::cout<<list<<std::endl;
            pause();
            break;

        case 2:
            value = readInt(" Podaj wartosc: ");
            pos = readInt(" Podaj pozycje: ");
            list.insert(value, pos);
            std::cout<<list<<std::endl;
            pause();
            break;

        case 3:
            value = readInt(" Podaj wartosc: ");
            list.push_back(value);
            std::cout<<list<<std::endl;
            pause();
            break;

        case 4:
            value = readInt(" Podaj wartosc: ");
            list.push_front(value);
            std::cout<<list<<std::endl;
            pause();
            break;

        case 5:
            pos = readInt(" Podaj pozycje: ");
            list.remove(pos);
            std::cout<<list<<std::endl;
            pause();
            break;

        case 6:
            std::cout<<"Aktualna dlugosc tablicy wynosi: "<<list.length()<<std::endl;
            pause();
            break;
        }


    }while(choise != 0);


}

void Menu::heapRun()
{

    int choise = 0;

    MyHeap heap;
    heap.push(10);
    heap.push(100);
    heap.push(50);

    do{

        system("clear");
        std::cout<<HEAP_MENU<<std::endl;
        std::cin >> choise;

        int value;

        switch(choise){
        case 1:
            std::cout<<heap<<std::endl;
            pause();
            break;

        case 2:
            value = readInt(" Podaj wartosc: ");
            heap.push(value);
            std::cout<<heap<<std::endl;
            pause();
            break;

        case 3:
            value = readInt(" Podaj wartosc: ");
            heap.remove(value);
            std::cout<<heap<<std::endl;
            pause();
            break;

        case 4:
            heap.popHead();
            std::cout<<heap<<std::endl;
            pause();
            break;
        }

    }while(choise != 0);


}

void Menu::treeRun()
{

    int choise = 0;

    MyRedBlackTree tree;

    do{

        system("clear");
        std::cout<<TREE_MENU<<std::endl;
        std::cin >> choise;

        int value;

        switch(choise){
        case 1:
            std::cout<<tree<<std::endl;
            pause();
            break;

        case 2:
            value = readInt(" Podaj wartosc: ");
            tree.push(value);
            std::cout<<tree<<std::endl;
            pause();
            break;

        case 3:
            value = readInt(" Podaj wartosc: ");
            tree.remove(value);
            std::cout<<tree<<std::endl;
            pause();
            break;
        }

    }while(choise != 0);

}


void Menu::run()
{


    int choise = 0;


    do{

        system("clear");
        std::cout<<MAIN_MENU<<std::endl;
        std::cin >> choise;

        switch(choise){
        case 1: vectorRun(); break;
        case 2: listRun();   break;
        case 3: heapRun();   break;
        case 4: treeRun();   break;
        }

    }while(choise != 0);

    std::cout<<GOOD_BYE<<std::endl;
}

void Menu::pause()
{
    std::cin.ignore(1024, '\n');
    std::cout << "Wcisnij enter aby kontynuowac...";
    std::cin.get();
}

int Menu::readInt(std::string text)
{
    std::cout<<text;
    int i;
    std::cin >> i;
    return i;
}
