#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;


void enqueue(int elem){
    if(front==-1 && rear==-1){
        front = 0;
        rear = 0;
        queue[rear] = elem;
    }else if((rear+1)%MAX == front){
        printf("Queue is full!\n");
    }else{
        rear = (rear+1)%MAX;
        queue[rear] = elem;
    }
}

void dequeue(){
    if(front==-1){
        printf("Queue is empty!\n");
    }else{
        if(front==rear){
            printf("Dequeued element is %d\n", queue[front]);
            front=-1;
            rear=-1;
        }else{
            printf("Dequeued element is %d\n", queue[front]);
            front = (front+1)%MAX;
        }
    }
}


void display(){
    for(int i=front; i<=rear;){
        printf("%d ", queue[i]);
        i = (i+1)%MAX;
    }

    printf("\n");
}
int main(){
     int flag = 1;
    while(flag){
        int choice;
        printf("Enter 1 for enqueue function\n");
        printf("Enter 2 for dequeue function\n");
        printf("Enter 3 for Display function\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int elem;

        switch (choice){
            case 1:
            printf("Enter the element to be inserted from front into the Dqueue: ");
            scanf("%d", &elem);
            enqueue(elem);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            flag = 0;
            printf("You chose to exit....\n");
            break;
        }
    }
    return 0;
}