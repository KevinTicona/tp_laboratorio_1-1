#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdio.h>
#include "../inc/LinkedList.h"

int parser_MascotaFromText(FILE* pFile, LinkedList* pLinkedListMascotas);
int parser_duenoFromText(FILE* pFile, LinkedList* pLinkedListDuenos);

#endif // PARSER_H_INCLUDED
