#include <stdlib.h>
#include <stdio.h>
#include "skip-list.h"

int main() {
    int i;
    linked_list t = NULL;
    for (i = 0 ; i < 10 ; i++) {
        pushLinkedList(i, &t);
    }
    printLinkedList(t);
    removeLinkedList(3, &t);
    printLinkedList(t);
    return 0;
}
