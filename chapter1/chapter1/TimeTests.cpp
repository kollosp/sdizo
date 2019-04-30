#include "TimeTests.h"

TimeTests::TimeTests()
{

}

void TimeTests::test(int tests, int dataCount)
{

    std::cout<<"ilosc testow: "<<tests<<" populacja w tescie: "<<dataCount<<std::endl;
    std::vector<std::vector<int> > data;
    for(int i=0;i<tests;++i){
        data.push_back(generateInts(100000, 0, dataCount));
    }

    std::vector<std::vector<double> > vecResults;
    std::vector<std::vector<double> > listResults;
    std::vector<std::vector<double> > heapResults;
    std::vector<std::vector<double> > RBResults;

    for(int i=0;i<tests;++i)
        vecResults.push_back(vectorTests(data[i].data(), data[i].size()));

    for(int i=0;i<tests;++i)
        listResults.push_back(listTests(data[i].data(), data[i].size()));


    for(int i=0;i<tests;++i)
        heapResults.push_back(heapTests(data[i].data(), data[i].size()));

    for(int i=0;i<tests;++i)
        RBResults.push_back(RBTreeTests(data[i].data(), data[i].size()));

    std::cout<<std::endl<<std::endl<<"Tablica dynamiczna"<<std::endl;
    std::cout<<"push_back; remove_back; push_front; remove_front; push_random; remove_random; contains"<<std::endl;
    printAvg(std::cout, vecResults);

    std::cout<<std::endl<<std::endl<<"Lista"<<std::endl;
    std::cout<<"push_back; remove_back; push_front; remove_front; push_random; remove_random; contains"<<std::endl;
    printAvg(std::cout, listResults);

    std::cout<<std::endl<<std::endl<<"Kopiec"<<std::endl;
    std::cout<<"push; contains; pop;"<<std::endl;
    printAvg(std::cout, heapResults);

    std::cout<<std::endl<<std::endl<<"Drzewo"<<std::endl;
    std::cout<<"push; contains; "<<std::endl;
    printAvg(std::cout, RBResults);
}



std::vector<double> TimeTests::vectorTests(int* data, int count)
{

    std::vector<double> ret;

    MyVector obj;
    MyVector obj1;
    MyVector obj2;
    //std::cout<<"czasy przetwarzania wektora;"<<std::endl;
    //std::cout<<"push_back; remove_back; push_front; remove_front; push_random; remove_random; contains"<<std::endl;
    ret.push_back(pushBackFuncTest(obj, data, count));
    ret.push_back(removeBackFuncTest(obj));
    ret.push_back(pushFrontFuncTest(obj1, data, count));
    ret.push_back(removeFrontFuncTest(obj1));
    ret.push_back(pushRandomFuncTest(obj2, data, count));
    ret.push_back(removeRandomFuncTest(obj2));
    ret.push_back(containsFuncTest(obj2, data, count));
    return ret;
}

std::vector<double> TimeTests::listTests(int* data, int count)
{

    std::vector<double> ret;
    MyList obj;
    MyList obj1;
    MyList obj2;
    //ret.push_back("czasy przetwarzania listy;"<<std::endl;
    //ret.push_back("push_back; remove_back; push_front; remove_front; push_random; remove_random; contains"<<std::endl;
    ret.push_back(pushBackFuncTest(obj, data, count));
    ret.push_back(removeBackFuncTest(obj));
    ret.push_back(pushFrontFuncTest(obj1, data, count));
    ret.push_back(removeFrontFuncTest(obj1));
    ret.push_back(pushRandomFuncTest(obj2, data, count));
    ret.push_back(removeRandomFuncTest(obj2));
    ret.push_back(containsFuncTest(obj2, data, count));

    return ret;

}

std::vector<double> TimeTests::heapTests(int *data, int count)
{
    std::vector<double> ret;
    MyHeap obj;

    //ret.push_back("czasy przetwarzania kopca;"<<std::endl;
    //ret.push_back("push; contains; pop;"<<std::endl;
    ret.push_back(pushFrontFuncTest(obj, data, count));
    ret.push_back(containsFuncTest(obj, data, count));
    ret.push_back(popFuncTest(obj));
    return ret;

}

std::vector<double> TimeTests::RBTreeTests(int *data, int count)
{
    std::vector<double> ret;
    MyRedBlackTree obj;

    //ret.push_back("czasy przetwarzania kopca;"<<std::endl;
    //ret.push_back("push; contains; "<<std::endl;
    ret.push_back(pushFrontFuncTest(obj, data, count));
    ret.push_back(containsFuncTest(obj, data, count));
    return ret;
}

std::vector<int> TimeTests::generateInts(int max, int min, int count){

    std::vector<int> ret;
    int m = max-min;

    for(int i=0;i<count;++i){
        ret.push_back((rand()%m)+min);
        //cerr<<"\r generowanie liczb "<<i<<"/"<<count<<" ";
    }
    //cerr<<"done."<<endl;

    return ret;
}

void TimeTests::printAvg(std::ostream &str, std::vector<std::vector<double> > data)
{
    std::vector<double> avg(data[0].size());

    for(unsigned int i=0;i<data.size();++i){
        for(unsigned int j=0;j<data[i].size();++j)
            avg[j]+=data[i][j];
    }

    for(unsigned int i=0;i<avg.size();++i){
        avg[i] /= data[i].size();
        str<<std::fixed<<avg[i]<< " ";
    }
    str<<std::endl;
}

template<typename T>
double TimeTests::pushBackFuncTest(T &obj, int *data, int count)
{

    Timer tm;
    tm.start();
    for(int i=0;i<count;++i){
        obj.push_back(data[i]);
    }

    tm.stop();
    return tm.elapsed();

}

template<typename T>
double TimeTests::removeFrontFuncTest(T &obj)
{
    Timer tm;
    tm.start();
    int len = obj.length();
    for(int i=0;i<len;++i){
        obj.remove(0);
    }

    tm.stop();
    return tm.elapsed();
}

template<typename T>
double TimeTests::popFuncTest(T &obj)
{
    Timer tm;
    tm.start();

    while(!obj.isEmpty()){
        obj.pop();
    }

    tm.stop();
    return tm.elapsed();
}

template<typename T>
double TimeTests::removeBackFuncTest(T &obj)
{
    Timer tm;
    tm.start();
    int len = obj.length();
    for(int i=0;i<len;++i){
        obj.pop_back();
    }

    tm.stop();
    return tm.elapsed();
}

template<typename T>
double TimeTests::pushFrontFuncTest(T &obj, int *data, int count)
{
    Timer tm;
    tm.start();
    for(int i=0;i<count;++i){
        obj.push_front(data[i]);
    }

    tm.stop();
    return tm.elapsed();
}

template<typename T>
double TimeTests::pushRandomFuncTest(T &obj, int *data, int count)
{
    Timer tm;
    tm.start();
    for(int i=0;i<count;++i){
        int pos = 2*(i+1)/3;
        obj.insert(data[i], pos);
    }

    tm.stop();
    return tm.elapsed();
}

template<typename T>
double TimeTests::removeRandomFuncTest(T &obj)
{
    Timer tm;
    tm.start();
    int len = obj.length();
    for(int i=0;i<len;++i){
        int pos = 2*(i+1)/3;
        obj.remove(pos);
    }

    tm.stop();
    return tm.elapsed();
}

template<typename T>
double TimeTests::containsFuncTest(T &obj, int *data, int count)
{
    Timer tm;
    tm.start();
    for(int i=0;i<count;++i){
        obj.contains(data[i]);
    }

    tm.stop();
    return tm.elapsed();
}
