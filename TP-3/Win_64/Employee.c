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

Employee* employee_newParametros(char* id, char* nombre,char* horasTrabajadas, char* sueldo)
{
    Employee* nuevo = employee_new();

    if(nuevo != NULL)
    {
        /*
        if(
            !(!employee_setId(nuevo,id) &&
              !employee_setNombre(nuevo, nombre) &&
              !employee_setHorasTrabajadas(nuevo,horasTrabajadas) &&
              !employee_setSueldo(nuevo, sueldo))
        )
        {
            nuevo = NULL;
        }
        */

        if(
            !(!employee_setNombre(nuevo, nombre))
        )
        {
            printf("Something was wrong while setting the employees fields");
            nuevo = NULL;
        }
    }

    return nuevo;
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

    if(this != NULL && nombre != NULL/* && validations_nombre(nombre)*/) // por ahora borramos esta validacion
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
        employee_getSueldo((Employee*)empleadoA, &sueldoA);
        employee_getSueldo((Employee*)empleadoB, &sueldoB);
        retorno = sueldoA -sueldoB;
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
        employee_getHorasTrabajadas((Employee*)empleadoA, &horasA);
        employee_getHorasTrabajadas((Employee*)empleadoB, &horasB);
        retorno = horasA - horasB;
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
        employee_getSueldo((Employee*)empleadoA, &sueldoA);
        employee_getSueldo((Employee*)empleadoB, &sueldoB);
        retorno = sueldoA-sueldoB;
    }

    return retorno;
}
