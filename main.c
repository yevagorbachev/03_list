#include<stdlib.h>
#include<stdio.h>
#include "llist.h"

int main() {
    struct node * first = NULL;
    printf("Empty list:\n");
    print_list(first);

    first = insert_front(first, 5);
    first = insert_front(first, 4);
    first = insert_front(first, 3);
    first = insert_front(first, 2);
    first = insert_front(first, 1);
    first = insert_front(first, 0);
    printf("Populated list:\n");
    print_list(first);
    
    first = remove_node(first, 5);
    first = remove_node(first, 0);
    first = remove_node(first, 1);
    first = remove_node(first, 100);

    printf("Partially depopulated list:\n");
    print_list(first);

    first = free_list(first);
    printf("Freed list:\n");
    print_list(first);
    return 0;
}