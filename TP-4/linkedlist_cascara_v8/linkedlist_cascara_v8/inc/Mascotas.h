#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int ID;
    char nombre[100];
    char tipo[50];
    char sexo[1];
    int edad;
    int ID_Duenio;
}Mascota;

/** \brief Crea un puntero a Mascota, setea los valores en cero o string vacio
 * le asigna espacio en memoria dinamica.
 * \return un puntero a mascota o NULL si no consigue espacio en memoria
 *
 */
Mascota* mascota_new();

/** \brief Crea un puntero a mascota, setea los valores y le asigna espacio en memoria dinamica.
 *
 * \param char* id
 * \param char* nombre
 * \param char* tipo
 * \param char* sexo
 * \param char* edad
 * \param char* id_dueno
 * \return un puntero a mascota o NULL si no consigue espacio en memoria
 *
 */
Mascota* mascota_newParams(char* id, char* nombre, char* tipo,char* sexo, char* edad, char* ID_duenio);

/** \brief Libera el espacio en memoria que ocupa un puntero a mascota
 *
 * \param Mascota* this
 *
 */
void mascotas_deleteOne(Mascota* this);

/** \brief Asigna un ID a una mascota
 *
 * \param Mascota* this
 * \param int id
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int mascotas_setId(Mascota* this,int id);

/** \brief Obtiene un ID de una mascota
 *
 * \param Mascota* this
 * \param int* id
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int mascotas_getId(Mascota* this,int* id);

/** \brief Asigna un nombre a una mascota
 *
 * \param Mascota* this
 * \param char* nombre
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o nombre no es valido)
 *
 */
int mascotas_setNombre(Mascota* this,char* nombre);

/** \brief Obtiene el nombre de una mascota
 *
 * \param Mascota* this
 * \param char* nombre
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el nombre no es valido)
 *
 */
int mascotas_getNombre(Mascota* this,char* nombre);

/** \brief Asigna un tipo a una mascota
 *
 * \param Mascota* this
 * \param char* tipo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el nombre no es valido)
 *
 */
int mascotas_setTipo(Mascota* this,char* tipo);

/** \brief Obtiene el tipo de una mascota
 *
 * \param Mascota* this
 * \param char* tipo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el tipo no es valido)
 *
 */
int mascotas_getTipo(Mascota* this,char* tipo);

/** \brief Asigna un sexo a una mascota
 *
 * \param Mascota* this
 * \param char* sexo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el tipo no es valido)
 *
 */
int mascotas_setSexo(Mascota* this,char* sexo);

/** \brief Obtiene el sexo de una mascota
 *
 * \param Mascota* this
 * \param char* sexo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el sexo no es valido)
 *
 */
int mascotas_getSexo(Mascota* this,char* sexo);

/** \brief Asigna la edad a una mascota
 *
 * \param Mascota* this
 * \param int edad
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o la edad no es valida)
 *
 */
int mascotas_setEdad(Mascota* this,int edad);

/** \brief Obtiene la edad de una mascota
 *
 * \param Mascota* this
 * \param int* edad
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o la edad no es valida)
 *
 */
int mascotas_getEdad(Mascota* this,int *edad);

/** \brief Asigna un ID_Duenio a una mascota
 *
 * \param Mascota* this
 * \param int ID_Duenio
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el ID_Duenio no es valido)
 *
 */
int mascotas_setIdDuenio(Mascota* this,int ID_Duenio);

/** \brief Obtiene un ID_Duenio de una mascota
 *
 * \param Mascota* this
 * \param int* ID_Duenio
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el ID_Duenio no es valido)
 *
 */
int mascotas_getIdDuenio(Mascota* this,int* ID_Duenio);

//Ingreso de datos

/** \brief Pide y valida un nombre, guardándolo en un puntero
 *
 * \param char* name
 *
 */
void mascotas_enterName(char* name);

/** \brief Pide y valida un tipo, guardándolo en un puntero
 *
 * \param char* tipoValidado
 *
 */
void mascotas_enterType(char* tipoValidado);

/** \brief Pide y valida un sexo, guardándolo en un puntero
 *
 * \param char* sexoValidado
 *
 */
void mascotas_enterSex(char* sexoValidado);

/** \brief Pide y valida una edad, guardándolo en un puntero
 *
 * \param char* edadValidada
 *
 */
void mascotas_enterAge(char* edadValidada);

/** \brief Pide y valida un id_dueno, guardándolo en un puntero
 *
 * \param char* idDuenoValidado
 *
 */
void mascotas_enterIdDueno(char* idDuenoValidado);

/** \brief Busca una mascota en la LL por su campo ID
 *
 * \param LinkedList* this
 * \param int id
 * \return un puntero a mascota si esta todo ok, NULL si la lista es NULL o si no encuentra la mascota
 *
 */
Mascota* mascotas_searchByID(LinkedList* this,int id);

//Sort
/** \brief Compara el campo nombre de dos mascotas
 *
 * \param void* mascotaA
 * \param void* mascotaB
 * \return [0] si son iguales, [-1] si el primero esta después en la tabla ASCII
 * o [1] si el primero esta antes en la tabla ASCII
 *
 */
int mascotas_SortByName(void* mascotaA, void* mascotaB);

/** \brief Compara el campo tipo de dos mascotas
 *
 * \param void* mascotaA
 * \param void* mascotaB
 * \return [0] si son iguales, [-1] si el primero esta después en la tabla ASCII
 * o [1] si el primero esta antes en la tabla ASCII
 *
 */
int mascotas_SortByTipo(void* mascotaA, void* mascotaB);

/** \brief Compara el id de dos mascotas
 *
 * \param void* mascotaA
 * \param void* mascotaB
 * \return [0] si son iguales, [-1] si el primero es menor
 * o [1] si el primero es mayor
 *
 */
int mascotas_SortById(void* mascotaA, void* mascotaB);

//Filtrar
/** \brief Filtra las mascotas por tipo GATOS
 *
 * \param void* mascota
 * \return [0] si no es del tipo indicado, o [1] si es del tipo indicado
 *
 */
int mascotas_filtrarGatos(void* mascota);

/** \brief Filtra las mascotas por tipo PERROS
 *
 * \param void* mascota
 * \return [0] si no es del tipo indicado, o [1] si es del tipo indicado
 *
 */
int mascotas_filtrarPerros(void* mascota);

/** \brief Filtra las mascotas por tipo ROEDORES
 *
 * \param void* mascota
 * \return [0] si no es del tipo indicado, o [1] si es del tipo indicado
 *
 */
int mascotas_filtrarRoedores(void* mascota);

/** \brief Filtra las mascotas por tipo REPTILES
 *
 * \param void* mascota
 * \return [0] si no es del tipo indicado, o [1] si es del tipo indicado
 *
 */
int mascotas_filtrarReptiles(void* mascota);

#endif // MASCOTAS_H_INCLUDED
