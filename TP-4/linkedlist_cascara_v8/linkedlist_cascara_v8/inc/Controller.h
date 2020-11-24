#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "../inc/LinkedList.h"

int controller_loadMascotasFromText(char* path, LinkedList* pLLMascotas);
int controller_loadDuenosFromText(char* path, LinkedList* pLLDuenos);

int controller_loadMascotasFromBinary(char* path, LinkedList* pLLMascotas);
int controller_loadDuenosFromBinary(char* path, LinkedList* pLLDuenos);

int controller_addMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

int controller_editMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

int controller_removeMascota(LinkedList* pLLMascotas,LinkedList* pLLDuenos);
int controller_removeMascotaWithPop(LinkedList* pLLMascotas,LinkedList* pLLDuenos);

int controller_sortMascotas(LinkedList* pLLMascotas, LinkedList* pLLDuenos);
int controller_filterMascotas(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

int controller_ListMascotas(LinkedList* pLLMascotas, LinkedList* duenos);
int controller_ListDuenos(LinkedList* pLLDuenos);

int controller_saveMascotasAsText(char* path, LinkedList* pLLMascotas);
int controller_saveDuenosAsText(char* path, LinkedList* pLLDuenos);

int controller_saveMascotasAsBinary(char* path, LinkedList* pLLMascotas);
int controller_saveDuenosAsBinary(char* path, LinkedList* pLLDuenos);

int controller_freeResources(LinkedList* this);

int controller_cloneList(LinkedList* pLLMascotas, LinkedList* pLLDuenos);
int controller_makeSubList(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

int controller_containsList(LinkedList* pLLMascotas, LinkedList* pLLDuenos);
int controller_settingMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

int controller_pushMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

#endif // CONTROLLER_H_INCLUDED
