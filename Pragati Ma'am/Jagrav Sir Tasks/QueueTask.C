/*
Aim
To implement a Queue using Array with enqueue(), 
dequeue(), and display() operations, and handle overflow and underflow conditions.
*/

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){

    if(rear == MAX - 1){

        printf("Queue Overflowed!!\n");

    }else{

        rear++;
        queue[rear] = value;

        if(front == -1){

            front = 0;

        }

        printf("Element Entered Successfully...\n");

    }

}//end of enqueue

void dequeue(){

    if(front == -1){

        printf("Queue Underflow!!\n");

    }else if (front == rear)
    {

        printf("\n%d Removed.", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {

        printf("\n%d Removed.", queue[front]);
        front++;
    }

}//end of dequeue

void display(){

    printf("Queue : ");

    for(int i = front; i <= rear; i++){

        printf("%d ", queue[i]);

    }

    printf("\n");

}//end of display

int main(){

    int choice;

    do{

        printf("------------- QUEUE MENUE -------------\n");
        printf("1. To Enqueue\n");
        printf("2. To Dequeue\n");
        printf("3. To Display\n");
        printf("4. To Exit\n");
        printf("Enter Your Choiec : ");
        scanf("%d", &choice);

        switch(choice){

            case 1 : 
                int value;
                printf("Enter the Value you want : ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2 : 
                dequeue();
                break;

            case 3 : 
                display();
                break;

            case 4 : 
                printf("Exiting the program...\n");
                break;

            default : 
                printf("Invalid Choice!!");
            
        }//end of switch

    }while(choice != 4);

    return 0;

}//end of main