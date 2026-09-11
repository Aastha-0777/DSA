/*
    Merge Sort Task — Employee Salary System

    Write a program in C to store the salaries of n employees and sort them in ascending order using Merge Sort.

    Requirements:

    Input the number of employees.
    Input the salary of each employee.
    Display the original salaries.
    Sort the salaries using Merge Sort.
    Display the sorted salaries.
    Also find and display the highest and lowest salary.
*/

#include <stdio.h>
#define MAX 100

int empSalary[MAX];

void merge(int arr[], int low, int mid, int high){

    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[MAX];

    // Compare and store
    while(i <= mid && j <= high){

        if(arr[i] < arr[j]){

            temp[k] = arr[i];
            i++;

        }else{

            temp[k] = arr[j];
            j++;

        }//end of if-else

        k++;

    }//end of while

    // Elements of left subarray
    while(i <= mid){

        temp[k] = arr[i];
        i++;
        k++;

    }//end of while
    
    // Elements of right subarray
    while(j <= high){

        temp[k] = arr[j];
        j++;
        k++;

    }//end of while

    // Copy temp to original array
    for(i = low, k = 0; i <= high; i++, k++){

        arr[i] = temp[k];

    }//end of for

}

void mergeSort(int arr[], int low, int high){

    if(low < high){

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);

    }//end of if

}//end of mergeSort

int main(){

    int empNum;

    printf("\nEnter the Number of Employees : ");
    scanf("%d", &empNum);

    printf("\nEnter the Salary of Employees : \n");
    for(int i = 0; i < empNum; i++){   
        printf("Salary of Employee %d : ", i + 1);
        scanf("%d", &empSalary[i]);
    }

    printf("\nOriginal Salaries : ");
    for(int i = 0; i < empNum; i++){
        printf("%d ", empSalary[i]);
    }

    mergeSort(empSalary, 0, empNum - 1);

    printf("\nSorted Salaries : ");
    for(int i = 0; i < empNum; i++){
        printf("%d ", empSalary[i]);
    }

    printf("\nLowest Salary : %d and Highest Salary : %d", empSalary[0], empSalary[empNum - 1]);

    return 0;

}//end of main