#include<stdlib.h>
#include<stdio.h>
#include "llist.h"

void print_list(struct node* h) {
    printf("[ ");
    struct node* next = h;
    while (next != NULL) {
        printf("%d ", next->i);
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
    struct node * next = h;
    while (next != NULL) {
        printf("deallocating location %p containing integer %d\n", h, h->i);
        next = h->next;
        free(h);
        h = next;    
    }
    return NULL;
}

struct node * remove_node(struct node * h, int data) {
    struct node * next = h->next;
    if (h->i == data) {
        printf("deallocating location %p containing integer %d\n", h, h->i);
        free(h);
        return next;
    }
    struct node * prev = h;
    while (next != NULL) {
        if (next->i == data) {
            prev->next = next->next;
            printf("deallocating location %p containing integer %d\n", next, next->i);
            free(next);
            break;
        } else {
            prev = next;
            next = next->next;
        }
    }
    return h;
}
