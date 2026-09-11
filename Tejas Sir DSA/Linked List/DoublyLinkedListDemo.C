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

int main(){

    addNode(10);
    addNode(20);


    printf("%d %d", head->data, last->prev->data);

    return 0;

}//end of main