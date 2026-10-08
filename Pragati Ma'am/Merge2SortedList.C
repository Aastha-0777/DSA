#include <stdio.h>
#include <stdlib.h>

struct ListNode
{

    int val;
    struct ListNode *next;
};

void addNode(struct ListNode **head, struct ListNode **last, int value)
{

    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = value;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        *last = temp;
    }
    else
    {
        (*last)->next = temp;
        *last = temp;
    } // end of if-else

} // enf of addNode

void display(struct ListNode *head)
{

    struct ListNode *itr = head;

    while (itr != NULL)
    {

        printf("%d ", itr->val);
        itr = itr->next;

    } // end of while

} // end of display

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
}//end of mergeTwoLists

int main()
{

    struct ListNode *head1 = NULL;
    struct ListNode *last1 = NULL;
    addNode(&head1, &last1, 1);
    addNode(&head1, &last1, 2);
    addNode(&head1, &last1, 4);

    struct ListNode* head2 = NULL;
    struct ListNode* last2 = NULL;
    addNode(&head2, &last2, 1);
    addNode(&head2, &last2, 3);
    addNode(&head2, &last2, 4);

    printf("List 1: ");
    display(head1);
    printf("List 2: ");
    display(head2);

    

    return 0;

} // end of main