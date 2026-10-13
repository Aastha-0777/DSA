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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    struct ListNode dummy, *fast, *slow;
    dummy.next = head;

    fast = slow = &dummy;

    for(int i = 0; i <= n; i++){

        fast = fast->next;

    }//end of for

    while(fast != NULL){

        fast = fast->next;
        slow = slow->next;

    }//end of while

    slow->next = slow->next->next;

    return dummy.next;

}

int main() {
  
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    int n = 2; 
    head = removeNthFromEnd(head, n);

    printf("Updated List:  ");
    printList(head);

    return 0;
}
