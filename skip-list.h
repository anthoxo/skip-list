struct t_linked_list {
    int data;
    struct t_linked_list *next;
};
typedef struct t_linked_list *linked_list;

linked_list initLinkedList();
void pushLinkedList(int d, linked_list *l);
int removeLinkedList(int d, linked_list *l);
int findLinkedList(int d, linked_list l);
void printLinkedList(linked_list l);

struct t_skip_list {
    int probability;
    linked_list *levels;
};
typedef struct t_skip_list skip_list;

void pushSkipList(int d, linked_list *l);
void removeSkipList(int d, linked_list *l);
int findSkipList(int d, linked_list l);
void printSkipList(linked_list l);
