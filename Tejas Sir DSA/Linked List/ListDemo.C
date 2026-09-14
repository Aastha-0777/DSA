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

void display()
{

    struct Node *p;

    p = head;

    printf("\nLinked List : ");
    while (p != NULL)
    {

        printf(" %d", p->data);
        p = p->next;
    }

} // end of display

void addNodeBeg(int value)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = head;
    head = temp;

} // end of addNodeBeg

void countOddNode()
{

    struct Node *t;
    t = head;
    int counter = 0;

    while (t != NULL)
    {

        if (t->data % 2 != 0)
        {

            counter++;
        }

        t = t->next;

    } // end of while

    printf("\nNumber of Odd Nodes : %d", counter);

} // end of countOddNode

void searchNode(int data)
{

    struct Node *t;
    t = head;
    int found = 0;

    while (t != NULL)
    {

        if (t->data == data)
        {

            found = 1;
            break;
        }

        t = t->next;
    }

    if (found)
    {

        printf("\nNode Found!!");

    }
    else
    {

        printf("\nNode Not Found!!");

    }

} // end of searchNode

int main()
{

    addNode(10);
    addNode(20);
    addNode(33);
    display();
    addNode(40);
    display();
    addNodeBeg(15);
    addNodeBeg(67);
    display();

    countOddNode();

    searchNode(67);
    searchNode(670);

    return 0;

} // end of main