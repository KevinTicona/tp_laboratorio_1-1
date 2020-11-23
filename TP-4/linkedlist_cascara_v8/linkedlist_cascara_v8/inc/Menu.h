#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu_main();
void menu_imprimirMascota(LinkedList* duenos,Mascota* currentMascota);
int menu_imprimirMascotas(LinkedList* pLLMascotas,LinkedList* duenos);

void menu_imprimirDueno(Dueno* currentDueno);
int menu_imprimirDuenos(LinkedList* this);

void menu_encabezadoMascota();
void menu_modificaciones();

void menu_submenu_order();
void menu_submenu_filter();

void menu_submenu_contains();
#endif // MENU_H_INCLUDED
