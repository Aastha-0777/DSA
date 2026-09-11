/*
Challenge 5: First and Last Occurrence
Problem: Given an array of integers and a target number, find both the first index and the last index where the target appears
. If the target does not exist, return -1 for both
.
Example: Input: nums =
, target = 8 | Output: First Index: 3, Last Index: 5.
Constraint: Achieve this in a single pass (one loop) to maintain an O(N) time complexity
.
Logic Tip: A standard linear search stops the moment it finds the target
. To do this in one pass, you need state variables (like first and last) to track the changing indices as you scan the entire array
.
*/

#include<stdio.h>
#define MAX 5

int firstLastOccurence(int arr[], int target){

    int firstOccur = -1;
    int lastOccur = -1;

    for(int i = 0; i < MAX; i++){

        if(arr[i] == target){

            if(firstOccur == -1){

                firstOccur = i;

            }

            lastOccur = i;
            
        }

    }//end of for

    if(firstOccur == -1){

        return -1;

    }else{

        printf("\nFirst Occurence : %d", firstOccur);
        printf("\nLast Occurence : %d", lastOccur);
        return 1;

    }

}//end 

int main(){

    int arr[MAX] = {10, 30, 10, 10, 67};
    int target;

    printf("Array : ");
    for (int i = 0; i < MAX; i++)
    {
        
        printf("%d ", arr[i]);

    }
    
    printf("\nEnter the Target : ");
    scanf("%d", &target);

    int res = firstLastOccurence(arr, target);

    if(res == -1){

        printf("\nTarget Not Found!!");

    }    
    

    return 0;

}//end of main