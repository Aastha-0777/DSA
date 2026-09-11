/*
---------------------------------------
TASK 1 : LINEAR SEARCH
---------------------------------------

Problem:
A school stores the roll numbers of 10 students in an array.

Write a program to:
1. Store the roll numbers in an array.
2. Ask the user to enter a roll number.
3. Search the roll number using Linear Search.
4. If found, display its position.
5. Otherwise, display "Roll Number Not Found."

Sample Input:
Roll Numbers:
101 105 108 110 115 120 125 130 135 140

Enter Roll Number: 125

Sample Output:
Roll Number Found at Position 7

---------------------------------------

Sample Input:
Enter Roll Number: 150

Sample Output:
Roll Number Not Found

---------------------------------------
Concept Used:
- Array
- Loop
- Linear Search


=======================================
*/

#include<stdio.h>
#define MAX 100

int main(){

    int rollNo[MAX];
    int n;

    printf("\nEnter the Number of RollNo You Want to Enter : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        printf("Enter the Roll Numner : ");
        scanf("%d", &rollNo[i]);

    }//end of for

    return 0;

}//end of main