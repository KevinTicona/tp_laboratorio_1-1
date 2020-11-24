#include "../inc/LinkedList.h"
#ifndef DUENOS_H_INCLUDED
#define DUENOS_H_INCLUDED

typedef struct
{
    int ID;
    char nombre[100];
    char telefono[35];
}Dueno;

/** \brief Crea un puntero a Dueno, setea los valores en cero o string vacio
 * le asigna espacio en memoria dinamica.
 *
 * \return un puntero a dueno o NULL si no consigue espacio en memoria
 *
 */
Dueno* dueno_new();

/** \brief Crea un puntero a dueno, setea los valores y le asigna espacio en memoria dinamica.
 *
 * \param char* id
 * \param char* nombre
 * \param char* telefono
 * \return un puntero a dueno o NULL si no consigue espacio en memoria
 *
 */
Dueno* dueno_newParams(char* id, char* nombre, char* telefono);

/** \brief Libera el espacio en memoria que ocupa un puntero a dueno
 *
 * \param Dueno* this
 *
 */
void duenos_deleteOne(Dueno* this);

/** \brief Asigna un ID a un dueno
 *
 * \param Dueno* this
 * \param int id
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int duenos_setId(Dueno* this,int id);

/** \brief Obtiene un ID de un dueno
 *
 * \param Dueno* this
 * \param int* id
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int duenos_getId(Dueno* this,int* id);

/** \brief Asigna un nombre a un Dueno
 *
 * \param Dueno* this
 * \param char* nombre
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el nombre no es valido)
 *
 */
int duenos_setNombre(Dueno* this,char* nombre);

/** \brief Obtiene un nombre de un Dueno
 *
 * \param Dueno* this
 * \param char* nombre
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el nombre no es valido)
 *
 */
int duenos_getNombre(Dueno* this,char* nombre);

/** \brief Asigna un telefono a un Dueno
 *
 * \param Dueno* this
 * \param char* telefono
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el telefono no es valido)
 *
 */
int duenos_setTelefono(Dueno* this, char* telefono);

/** \brief Obtiene un telefono de un Dueno
 *
 * \param Dueno* this
 * \param char* telefono
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el telefono no es valido)
 *
 */
int duenos_getTelefono(Dueno* this, char* telefono);

/** \brief Busca un dueño en la LL por su campo ID
 *
 * \param LinkedList* this
 * \param int id
 * \return un puntero a dueño si esta todo ok, NULL si la lista es NULL o si no encuentra al dueño
 *
 */
Dueno* duenos_searchByID(LinkedList* this,int id);

#endif // DUENOS_H_INCLUDED
