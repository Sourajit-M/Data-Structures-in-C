#include <stdio.h>
#include <stdlib.h>

typedef struct LinearList{
    int elements[100];
    int size;
} List;


void initialize(List *l) {
    l->size = 0;
}


void add(List *l, int element) {
    if (l->size < 100) {
        l->elements[l->size++] = element;
    } else {
        printf("List is full. Cannot add element.\n");
    }
}

//int *ptr


void remove_elements(List *l, int element) {
    int i, found = 0;
    for (i = 0; i < l->size; i++) {
        if (l->elements[i] == element) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < l->size - 1; i++) {
            l->elements[i] = l->elements[i + 1];
        }
        l->size--;
    } else {
        printf("Element not found in the l.\n");
    }
}

void display(List *l) {
    int i;
    for (i = 0; i < l->size; i++) {
        printf("%d ", l->elements[i]);
    }
    printf("\n");
}

int main() {
    List l;
    initialize(&l);

    add(&l, 69);
    add(&l, 70);
    add(&l, 8);
    display(&l);

    remove_elements(&l, 8);
    display(&l);

    return 0;
}