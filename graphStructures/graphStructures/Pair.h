#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template<typename T1, typename T2>
class Pair{
public:
    Pair(T1 k1, T2 k2): obj1(k1), obj2(k2) {}
    T1 obj1;
    T2 obj2;

};

template<typename T1>
std::ostream& operator << (std::ostream& str, const Pair<T1,int*>& v){
    str<<v.obj1<<":"<<*v.obj2;
    return str;
}

bool operator > (const Pair<int, int*>& p1, const Pair<int, int*>& p2);

#endif // PAIR_H
