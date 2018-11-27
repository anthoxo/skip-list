#include <stdio.h>
#include <stdlib.h>
#include "skip-list.h"

linked_list initLinkedList(int d) {
    linked_list result = calloc(1, sizeof(struct t_linked_list));
    if (result == NULL) {
        exit(1);
    }
    result->data = d;
    result->next = NULL;
    return result;
}

void pushLinkedList(int d, linked_list *l) {
    linked_list result = initLinkedList(d);
    result->next = *l;
    *l = result;
}

void removeLinkedList(int d, linked_list *l) {
    if (l != NULL) {
        if ((*l)->data == d) {
            *l = (*l)->next;
        } else if ((*l)->next == NULL) {

        } else {
            linked_list *previous = l;
            linked_list *point = &((*l)->next);
            int boolean = 1;
            int alreadyFind = 0;
            while(boolean) {
                if ((*point)->data == d && alreadyFind == 0) {
                    printf("b + %d\n", (*point)->data);
                    alreadyFind = 1;
                    (*previous)->next = (*point)->next;
                } else {

                }
                if ((*point)->next == NULL) {
                    boolean = 0;
                } else {
                    previous = point;
                    point = &((*point)->next);
                }
            }
        } 
    }
}

int findLinkedList(int d, linked_list l) {
    int result = 0;
    while (l->next == NULL) {
        if (l->data == d) {
            result = 1;
        }
    }
    if (l->data == d) {
        result = 1;
    }
    return result;
}

void printLinkedList(linked_list l) {
    linked_list tmp = l;
    while (tmp->next != NULL) {
        printf("%d - ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);
}