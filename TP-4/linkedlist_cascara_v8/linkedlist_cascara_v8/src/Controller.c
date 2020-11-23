#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Controller.h"
#include "../inc/Parser.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Menu.h"
#include "../inc/Validations.h"


int controller_loadMascotasFromText(char* path, LinkedList* pLLMascotas)
{
    int status = -1;
    FILE *pFile = fopen(path, "r");

    if (pFile == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path);
        return status;
    }

    ll_clear(pLLMascotas);

    status = parser_MascotaFromText(pFile, pLLMascotas);

    fclose(pFile);

    return status;
}

int controller_loadDuenosFromText(char* path, LinkedList* pLLDuenos)
{
    int status = -1;
    FILE *pFile = fopen(path, "r");

    if (pFile == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path);
        return status;
    }

    ll_clear(pLLDuenos);

    status = parser_duenoFromText(pFile, pLLDuenos);

    fclose(pFile);

    return status;
}

int controller_loadMascotasFromBinary(char* path, LinkedList* pLLMascotas)
{
    int status = -1;
    FILE *pFile = fopen(path, "rb");

    if (pFile == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path);
        return status;
    }

    ll_clear(pLLMascotas);

    status = parser_MascotaFromBinary(pFile,pLLMascotas);

    fclose(pFile);

    return status;
}

int controller_loadDuenosFromBinary(char* path, LinkedList* pLLDuenos)
{
    int status = -1;
    FILE *pFile = fopen(path, "rb");

    if (pFile == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path);
        return status;
    }

    ll_clear(pLLDuenos);

    status = parser_DuenoFromBinary(pFile, pLLDuenos);

    fclose(pFile);

    return status;
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

    //Buscamos por ID verificando que exista esa mascota
    id = atoi(idChar);
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
        return -1;
    }

    return 0;
}

int controller_removeMascota(LinkedList* pLLMascotas,LinkedList* pLLDuenos)
{
    if(ll_isEmpty(pLLMascotas) != 0)
    {
        printf("\nSe deben cargar los datos antes de eliminar una mascota a la lista.\n");
        return -1;
    }

    int validarEntero, id;
    char idChar[50];

    //Validar ingreso de datos
    printf("\nIngrese el ID de la mascota que desea eliminar\n");
    fflush(stdin);
    gets(idChar);
    validarEntero = validations_isValidID(idChar);
    while(validarEntero != 1)
    {
        printf("\nNumeracion invalida. Ingrese el ID de la mascota que desea eliminar\n");
        fflush(stdin);
        gets(idChar);
        validarEntero = validations_isValidID(idChar);
    }
    id = atoi(idChar);

    //Recorrer la lista, si existe la mascota, la muestro y la borro
    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLLMascotas);
    Node* currentNode = pLLMascotas->pFirstNode;
    Mascota* currentMascota = NULL;

    while (currentNodeIndex < linkedListSize)
    {
        currentMascota = (Mascota*)ll_get(pLLMascotas, currentNodeIndex);

        if (currentMascota->ID == id)
        {
            currentMascota = ll_pop(pLLMascotas,currentNodeIndex);
            menu_encabezadoMascota();
            menu_imprimirMascota(pLLDuenos,currentMascota);
            printf("\nSe ha eliminado esta mascota.\n");
            return 0;
        }

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    printf("\nNo se encontro una mascota con ese ID.\n");
    return -1;
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

int controller_saveMascotasAsText(char* path, LinkedList* pLLMascotas)
{
    FILE *pFile;

    pFile = fopen(path, "w");

    if (pFile == NULL || pLLMascotas == NULL)
    {
        return -1;
    }

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLLMascotas);

    Mascota* currentMascota;
    Node* currentNode = pLLMascotas->pFirstNode;

    // Escribimos los headers del CSV
    fprintf(pFile, "ID,NOMBRE,TIPO,SEXO,EDAD,ID_DUENO\n");

    // Recorremos la Linked List con un índice (un número)
    while (currentNodeIndex < linkedListSize)
    {
        currentMascota = (Mascota*)ll_get(pLLMascotas, currentNodeIndex);

        fprintf(pFile, "%d,%s,%s,%s,%d,%d\n",
                currentMascota->ID,
                currentMascota->nombre,
                currentMascota->tipo,
                currentMascota->sexo,
                currentMascota->edad,
                currentMascota->ID_Duenio);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    fclose(pFile);

    printf("\nLos cambios para la lista de mascotas, han sido guardados correctamente.\n");

    return 0;
}

int controller_saveDuenosAsText(char* path, LinkedList* pLLDuenos)
{
    FILE *pFile;

    pFile = fopen(path, "w");

    if (pFile == NULL || pLLDuenos == NULL)
    {
        return -1;
    }

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLLDuenos);

    Dueno* currentDueno;
    Node* currentNode = pLLDuenos->pFirstNode;

    // Escribimos los headers del CSV
    fprintf(pFile, "ID,NOMBRE,TELEFONO\n");

    // Recorremos la Linked List con un índice (un número)
    while (currentNodeIndex < linkedListSize)
    {
        currentDueno = (Dueno*)ll_get(pLLDuenos, currentNodeIndex);

        fprintf(pFile, "%d,%s,%s\n",
                currentDueno->ID,
                currentDueno->nombre,
                currentDueno->telefono);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    fclose(pFile);

    printf("\nLos cambios para la lista de duenos, han sido guardados correctamente.\n");

    return 0;
}

int controller_saveMascotasAsBinary(char* path, LinkedList* pLLMascotas)
{
    FILE* pFile= fopen(path, "wb");

    if (pFile == NULL || pLLMascotas == NULL)
    {
        return -1;
    }

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLLMascotas);

    Mascota* currentMascota;
    Node* currentNode = pLLMascotas->pFirstNode;

    while (currentNodeIndex < linkedListSize)
    {
        currentMascota = (Mascota*)ll_get(pLLMascotas, currentNodeIndex);

        fwrite(currentMascota, sizeof(Mascota), 1, pFile);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    fclose(pFile);

    return 0;
}

int controller_saveDuenosAsBinary(char* path, LinkedList* pLLDuenos)
{
    FILE* pFile= fopen(path, "wb");

    if (pFile == NULL || pLLDuenos == NULL)
    {
        return -1;
    }

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLLDuenos);

    Dueno* currentDueno;
    Node* currentNode = pLLDuenos->pFirstNode;

    while (currentNodeIndex < linkedListSize)
    {
        currentDueno = (Dueno*)ll_get(pLLDuenos, currentNodeIndex);

        fwrite(currentDueno, sizeof(Dueno), 1, pFile);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    fclose(pFile);

    return 0;
}

int controller_freeResources(LinkedList* this)
{
    if(!ll_deleteLinkedList(this))
    {
        return 0;
    }

    return -1;
}

int controller_sortMascotas(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if (ll_isEmpty(pLLMascotas) == 1)
    {
        printf("\nNo existen mascotas en el sistema. Intente cargarlaspara poder listarlas.\n");
        return -1;
    }

    int optionSort = 0;
    int selectSort = 0;

    do
    {
        menu_submenu_order();
        selectSort = validations_getOption(
                         &optionSort,
                         "\nOpcion invalida, vuelva a intentarlo.\n",
                         1,
                         5);
        if(!selectSort)
        {
            switch(optionSort)
            {
            case 1:
                printf("Aguarde, esto podria tardar un momento. Ordenando por nombre ...");
                ll_sort(pLLMascotas, mascotas_SortByName, 1);
                printf("\nMascotas ordenadas por nombre exitosamente.\n");
                system("pause");
                controller_ListMascotas(pLLMascotas, pLLDuenos);
                break;
            case 2:
                printf("Aguarde, esto podria tardar un momento. Ordenando por ID ...");
                ll_sort(pLLMascotas, mascotas_SortById,1);
                printf("\nMascotas ordenadas por ID exitosamente.\n");
                system("pause");
                controller_ListMascotas(pLLMascotas,pLLDuenos);
                break;
            case 3:
                printf("Aguarde, esto podria tardar un momento. Ordenando por tipo ...");
                ll_sort(pLLMascotas, mascotas_SortByTipo, 1);
                printf("\nMascotas ordenadas por tipo exitosamente.\n");
                system("pause");
                controller_ListMascotas(pLLMascotas,pLLDuenos);
                break;
            case 4:
                printf("\nMantenimiento...\n");
                break;
            case 5:
                printf("Volviendo al menu principal...\n");
                break;
            }
            system("pause");
        }
    }
    while(optionSort != 5);

    return 0;
}
