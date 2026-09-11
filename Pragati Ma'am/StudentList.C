#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{

    int id;
    char name[70];
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last = NULL;

void addStudent(int id, const char *name)
{

    if (head == NULL)
    {

        head = (struct Node *)malloc(sizeof(struct Node));
        head->id = id;
        strcpy(head->name, name);
        head->next = NULL;
        last = head;
    }
    else
    {

        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        temp->id = id;
        strcpy(temp->name, name);
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

} // end of addStudent

void deleteStudent(int id)
{

    struct Node *del;
    struct Node *temp = NULL;
    del = head;

    if (head == NULL)
    {
        printf("\nLinked list is empty..");
        return;
    }

    if (head->id == id)
    {
        head = head->next;
        free(del);

        printf("Delete success..\n");
        return;
    }

    while (del != NULL)
    {

        if (del->id == id)
        {

            temp->next = del->next;
            free(del);
            printf("Delete success..\n");
            break;
        }

        temp = del;
        del = del->next;

    } // end of

} // end of deleteStudent

void displayStudent()
{

    struct Node *dis;
    dis = head;

    while (dis != NULL)
    {

        printf("%d %s\n", dis->id, dis->name);
        dis = dis->next;
    }

} // end of displayStudent

void updateStudent(int idToChange, int id, const char *name)
{

    struct Node *updt = head;
    int found = 0;

    if (head == NULL)
    {
        printf("Linked list is empty..\n");
        return;
    }

    while (updt != NULL)
    {

        if (updt->id = idToChange)
        {

            updt->id = id;
            strcpy(updt->name, name);
            found = 1;
            break;
        }

        updt = updt->next;
    }

    if (found)
    {

        printf("Data Updated Successfully!!\n");
    }
    else
    {

        printf("Data Not Found!!\n");
    }

} // end of updateStudent

int main()
{

    int choice;

    do
    {

        printf("1. Add Student\n");
        printf("2. Display Student\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit Program\n");
        printf("Enter You Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
        {
            int id;
            char name[70];

            printf("Enter the Id : ");
            scanf("%d", &id);
            fflush(stdin);
            printf("Enter the Name : ");
            scanf("%s", name);

            addStudent(id, name);
        }
        break;

        case 2:
            displayStudent();
            break;

        case 3:
        {

            int id, idtoupdt;
            char nametoupdt[70];

            printf("Enter the Id you want to update : ");
            scanf("%d", &idtoupdt);
            printf("Enter the Id : ");
            scanf("%d", &id);
            fflush(stdin);
            printf("Enter the Name : ");
            scanf("%s", nametoupdt);

            updateStudent(idtoupdt, id, nametoupdt);
        }
        break;

        case 4:
        {

            int id;
            printf("Enter the Id you Want to delete : ");
            scanf("%d", &id);

            deleteStudent(id);
        }
        break;

        case 5:
            printf("Exiting the Application...\n");
            exit(0);
            break;

        default:
            printf("Invalid Choice!!");

        } // end of switch-case

    } while (choice != 5);

    return 0;

} // end of main