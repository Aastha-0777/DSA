#include <stdio.h>
#define MAX 100

int main()
{

    int arr[MAX];
    int n;

    printf("Enter the Number of Element You Want : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("Enter arr[%d] : ", i);
        scanf("%d", &arr[i]);

    } // end of for

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                // nos beign sort
                printf("\nPhase %d : ", i + 1);

                printf("Swapping %d and %d", arr[j], arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                printf("\nArray : ");
                for (int k = 0; k < n; k++)
                {

                    printf("%d ", arr[k]);

                } // end of for

            } // end of if

        } // end of inner for

    } // end of for

    printf("\nSorted Array : ");

    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);

    } // end of for

    return 0;

} // end of main
