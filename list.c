#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ui.h"

void listAdd(List *list, Przedmiot item) {
    Node *node = calloc(1, sizeof(Node));

    if (node == NULL) {
        printf("Nie udalo sie dodac przedmiotu do listy");
        return;
    }
    item.id = list->nextId++;
    node->value = item;
    node->next = NULL;
    node->prev = list->tail;

    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

void listRemove(List *list, long id) {
    Node *curr = list->head;

    while (curr != NULL) {
        Node *currNext = curr->next;

        if (curr->value.id == id) {
            if (curr->value.stabilnosc == NIESTABILNY) {
                printf("Przedmiot '%s' o ID:%li nie mogl zostac usuniety, poniewaz jest NIESTABILNY\n", curr->value.nazwa, curr->value.id);
                return;
            }

            if (curr->prev != NULL) curr->prev->next = currNext;
            else list->head = curr->next;

            if (currNext != NULL) currNext->prev = curr->prev;
            else list->tail = curr->prev;

            printf("Przedmiot '%s' o ID:%li zostal usuniety\n", curr->value.nazwa, curr->value.id);
            free(curr);
            return;
        }
        curr = currNext;
    }
    printf("Nieznaleziono przedmiotu o podanym ID\n");
}

void listRemoveBelowChaos(List *list, int chaos) {
    Node *curr = list->head;

    while (curr != NULL) {
        Node *currNext = curr->next;

        if (curr->value.poziomChaosu < chaos) {
            if (curr->value.stabilnosc == NIESTABILNY) {
                printf("Przedmiot '%s' o ID:%li nie mogl zostac usuniety, poniewaz jest NIESTABILNY\n", curr->value.nazwa, curr->value.id);
                curr = currNext;
                continue;
            }

            if (curr->prev != NULL) curr->prev->next = currNext;
            else list->head = curr->next;

            if (currNext != NULL) currNext->prev = curr->prev;
            else list->tail = curr->prev;

            printf("Przedmiot '%s' o ID:%li zostal usuniety\n", curr->value.nazwa, curr->value.id);
            free(curr);
        }
        curr = currNext;
    }
}

void modifyItem(Node *target) {

    if (target == NULL) return;

    showEditMenu();
    int choice = getMenuChoice(5);

    switch (choice) {
        case 1:
            printf("Nowa nazwa: ");
            fgets(target->value.nazwa, MAX_NAZWA, stdin);
            removeNewlineAndClean(target->value.nazwa);
            break;
        case 2:
            printf("Nowy swiat: ");
            fgets(target->value.swiat, MAX_SWIAT, stdin);
            removeNewlineAndClean(target->value.swiat);
            break;
        case 3:
            printf("Nowy chaos (0-10): ");
            target->value.poziomChaosu = getMenuChoice(10);
            break;
        case 4:
            printf("Nowy opis: ");
            fgets(target->value.opis, MAX_OPIS, stdin);
            removeNewlineAndClean(target->value.opis);
            break;
        case 5:
            printf("Nowa stabilnosc (stabilny/chwiejny/niestabilny): ");
            char tab[20];
            fgets(tab, 20, stdin);
            removeNewlineAndClean(tab);
            target->value.stabilnosc = stringToEnum(tab);
            break;
        default: return;
    }
    printf("Zmiany zapisane\n");

}

void searchByName(List *list, char *name) {
    Node *curr = list->head;
    int found = 0;
    while (curr != NULL) {
        if (stricmp(curr->value.nazwa, name) == 0) {
            printObject(curr->value);
            found = 1;
        }
        curr = curr->next;
    }
    if (!found) printf("Brak przedmiotow o nazwie: %s\n", name);
}

void searchByChaos(List *list, int chaos) {
    Node *curr = list->head;
    int found = 0;
    while (curr != NULL) {
        if (curr->value.poziomChaosu == chaos) {
            printObject(curr->value);
            found = 1;
        }
        curr = curr->next;
    }
    if (!found) printf("Brak przedmiotow o poziomie chaosu: %i\n", chaos);
}

Node *getFromID(List *list, long id) {

    Node *curr = list->head;
    while (curr != NULL) {
        if (curr->value.id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void sortAlphabetically(List *list) {
    if (list->head == NULL || list->head->next == NULL) return;
    int swapped;
    Node *curr;
    Node *lastNode = NULL;

    do {
        swapped = 0;
        curr = list->head;

        while (curr->next != lastNode) {
            if (stricmp(curr->value.nazwa, curr->next->value.nazwa) > 0) {
                Przedmiot temp = curr->value;
                curr->value = curr->next->value;
                curr->next->value = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
        lastNode = curr;
    } while (swapped);
}

void sortByChaos(List *list) {
    if (list->head == NULL || list->head->next == NULL) return;
    int swapped;
    Node *curr;
    Node *lastNode = NULL;

    do {
        swapped = 0;
        curr = list->head;

        while (curr->next != lastNode) {
            if (curr->value.poziomChaosu > curr->next->value.poziomChaosu) {
                Przedmiot temp = curr->value;
                curr->value = curr->next->value;
                curr->next->value = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
        lastNode = curr;
    } while (swapped);
}

void freeList(List *list) {
    Node *curr = list->head;
    Node *next;

    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
