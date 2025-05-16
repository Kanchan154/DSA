#include<stdio.h>

#define Max_Size 5
int queue[Max_Size];
int front = -1, rear = -1;
int item;

void Enqueue();
void Dequeue();
void Display();


int main(){
    int choice, item;
    printf("\n Press (1) for Enqueue \n Press (2) for Dequeue \n Press (3) for Display \n Press (4) for EXIT \n \n");
    do {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice){
        case 1: Enqueue();
            break;
        case 2: Dequeue();
            break;
        case 3: Display();
            break;
        case 4: printf("EXIT...........");
            break;
        default: printf("Enter the Valid option...........\n");
            break;
        }
    }while(choice != 4);
}

void Enqueue(){
    
    if(rear == Max_Size - 1){
        printf("Overflow and Exit ........... \n");
    }
    else{
        printf("Enter the number : ");
        scanf("%d", &item);
        if(front == -1){
            front = rear = 0;
        }
        else{
            rear++;
        }
        queue[rear] = item;
        printf("Item Inserted........ \n");
    }
}

void Dequeue(){
    if(front == -1){
        printf("Underflow and exit..............\n");
    }
    else if(front == rear){
        item = queue[front];
        front = rear = -1;
        printf("Item : %d has been deleted.................\n",item);      
    }
    else{
        item = queue[front];
        for(int i = front;i<=rear;i++){
            queue[i] = queue[i+1];
        }
        rear--;
        printf("Item : %d has been deleted.................\n",item);
    }

}

void Display(){
    if(front == -1){
        printf("Queue is Empty.......... \n");
    }
    else{
        for(int j=front;j<=rear;j++){
            printf("%d \t",queue[j]);
        }
        printf("\n");
    }
}
