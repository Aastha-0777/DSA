/*
To write a C program to insert an element into an array at a given position.
*/
#include<stdio.h>
#define SIZE 10

int arr[SIZE];

void insert(int data, int location){

    for(int i = SIZE - 1; i >= location; i--){

        arr[i] = arr[i - 1];

    }//end of for

    arr[location - 1] = data; 

}//end of insert

int main(){

    insert(10, 1);
    insert(20, 2);
    insert(30, 3);

    for (int i = 0; i < SIZE; i++)
    {
        
        printf("%d ", arr[i]);        

    }

    return 0;

}//end of main