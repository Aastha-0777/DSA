/*

Problem 3: Count the Even and Odd Elements
The Challenge: Scan through an array of numbers. 
Count how many numbers are even and how many are odd, then print both counts.

Why this builds logic: This trains you in conditional filtering during a single traversal. 
You aren't looking for a single position; you are analyzing properties of every single element.

*/

#include<stdio.h>
#define SIZE 100

void evenOddCounter(int arr[], int n){

    int evenCounter = 0;
    int oddCounter = 0;

    for (int i = 0; i < n; i++){
        
        if(arr[i] % 2 == 0){

            evenCounter++;

        }else{

            oddCounter++;

        }//end of if - else

    }

    printf("The Number of EVEN Elemets are %d and ODD are %d.", evenCounter, oddCounter);

}//end of evenOddCounter

int main(){

    int arr[SIZE];
    int n;

    printf("Enter the Number of Elements You want to Enter : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        printf("Enter the value of arr[%d] : ", i);
        scanf("%d", &arr[i]);

    }//end of for

    evenOddCounter(arr, n);

    return 0;

}//end of main