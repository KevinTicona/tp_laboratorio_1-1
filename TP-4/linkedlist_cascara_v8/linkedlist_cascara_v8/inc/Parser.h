#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdio.h>
#include "../inc/LinkedList.h"

/** \brief Parsea los datos de las mascotas desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param LinkedList* pLinkedListMascotas
 * \return int [0] si no hay errores, [-1] si el archivo no existe y/o la lista es NULL
 *
 */
int parser_MascotaFromText(FILE* pFile, LinkedList* pLinkedListMascotas);

/** \brief Parsea los datos de los dueños desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param inkedList* pLinkedListDuenos
 * \return int [0] si no hay errores, [-1] si el archivo no existe y/o la lista es NULL
 *
 */
int parser_duenoFromText(FILE* pFile, LinkedList* pLinkedListDuenos);

/** \brief Parsea los datos de las mascotas desde el archivo data.bin (modo binario).
 *
 * \param FILE* pFile
 * \param LinkedList* pLinkedListMascotas
 * \return int [0] si no hay errores, [-1] si el archivo no existe y/o la lista es NULL
 *
 */
int parser_MascotaFromBinary(FILE* pFile, LinkedList* pLLMascotas);

/** \brief Parsea los datos de los dueños desde el archivo data.bin (modo binario).
 *
 * \param FILE* pFile
 * \param inkedList* pLinkedListDuenos
 * \return int [0] si no hay errores, [-1] si el archivo no existe y/o la lista es NULL
 *
  */
int parser_DuenoFromBinary(FILE* pFile, LinkedList* pLLDueno);


#endif // PARSER_H_INCLUDED
