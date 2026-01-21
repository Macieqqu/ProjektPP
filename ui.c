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
    printf("0. Zakoncz program\n");
    getMenuChoice(8);
}

void showEditMenu() {
    printf("===---=== EDYTOWANIE ===---===\n");
    printf("1. Edytuj nazwe\n");
    printf("2. Edutuj swiat\n");
    printf("3. Edytuj poziom chaosu\n");
    printf("4. Edytuj opis\n");
    printf("5. Edytuj stabilnosc\n");
    printf("0. Anuluj edytowanie\n");
    getMenuChoice(5);
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

Przedmiot getItemFromUser() {
    Przedmiot p;

    printf("Podaj nazwe przedmiotu (max %i znakow): ", MAX_NAZWA);
    fgets(p.nazwa, MAX_NAZWA, stdin);
    removeNewlineAndClean(p.nazwa);

    printf("Podaj nazwe swiata (max %i znakow): ", MAX_SWIAT);
    fgets(p.swiat, MAX_SWIAT, stdin);
    removeNewlineAndClean(p.swiat);

    printf("Podaj poziom chaosu (zakres 0-10): ");
    p.poziomChaosu = getMenuChoice(10);

    printf("Podaj stabilnosc (stabilny / chwiejny / niestabilny / nieklasyfikowany): ");
    char tab[20];
    fgets(tab, 20, stdin);
    removeNewlineAndClean(tab);
    p.stabilnosc = stringToEnum(tab);

    printf("Podaj opis przedmiotu: ");
    fgets(p.opis, MAX_OPIS, stdin);
    removeNewlineAndClean(p.opis);

    return p;
}

int getMenuChoice(int max) {
    int wybor;
    printf("Wybor: ");
    while (scanf("%i", &wybor) != 1 || wybor < 0 || wybor > max) {
        printf("Niepoprawna wartość!\n");
        printf("Podaj poprawną wartość: ");
        clearBuffer();
    }
    clearBuffer();
    return wybor;
}

void removeNewlineAndClean(char *str) {
    char *newline = strchr(str, '\n');
    if (newline) {
        *newline = '\0';
    } else {
        clearBuffer();
    }
}

 void clearBuffer() {
     int c;
     while ((c = getchar()) != '\n' && c != EOF);
 }
