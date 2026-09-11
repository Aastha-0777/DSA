/*
Challenge 6: The Target Sum Pair
    Problem: Given a sorted array of integers and a target sum,
    return 1 if there are two numbers that add up exactly to the target, or 0 if there are none.
    Example: Input: nums = [1-5], target = 6 | Output: 1 (because 2 + 4 = 6)
    Constraint: Achieve O(N) time complexity and O(1) space. Nested loops are not allowed.
    Logic Tip: Use Two Pointers.
    Place one pointer at the start of the array and the second pointer at the very end.
    Check their sum, and move the pointers inward based on whether the sum is too big or too small.
*/

#include <stdio.h>
#define MAX 5

int findTargetSumPair(int arr[], int targetSum)
{

    int start = 0;
    int sum;
    int end = MAX - 1;

    while (start < end)
    {

        //         2          5     =   7
        sum = arr[start] + arr[end];

        if (sum == targetSum)
        {
            return 1;

        } //     7   8
        else if (sum < targetSum)
        {
            start++; // 1
        }
        else if (sum > targetSum)
        {
            end--;

        } // end of if
    }

    return 0;

} // end of findTargetSumPair

int main()
{

    int arr[MAX] = {1, 21, 3, 4, 5};
    int targetSum;

    printf("Array : ");
    for (int i = 0; i < MAX; i++)
    {

        printf("%d ", arr[i]);

    } // end of for

    printf("\nEnter the Target Sum : ");
    scanf("%d", &targetSum);

    int res = findTargetSumPair(arr, targetSum);

    if (res == 1)
    {

        printf("\nThe Array Contains the Targeted Sum Pair!!");
    }
    else
    {

        printf("\nThe Array Does NOT Contains the Targeted Sum Pair!!");

    } // end of if - else

} // end of main
