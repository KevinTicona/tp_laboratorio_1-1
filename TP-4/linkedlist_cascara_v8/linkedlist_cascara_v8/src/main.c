/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Validations.h"
#include "../inc/Menu.h"

int main(void)
{
    //validations_testLL(19); //Esto corre todos los test del LinkedList
    int option;
    int selection;

    //LinkedList* petList = ll_newLinkedList();
    //LinkedList* ownersList = ll_newLinkedList();

    do
    {
        menu_main();
        selection = validations_getOption(
                        &option,
                        "\nOpcion invalida, vuelva a intentar.\n",
                        1,
                        10
                    );
        if(!selection)
        {
            switch(option)
            {
            case 1:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 2:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 3:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 4:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 5:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 6:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 7:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 8:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 9:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 10:
                printf("\nSaliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(option!=10);


    return 0;
}

































