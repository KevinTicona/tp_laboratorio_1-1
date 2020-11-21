#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Controller.h"
#include "../inc/Parser.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Menu.h"
#include "../inc/Validations.h"

int controller_loadFromText(char* path1, char* path2, LinkedList* pLListMascotas, LinkedList* pLListDuenos)
{
    int statusDuenos;
    int statusMascotas;

    FILE *pFile1 = fopen(path1, "r");

    if (pFile1 == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path1);
        return -1;
    }

    ll_clear(pLListMascotas);

    statusMascotas = parser_MascotaFromText(pFile1,pLListMascotas);

    fclose(pFile1);

    //Segundo archivo
    FILE *pFile2 = fopen(path2,"r");

    if (pFile2 == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path2);
        return -1;
    }

    ll_clear(pLListDuenos);
    statusDuenos  = parser_duenoFromText(pFile2,pLListDuenos);

    fclose(pFile2);

    if(statusMascotas == -1 || statusDuenos == -1)
    {
        return -1;
    }

    return 0;
}

int controller_addMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if(ll_isEmpty(pLLMascotas) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar una mascota a la lista.\n");
        return -1;
    }

    Mascota* newMascota = NULL;
    int id;
    char idAsChar[50], nombre[100], tipo[50], sexo[50], edad[50], idDueno[50];

    // Ingresar y validar datos
    mascotas_enterName(nombre);
    mascotas_enterType(tipo);
    mascotas_enterSex(sexo);
    mascotas_enterAge(edad);
    mascotas_enterIdDueno(idDueno,pLLDuenos);

    // Id autoincremental
    Node* currentNode = pLLMascotas->pFirstNode;

    while (currentNode->pNextNode != NULL)
    {
        currentNode = currentNode->pNextNode;
    }

    // Al terminar el while, currentNode será el último Nodo en nuestra Linked List
    // Luego de encontrar la ultima mascota en la Linked List, utilizamos su Id y le agregamos 1.
    Mascota* ultimaMascota = (Mascota*)currentNode->pElement;
    id = ultimaMascota->ID + 1;
    itoa(id, idAsChar, 10);

    //Creamos la mascota con los datos recibidos
    newMascota = mascota_newParams(idAsChar,nombre,tipo,sexo,edad,idDueno);

    if(newMascota != NULL)
    {
        ll_add(pLLMascotas,newMascota);
    }

    return 0;
}

int controller_editMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if(ll_isEmpty(pLLMascotas) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar una mascota a la lista.\n");
        return -1;
    }

    Mascota* mascotaAModificar = NULL;
    int validarEntero, id, selection, option, integerAge;
    char idChar[50], newName[100], newType[30], newAge[30];

    //Validar ingreso de datos
    printf("\nIngrese el ID de la mascota que desea modificar\n");
    fflush(stdin);
    gets(idChar);
    validarEntero = validations_isValidID(idChar);
    while(validarEntero != 1)
    {
        printf("\nNumeracion invalida. Ingrese el ID de la mascota que desea modificar\n");
        fflush(stdin);
        gets(idChar);
        validarEntero = validations_isValidID(idChar);
    }

    // Si la numeracion ingresada es valida, verificamos que sea existente
    id = atoi(idChar);
    if(id < 0 && id > ll_len(pLLMascotas))
    {
        printf("No hay mascotas con ese ID");
        return -1;
    }

    //Buscamos por ID
    if(id > 0 && id <= ll_len(pLLMascotas))
    {
        mascotaAModificar = mascotas_searchByID(pLLMascotas, id);
        do
        {
            system("cls");
            menu_encabezadoMascota();
            menu_imprimirMascota(pLLDuenos,mascotaAModificar);
            menu_modificaciones();
            selection = validations_getOption(
                            &option,
                            "\nOpcion invalida. Ingrese una opcion corrcta\n",
                            1,
                            4);
            if(!selection)
            {
                switch(option)
                {
                case 1:
                    mascotas_enterName(newName);
                    if(!mascotas_setNombre(mascotaAModificar,newName))
                    {
                        printf("\nNombre modificado con exito.\n");
                    }
                    break;
                case 2:
                    mascotas_enterType(newType);
                    if(!mascotas_setTipo(mascotaAModificar,newType))
                    {
                        printf("\nTipo modificado con exito.\n");
                    }
                    break;
                case 3:
                    mascotas_enterAge(newAge);
                    integerAge = atoi(newAge);
                    if(!mascotas_setEdad(mascotaAModificar,integerAge))
                    {
                        printf("\nEdad modificada con exito.\n");
                    }
                    break;
                case 4:
                    printf("\nVolviendo al menu principal...\n");
                    break;
                }
                system("pause");
            }
        }
        while(option != 4);
    }
    else
    {
        printf("\nNo hay mascotas con ese ID\n");
    }


    return 0;
}

int controller_ListMascotas(LinkedList* pLLMascotas, LinkedList* duenos)
{
    if (ll_isEmpty(pLLMascotas) == 1)
    {
        printf("\nNo existen mascotas en el sistema. Intente cargarlas desde el menu para poder visualizarlas.\n");
        return 0;
    }

    menu_imprimirMascotas(pLLMascotas,duenos);

    return 1;
}

int controller_ListDuenos(LinkedList* pLLDuenos)
{
    if (ll_isEmpty(pLLDuenos) == 1)
    {
        printf("\nNo existen Duenos en el sistema. Intente cargarlos desde el menu para poder visualizarlos.\n");
        return 0;
    }

    menu_imprimirDuenos(pLLDuenos);

    return 1;
}

int controller_freeResources(LinkedList* this)
{
    Node* currentNode = this->pFirstNode;
    Node* temporaryNode;

    while (currentNode != NULL)
    {
        temporaryNode = currentNode;
        currentNode = currentNode->pNextNode;
        free(temporaryNode);
    }

    ll_deleteLinkedList(this);

    return 1;
}

