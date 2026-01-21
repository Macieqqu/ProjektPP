#include <stdio.h>

#include "common.h"
#include "list.h"
#include "ui.h"

int main(void) {

    List lista;
    lista.nextId = 1;
    lista.head = NULL;
    lista.tail = NULL;
    int running = 1;

    while (running) {
        showMenu();
        int wybor = getMenuChoice(9);

        switch (wybor) {
            case 1: {

                Przedmiot p = getItemFromUser();
                listAdd(&lista, p);
                printf("Dodano przedmiot!\n");
                break;
            }
            case 2: {

                printf("Podaj ID przedmiotu do edycji: ");
                int id = scanfInt();

                Node *edit = getFromID(&lista, id);
                if (edit == NULL) {
                    printf("Nieznaleziono przedmiotu o podanym ID\n");
                    break;
                }
                modifyItem(edit);
                break;
            }
            case 3: {

                printf("Podaj ID przedmiotu do usuniecia: ");
                int id = scanfInt();
                listRemove(&lista, id);
                break;
            }
            case 4: {

                printf("Podaj poziom chaosu (0-10)\n");
                int chaos = getMenuChoice(10);
                listRemoveBelowChaos(&lista, chaos);
                break;
            }
            case 5: {

                printf("Podaj nazwe do wyszukania: ");
                char tab[MAX_NAZWA];
                fgets(tab, MAX_NAZWA, stdin);
                removeNewlineAndClean(tab);
                searchByName(&lista, tab);
                break;
            }
            case 6: {

                printf("Podaj poziom chaosu (0-10)\n");
                int chaos = getMenuChoice(10);
                searchByChaos(&lista, chaos);
                break;
            }
            case 7: {

                sortAlphabetically(&lista);
                break;
            }
            case 8: {

                sortByChaos(&lista);
                break;
            }
            case 9: {

                printList(&lista);
                break;
            }

            case 0: {
                freeList(&lista);
                running = 0;
                break;
            }
        }

    }
    return 0;
}
