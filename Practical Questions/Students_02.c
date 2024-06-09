#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct Student
{
    char name[50];
    int roll;
    int marks;
} Student;

typedef struct Node
{
    Student student;
    struct Node* next;
} Node;

void append(Node** head, Student std) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* temp = *head;

    newNode->student = std;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

char *calcMarks(int marks) {
    if (marks < 50)
        return "Fail";
    else if (marks < 60)
        return "D";
    else if (marks < 70)
        return "C";
    else if (marks < 80)
        return "B";
    else if (marks < 90)
        return "A";
    else
        return "Excellent";
}

void display_excellent_grade(Node *head) {
    while (head != NULL) {
        if (strcmp(calcMarks(head->student.marks), "Excellent") == 0) {
            printf("%s\n", head->student.name);
        }
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    Student student;

    for (int i = 0; i < MAX; i++) {
        printf("Enter the name of the student %d: ", (i + 1));
        scanf("%s", student.name);
        printf("Enter the roll number of the student %d: ", (i + 1));
        scanf("%d", &student.roll);
        printf("Enter the marks of the student %d: ", (i + 1));
        scanf("%d", &student.marks);

        append(&head, student);
    } 

    printf("\nStudents with Excellent grade:\n");
    display_excellent_grade(head);

    return 0;
}
