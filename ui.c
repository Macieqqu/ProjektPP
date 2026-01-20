#include "ui.h"

#include <stdio.h>
#include <string.h>

void showMenu() {
    printf("\n===---=== MENU ===---===\n");
    printf("1. Dodaj nowy przedmiot\n");
    printf("2. Edytuj przedmiot\n");
    printf("3. Usun przedmiot\n");
    printf("4. Usun przedmiot poniżej danego poziomu chaosu\n");
    printf("5. Wyszukaj wedlug nazwy\n");
    printf("6. Wyszukaj wedlug poziomu chaosu\n");
    printf("7. Posortuj alfabetycznie\n");
    printf("8. Posortuj wedlug poziomu chaosu\n");
    printf("9. Zakoncz program\n");
    printf("10. Wybor: ");
}

void showEditMenu() {
    printf("===---=== EDYTOWANIE ===---===\n");
    printf("1. Edytuj nazwe\n"); //TODO: czy nazwa nie jest jako "id"?
    printf("2. Edutuj swiat\n");
    printf("3. Edytuj poziom chaosu\n");
    printf("4. Edytuj opis\n");
    printf("5. Edytuj stabilnosc\n");
}

void printList(List *list) {
    Node *curr = list->head;

    if (curr == NULL) {
        printf("\nLista jest pusta\n");
        return;
    }

    while (curr != NULL) {
        printObject(curr->value);
        curr = curr->next;
    }
}

void printObject(Przedmiot przedmiot) {
    printf("----------------------------------------------------");
    printf("Nazwa: %s\n", przedmiot.nazwa);
    printf("Swiat: %s\n", przedmiot.swiat);
    printf("Poziom chaosu: %i\n", przedmiot.poziomChaosu);
    printf("Stabilnosc: %s\n", enumToString(przedmiot.stabilnosc));
    printf("Opis:\n%s\n", przedmiot.opis);
}

char *enumToString(Stabilnosc stabilnosc) {
    switch (stabilnosc) {
        case STABILNY: return "Stabilny";
        case CHWIEJNY: return "Chwiejny";
        case NIESTABILNY: return "Niestabilny";
        default: return "Nieklasyfikowany";
    }
}

Stabilnosc stringToEnum(char *string) {
    if (stricmp(string, "stabilny") == 0) return STABILNY;
    if (stricmp(string, "chwiejny") == 0) return CHWIEJNY;
    if (stricmp(string, "niestabilny") == 0) return NIESTABILNY;
    return NIEKLASYFIKOWANY;
}
//TODO:
// void clearBuffer() {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF);
// }
