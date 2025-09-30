#include <stdio.h>
#include <string.h>

#include "comun.h"
#include "funcsComun.h"
#include "funcsVariadas.h"

size_t tamaLista(lista_t *inicio);
int inReg(const data_t *registro, int sz, const data_t *valor);

int invList(lista_t **inicio)
{
    int i = 0;

    if (!*inicio)
    {
        fprintf(stderr, "No hay lista\n");
        return EST_EMPTY;
    }

    if (!(*inicio)->sig)
    {
        fprintf(stdout, "Lista con un solo elemento\n");
        return 1;
    }

    lista_t *siguiente = NULL;
    lista_t *centro = *inicio;
    lista_t *anterior = NULL;

    while (centro)
    {
        siguiente = centro->sig; // 1. Guardar referencia al siguiente
        centro->sig = anterior;  // 2. ¡INVERTIR EL ENLACE!
        anterior = centro;       // 3. Mover anterior hacia adelante
        centro = siguiente;      // 4. Mover centro hacia adelante
        i++;
    }
    *inicio = anterior; // 5. El nuevo inicio es el que era el último

    return i;
}

size_t cdadRepetidos(lista_t *inicio)
{
    if (!inicio)
    {
        fprintf(stderr, "No hay lista\n");
        return EST_EMPTY;
    }
    if (!(inicio)->sig)
    {
        fprintf(stdout, "Lista con un solo elemento\n");
        return 0;
    }

    data_t regRepetidos[100];
    size_t cdad = 0;
    int tieneRepetido = 0;

    
    while (inicio)
    {
        if (!inReg(regRepetidos, cdad, &(inicio->xy)))
        {
            lista_t *actual = inicio->sig;
            tieneRepetido = 0;
            while (actual)
            {
                if ((actual->xy.x == inicio->xy.x) && (actual->xy.y == inicio->xy.y))
                {
                    tieneRepetido = 1;
                    break;
                }
                actual = actual->sig;
            }

            if(tieneRepetido)
            {
                *(regRepetidos + cdad) = inicio->xy;
                cdad++;
            }
        }

        inicio = inicio->sig;
    }

    return cdad;
}

#define SI 1
#define NO 0
int inReg(const data_t *registro, int sz, const data_t *valor)
{
    for (int i = 0; i < sz; i++)
    {
        if ((valor->x == registro[i].x) && (valor->y == registro[i].y))
        {
            return SI;
        }
    }

    return NO;
}

size_t tamaLista(lista_t *inicio)
{
    size_t szList = 0;
    if (!inicio)
    {
        printf("Lista vacia\n");
        return szList;
    }

    while (inicio)
    {
        szList++;
        inicio = inicio->sig;
    }
    return szList;
}