#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "validations.h"


Employee* employee_new()
{
    Employee* nuevo = NULL;
    nuevo = (Employee*) malloc(sizeof(Employee));

    if(nuevo != NULL)
    {
        nuevo->id = 0;
        nuevo->horasTrabajadas = 0;
        strcpy(nuevo->nombre, "");
        nuevo->sueldo = 0;
    }

    return nuevo;
}

Employee* employee_newParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
    int idIsvalid = validations_isValidNumber(id);
    int horasIsValid = validations_isValidNumber(horasTrabajadas);
    int sueldoIsValid = validations_isValidNumber(sueldo);

    if(!idIsvalid || !horasIsValid || !sueldoIsValid)
    {
        if (!idIsvalid)
        {
            printf("\nEl Id del nuevo Empleado es invalido. Valor recibido: %s\n", id);
        }
        else if (!horasIsValid)
        {
            printf("\nLas horas del nuevo Empleado son invalidas. Valor recibido: %s\n", horasTrabajadas);
        }
        else if (!sueldoIsValid)
        {
            printf("\nEl sueldo del nuevo Empleado es invalido. Valor recibido: %s\n", sueldo);
        }

        return NULL;
    }

    int idValue = atoi(id);
    int horasValue = atoi(horasTrabajadas);
    int sueldoValue = atoi(sueldo);

    Employee* newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if(
            !(!employee_setId(newEmployee,idValue) &&
              !employee_setNombre(newEmployee, nombre) &&
              !employee_setHorasTrabajadas(newEmployee,horasValue) &&
              !employee_setSueldo(newEmployee, sueldoValue)
             )
        )
        {
            printf("\nOcurrio un problema al inicializar las propiedades del nuevo Empleado. El mismo no sera creado.\n");
            newEmployee = NULL;
        }

    }

    return newEmployee;
}


void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id) //revisar
{
    int error = -1;

    if(this != NULL && id > 0)
    {
        this->id = id;
        error = 0;
    }

    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL && validations_nombre(nombre))
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }

    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        error = 0;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = -1;

    if(this != NULL && validations_horasTrabajadas(horasTrabajadas))
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }

    return error;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 0;
    }

    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = -1;

    if(this != NULL && validations_sueldo(sueldo))
    {
        this->sueldo = sueldo;
        error = 0;
    }

    return error;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }

    return error;
}

int employee_SortByName(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;

    if(empleadoA != NULL && empleadoB != NULL)
    {
        empA = empleadoA;
        empB = empleadoB;

        retorno = strcmp(empA->nombre, empB->nombre);
    }

    return retorno;
}

int employee_SortById(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int sueldoA;
    int sueldoB;

    if(empleadoA != NULL && empleadoB != NULL)
    {
        if(employee_getId((Employee*)empleadoA, &sueldoA) == 0 &&
                employee_getId((Employee*)empleadoB, &sueldoB) == 0)
        {
            if(sueldoA > sueldoB)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }

    }

    return retorno;
}

int employee_SortByWorkHours(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int horasA;
    int horasB;

    if(empleadoA != NULL && empleadoB != NULL)
    {
        if(employee_getHorasTrabajadas((Employee*)empleadoA, &horasA) == 0 &&
                employee_getHorasTrabajadas((Employee*)empleadoB, &horasB) == 0)
        {
            if(horasA > horasB)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}

int employee_SortBySalary(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int sueldoA;
    int sueldoB;

    if(empleadoA != NULL && empleadoB != NULL)
    {
        if(employee_getSueldo((Employee*)empleadoA, &sueldoA) == 0 &&
                employee_getSueldo((Employee*)empleadoB, &sueldoB) == 0)
        {
            if(sueldoA > sueldoB)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}


