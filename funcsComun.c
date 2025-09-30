#include <stdio.h>
#include "funcsComun.h"

lista_t *crtNode(const data_t *datos)
{
    lista_t *newNode = malloc(sizeof(lista_t));
    if(!newNode)
    {
        printf("Error de memoria\n");
        return NULL;
    }

    newNode->xy = *datos;
    newNode->sig = NULL;

    return newNode;
}

// *inicio es la direccion del primer elemento nodo
// (*inicio) -> sig es el contenido del sigiente elemnto del nodo
int pushList(lista_t **inicio, const data_t *datos)
{
    lista_t *node = crtNode(datos);

    if(!node)
    {
        printf("Error al crear nuevo nodo\n");
        return EST_ERROR;
    }

    if(!*inicio)
    {
        *inicio = node;
        return EST_OK;
    }

    lista_t *auxInit = *inicio;

    while(auxInit->sig)
    {
        auxInit = auxInit->sig;
    }

    auxInit->sig = node;

    return EST_OK;
}

void printList(const lista_t *inicio)
{
    if(!inicio)
    {
        printf("Lista vacia\n");
        return;
    }

    while(inicio)
    {
        printf("X: %d, Y: %d\n", inicio->xy.x, inicio->xy.y);
        inicio = inicio ->sig;
    }
}

void freeList(lista_t **inicio)
{
    lista_t *auxSig = NULL;
    lista_t *auxInicio = *inicio;

    if(!*inicio)
    {
        printf("Lista vacia\n");
        return;
    }

    while (auxInicio)
    {
        auxSig = auxInicio -> sig;

        free(auxInicio);

        auxInicio = auxSig;
    }

    *inicio = NULL;    
}