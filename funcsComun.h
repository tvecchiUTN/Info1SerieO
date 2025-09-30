#ifndef __FUNCSCOMUN_H
#define __FUNCSCOMUN_H

#define EST_EMPTY 0
#define EST_ERROR -1
#define EST_OK 1

#include "comun.h"

lista_t *crtNode(const data_t *datos);

int pushList(lista_t **inicio, const data_t *datos);

void printList(lista_t *inicio);

void freeList(lista_t **inicio);

#endif