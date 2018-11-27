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

void printLinkedList(linked_list l) {
    linked_list tmp = l;
    while (tmp->next != NULL) {
        printf("%d - ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);
}