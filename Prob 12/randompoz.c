///\file randompoz.c
///\brief Function used to generate a random number smaller than the lenght of vector a ( lenght of the message )
/// Created by Iofcea Albert Catalin  on 20/5/18

#include "randompoz.h"

int randompoz(int strlena){

    return rand()%strlena;
}
