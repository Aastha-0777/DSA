#include <stdio.h>
#define SIZE 6

void merge(int arr[], int low, int mid, int high){

    int i = low;
    int j = mid - 1;
    int k = 0;

    int temp[100];

    //compare and store
    while(i <= mid && j <= high){

        if(arr[i] < arr[j]){

            temp[k] = arr[i];
            i++;

        }else{

            temp[k] = arr[j];
            j++;

        }//end of if-else

    }//end of while

    //elements of left subarray

    while(i <= mid){

        temp[k] = arr[i];
        i++;
        k++;

    }//end of while
    
    while(j <= high){

        temp[k] = arr[j];
        j++;
        k++;

    }//end of while

    //copy temp to org array

    for(i = low, k = 0; i <= high; i++, k++){

        arr[i] = temp[k];

    }//end of for

}//end of merge

void mergeSort(int arr[], int low, int high){

    if(low < high){

        int mid = (low + high) / 2;

        // Divide left part
        mergeSort(arr, low, mid);

        // Divide right part
        mergeSort(arr, mid + 1, high);

        // Merge the two parts 
        merge(arr, low, mid, high);

    }//end of if

}//end of mergeSort

int main(){

    int arr[SIZE] = {};
    
    mergeSort(arr, 0, SIZE - 1);

    printf("Sorted Array : ");
    for(int i = 0; i < SIZE; i++){

        printf("%d ", arr[i]);

    }//end of for

    return 0;

}//end of main