#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Print main menu
 *
 *
 */
void menu_main();

/** \brief Print submenu (order employees)
 *
 *
 */
void menu_submenu_order();

/** \brief Imprime un empleado
 *
 * \param Employee* currentEmployee
 * \return
 *
 */
void menu_imprimirEmpleado(Employee* currentEmployee);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int menu_imprimirEmpleados(LinkedList* pArrayListEmployee);

/** \brief Imprime un menu de modificaciones
 *
 *
 */
void menu_menuModificaciones();

/** \brief Imprime un menu encabezado para empleado
 *
 *
 */
void menu_encabezadoEmpleado();

#endif // MENU_H_INCLUDED
