// Stack is implemented using functions


#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

void push(int stack[]);
void pop(int stack[]);
void display(int stack[]);

int main(){
    int flag = 1;
    while(flag){
        int choice;
        printf("Enter 1 for push function\n");
        printf("Enter 2 for pop function\n");
        printf("Enter 3 for display function\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
            //push function
            push(stack);
            break;

            case 2:
            //pop function
            pop(stack);
            break;

            case 3:
            //display function
            display(stack);
            break;

            case 4:
            flag = 0;
            printf("You chose to Exit!");
            break;
        }
    }
    return 0;
}

void push(int stack[]){
    if(top == MAX_SIZE-1){
        printf("Stack is Overflow!! \n");
        return;
    }

    int elem;
    printf("Enter a element to be inserted into the stack: ");
    scanf("%d", &elem);
    top++;
    stack[top] = elem;
    printf("%d is pushed into Stack\n", elem);
}

void pop(int stack[]){
    if(top >= 0){
        printf("Popped out element from the Stack is %d\n", stack[top]);
        top--;
    }else{
        printf("Stack is Underflow!!\n");
    }
}

void display(int stack[]){
    printf("Elements of the stack are: \n");
    for(int i=0; i<=top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}