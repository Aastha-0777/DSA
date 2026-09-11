/*

Problem Statement

Write a C program that performs both Bubble Sort and Selection Sort on the same array and compares their results.

Requirements
Accept the number of elements (n) from the user.
Input n integer elements into an array.
Copy the original array into two separate arrays:
bubbleArr
selectionArr
Sort:
bubbleArr using Bubble Sort.
selectionArr using Selection Sort.
Display:
Original Array
Bubble Sorted Array
Selection Sorted Array
Count and display:
Number of comparisons made by Bubble Sort.
Number of swaps made by Bubble Sort.
Number of comparisons made by Selection Sort.
Number of swaps made by Selection Sort.
Finally, print whether both algorithms produced the same sorted array.

*/

#include <stdio.h>
#define MAX 100

int main()
{

    int arr[MAX];
    int n, i, j, temp = 0, min;

    printf("Enter the Number of Element You Want : ");
    scanf("%d", &n);

    for (int k = 0; k < n; k++)
    {

        printf("Enter the Arr[%d] : ", k);
        scanf("%d", &arr[k]);
    }

    //copy the original array into two separate arrays
    int bubbleArr[MAX], selectionArr[MAX];
   
    for (int k = 0; k < n; k++)
    {

        bubbleArr[k] = arr[k];
        selectionArr[k] = arr[k];
    }

    int selectionComparisons = 0, selectionSwaps = 0;
    int bubbleComparisons = 0, bubbleSwaps = 0;

    // bubble sort

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n; j++)
        {

            if (bubbleArr[j] > bubbleArr[j + 1])
            {

                temp = bubbleArr[j];
                bubbleArr[j] = bubbleArr[j + 1];
                bubbleArr[j + 1] = temp;
                bubbleSwaps++;
            } // end of if

            bubbleComparisons++;

        } // end of inner for

    } // end of outer for

    // selection sort

    temp = 0;

    for (i = 0; i < n; i++)
    {

        min = i;

        for (j = i + 1; j < n; j++)
        {

            if (selectionArr[j] < selectionArr[min])
            {

                min = j;

            } // end of if

            selectionComparisons++;

        } // end of inner for

        temp = selectionArr[i];
        selectionArr[i] = selectionArr[min];
        selectionArr[min] = temp;
        selectionSwaps++;

    } // end of outer for

    printf("\nOriginal Array : ");

    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);

    }

    printf("\nBubble Sorted Array : ");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", bubbleArr[i]);

    }

    printf("\nSelection Sorted Array : ");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", selectionArr[i]);

    }

    printf("\n\nBubble Sort Comparisons : %d", bubbleComparisons);
    printf("\nBubble Sort Swaps : %d", bubbleSwaps);

    printf("\nSelection Sort Comparisons : %d", selectionComparisons);
    printf("\nSelection Sort Swaps : %d", selectionSwaps);

    return 0;
}
