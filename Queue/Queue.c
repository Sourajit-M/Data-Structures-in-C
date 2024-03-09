#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void add(int queue[]){
    if(rear == MAX_SIZE-1){
        printf("Queue is Overflow!!\n");
        return;
    }
    if(rear == -1){
        front = 0;
    }
    int elem;
    printf("Enter the element to be inserted: ");
    scanf("%d", &elem);
    queue[++rear] = elem;
    printf("%d is pushed into Queue\n", elem);
    
}

void remove_element(int queue[]){
    if(rear==-1 && front==-1){
        printf("Queue is Underflow!!\n");
    }else if(front==rear){
        printf("Removed element is %d \n", queue[rear]);
        front=-1;
        rear=-1;
    }else{
        printf("Removed element is %d \n", queue[front]);
        front++;
    }
}

void display(int queue[]){
    printf("Elements of the Queue are: \n");
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int flag = 1;

    while (flag) {
        int choice;
        printf("Enter 1 for add function\n");
        printf("Enter 2 for remove function\n");
        printf("Enter 3 for display function\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            add(queue);
            break;

            case 2:
            remove_element(queue);
            break;

            case 3:
            display(queue);
            break;

            case 4:
            flag = 0;
            printf("You chose to Exit!");
            break;
        }
    }
    return 0;
}