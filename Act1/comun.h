#ifndef __COMUN_H
#define __COMUN_H

#include <stdlib.h>

#define SZ_ARR 128
typedef struct
{
    int x, y;
    char str[SZ_ARR];
}data_t;

typedef struct lista
{
    data_t xy;
    struct lista *sig;
}lista_t;

#endif