#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un puntero a Empleado, setea los valores en cero o string vacio
 * le asigna espacio en memoria dinamica.
 * \return un puntero a Empleado
 *
 */
Employee* employee_new();

/** \brief Crea un puntero a Empleado, setea los valores y le asigna espacio en memoria dinamica.
 *
 * \param char* id
 * \param char* nombre
 * \param char* horasTrabajadas
 * \param char* sueldo
 * \return un puntero a Empleado
 *
 */
Employee* employee_newParametros(char* id, char* nombre,char* horasTrabajadas, char* sueldo);

/** \brief Libera el espacio en memoria que ocupa un puntero a empleado
 *
 * \param Employee* this
 *
 */
void employee_delete(Employee* this);

/** \brief Asigna un ID a un empleado
 *
 * \param Employee* this
 * \param int id
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Obtiene un ID de un empleado
 *
 * \param Employee* this
 * \param int id
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Asigna un nombre a un empleado
 *
 * \param Employee* this
 * \param char* nombre
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Obtiene un nombre de un empleado
 *
 * \param Employee* this
 * \param char* nombre
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Asigna horas de trabajo a un empleado
 *
 * \param Employee* this
 * \param int horasTrabajadas
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene horas de trabajo de un empleado
 *
 * \param Employee* this
 * \param int horasTrabajadas
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Asigna sueldo a un empleado
 *
 * \param Employee* this
 * \param int sueldo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo de un empleado
 *
 * \param Employee* this
 * \param int sueldo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara el nombre de dos empleados
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return [0] si son iguales, [-1] si el primero esta después en la tabla ASCII
 * o [1] si el primero esta antes en la tabla ASCII
 *
 */
int employee_SortByName(void* empleadoA, void* empleadoB);

/** \brief Compara el id de dos empleados
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return [0] si son iguales, [-1] si el primero esta después en la tabla ASCII
 * o [1] si el primero esta antes en la tabla ASCII
 *
 */
int employee_SortById(void* empleadoA, void* empleadoB);

/** \brief Compara las horas de trabajo de dos empleados
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return [0] si son iguales, [-1] si el primero esta después en la tabla ASCII
 * o [1] si el primero esta antes en la tabla ASCII
 *
 */
int employee_SortByWorkHours(void* empleadoA, void* empleadoB);

/** \brief Compara el sueldo de trabajo de dos empleados
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return [0] si son iguales, [-1] si el primero esta después en la tabla ASCII
 * o [1] si el primero esta antes en la tabla ASCII
 *
 */
int employee_SortBySalary(void* empleadoA, void* empleadoB);



#endif // employee_H_INCLUDED
