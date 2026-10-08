/*
Requirements
1. Singly Linked List — Student Database
   - Add student
   - Display all students
   - Search student by ID
   - Delete student by ID
   - Update student details
2. Queue — Student Admission/Registration
   - Add student ID to admission queue
   - Process the next student
   - Display waiting students
   - Show first student in queue
3. Stack — Recently Deleted Students
   - Whenever a student is deleted from the linked list, push their details into the stack.
   - Display deleted students
   - Restore the most recently deleted student using POP.
===== STUDENT MANAGEMENT SYSTEM =====

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student

6. Add Student to Admission Queue
7. Process Admission
8. Display Admission Queue

9. Display Deleted Students
10. Restore Last Deleted Student

0. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//---------------------
struct Student
{

    int id;
    char name[67];
    int std;
    struct Student *nextStd;
};

struct Student *head;
struct Student *last;

//---------------------

int admisionQueue[MAX];
int front = -1;
int rear = -1;

//---------------------

struct Student studDelStack[MAX];
int top = -1;

//---------------------

void addStudent(int id, int std, char name[])
{

    if (head == NULL)
    {

        head = (struct Student *)malloc(sizeof(struct Student));
        head->id = id;
        head->std = std;
        strcpy(head->name, name);
        head->nextStd = NULL;
        last = head;
    }
    else
    {

        struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
        temp->id = id;
        temp->std = std;
        strcpy(temp->name, name);
        temp->nextStd = NULL;
        last->nextStd = temp;
        last = temp;

    } // end of if-else

    printf("Student Added Successfully...\n");

} // end of addStudent

void disStudent()
{

    struct Student *itr = head;

    printf("Student's Detail : \n");
    while (itr != NULL)
    {

        printf("%d %s %d\n", itr->id, itr->name, itr->std);
        itr = itr->nextStd;

    } // end of while

} // end of disStudent

void searchStudent(int id)
{

    struct Student *itr = head;

    while (itr != NULL)
    {

        if (itr->id == id)
        {

            printf("Student Found.. : ");
            printf("%d %s %d\n", itr->id, itr->name, itr->std);

            break;

        } // end of for

        itr = itr->nextStd;
    
    } // end of while

} // end of searchStudent

void updateStudent(int id)
{

    struct Student *itr = head;

    while (itr != NULL)
    {

        if (itr->id == id)
        {

            printf("Student Found.. : ");
            printf("%d %s %d\n", itr->id, itr->name, itr->std);
            break;

        } // end of for

        itr = itr->nextStd;

    } // end of while

} // end of updateStudent

int main()
{

    int choice;

    do
    {

        printf("===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Add Student to Admission Queue\n");
        printf("7. Process Admission\n");
        printf("8. Display Admission Queue\n");
        printf("9. Display Deleted Students\n");
        printf("10. Restore Last Deleted Student\n");
        printf("0. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            int id, std;
            char name[67];
            printf("Enter the Student's Id : ");
            scanf("%d", &id);
            printf("Enter the Student's Standard : ");
            scanf("%d", &std);
            printf("Enter the Student's Name : ");
            scanf("%s", name);
            addStudent(id, std, name);
            break;
        case 2:
            disStudent();
            break;
        case 3:
            int searchId;
            printf("Enter the Id of the Student You Want to Search : ");
            scanf("%d", &searchId);
            searchStudent(searchId);
            break;
        case 4:
            int updateId;
            printf("Enter the Id of the Student You Want to Update : ");
            scanf("%d", &updateId);
            updateStudent(updateId);
            break;
        case 5:
            delStudent();
            break;
        case 6:
            addStdToAdmiQueue();
            break;
        case 7:
            processAdmision();
            break;
        case 8:
            disAdmisionQueue();
            break;
        case 9:
            disDeletedStud();
            break;
        case 10:
            restoreLastDelStud();
            break;
        case 0:
            printf("Exiting the STUDENT MANAGEMENT SYSTEM...\n");
            break;
        default:
            printf("Invalid Choice!!\n\tPlease Enter a Valid Choice...\n");

        } // end of switch-case

    } while (choice != 0);

    return 0;

} // end of main