///\file primrandom.c
///\brief Function used to generate a random prim number
/// Created by Iofcea Albert Catalin  on 20/5/18

#include "primrandom.h"
#include "isprim.h"

int primrandom(){

    int p;

    p=rand()%10;
    if(p>1){
        if(isprim(p)==1)
            return p;
        else
            primrandom();
    }
    else
        primrandom();
}
