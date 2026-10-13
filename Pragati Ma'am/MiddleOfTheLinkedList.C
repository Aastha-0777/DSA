#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct ListNode* middleNode(struct ListNode* head) {

    struct ListNode *fast, *slow;

    fast = slow = head;

    while(fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        slow = slow->next;

    }//end of while

    return slow;
    
}

int main() {
    
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    head = middleNode(head);

    printf("Middle of the Linked List:  ");
    printList(head);

    return 0;
}
