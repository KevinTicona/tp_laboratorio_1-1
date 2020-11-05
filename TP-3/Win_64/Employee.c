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

    if(nuevo != NULL){
        nuevo->id = 0;
        nuevo->horasTrabajadas = 0;
        strcpy(nuevo->nombre, "");
        nuevo->sueldo = 0;
    }

    return nuevo;
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

