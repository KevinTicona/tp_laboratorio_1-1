#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    //imprimir dueños
    system("cls");
    menu_imprimirDuenos(pLLDuenos);
    mascotas_enterIdDueno(idDueno);

    // Id autoincremental
    Node* currentNode = pLLMascotas->pFirstNode;

    while (currentNode->pNextNode != NULL)
    {
        currentNode = currentNode->pNextNode;
    }

    // Al terminar el while, currentNode será el último Nodo en nuestra Linked List
    // Luego de encontrar la ultima mascota en la Linked List, utilizamos su Id y le agregamos 1.
    Mascota* ultimaMascota = (Mascota*)currentNode->pElement;
    mascotas_getId(ultimaMascota,&id);
    id += 1;
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
        printf("\nSe deben cargar los datos antes de editar una mascota de la lista.\n");
        return -1;
    }

    Mascota* mascotaAModificar = NULL;
    int validarEntero, id, selection, option, integerAge;
    char idChar[50], newName[100], newType[30], newAge[30];
    char confirmation;

    //Validar ingreso de datos
    system("cls");
    menu_imprimirMascotas(pLLMascotas,pLLDuenos);
    printf("\nIngrese el ID de la mascota que desea modificar: ");
    fflush(stdin);
    gets(idChar);
    validarEntero = validations_isValidID(idChar);
    while(validarEntero != 1)
    {
        printf("\nNumeracion invalida. Ingrese el ID de la mascota que desea modificar: ");
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
                            "\nOpcion invalida. Vuelva a intentarlo.\n",
                            1,
                            4);
            if(!selection)
            {
                switch(option)
                {
                case 1:
                    //Pedir dato
                    mascotas_enterName(newName);
                    //mostrar dato
                    printf("\nNombre ingresado: %s\nNombre anterior: %s\n",newName,mascotaAModificar->nombre);
                    //Confirmar modificacion
                    menu_confirmar(&confirmation);

                    if(confirmation == 's')
                    {
                        mascotas_setNombre(mascotaAModificar,newName);
                        printf("\nSe ha modificado el nombre.\n");
                        break;
                    }
                    else if(confirmation == 'n')
                    {
                        printf("\nModificacion cancelada por usuario.\n");
                        break;
                    }
                    break;
                case 2:
                    mascotas_enterType(newType);
                    printf("\nTipo ingresado: %s\nTipo anterior: %s\n",newType,mascotaAModificar->tipo);

                    menu_confirmar(&confirmation);

                    if(confirmation == 's')
                    {
                        mascotas_setTipo(mascotaAModificar,newType);
                        printf("\nSe ha modificado el tipo.\n");
                        break;
                    }
                    else if(confirmation == 'n')
                    {
                        printf("\nModificacion cancelada por usuario.\n");
                        break;
                    }
                    break;
                case 3:
                    mascotas_enterAge(newAge);
                    integerAge = atoi(newAge);
                    printf("\nEdad ingresada: %d\nEdad anterior: %d\n",integerAge,mascotaAModificar->edad);

                    menu_confirmar(&confirmation);

                    if(confirmation == 's')
                    {
                        mascotas_setEdad(mascotaAModificar,integerAge);
                        printf("\nSe ha modificado la edad.\n");
                        break;
                    }
                    else if(confirmation == 'n')
                    {
                        printf("\nModificacion cancelada por usuario.\n");
                        break;
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
    char confirmacion;
    char idChar[50];

    //Validar ingreso de datos
    system("cls");
    menu_imprimirMascotas(pLLMascotas,pLLDuenos);
    printf("\nIngrese el ID de la mascota que desea eliminar: ");
    fflush(stdin);
    gets(idChar);
    validarEntero = validations_isValidID(idChar);
    while(validarEntero != 1)
    {
        printf("\nNumeracion invalida. Ingrese el ID de la mascota que desea eliminar: ");
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
            menu_encabezadoMascota();
            menu_imprimirMascota(pLLDuenos,currentMascota);
            menu_confirmar(&confirmacion);
            if(confirmacion == 's')
            {
                ll_remove(pLLMascotas,currentNodeIndex);
                printf("\nSe ha eliminado esta mascota.\n");
                return 0;
            }
            else if (confirmacion == 'n')
            {
                printf("\nBaja cancelada por usuario.\n");
                return 0;
            }
        }

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    printf("\nNo se encontro una mascota con ese ID.\n");
    return -1;
}

int controller_removeMascotaWithPop(LinkedList* pLLMascotas,LinkedList* pLLDuenos)
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

    system("cls");
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

int controller_cloneList(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if (ll_isEmpty(pLLMascotas) == 1 && ll_isEmpty(pLLDuenos) == 1)
    {
        printf("\nNo existen mascotas en el sistema. Intente cargarlos desde el menu para poder clonarlas.\n");
        return -1;
    }

    int error = -1;

    LinkedList* cloneList = ll_clone(pLLMascotas);

    if(cloneList != NULL)
    {
        system("cls");
        printf("_____________________________________________________________________________________________\n");
        printf("                                         LISTA CLONADA \n");
        menu_imprimirMascotas(cloneList,pLLDuenos);
        ll_deleteLinkedList(cloneList);
        error = 0;
    }

    return error;
}

int controller_makeSubList(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if (ll_isEmpty(pLLMascotas) == 1 && ll_isEmpty(pLLDuenos) == 1)
    {
        printf("\nNo existen mascotas en el sistema. Intente cargarlos desde el menu para poder realizar una sublista.\n");
        return -1;
    }

    int error = -1;
    LinkedList* subList = NULL;
    char fromAsChar[100];
    char toAsChar[100];
    int validFrom;
    int validTo;
    int from;
    int to;

    printf("\nIngrese un indice entero desde donde quiere comenzar a copiar\n");
    fflush(stdin);
    gets(fromAsChar);
    validFrom = validations_isValidNumber(fromAsChar);
    while(validFrom != 1)
    {
        printf("\nDato invalido. Ingrese un indice entero desde donde quiere comenzar a copiar\n");
        fflush(stdin);
        gets(fromAsChar);
        validFrom = validations_isValidNumber(fromAsChar);
    }

    printf("\nIngrese un indice entero desde donde quiere finalizar el copiado\n");
    fflush(stdin);
    gets(toAsChar);
    validTo = validations_isValidNumber(toAsChar);
    while(validTo != 1)
    {
        printf("\nDato invalido. Ingrese un indice entero desde donde quiere finalizar el copiado\n");
        fflush(stdin);
        gets(toAsChar);
        validTo = validations_isValidNumber(toAsChar);
    }

    from = atoi(fromAsChar);
    to = atoi(toAsChar);

    subList = ll_subList(pLLMascotas,from,to);

    if(subList != NULL)
    {
        system("cls");
        printf("_____________________________________________________________________________________________\n");
        printf("                                       SUB-LISTA\n");
        menu_imprimirMascotas(subList,pLLDuenos);
        ll_deleteLinkedList(subList);
        error = 0;
    }

    return error;
}

int controller_saveMascotasAsText(char* path, LinkedList* pLLMascotas)
{
    if (ll_isEmpty(pLLMascotas) == 1)
    {
        printf("\nPrimero deben haber mascotas cargadas.\n");
        return -1;
    }

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
    if (ll_isEmpty(pLLDuenos) == 1)
    {
        printf("\nPrimero deben haber duenos cargados.\n");
        return -1;
    }

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
    if (ll_isEmpty(pLLMascotas) == 1)
    {
        printf("\nPrimero deben haber mascotas cargadas.\n");
        return -1;
    }

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
    if (ll_isEmpty(pLLDuenos) == 1)
    {
        printf("\nPrimero deben haber duenos cargados.\n");
        return -1;
    }

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
        printf("\nNo existen mascotas en el sistema. Intente cargarlas para poder listarlas.\n");
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
                         4);
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
                printf("Volviendo al menu principal...\n");
                break;
            }
            system("pause");
        }
    }
    while(optionSort != 4);

    return 0;
}

int controller_filterMascotas(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if (ll_isEmpty(pLLMascotas) == 1)
    {
        printf("\nNo existen mascotas en el sistema. Intente cargarlas para poder filtrarlas.\n");
        return -1;
    }

    int optionSort = 0;
    int selectSort = 0;

    do
    {
        menu_submenu_filter();
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
            {
                LinkedList* perros = ll_filter(pLLMascotas,mascotas_filtrarPerros);
                if(perros != NULL)
                {
                    system("cls");
                    printf("_____________________________________________________________________________________________\n");
                    printf("                                          PERROS \n");
                    menu_imprimirMascotas(perros,pLLDuenos);
                    ll_deleteLinkedList(perros);
                }
                else
                {
                    ll_deleteLinkedList(perros);
                }
            }
            break;
            case 2:
            {
                LinkedList* gatos = ll_filter(pLLMascotas,mascotas_filtrarGatos);
                if(gatos != NULL)
                {
                    system("cls");
                    printf("_____________________________________________________________________________________________\n");
                    printf("                                          GATOS \n");
                    menu_imprimirMascotas(gatos,pLLDuenos);
                    ll_deleteLinkedList(gatos);
                }
                else
                {
                    ll_deleteLinkedList(gatos);
                }
            }
            break;
            case 3:
            {
                LinkedList* reptiles = ll_filter(pLLMascotas,mascotas_filtrarReptiles);
                if(reptiles != NULL)
                {
                    system("cls");
                    printf("_____________________________________________________________________________________________\n");
                    printf("                                          REPTILES \n");
                    menu_imprimirMascotas(reptiles,pLLDuenos);
                    ll_deleteLinkedList(reptiles);
                }
                else
                {
                    ll_deleteLinkedList(reptiles);
                }
            }
            break;
            case 4:
            {
                LinkedList* roedores = ll_filter(pLLMascotas,mascotas_filtrarRoedores);
                if(roedores != NULL)
                {
                    system("cls");
                    printf("_____________________________________________________________________________________________\n");
                    printf("                                          ROEDORES \n");
                    menu_imprimirMascotas(roedores,pLLDuenos);
                    ll_deleteLinkedList(roedores);
                }
                else
                {
                    ll_deleteLinkedList(roedores);
                }
            }
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

int controller_containsList(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if (ll_isEmpty(pLLMascotas) == 1)
    {
        printf("\nNo existen mascotas en el sistema. Intente cargarlas desde el menu principal primero.\n");
        return -1;
    }
    //Generar una sublista de pLLMascotas y ver si esta contenida en pll mascotas
    //Ver si pLLDueños esta contenido en pLLMascotas
    int optionSort = 0;
    int selectSort = 0;

    do
    {
        menu_submenu_contains();
        selectSort = validations_getOption(
                         &optionSort,
                         "\nOpcion invalida, vuelva a intentarlo.\n",
                         1,
                         3);
        if(!selectSort)
        {
            switch(optionSort)
            {
            case 1:
            {
                int contiene;
                LinkedList* listaContenida = ll_subList(pLLMascotas,10,15);
                system("cls");
                printf("_____________________________________________________________________________________________\n");
                printf("                                        Sub-lista 1 \n");
                menu_imprimirMascotas(listaContenida,pLLDuenos);
                printf("_____________________________________________________________________________________________\n");
                printf("\n\nEstara esta sublista contenida en la lista de mascotas principal?\n");

                if(listaContenida != NULL)
                {
                    contiene = ll_containsAll(pLLMascotas,listaContenida);
                    if(contiene == 1)
                    {
                        printf("\nSi! La lista esta contenida.\n");
                        ll_deleteLinkedList(listaContenida);
                    }
                    else if(contiene == 0)
                    {
                        printf("\nNo, la lista no esta contenida...\n");
                        ll_deleteLinkedList(listaContenida);
                    }
                }
            }
            break;
            case 2:
            {
                int contiene;
                LinkedList* listaContenidaD = ll_subList(pLLDuenos,5,10);

                system("cls");
                printf("____________________________________________________\n");
                printf("                 Sub-lista 2 \n");
                menu_imprimirDuenos(listaContenidaD);
                printf("____________________________________________________\n");
                printf("\n\nEstara esta sublista contenida en la lista de mascotas principal?\n");

                if(listaContenidaD != NULL)
                {
                    contiene = ll_containsAll(pLLMascotas,listaContenidaD);
                    if(contiene == 1)
                    {
                        printf("\nSi! La lista esta contenida.\n");
                        ll_deleteLinkedList(listaContenidaD);
                    }
                    else if(contiene == 0)
                    {
                        printf("\nNo, la lista no esta contenida...\n");
                        ll_deleteLinkedList(listaContenidaD);
                    }
                }

            }
            break;
            case 3:
                printf("Volviendo al menu principal...\n");
                break;
            }
            system("pause");
        }
    }
    while(optionSort != 3);

    return 0;
}

int controller_settingMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if(ll_isEmpty(pLLMascotas) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar una mascota a la lista.\n");
        return -1;
    }

    // preguntar un indice dónde guardarlo (validar!!!!)
    char indexAsChar[100];
    int index;
    int validIndex;
    int id;

    printf("\n Ingrese una posicion de la lista: ");
    fflush(stdin);
    gets(indexAsChar);
    validIndex = validations_isValidNumber(indexAsChar);
    while(validIndex != 1)
    {
        printf("\n Dato invalido. Ingrese una posicion de la lista: ");
        fflush(stdin);
        gets(indexAsChar);
        validIndex = validations_isValidNumber(indexAsChar);
    }

    index = atoi(indexAsChar);

    if(index >= 0 && index < ll_len(pLLMascotas))
    {
        // de esa mascota sacar el ID -> para ponerlo en la mascota nueva
        Mascota* masc = ll_get(pLLMascotas,index);

        if(masc != NULL)
        {
            id = masc->ID;
        }
    }
    else
    {
        printf("\nEl indice se encuentra fuera de rango.\n");
        return -1;
    }

    Mascota* newMascota = NULL;
    char idAsChar[50], nombre[100], tipo[50], sexo[50], edad[50], idDueno[50];

    // Ingresar y validar datos
    itoa(id,idAsChar,10);
    mascotas_enterName(nombre);
    mascotas_enterType(tipo);
    mascotas_enterSex(sexo);
    mascotas_enterAge(edad);
    //imprimir dueños
    system("cls");
    menu_imprimirDuenos(pLLDuenos);
    mascotas_enterIdDueno(idDueno);

    // cree una mascota nueva sin añadirla al LL
    newMascota = mascota_newParams(idAsChar,nombre,tipo,sexo,edad,idDueno);

    // guardar la mascota
    if(newMascota != NULL)
    {
        ll_set(pLLMascotas,index,newMascota);
        return 0;
    }

    return -1;
}

int controller_pushMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if(ll_isEmpty(pLLMascotas) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar una mascota a la lista.\n");
        return -1;
    }

    // preguntar un indice dónde guardarlo (validar!!!!)
    char indexAsChar[100];
    int index;
    int validIndex;


    printf("\n Ingrese una posicion de la lista: ");
    fflush(stdin);
    gets(indexAsChar);
    validIndex = validations_isValidNumber(indexAsChar);
    while(validIndex != 1)
    {
        printf("\n Dato invalido. Ingrese una posicion de la lista: ");
        fflush(stdin);
        gets(indexAsChar);
        validIndex = validations_isValidNumber(indexAsChar);
    }

    index = atoi(indexAsChar);

    if(index < 0 || index >= ll_len(pLLMascotas))
    {
        printf("\nIndice fuera del rango. \n");
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
    system("cls");
    menu_imprimirDuenos(pLLDuenos);
    mascotas_enterIdDueno(idDueno);

    // Id autoincremental
    Node* currentNode = pLLMascotas->pFirstNode;

    while (currentNode->pNextNode != NULL)
    {
        currentNode = currentNode->pNextNode;
    }

    Mascota* ultimaMascota = (Mascota*)currentNode->pElement;
    mascotas_getId(ultimaMascota,&id);
    id += 1;
    itoa(id, idAsChar, 10);

    newMascota = mascota_newParams(idAsChar,nombre,tipo,sexo,edad,idDueno);

    if(newMascota != NULL)
    {
        ll_push(pLLMascotas,index,newMascota);
    }

    return 0;
}
