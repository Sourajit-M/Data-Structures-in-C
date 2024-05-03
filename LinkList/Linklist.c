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

    int flag = 1;

    while (flag) {
        int choice;
        printf("Enter 1 to insert at the beginning\n");
        printf("Enter 2 to insert at the end\n");
        printf("Enter 3 to insert at a random position\n");
        printf("Enter 4 to delete from the beginning\n");
        printf("Enter 5 to delete from the end\n");
        printf("Enter 6 to delete a specific element\n");
        printf("Enter 7 to display the list\n");
        printf("Enter 8 to reverse the list\n");
        printf("Enter 9 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int val;
        int index;

        switch (choice) {
            case 1:
                getUserInput(&val, "Enter the element to be inserted at the beginning: ");
                insertAtBegin(&head, val);
                break;
            case 2:
                getUserInput(&val, "Enter the element to be inserted at the end: ");
                insertAtEnd(&head, val);
                break;
            case 3:
                getUserInput(&val, "Enter the element to be inserted: ");
                getUserInput(&index, "Enter the index to insert the element: ");
                insertAtRandom(&head, val, index);
                break;
            case 4:
                deleteFromFront(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                getUserInput(&val, "Enter the element to be deleted: ");
                deleteElementRandom(&head, val);
                break;
            case 7:
                display(head);
                break;
            case 8:
                head = reverseList(head);
                break;
            case 9:
                flag = 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

     Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
