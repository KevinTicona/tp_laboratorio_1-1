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

Mascota* mascota_new();
Mascota* mascota_newParams(char* id, char* nombre, char* tipo,char* sexo, char* edad, char* ID_duenio);
void mascotas_deleteOne(Mascota* this);
int mascotas_setId(Mascota* this,int id);
int mascotas_getId(Mascota* this,int* id);
int mascotas_setNombre(Mascota* this,char* nombre);
int mascotas_getNombre(Mascota* this,char* nombre);
int mascotas_setTipo(Mascota* this,char* tipo);
int mascotas_getTipo(Mascota* this,char* tipo);
int mascotas_setSexo(Mascota* this,char* sexo);
int mascotas_getSexo(Mascota* this,char* sexo);
int mascotas_setEdad(Mascota* this,int edad);
int mascotas_getEdad(Mascota* this,int *edad);
int mascotas_setIdDuenio(Mascota* this,int ID_Duenio);
int mascotas_getIdDuenio(Mascota* this,int* ID_Duenio);

//Ingreso de datos
void mascotas_enterName(char* name);
void mascotas_enterType(char* tipoValidado);
void mascotas_enterSex(char* sexoValidado);
void mascotas_enterAge(char* edadValidada);
void mascotas_enterIdDueno(char* idDuenoValidado, LinkedList* pLLduenos);

Mascota* mascotas_searchByID(LinkedList* this,int id);


#endif // MASCOTAS_H_INCLUDED
