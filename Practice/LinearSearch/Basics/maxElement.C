/*

Problem 2: Find the Maximum Element (and its Index)
The Challenge: You are given an array of unsorted numbers. 
Find the largest number in the array and print the index position where you found it.

Why this builds logic: Instead of searching for a fixed target, your "target" is dynamic. 
It changes as you scan through the array. You have to maintain a "current champion" variable.

*/

#include<stdio.h>
#define SIZE 100

int maxIdx(int arr[], int n){

    int max = arr[0];
    int maxIndx = 0;

    for (int i = 1; i < n; i++){

        if(arr[i] > max){

            maxIndx = i;

        }//end of if

    }
    
    return maxIndx;

}//end of max

int main(){

    int arr[SIZE];
    int n; 

    printf("Enter the Number of Elements You want to Enter : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        printf("Enter the value of arr[%d] : ", i);
        scanf("%d", &arr[i]);

    }//end of for

   printf("The Maximum element in the Array is %d at index %d", arr[maxIdx(arr, n)], maxIdx(arr, n));

}//end of main