///\file verif_prim.c
///\brief Function used to verify if the numbet is prim .Returns 1 when is prim and 0 when is not
/// Created by Iofcea Albert Catalin  on 20/5/18

#include "verif_prim.h"

///\fn void verif_prim()
int verif_prim( int nr ){
    ///\param nr
    int i;
    ///\brief int i  - Iterator
    ///
    int h=0;
    ///\brief int h  - variable who store the number of divisors
    for(i=2;i*i<=nr;i++)
        if(nr%i==0)
            h++;
    if(h==0)
        return 1;
    else
        return 0;
}
