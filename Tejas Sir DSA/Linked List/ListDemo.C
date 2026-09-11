#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last = NULL;

void addNode(int value)
{

    if (head == NULL)
    {

        head = (struct Node *)malloc(sizeof(struct Node));

        head->data = value;
        head->next = NULL;
        last = head;
    }
    else
    {

        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        temp->data = value;
        temp->next = NULL;
        last->next = temp;
        last = temp;

    } // end of if-else

} // end of addNode

void display(){

    struct Node *p;

    p = head;

    printf("\nLinked List : ");
    while (p != NULL)
    {
        
        printf(" %d", p->data);
        p = p->next;

    }
    

}//end of display

void addNodeBeg(int value){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = head;
    head = temp;

}//end of addNodeBeg

int main()
{

    addNode(10);
    addNode(20);
    addNode(30);
    display();
    addNode(40);
    display();
    addNodeBeg(15);
    display();

    return 0;

} // end of main