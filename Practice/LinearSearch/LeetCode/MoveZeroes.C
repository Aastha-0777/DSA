/*
Challenge 3: "Move Zeroes"
    Problem: Given an integer array nums, move all 0s to the end of it while maintaining the relative order of the non-zero elements.
    Example: Input: nums = [0, 1, 0, 3, 12] | Output: [1, 3, 12, 0, 0]
    Constraint: You must do this in-place without making a copy of the array.
    Logic Tip: This is not a search problem, but a Two-Pointer problem. Use one pointer to track where the next non-zero element should go,
               and another to scan the array.
*/

#include <stdio.h>
#define SIZE 100

void moveZeroes(int arr[], int n)
{

    // for (int i = 0; i < n; i++)
    // {

    //     for (int j = 0; j < n; j++)
    //     {

    //         if(arr[j] == 0){

    //             int temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;

    //         }//end of if
            
    //     }
        

    // }

    int traker = 0;

    for(int i = 0; i < n; i++){

        if(arr[i] != 0){

            arr[traker] = arr[i];
            traker++;

        }//end of if

    }//end of for

    for (int i = traker; i < n; i++)
    {
        
        arr[i] = 0;
        
    }
    

    for (int i = 0; i < n; i++)
    {
        
        printf("%d ", arr[i]);

    }
    
    

} // end of moveZeroes

int main()
{

    int arr[SIZE];
    int n;

    printf("Enter the Number of Elements You want to Enter : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("Enter the value of arr[%d] : ", i);
        scanf("%d", &arr[i]);

    } // end of for

    moveZeroes(arr, n);

    return 0;

} // end of main