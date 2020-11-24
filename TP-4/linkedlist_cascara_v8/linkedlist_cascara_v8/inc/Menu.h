#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Imprime el menu principal
 *
 *
 */
void menu_main();

/** \brief Imprime una mascota
 *
 * \param LinkedList* duenos
 * \param Mascota* currentMascota
 *
 */
void menu_imprimirMascota(LinkedList* duenos,Mascota* currentMascota);

/** \brief Imprime una lista de mascotas
 *
 * \param LinkedList* duenos
 * \param Mascota* currentMascota
 * \return [0]
 *
 */
int menu_imprimirMascotas(LinkedList* pLLMascotas,LinkedList* duenos);

/** \brief Imprime un dueño
 *
 * \param Dueno* currentDueno
 *
 */
void menu_imprimirDueno(Dueno* currentDueno);

/** \brief Imprime una lista de dueños
 *
 * \param LinkedList* duenos
 * \return [0]
 *
 */
int menu_imprimirDuenos(LinkedList* this);

/** \brief Imprime un encabezado para mascota
 *
 *
 */
void menu_encabezadoMascota();

/** \brief Imprime el sub-menu de modificaciones
 *
 *
 */
void menu_modificaciones();

/** \brief Imprime el sub-menu de ordenamientos
 *
 *
 */
void menu_submenu_order();

/** \brief Imprime el sub-menu de filtros
 *
 *
 */
void menu_submenu_filter();

/** \brief Imprime el sub-menu de contains
 *
 *
 */
void menu_submenu_contains();

/** \brief Pide confirmacion por si o por no y la guarda en un puntero a char
 * \param char* decision
 *
 */
void menu_confirmar(char* decision);
#endif // MENU_H_INCLUDED
