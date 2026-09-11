#include <stdio.h>
#define MAX 100

int main()
{

    int arr[MAX];
    int n, min, i, j, temp;

    printf("Enter the Number of Element You Want : ");
    scanf("%d", &n);

    for (int k = 0; k < n; k++)
    {

        printf("Enter the Arr[%d] : ", k);
        scanf("%d", &arr[k]);
    }

    for (i = 0; i < n; i++)
    {

        min = i;

        for (j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[min])
            {

                min = j;

            } // end of if

        } // end of inner for

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("\nSorted Array : ");

    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);

    }

    return 0;

} // end of main