#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Student
{
    char name[50];
    int roll;
    int marks;
} Student;

char *calcMarks(int marks){
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

int main()
{
    Student students[MAX];

    for (int i = 0; i < MAX; i++)
    {
        printf("Enter the name of the student %d: ", (i + 1));
        scanf("%s", &students[i].name);
        printf("Enter the roll number of the student %d: ", (i + 1));
        scanf("%d", &students[i].roll);
        printf("Enter the marks of the student %d: ", (i + 1));
        scanf("%d", &students[i].marks);
    }

    printf("\nStudents with Excellent Grade:\n");
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(calcMarks(students[i].marks), "Excellent") == 0)
        {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}