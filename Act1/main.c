#include <stdio.h>
#include "comun.h"
#include "funcsComun.h"

int main(void)
{
    printf("Programa copilado el %s a las %s\n", __DATE__, __TIME__);

    data_t a1;
    lista_t *inicioList = NULL;
    for(int i = 1; i <= 10; i++)
    {
        a1.x = i;
        a1.y = i * i;

        pushList(&inicioList, &a1);
    }

    printList(inicioList);

    freeList(&inicioList);
    
}

