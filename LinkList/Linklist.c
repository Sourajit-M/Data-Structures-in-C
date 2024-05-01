#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *ptr;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    // int eshita = (int *)malloc(sizeof(2*int))
    if (newNode == NULL) {
        printf("Memory Allocation failed! \n");
        exit(1);
    }

    newNode->data = data;
    newNode->ptr = NULL;
    return newNode;
}

void add_element(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->ptr != NULL) {
            temp = temp->ptr;
        }
        temp->ptr = newNode;
    }
}

void remove_element(Node **head, int data) {
    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->ptr;
    }

    if (current == NULL) {
        printf("Element not found in the list\n");
        return;
    }

    if (prev == NULL) {
        *head = current->ptr;
    } else {
        prev->ptr = current->ptr;
    }

    free(current);
}

void display(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->ptr;
    }
    printf("\n");
}


// 1 2 3 4 5 ----> 5 4 3 2 1

void reverseList(Node **head){
    Node *prev = NULL;

    while(head != NULL){
        Node *next = prev;
        prev =  head;
        head = next;
    }

    return prev;
}

int main() {
    Node *head = NULL;

    add_element(&head, 10);
    add_element(&head, 20);
    add_element(&head, 30);
    display(head);

    remove_element(&head, 20);
    display(head);

    return 0;
}

