#include <stdio.h>

int main(){
    int MAX_SIZE;
    printf("Enter the max size of the stack: ");
    scanf("%d", &MAX_SIZE);

    int stack[MAX_SIZE];
    int top = -1;

    int flag = 1;

    while(1){
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
            if(top == -1){
                top = 0;
                int elem;
                printf("Enter the element to be inserted: ");
                scanf("%d", &elem);
                stack[top] = elem;
            }
            else if(top < MAX_SIZE-1){
                int elem;
                printf("Enter the element to be inserted: ");
                scanf("%d", &elem);
                top++;
                stack[top] = elem;
            }else{
                printf("Stack is Overflow!!\n");
            }
            break;

            case 2:
            //pop function
            if(top>=0){
                printf("Popped out element of the stack is %d\n", stack[top]);
                top--;
            }else{
                printf("Stack is underflow!!\n");
            }
            break;

            case 3:
            //display function
            printf("Elements of the stack are: \n");
            for(int i=0; i<=top; i++){
                printf("%d ", stack[i]);
            }
            printf("\n");
            break;
            
            case 4:
            flag = 0;
            break;
        }

        if(flag == 0){
            printf("You chose to exit..");
            break;
        }
    }
    return 0;
}