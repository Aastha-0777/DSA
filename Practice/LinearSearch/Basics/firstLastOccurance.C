/*

Problem 1: The First and Last Occurrence
The Challenge: You are given an array of integers and a target number. 
The target might appear multiple times in the array. 
Write a program to find both the first index and the last index where the target appears. 
If it doesn't exist, return -1 for both.

Why this builds logic: A standard linear search stops the moment it finds the target.
This problem forces you to think about how to keep searching even after you find a match, 
tracking changing states.

*/

#include<stdio.h>
#define SIZE 100

// int arr[5];

// int firstOccurrenceIdx(int target){

//     for(int i = 0; i < SIZE; i++){

//         if(arr[i] == target){

//             return i;
//             break;

//         }//end of if

//     }//end of for

//     return -1;

// }//end of firstOccurenceIdx

// int lastOccurrenceIdx(int target){

//     for(int i = SIZE - 1; i >= 0; i--){

//         if(arr[i] == target){

//             return i;
//             break;

//         }//end of if

//     }//end of for

//     return -1;

// }//end of lastOccurrenceIdx

void findBothOccurrence(int arr[], int n, int target){

    int first = -1;
    int last = -1;

    for(int i = 0; i < n; i++){

         if(arr[i] == target){

            if(first == -1){

                first = i;

            }//end of inner if

            last = i;

         }//end of outer if

    }//end of for

    printf("First Index : %d, Last Index : %d", first, last);

}//end of findBothOccurrence

int main(){

    int arr[SIZE];
    int n;
    int key;

    printf("Enter the Number of Elements You want to Enter : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        printf("Enter the value of arr[%d] : ", i);
        scanf("%d", &arr[i]);

    }//end of for

    printf("Enter the Value whose Occurrence You want to Find : ");
    scanf("%d", &key);

    findBothOccurrence(arr, n, key);

    return 0;

}//end of main