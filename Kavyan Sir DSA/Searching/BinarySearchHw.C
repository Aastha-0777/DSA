#include <stdio.h>
#define MAX 6

int binarySearch(int arr[], int key)
{

    int low = 0;
    int high = MAX - 1;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {

            return mid;

        }
        else if (arr[mid] > key)
        {

            high = mid - 1;
        }
        else
        {

            low = mid + 1;

        } // end of if-else ladder

    } // end of while

    return -1;

} // end of binarySearch

int main()
{

    int arr[MAX];
    int key, res;

    for (int i = 0; i < MAX; i++)
    {

        printf("Enter the Element %d : ", i + 1);
        scanf("%d", &arr[i]);

    } // end of for

    int i;

    for (i = 0; i < MAX; i++)
    {

        for (int j = 0; j < MAX - 1; j++)
        {

            if (arr[i] > arr[i + 1])
            {

                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

            } // end of if

        } // end of inner for

    } // end of for

    printf("\nElement After Sorting : ");

    for (int i = 0; i < MAX; i++)
    {

        printf("%d ", arr[i]);

    } // end of for


    printf("Enter the Number You Want to Search : ");
    scanf("%d", &key);

    res = binarySearch(arr, key);

    if (res != -1)
    {

        printf("The Element %d is Found at Position %d.", key, i + 1);
    }
    else
    {

        printf("The Element %d Not Found in the Array.");

    } // end of if-else

} // end of main