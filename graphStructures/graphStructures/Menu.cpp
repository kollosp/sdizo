#include "Menu.h"

Menu::Menu()
{

}

void Menu::fromFile()
{
    std::cout<<"Ladowanie grafu z pliku"<<std::endl;

    std::string file;
    std::cout<<"podaj sciezke do pliku: ";
    std::cin >> file;

    char bidirectional = 'N';
    std::cout<<"Wymys graf nieskierowany(N/T): ";
    std::cin >> bidirectional;

    Algorythms::fromFile(graphList, file, bidirectional == 'N' ? 0:1);
    Algorythms::fromFile(graphMatrix, file, bidirectional == 'N' ? 0:1);

    std::cout<<"Zaladowano"<<std::endl;
    pause();
}

void Menu::toFile()
{
    std::cout<<"Zapisywanie grafu do pliku"<<std::endl;

    std::string file;
    std::cout<<"podaj sciezke do pliku: ";
    std::cin >> file;

    Algorythms::toFile(graphList, file);
    Algorythms::toFile(graphMatrix, file);


    std::cout<<"Zapisano"<<std::endl;
    pause();

}

void Menu::random()
{
    std::cout<<"Generowanie losowego grafu"<<std::endl;

    int vert;
    std::cout<<"podaj ilosc wierzcholkow: ";
    std::cin >> vert;

    int factor;
    std::cout<<"podaj stopien wypelnienia grafu (0-100%): ";
    std::cin >> factor;

    graphMatrix.init(vert);
    Algorythms::fillGraph(graphMatrix, factor);

    Algorythms::copy(graphMatrix, graphList);


    std::cout<<"Wygenerowano"<<std::endl;
    pause();

}

void Menu::displayMatrix()
{

    std::cout<<"Wyswietlanie grafu: macierz sasiedztwa"<<std::endl;
    std::cout<<graphMatrix<<std::endl;
    pause();
}

void Menu::displayList()
{
    std::cout<<"Wyswietlanie grafu: Lista sasiadow"<<std::endl;
    std::cout<<graphList<<std::endl;
    pause();
}

void Menu::djiskra()
{
    char choise;
    std::cout<<"Algorytm djikstry (Macierz/Lista):"<<std::endl;
    std::cin>>choise;
    std::cout<<"Podaj wierzcholek z zakresu(0 - "<<graphMatrix.size()-1<<"): ";
    int vert;

    std::cin>>vert;

    std::vector<int> p;
    std::vector<int> d;

    if(choise == 'M')
        Algorythms::dijkstra(graphMatrix, vert, p, d);
    if(choise == 'L')
        Algorythms::dijkstra(graphList, vert, p, d);

    std::cout<<"nr    : ";
    for(unsigned int i=0;i<p.size();++i)
        std::cout<<std::setw(4)<<i;
    std::cout<<std::endl;

    std::cout<<"odl.  : ";
    for(unsigned int i=0;i<d.size();++i)
        std::cout<<std::setw(4)<<d[i];
    std::cout<<std::endl;


    std::cout<<"poprz.: ";
    for(unsigned int i=0;i<p.size();++i)
        std::cout<<std::setw(4)<<p[i];
    std::cout<<std::endl;
}

void Menu::bellford()
{
    char choise;
    std::cout<<"Algorytm bellmana-forda (Macierz/Lista):"<<std::endl;
    std::cin>>choise;
    std::cout<<"Podaj wierzcholek z zakresu(0 - "<<graphMatrix.size()-1<<"): ";
    int vert;

    std::cin>>vert;

    std::vector<int> p;
    std::vector<int> d;

    if(choise == 'M')
        Algorythms::bellFord(graphMatrix, vert, p, d);
    if(choise == 'L')
        Algorythms::bellFord(graphList, vert, p, d);

    std::cout<<"nr    : ";
    for(unsigned int i=0;i<p.size();++i)
        std::cout<<std::setw(4)<<i;
    std::cout<<std::endl;

    std::cout<<"odl.  : ";
    for(unsigned int i=0;i<d.size();++i)
        std::cout<<std::setw(4)<<d[i];
    std::cout<<std::endl;


    std::cout<<"poprz.: ";
    for(unsigned int i=0;i<p.size();++i)
        std::cout<<std::setw(4)<<p[i];
    std::cout<<std::endl;
}

void Menu::prime()
{
    char choise;
    std::cout<<"Algorytm prima (Macierz/Lista):"<<std::endl;
    std::cin>>choise;
    std::cout<<"Podaj wierzcholek z zakresu(0 - "<<graphMatrix.size()-1<<"): ";
    int vert;

    std::cin>>vert;

    NeighbourMatrix matrix;
    NeighbourLists list;

    if(choise == 'M')
        Algorythms::prime(graphMatrix, matrix, vert);
    if(choise == 'L')
        Algorythms::prime(graphList, matrix, vert);

    std::cout<<matrix<<std::endl;
    std::cout<<"-------------------"<<std::endl;
    Algorythms::copy(matrix, list);
    std::cout<<list<<std::endl;
    pause();
}

void Menu::kruskal()
{
    char choise;
    std::cout<<"Algorytm prima (Macierz/Lista):"<<std::endl;
    std::cin>>choise;


    NeighbourMatrix matrix;
    NeighbourLists list;

    if(choise == 'M')
        Algorythms::kruskal(graphMatrix, matrix);
    if(choise == 'L')
        Algorythms::kruskal(graphList, matrix);

    std::cout<<matrix<<std::endl;
    std::cout<<"-------------------"<<std::endl;
    Algorythms::copy(matrix, list);
    std::cout<<list<<std::endl;
    pause();
}


void Menu::run()
{
    int d = 0;


    do{

        std::cout<<"----------------------------------------------"<<std::endl;
        std::cout<<mainMenu<<std::endl;
        std::cin >> d;

        switch(d){
        case 1: fromFile();      break;
        case 2: toFile();        break;
        case 3: random();        break;
        case 4: displayMatrix(); break;
        case 5: displayList();   break;
        case 6: djiskra();       break;
        case 7: bellford();      break;
        case 8: prime();         break;
        case 9: kruskal();       break;
        }

    }while(d!=0);
}

void Menu::pause()
{
    std::cin.ignore(1024, '\n');
    std::cout << "Wcisnij enter aby kontynuowac...";
    std::cin.get();
}
