#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "../inc/LinkedList.h"

int controller_loadFromText(char* path1, char* path2, LinkedList* pLListMascotas, LinkedList* pLListDuenos);

int controller_addMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

int controller_editMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

int controller_removeMascota(LinkedList* pLLMascotas,LinkedList* pLLDuenos);

int controller_ListMascotas(LinkedList* pLLMascotas, LinkedList* duenos);
int controller_ListDuenos(LinkedList* pLLDuenos);

int controller_freeResources(LinkedList* this);

#endif // CONTROLLER_H_INCLUDED
