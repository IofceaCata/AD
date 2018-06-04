///\file isprim.c
///\brief Function used to check if a number is prim
/// Created by Iofcea Albert Catalin  on 20/5/18

#include "isprim.h"

int isprim(int p){
    int i;
    for(i=2;i*i<=p;i++) /// we check if the number has divisors ( it is enought to check up to sqrt of it )
        if(p%i==0)
            return 0;
    return 1;
}
