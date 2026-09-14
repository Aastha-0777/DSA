#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *next;
    struct Node *prev;

};

struct Node *head = NULL;
struct Node *last = NULL;

void addNode(int value){

    if(head == NULL){

        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = value;
        head->prev = NULL;
        head->next = NULL;
        last = head;

    }else{

        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = value;
        temp->prev = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;

    }

}//end of addNode

void disNode(){

    struct Node* dis;
    dis = head;

    while(dis != NULL){

        printf("%d ", dis->data);
        dis = dis->next;

    }//end of while

}//end of disNode

void countOddNode(){

    struct Node* p;
    p = head;
    int counter = 0;

    while(p != NULL){

        if(p->data % 2 != 0){

            counter++;

        }

        p = p->next;

    }//end of while

    printf("\nNumber of Odd Nodes Present are : %d", counter);

}//end of countOddNode

void searchNode(int data){

    struct Node* t;
    t = head;
    int found = 0;

    while (t != NULL)
    {

        if(t->data == data){

            found = 1;
            break;

        }

        t = t->next;
        
    }
    
    if(found){

        printf("\nNode Found!!");

    }else{

        printf("\nNode Not Found!!");

    }


}//end of searchNode

int main(){

    addNode(10);
    addNode(20);
    addNode(33);
    addNode(40);
    addNode(55);

    disNode();

    countOddNode();

    searchNode(55);
    searchNode(550);
    
    return 0;

}//end of main