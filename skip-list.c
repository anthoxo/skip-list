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

int removeLinkedList(int d, linked_list *l) {
    if (l != NULL) {
        if ((*l)->data == d) {
            *l = (*l)->next;
            return 1;
        } else if ((*l)->next == NULL) {
            return 0;
        } else {
            linked_list *previous = l;
            linked_list *point = &((*l)->next);
            int isFind = 0;
            while(1) {
                if ((*point)->data == d) {
                    isFind = 1;
                    if ((*point)->next != NULL) {
                        (*previous)->next = (*point)->next;
                    } else {
                        (*previous)->next = NULL;
                    }
                    break;
                } else {

                }
                if ((*point)->next == NULL) {
                    break; 
                } else {
                    previous = point;
                    point = &((*point)->next);
                }
            }
            return isFind;
        } 
    } else {
        return 0;
    }
}

int findLinkedList(int d, linked_list l) {
    int result = 0;
    linked_list tmp = l;
    while (tmp->next != NULL) {
        if (tmp->data == d) {
            result = 1;
        }
        tmp = tmp->next;
    }
    if (tmp->data == d) {
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