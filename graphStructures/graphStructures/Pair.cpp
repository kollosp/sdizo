#include "Pair.h"

bool operator >(const Pair<int, int *> &p1, const Pair<int, int *> &p2)
{
    return (*p1.obj2) > (*p2.obj2);

}
