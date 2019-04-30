#ifndef TIMETESTS_H
#define TIMETESTS_H


#include "MyVector.h"
#include "MyList.h"
#include "MyHeap.h"
#include "MyRedBlackTree.h"
#include "Timer.h"

#include <vector>

class TimeTests
{
public:
    TimeTests();

    void test(int tests, int dataCount);

    std::vector<double> vectorTests(int *data, int count);
    std::vector<double> listTests(int *data, int count);
    std::vector<double> heapTests(int *data, int count);
    std::vector<double> RBTreeTests(int *data, int count);

    template<typename T>
    double pushBackFuncTest(T& obj, int* data, int count);

    template<typename T>
    double pushFrontFuncTest(T& obj, int* data, int count);

    template<typename T>
    double pushRandomFuncTest(T& obj, int* data, int count);

    template<typename T>
    double containsFuncTest(T& obj, int* data, int count);

    template<typename T>
    double popFuncTest(T& obj);

    template<typename T>
    double removeRandomFuncTest(T& obj);

    template<typename T>
    double removeFrontFuncTest(T& obj);

    template<typename T>
    double removeBackFuncTest(T& obj);


    std::vector<int> generateInts(int max, int min, int count);

    void printAvg(std::ostream& str, std::vector<std::vector<double> > data);

};


#endif // TIMETESTS_H
