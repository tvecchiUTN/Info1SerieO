#include <stdio.h>
#include "comun.h"
#include "funcsComun.h"
#include "funcsVariadas.h"
int main(void)
{
    data_t a1;
    lista_t *inicioList = NULL;
    for(int i = 0; i < 10; i++)
    {
        a1.x = i % 5;
        a1.y = rand() % 5;

        pushList(&inicioList, &a1);
    }

    printList(inicioList);
    printf("\n");

    printf("%ld\n", cdadRepetidos(inicioList));
    freeList(&inicioList);
    
}

