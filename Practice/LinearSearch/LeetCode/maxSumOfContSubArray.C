/*
Challenge 7: Maximum Sum of a Contiguous Subarray
    Problem: Given an array of integers and a window size 'k', find the maximum sum of any contiguous subarray of size 'k'.
    Example: Input: nums = [1-4], k = 3 | Output: 9 (because the subarray [2-4] has the maximum sum).
    Constraint: Achieve O(N) time complexity. You cannot use nested loops to recalculate the sum from scratch every time.
    Logic Tip: Calculate the sum of the first window (first 'k' elements).
    Then, "slide" the window forward by subtracting the element that drops out of the left side of the window,
    and adding the new element that comes into the right side.
*/

#include <stdio.h>
#define MAX 4

int findMaxSumOfCountSubArray(int arr[], int k)
{

    int maxSum = 0;
    int i = 0;

    for (i = 0; i < k; i++)
    {

        maxSum += arr[i];

    }

    int currentMaxSum = maxSum;

    for (i = k; i < MAX; i++)
    {

        currentMaxSum = currentMaxSum - arr[i - k] + arr[i];

        if(currentMaxSum > maxSum){

            maxSum = currentMaxSum;

        }//end of if

    }

    return maxSum;

} // end of findMaxSumOfCountSubArray

int main()
{

    int arr[MAX] = {2, 3, 4, 60};

    int k = 3;

    printf("Array : ");
    for (int i = 0; i < MAX; i++)
    {

        printf("%d ", arr[i]);

    } // end of for

    int result = findMaxSumOfCountSubArray(arr, k);

    printf("\nThe Maximum Sum of Contiues Array : %d", result);

} // end of main