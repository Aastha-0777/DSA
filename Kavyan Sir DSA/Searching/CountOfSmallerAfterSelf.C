/*
Count of Smaller Numbers After Self

Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).|
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
*/

#include <stdio.h>
#define MAX 4

int main()
{

    //int arr[MAX] = {5, 2, 6, 1};
    int arr[MAX] = {7, 2, 6, 5};
    int num;
    int low = 0;
    int high = MAX - 1;
    int smallerEleCounter = 0;

    for (int i = 0; i < MAX; i++)
    {

        for (int j = i + 1; j < MAX; j++)
        {

            if (arr[i] <= arr[j])
            {

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            } // end of if
        } // end of inner for
    } // end of outer for

    printf("\nElement After Sorting : ");

    for (int i = 0; i < MAX; i++)
    {

        printf("%d ", arr[i]);

    } // end of for

    printf("\nEnter the Number : ");
    scanf("%d", &num);

    while (low <= high)
    {

        int mid = (high + low) / 2;

        if (arr[mid] == num)
        {

            if (mid == 0 && high == 0)
            {

                smallerEleCounter = MAX - (mid + 1);
                printf("%d", low);
                printf("%d", mid);
                printf("%d", high);
                // printf("%d", high - mid);
            }
            else
            {

                smallerEleCounter = high - mid;
                printf("%d", mid);
                printf("%d", high);
                // printf("%d", high - mid);

            } // end of if-else
            break;
        }
        else if (arr[mid] < num)
        {

            high = mid - 1;
            // printf("%d", mid);
            // printf("num is smaller");
        }
        else
        {

            low = mid + 1;
            // printf("%d", mid);
            // printf("num is greater");

        } // end of if - else ladder

    } // end of while

    printf("\nThe Number of Smaller Elements at the Right of %d are : %d", num, smallerEleCounter);

    return 0;

} // end of main