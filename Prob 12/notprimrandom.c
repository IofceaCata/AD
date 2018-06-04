///\file notprimrandom.c
///\brief Function used to generate a random nonprim number
/// Created by Iofcea Albert Catalin  on 20/5/18

#include "notprimrandom.h"
#include "isprim.h"

int notprimrandom(){

    int p;

    p=rand()%10;
    if(p>1){
        if(isprim(p)==0)
            return p;
        else
            notprimrandom();
    }
    else
        notprimrandom();
}
