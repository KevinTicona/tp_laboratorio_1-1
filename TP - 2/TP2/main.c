#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int len);


/** \brief print one Employee of a list of Employees
 *
 * \param one employee
 *
 */

void showEmployee(Employee emp);


int main()
{
    Employee list[1000];
    initEmployees(list, 1000);

    addEmployee(list, 1000, "Pepe", "Argento", 45000.98, 3);
    addEmployee(list, 1000, "Jose", "Cayola", 55248.98, 1);
    addEmployee(list, 1000, "Jose", "Berutti", 55248.98, 2);
    addEmployee(list, 1000, "Pepe", "Zarasa", 45000.98, 3);
    addEmployee(list, 1000, "Jose", "Jiji", 55248.98, 1);
    addEmployee(list, 1000, "Jose", "Walace", 55248.98, 2);

    printEmployees(list, 1000);

    removeEmployee(list, 1000, 3);

    printEmployees(list, 1000);

    return 0;
}

int initEmployees(Employee* list, int len)
{
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        return 0;
    }

    return -1;
}

int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector)
{
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                list[i].id = i;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                return 0;
            }
        }

    }

    return -1;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int indiceId = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                indiceId = i;
                break;
            }
        }
    }
    return indiceId;
}

int removeEmployee(Employee* list, int len, int id)
{
    int error = -1;
    int index;
    char confirmacion;
    //No es necesario limpiar todos los campos
    //Falta: Cambiar la identación cuando obtengo el index. La función podría devolver 3 enteros (0 - ok, -1 error, 2 ok pero no borró a nadie
    if(list != NULL && len > 0 && len <= 1000)
    {
        index = findEmployeeById(list, len, id);
        if(index != -1)
        {
            printf("ID Nombre  Apellido  Salario  Sector \n");
            showEmployee(list[index]);
            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmacion);
            while(confirmacion != 's' && confirmacion != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmacion);
            }

            if(confirmacion == 's')
            {
                list[index].isEmpty = 1;
            }
            error = 0;
        } else{
            printf("No hay personas con ese ID\n");
        }
    }

    return error;
}

int sortEmployees(Employee* list, int len, int order)
{
    if(list == NULL || len < 0 || len > 1000 || order < 0 || order > 1 )
    {
        return -1;
    }

    Employee aux;
    if(order == 1)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(list[i].sector > list[j].sector)  // Ordenar alfabeticamente por apellido && sector
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else if (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    else if(order == 0)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(list[i].sector < list[j].sector)  // Ordenar en forma inversa alfabeticamente por apellido && sector
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else if (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }

    return 0;
}

int printEmployees(Employee* list, int len)
{
    if(list != NULL && len > 0 && len <= 1000)
    {
        //system("cls");
        printf("ID Nombre  Apellido  Salario  Sector \n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty != 1)
            {
                showEmployee(list[i]);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showEmployee(Employee emp)
{
    printf(" %d %s %s %4.2f %d \n",
           emp.id,
           emp.name,
           emp.lastName,
           emp.salary,
           emp.sector);
}
