#include "../inc/Controller.h"
#include "../inc/LinkedList.h"
#include "../inc/Parser.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Menu.h"

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
