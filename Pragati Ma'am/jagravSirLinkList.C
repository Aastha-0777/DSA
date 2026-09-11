#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node* next;

};

struct Node* head;
struct Node* last;

addNode(int value){

    if(head == NULL)
    {

        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = value;
        head->next = NULL;
        last = head;

    }else{

        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = value;
        temp->next = NULL;
        last->next = temp;
        last = temp;

    }//end of if-else

}//end of addNode

void disData(){

    struct Node* dis;
    dis = head;

    printf("\n");

    while (dis != NULL)
    {
        
        printf("%d ", dis->data);
        dis = dis->next;

    }
    

}//end of disData

void addNodeAtBeg(int value){

    struct Node* beg = (struct Node*)malloc(sizeof(struct Node));
    
    beg->data = value;
    beg->next = head;
    head = beg;

}//end of addNodeAtBeg

int main(){

    addNode(10);
    addNode(20);
    addNode(30);
    addNode(40);

    disData();

    addNodeAtBeg(67);

    disData();

    return 0;

}//end of main