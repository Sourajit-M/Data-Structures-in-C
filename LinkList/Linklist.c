#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertAtBegin(Node **head, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtRandom(Node **head, int val, int index) {
    if (index < 1) {
        printf("Invalid index\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;

    if (index == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid index\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromFront(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = *head;
    printf("%d is removed\n", temp->data);
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        printf("%d is removed\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("%d is removed\n", temp->data);
    free(temp);
}

void display(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteElementRandom(Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the list\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    printf("%d is removed from the list\n", data);
    free(current);
}

Node* reverseList(Node *head) {
    Node *prev = NULL;
    while (head != NULL) {
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void getUserInput(int *ptr, const char *message) {
    printf("%s", message);
    scanf("%d", ptr);
}

int main() {
    Node *head = NULL;

    // Example input for inserting at the beginning
    insertAtBegin(&head, 10);
    insertAtBegin(&head, 20);
    insertAtBegin(&head, 30);

    // Display the list
    printf("List after inserting at the beginning: ");
    display(head);

    // Example input for inserting at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Display the list
    printf("List after inserting at the end: ");
    display(head);

    // Example input for inserting at a random position
    insertAtRandom(&head, 25, 2); // Insert 25 at position 2
    insertAtRandom(&head, 35, 5); // Insert 35 at position 5

    // Display the list
    printf("List after inserting at random positions: ");
    display(head);

    // Example input for deleting from the front
    deleteFromFront(&head);

    // Display the list
    printf("List after deleting from the front: ");
    display(head);

    // Example input for deleting from the end
    deleteFromEnd(&head);

    // Display the list
    printf("List after deleting from the end: ");
    display(head);

    // Example input for deleting a specific element
    deleteElementRandom(&head, 25); // Delete element with value 25
    deleteElementRandom(&head, 100); // Attempt to delete element with value 100 (not in list)

    // Display the list
    printf("List after deleting specific elements: ");
    display(head);


    return 0;
}

