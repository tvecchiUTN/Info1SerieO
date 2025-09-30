#include <stdio.h>
#include <string.h>

#include "comun.h"
#include "funcsComun.h"
#include "funcsVariadas.h"

int invList(lista_t **inicio)
{
    int i = 0;

    if(!*inicio)
    {
        fprintf(stderr, "No hay lista\n");
        return EST_EMPTY;
    }

    if(!(*inicio)->sig)
    {
        fprintf(stdout, "Lista con un solo elemento\n");
        return 1;
    }

    lista_t *siguiente = NULL;
    lista_t *centro = *inicio;
    lista_t *anterior = NULL;

    while(centro)
    {
        siguiente = centro -> sig;  // 1. Guardar referencia al siguiente
        centro ->sig = anterior;    // 2. ¡INVERTIR EL ENLACE!
        anterior = centro;          // 3. Mover anterior hacia adelante
        centro = siguiente;         // 4. Mover centro hacia adelante
        i++;
    }
    *inicio = anterior;             // 5. El nuevo inicio es el que era el último

    return i;
}

