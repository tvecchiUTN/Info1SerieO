#ifndef __FUNCSCOMUN_H
#define __FUNCSCOMUN_H

lista_t *crtNode(const data_t *datos);

void pushList(lista_t **cabeza, const data_t *datos);

void printList(lista_t *inicio);

void freeList(lista_t **inicio);

#endif