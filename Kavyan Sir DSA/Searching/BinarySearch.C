#include <stdio.h>

int binarySearch(int arr[], int size, int key){

    int low = 0;
    int high = size - 1;

    while(low <= high){

        int mid = (low + high) / 2;

        if(key == arr[mid]){

            return mid;

        }else if(key < arr[mid]){

            high = mid - 1;

        }else{

            low = mid + 1;

        }//end of if-else ladder

    }//end of while

    return -1;

}//end of binarySearch

int main(){

    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int key, res;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the Number You Want to Search : ");
    scanf("%d", &key);

    res = binarySearch(arr, size, key);

    if(res != -1){

        printf("Element %d found at Index %d.", key, res + 1);

    }else{

        printf("Element %d Not found in the Array.", key);

    }//end of if-else

    return 0;

}//end of main

/*
H.W. :  to take a unshorted array and do the same thing by shorting it
*/