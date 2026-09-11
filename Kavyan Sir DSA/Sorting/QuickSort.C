#include<stdio.h>

void quickSort(int arr[], int low, int high){

    if(low >= high){

        return;

    }

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){

        if(arr[j] < pivot){

            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }//end of if

    }//end of for

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    int p = i + 1;

    //left side

    quickSort(arr, low, p - 1);

    //right side

    quickSort(arr, p + 1, high);

}//end of quickSort

int main(){

    int arr[] = {20, 2, 9, 7, 12, 15, 1, 6, 8};
    int n = 9;

    printf("\nArray Before Sorting : ");
    for(int i = 0; i < n; i++){

        printf(" %d", arr[i]);

    }//end of for

    quickSort(arr, 0, n - 1);

    printf("\nArray After Sorting : ");
    for(int i = 0; i < n; i++){

        printf(" %d", arr[i]);

    }//end of for

    return 0;

}//end of main