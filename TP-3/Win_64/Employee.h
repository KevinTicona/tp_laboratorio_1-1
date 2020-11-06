#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* id, char* nombre,char* horasTrabajadas, char* sueldo);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


int employee_SortByName(void* empleadoA, void* empleadoB);
int employee_SortById(void* empleadoA, void* empleadoB);
int employee_SortByWorkHours(void* empleadoA, void* empleadoB);
int employee_SortBySalary(void* empleadoA, void* empleadoB);



#endif // employee_H_INCLUDED
