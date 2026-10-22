#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* getKth(struct ListNode* curr, int k){

    while(curr != NULL && k > 0){

        curr = curr->next;
        k--;

    }//end of while

    return curr;

}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* groupPrev = &dummy;

    while(1){

        struct ListNode* kth = getKth(groupPrev, k);

        if(kth == NULL){

            break;

        }//end of if

        struct ListNode* groupNext = kth->next;
        struct ListNode* oldGroupHead = groupPrev->next;

        struct ListNode* prev = groupNext;
        struct ListNode* curr = groupPrev->next;

        while(curr != groupNext){

            struct ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;

        }//end of while

        groupPrev->next = kth;
        groupPrev = oldGroupHead;

    }//end of while

    return dummy.next;

}

int main(){



}//end of main