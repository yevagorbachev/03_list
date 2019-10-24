#include<stdlib.h>
#include<stdio.h>
#include "llist.h"

void print_list(struct node* h) {
    printf("[ ");
    struct node* next = h;
    while (next != NULL) {
        printf("%d", next->i);
        next = next->next;
    }
    printf("]\n");
}

struct node * insert_front(struct node* h, int i) {
    struct node * newh = malloc(sizeof(int) + sizeof(struct node *)); // should be 12 always
    newh->i = i;
    newh->next = h;
}

struct node * free_list(struct node * h) {
    struct node * start = h;
    struct node * next = h;
    while (next != NULL) {
        printf("deallocating location %p containing integer %d\n", h, h->i);
        next = h->next;
        free(h);
        h = next;    
    }
    return start;
}

