/*
Problem: Binary Search (LeetCode # 704)
Description: Given an array of integers 'nums' which is sorted in ascending order,
and an integer 'target', write a function to search for 'target' in 'nums'.

If 'target' exists, return its index. Otherwise, return -1.

Constraints:
- Time Complexity must be O(log N).
- Space Complexity must be O(1).
- All elements in 'nums' are unique and sorted in ascending order.

Example 1:
Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
Output: 4 (since 9 is at index 4)

Example 2:
Input: nums = [-1, 0, 3, 5, 9, 12], target = 2
Output: -1 (since 2 is not in the array)
*/
#include <stdio.h>
#define MAX 6

int isPresentInArr(int *arr, int target)
{

    int low = 0;
    int high = MAX - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {

            return mid;
        }
        else if (arr[mid] < target)
        {

            low = mid + 1;
        }
        else
        {

            high = mid - 1;

        } // end of if-else ladder

    } // end of while

    return -1;

} // end of isPresentInArr

int main()
{

    int arr[MAX] = {-1, 0, 3, 5, 9, 12};
    int target;

    printf("\nArray : ");

    for (int i = 0; i < MAX; i++)
    {

        printf("%d ", arr[i]);

    } // end of for

    printf("\nEnter the Target : ");
    scanf("%d", &target);

    int result = isPresentInArr(arr, target);

    if (result == -1)
    {

        printf("\nThe target %d is NOT Present!", target);
    }
    else
    {

        printf("\nThe target %d is Present at the Index : %d", target, result);

    } // end of if-else

    return 0;

} // end of main