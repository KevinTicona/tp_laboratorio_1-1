#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* ll_newLinkedList(void) {
    LinkedList* linkedList = malloc(sizeof(LinkedList));
    linkedList->size = 50;
    linkedList->pFirstNode = NULL;
    return NULL;
}
