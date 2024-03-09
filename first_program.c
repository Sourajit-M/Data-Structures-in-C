#include <stdio.h>

int main(){

    char name[30];
    printf("Enter the name of the user: ");
    fgets(name, sizeof(name), stdin);

    int age;
    printf("Enter the age of the user: ");
    scanf("%d", &age);

    printf("Name: %s Age: %d", name, age);

    return 0;
}