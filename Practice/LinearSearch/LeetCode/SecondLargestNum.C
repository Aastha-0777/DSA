/*

Challenge 4: The Second Largest
            Problem: Given an unsorted integer array nums, return the second largest distinct number.
            If a second largest number does not exist (
                     e.g., the array has fewer than two elements or all elements are identical), return -1.
            Example: Input: nums = | Output: 34
            Constraint: Achieve an O(N) time complexity and O(1) space complexity. You cannot sort the array, as sorting takes O(NlogN) time.
            Logic Tip: Track two variables (a "champion" and a "runner-up") simultaneously as you scan through the array from left to right.

*/

#include <stdio.h>
#include <limits.h>
#define MAX 5

int secondLargestNo(int arr[])
{

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < MAX; i++)
    {

        if (arr[i] > largest && arr[i] > secondLargest)
        {

            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest)
        {

            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN)
    {

        return -1;
    }
    else
    {

        return secondLargest;
    }

} // end of secondLargestNo

int main()
{

    int arr[MAX] = {7, 67, 100, 68, 99};

    int sLaragerst = secondLargestNo(arr);

    if (sLaragerst != -1)
    {

        printf("The Second Largest No is : %d", sLaragerst);
    }
    else
    {

        printf("The Second Largest No DO Not exsits!!");

    } // end of if - else statement

    return 0;

} // end of main