///\file litererandom.c
///\brief Function used to generate a random letter
/// Created by Iofcea Albert Catalin  on 20/5/18

#include "litererandom.h"

///\fn void litererandom()
int litererandom(){

    rand();
    char abc[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ///\brief int abc[]  - vector where the alphabet is stored
    ///
    int p=rand()%52;
    ///\brief int p=rand()%52  - generate a random number smaller than the number of letters in the alphabet

    return abc[p];
}
