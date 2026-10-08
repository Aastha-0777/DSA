#include <stdio.h>
#include <stdlib.h>

struct ListNode{

    int val;
    struct ListNode* next;

};

struct ListNode* head = NULL;
struct ListNode* last = NULL;

void addNode(int value){

    if(head == NULL){

        head = (struct ListNode*) malloc(sizeof(struct ListNode));
        head->val = value;
        head->next = NULL;
        last = head;

    }else{

        struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
        temp->val = value;
        temp->next = NULL;
        last->next = temp;
        last = temp;

    }//end of if-else

}//edn of addNode

void display(){

    struct ListNode* itr = head;

    while(itr != NULL){

        printf("%d ", itr->val);
        itr = itr->next;

    }//end of while

}//end of display

struct ListNode* reverseList(struct ListNode* head) {
 
    struct ListNode* prev = NULL;
    struct ListNode* curr = head; 
    struct ListNode* next = NULL;

    while(curr != NULL){

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }//end of while
    
    return prev;

}//end of reverseList

int main(){


    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);

    display();

    head = reverseList(head);

    display();

    return 0;

}//end of main