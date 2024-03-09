#include <stdio.h>
#define MAX_SIZE 5

int Dqueue[MAX_SIZE];
int front = -1;
int rear = -1;

void add_front(int Dqueue[]);
void add_rear(int Dqueue[]);
void remove_front(int Dqueue[]);
void remove_rear(int Dqueue[]);
void display(int Dqueue[]);

int main(){
    int flag = 1;
    while(flag){
        int choice;
        printf("Enter 1 for Add Front function\n");
        printf("Enter 2 for Add Rear function\n");
        printf("Enter 3 for Remove Front function\n");
        printf("Enter 4 for Remove Rear function\n");
        printf("Enter 5 for Display function\n");
        printf("Enter 6 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
            add_front(Dqueue);
            break;

            case 2:
            add_rear(Dqueue);
            break;

            case 3:
            remove_front(Dqueue);
            break;

            case 4:
            remove_rear(Dqueue);
            break;

            case 5:
            display(Dqueue);
            break;

            case 6:
            flag = 0;
            printf("You chose to exit....\n");
            break;
        }
    }
    return 0;
}

void add_front(int Dqueue[]){
    if(front==0 && rear==MAX_SIZE-1){
        printf("Queue is Overflow!!\n");
        return;
    }

    int elem;
    printf("Enter the element to be inserted from front into the Dqueue: ");
    scanf("%d", &elem);
    
    if(front==-1){
        front = 0;
        rear = 0;
        Dqueue[front] = elem;
    }else if(front == 0){
        front = MAX_SIZE -1;
        Dqueue[front] = elem; 
    }else{
        front--;
        Dqueue[front] = elem;
    }
    printf("%d is pushed into the Dqueue from front\n", elem);
}

void add_rear(int Dqueue[]){
    if(front==0 && rear == MAX_SIZE-1){
        printf("Queue is Overflow!!\n");
        return;
    }

    int elem;
    printf("Enter the element to be inserted from rear into the Dqueue: ");
    scanf("%d", &elem);

    if(front == -1){
        front = 0;
        rear = 0;
        Dqueue[rear] = elem;
    }else if(rear == MAX_SIZE-1){
        rear = 0;
        Dqueue[rear] = elem;
    }else{
        rear++;
        Dqueue[rear] = elem;
    }

    printf("%d is pushed into the Dqueue from rear\n", elem);
}

void remove_front(int Dqueue[]){
    if(front==-1){
        printf("Queue is Underflow!!\n");
        return;
    }

    printf("Removed element from front is %d\n", Dqueue[front]);

    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front = (front+1) % MAX_SIZE;
    }
}

void remove_rear(int Dqueue[]){
    if(front==-1){
        printf("Queue is Underflow!!\n");
        return;
    }

    printf("Removed element from rear is %d\n", Dqueue[rear]);

    if(front == rear){
        front = -1;
        rear = -1;
    }else if(rear == 0){
        rear = MAX_SIZE-1;
    }else{
        rear = (rear-1)%MAX_SIZE;
    }
}

void display(int Dqueue[]){
    if(front==-1){
        printf("Dequeue is empty!!\n");
        return;
    }

    int i= front;
    printf("Dequeu Elements are: \n");
    while(i!=rear){
        printf("%d ", Dqueue[i]);
        i = (i+1) % MAX_SIZE;
    }

    printf("%d\n", Dqueue[rear]);
}