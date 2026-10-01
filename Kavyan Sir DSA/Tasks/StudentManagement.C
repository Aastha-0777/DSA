/*
Linked List Problem: Student Record Management

Write a program to implement a Singly Linked List to store student records.

Each node should contain:
- rollNo
- name
- marks
- next

Implement the following operations:
1. Insert at Beginning
2. Insert at End
3. Insert at a Given Position
4. Delete by Roll Number
5. Search Student by Roll Number
6. Display All Students
7. Count Total Students

Sample Input
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete Student
5. Search Student
6. Display Students
7. Count Students
8. Exit

Enter choice: 2

Enter Roll No: 101
Enter Name: Rahul
Enter Marks: 85
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentNode
{

    int rollNo;
    char name[67];
    float marks;
    struct StudentNode *next;
};

struct StudentNode *head = NULL;

void insertAtBeginning()
{

    //if head is NULL then we will create the very fist node in our list
    if (head == NULL)
    {

        head = (struct StudentNode *)malloc(sizeof(struct StudentNode));
        printf("Enter Roll No : ");
        scanf("%d", &head->rollNo);
        printf("Enter Name : ");
        scanf("%s", head->name);
        printf("Enter Marks : ");
        scanf("%f", &head->marks);
        head->next = NULL;

        printf("Student's Record Added Successfully at Beginning!\n");
    }
    else
    {

        struct StudentNode *newNode = (struct StudentNode *)malloc(sizeof(struct StudentNode));
        printf("Enter Roll No : ");
        scanf("%d", &newNode->rollNo);
        printf("Enter Name : ");
        scanf("%s", newNode->name);
        printf("Enter Marks : ");
        scanf("%f", &newNode->marks);
        newNode->next = head;
        head = newNode;

        printf("Student's Record Added Successfully at Beginning!\n");
    }

} // end of insertAtBeginning

void insertAtEnd()
{

    struct StudentNode *newNode = (struct StudentNode *)malloc(sizeof(struct StudentNode));
    printf("Enter Roll No : ");
    scanf("%d", &newNode->rollNo);
    printf("Enter Name : ");
    scanf("%s", newNode->name);
    printf("Enter Marks : ");
    scanf("%f", &newNode->marks);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        printf("Student's Record Added Successfully at End!\n");
        return;
    }

    struct StudentNode *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;

    printf("Student's Record Added Successfully at End!\n");

} // end of insertAtEnd

void insertAtPosition()
{

    int position;
    printf("Enter Position to Insert: ");
    scanf("%d", &position);

    if (position <= 0)
    {
        printf("Invalid Position! Please enter a positive integer.\n");
        return;
    }

    struct StudentNode *newNode = (struct StudentNode *)malloc(sizeof(struct StudentNode));
    printf("Enter Roll No : ");
    scanf("%d", &newNode->rollNo);
    printf("Enter Name : ");
    scanf("%s", newNode->name);
    printf("Enter Marks : ");
    scanf("%f", &newNode->marks);
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        printf("Student's Record Added Successfully at Position %d!\n", position);
        return;
    }

    struct StudentNode *current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Position exceeds the number of students. Inserting at the end.\n");
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    else
    {
        newNode->next = current->next;
        current->next = newNode;
        printf("Student's Record Added Successfully at Position %d!\n", position);
    }

} // end of insertAtPosition

void deleteStudent()
{

    int rollNo;
    printf("Enter Roll No to Delete: ");
    scanf("%d", &rollNo);

    struct StudentNode *current = head;
    struct StudentNode *previous = NULL;

    while (current != NULL && current->rollNo != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Student with Roll No %d not found!\n", rollNo);
        return;
    }

    if (previous == NULL)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current);
    printf("Student with Roll No %d deleted successfully!\n", rollNo);

} // end of deleteStudent

void searchStudent()
{

    int rollNo;
    printf("Enter Roll No to Search: ");
    scanf("%d", &rollNo);

    struct StudentNode *current = head;

    while (current != NULL)
    {
        if (current->rollNo == rollNo)
        {
            printf("Student Found:\n");
            printf("Roll No: %d\n", current->rollNo);
            printf("Name: %s\n", current->name);
            printf("Marks: %.2f\n", current->marks);
            return;
        }
        current = current->next;
    }

    printf("Student with Roll No %d not found!\n", rollNo);

} // end of searchStudent

void displayStudents()
{

    struct StudentNode *current = head;

    if (current == NULL)
    {
        printf("No student records to display.\n");
        return;
    }

    printf("Student Records:\n");
    while (current != NULL)
    {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", current->rollNo, current->name, current->marks);
        current = current->next;
    }

} // end of displayStudents

void countStudents()
{

    int count = 0;
    struct StudentNode *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    printf("Total Students: %d\n", count);

} // end of countStudents

int main()
{

    int choice;

    do
    {

        printf("----------- Student Record Management -----------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Student\n");
        printf("5. Search Student\n");
        printf("6. Display Students\n");
        printf("7. Count Students\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            insertAtBeginning();
            break;

        case 2:
            insertAtEnd();
            break;

        case 3:
            insertAtPosition();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            searchStudent();
            break;

        case 6:
            displayStudents();
            break;

        case 7:
            countStudents();
            break;

        case 8:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");

        } // end of switch

    } while (choice != 8);

    return 0;

} // end of main