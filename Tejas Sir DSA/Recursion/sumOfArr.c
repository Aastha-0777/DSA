#include <stdio.h>
#define SIZE 5

int arr[SIZE] = {10, 15, 35, 50, 5}; // sum = 115
int sum = 0;

int arrSum(int idx)
{

    sum += arr[idx];
    idx++;
    if (idx < SIZE)
    {

        return arrSum(idx);
    }
    else
    {

        return sum;

    } // end of if

} // end of arrSum

int main()
{

    int sumMain = arrSum(0);

    printf("Sum : %d", sumMain);

} // end of main