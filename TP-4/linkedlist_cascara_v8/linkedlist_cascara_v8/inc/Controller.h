#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "../inc/LinkedList.h"

/** \brief Carga los datos de las macotas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLLMascotas LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL
 *
 */
int controller_loadMascotasFromText(char* path, LinkedList* pLLMascotas);

/** \brief Carga los datos de los dueños desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL
 *
 */
int controller_loadDuenosFromText(char* path, LinkedList* pLLDuenos);

/** \brief Carga los datos de las macotas desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pLLMascotas LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL
 *
 */
int controller_loadMascotasFromBinary(char* path, LinkedList* pLLMascotas);

/** \brief Carga los datos de las macotas desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL
 *
 */
int controller_loadDuenosFromBinary(char* path, LinkedList* pLLDuenos);

/** \brief Alta de mascota
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_addMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

/** \brief Modificar datos de empleado
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_editMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

/** \brief Baja de mascota
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_removeMascota(LinkedList* pLLMascotas,LinkedList* pLLDuenos);

/** \brief Baja de mascota utilizando pop. Es directa, no se puede emplear confirmacion
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_removeMascotaWithPop(LinkedList* pLLMascotas,LinkedList* pLLDuenos);

/** \brief Ordenar mascotas mediante la seleccion de una opcion en un menu
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_sortMascotas(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

/** \brief Filtrar mascotas mediante la seleccion de una opcion en un menu
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_filterMascotas(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

/** \brief Lista la mascotas de la lista de mascotas
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_ListMascotas(LinkedList* pLLMascotas, LinkedList* duenos);

/** \brief Lista los dueños de la lista de dueños
 *
 * \param pLLDuenos LinkedList*
 * \return int int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_ListDuenos(LinkedList* pLLDuenos);

/** \brief Guarda los datos de las mascotas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLLMascotas LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL o la lista esta vacia
 *
 */
int controller_saveMascotasAsText(char* path, LinkedList* pLLMascotas);

/** \brief Guarda los datos de los dueños en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL o la lista esta vacia
 *
 */
int controller_saveDuenosAsText(char* path, LinkedList* pLLDuenos);

/** \brief Guarda los datos de las mascotas en el archivo data.bin (modo dinario).
 *
 * \param path char*
 * \param pLLMascotas LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL o la lista esta vacia
 *
 */
int controller_saveMascotasAsBinary(char* path, LinkedList* pLLMascotas);

/** \brief Guarda los datos de los dueños en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL o la lista esta vacia
 *
 */
int controller_saveDuenosAsBinary(char* path, LinkedList* pLLDuenos);

/** \brief Borra una linked list liberando espacio de memoria
 *
 * \param LinkedList* this
 * \return int [0] si no hay errores, [-1] si la lista es NULL
 *
 */
int controller_freeResources(LinkedList* this);

/** \brief Clona una linked list completa y la muestra
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia.
 *
 */
int controller_cloneList(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

/** \brief Clona una porción de la linked list según parametros indicados y la muestra
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia.
 *
 */
int controller_makeSubList(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

/** \brief Desplega un menu de opciones donde se puede ver si una lista esta
 * dentro de la lista de mascotas
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia.
 *
 */
int controller_containsList(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

/** \brief Setea una nueva mascota en un id existente, sobreescrbiendo
 * la mascota que ya existe
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia o el indice esta fuera de rango.
 *
 */
int controller_settingMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

/** \brief Crea una nueva mascota con los parametros pasados y la inserta en un indice
 * del LL pasado como parametro
 *
 * \param pLLMascotas LinkedList*
 * \param pLLDuenos LinkedList*
 * \return int [0] si no hay errores, [-1] si la lista esta vacia o el indice esta fuera de rango.
 *
 */
int controller_pushMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos);

#endif // CONTROLLER_H_INCLUDED
