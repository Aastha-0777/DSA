/*
Challenge 1: The "Missing Number" (Linear Scan)Problem: Given an array nums containing n distinct numbers in the range [0, n], 
             return the only number in the range that is missing from the array.
             Example: Input: nums = [3, 0, 1] | Output: 2 
             Constraint: Solve this with O(N) time complexity and O(1) space.Logic 
             Tip: This is a classic "Summation" problem. 
                  How does the sum of the first N numbers help you identify the missing one?
*/

#include<stdio.h>
#define SIZE 100

void findMissingNum(int arr[], int n){

    int orgSum = (n * (n + 1)) / 2;
    int sum = 0;
    int missingNum = 0;
    for(int i = 0; i < n; i++){

        sum += arr[i];

    }//end of for

    missingNum = orgSum - sum;

    printf("Sum : %d | orgSum : %d | Missing Number : %d", sum, orgSum, missingNum);

}//end of findMissingNum

int main(){

    int arr[SIZE];
    int n;

    printf("Enter the Number of Elements You want to Enter : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        printf("Enter the value of arr[%d] : ", i);
        scanf("%d", &arr[i]);

    }//end of for

    findMissingNum(arr, n);

}//end of main