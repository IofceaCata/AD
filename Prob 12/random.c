///\file random.c
///\brief Function used to generate a random number
/// Created by Iofcea Albert Catalin  on 20/5/18

#include "random.h"

///\fn void random()
int random(int power){

    return rand()%power;
}
