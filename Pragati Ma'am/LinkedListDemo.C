// #include <stdio.h>
// #include <stdlib.h>

// struct Node {

//     int data;
//     struct Node *next;

// };

// int main(){

//     struct Node *head;
//     struct Node *sec;
//     struct Node *third;
//     struct Node *fourth;

//     head = (struct Node*)malloc(sizeof(struct Node));
//     sec = (struct Node*)malloc(sizeof(struct Node));
//     third = (struct Node*)malloc(sizeof(struct Node));
//     fourth = (struct Node*)malloc(sizeof(struct Node));

//     head->data = 10;
//     head->next = sec;
    
//     sec->data = 20;
//     sec->next = third;

//     third->data = 30;
//     third->next = fourth;

//     fourth->data = 67;
//     fourth->next = NULL;

//     printf("%d ", head->data);
//     printf("%d ", head->next->data);
//     printf("%d ", head->next->next->data);
//     printf("%d ", head->next->next->next->data);

//     return 0;

// }//end of main

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display()
{
    struct Node *temp = head;

    printf("\nLinked List = ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nNULL...");
}

void update()
{
    struct Node *temp = head;

    int oldValue, newValue;
    int found = 0; // false

    if (head == NULL)
    {
        printf("\nLinked list is empty..");
        return;
    }
    printf("\nEnter Old Value = ");
    scanf("%d", &oldValue);

    printf("\nEnter New Value = ");
    scanf("%d", &newValue);

    while (temp != NULL)
    {
        if (temp->data == oldValue)
        {
            temp->data = newValue;
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (found == 1)
    {
        printf("\nUpdated successfully...");
    }
    else
    {
        printf("\nNot found...");
    }
}

void delete ()
{
    struct Node *temp = head;
    struct Node *temp1 = NULL;

    int value;

    if (head == NULL)
    {
        printf("\nLinked list is empty..");
        return;
    }

    printf("\nEnter value to delete = ");
    scanf("%d", &value); // 1    2    3 4

    if (head->data == value)
    {
        head = head->next;
        free(temp);

        printf("\nDelete success..");
        return;
    }

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            temp1->next = temp->next;
            free(temp);

            printf("\nDelete success..");
            return;
        }
        temp1 = temp;

        temp = temp->next;
    }
}

int main()
{
    int no, value, ch;

    do
    {
        printf("\n\n=====LINKED LIST MENU=====\n");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Update");
        printf("\n4. Delete");
        printf("\n5. Exit");

        printf("\nEnter Choice = ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter size of data = ");
            scanf("%d", &no);

            for (int i = 1; i <= no; i++)
            {
                printf("\nEnter Value = ");
                scanf("%d", &value);

                insert(value);
            }
            break;

        case 2:
            display();
            break;

        case 3:
            update();
            break;

        case 4:
            delete ();
            break;

        case 5:
            printf("\nProgram Exit...");
            exit(0);
            break;

        default:
            printf("\nInvalid choice..");
            break;
        }
    } while (ch != 5);

    return 0;
}