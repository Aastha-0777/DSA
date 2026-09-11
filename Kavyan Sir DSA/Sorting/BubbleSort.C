#include <stdio.h>

int main()
{

    int arr[] = {20, 40, 39, 67, 25, 16, 69, 77, 88};
    int i, j;
    int temp;

    int n = sizeof(arr) / sizeof(arr[0]);

    // for (i = 0; i < n; i++){

    //     for(j = i + 1; j < n; j++){

    //         if(arr[i] > arr[j]){

    //             temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;

    //         }//end of if

    //     }//end of inner for

    // }//end of outer for

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            } // end of if
        }//end of inner for
    }//end of outer for

    printf("The Sorted Array : ");

    for (i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);

    } // end of for

    return 0;

} // end of main