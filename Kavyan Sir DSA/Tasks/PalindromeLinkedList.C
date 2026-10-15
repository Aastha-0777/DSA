#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

int isPalindromList(struct Node *head)
{

    struct Node *fast = head;
    struct Node *slow = head;

    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node *prev = NULL;
    struct Node *curr = slow;
    struct Node *next_node = NULL;
    
    while (curr != NULL)
    {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    struct Node *p1 = head;
    struct Node *p2 = prev;
    while (p2 != NULL)
    {
        if (p1->data != p2->data)
        {
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return 1;

}

int main()
{

    struct Node *headOrg = NULL;
    headOrg = (struct Node *)malloc(sizeof(struct Node));

    headOrg->data = 1;
    headOrg->next->data = 3;
    headOrg->next->next->data = 3;
    headOrg->next->next->next->data = 1;

    int res = isPalindromList(headOrg);

    if (res)
    {

        printf("List Is Pallindrom..\n");
    }
    else
    {

        printf("List Is Not Pallindrom..\n");
    }

} // end of main