///\file isprim.c
///\brief Function used to check if the number is prim
/// Created by Iofcea Albert Catalin  on 20/5/18

#include "isprim.h"

///\fn void isprim(int p)
int isprim(int p){
    ///\param p check id p is prim
    int i;
    ///
    ///\brief int i  - Iterator
    for(i=2;i*i<=p;i++)
        if(p%i==0)
            return 0;
    return 1;
}
