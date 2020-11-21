#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "../inc/LinkedList.h"

int controller_loadFromText(char* path1, char* path2, LinkedList* pLListMascotas, LinkedList* pLListDuenos);

int controller_ListMascotas(LinkedList* pLLMascotas, LinkedList* duenos);

#endif // CONTROLLER_H_INCLUDED
