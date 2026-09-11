#include <stdio.h>
#define MAX 5

int queue[MAX];
int rear = -1;
int front = -1;

void enQueue(int data)
{

    if (rear == MAX - 1)
    {

        printf("\nThe Queue is FULL FOR %d", data);
    }
    else
    {

        rear++;

        queue[rear] = data;

        if (front == -1)
        {

            front = 0;
        }
    }
} // end of enQueue

void deQueue()
{

    if (front == -1)
    {

        printf("\nThe Queue is Empty!!");
    }
    else if (front == rear)
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

} // end of deQueue

void display()
{
    if (front == -1)
    {

        printf("The Queue is Empty!!");
    }
    else
    {
        printf("\nQueue : ");

        for (int i = front; i <= rear; i++)
        {

            printf("%d ", queue[i]);

        } // end
    }

} // end of deQueue

int main()
{

    enQueue(10);
    enQueue(20);
    enQueue(30);

    display(); // 10 20 30

    enQueue(40); //

    enQueue(50); //

    enQueue(60); // full

    display(); // 10 20 30 40 50

    deQueue(); // 10

    // enQueue(50)

    // enQueue(60)
    display(); // 20 30 40 50
    return 0;

} // end of  main