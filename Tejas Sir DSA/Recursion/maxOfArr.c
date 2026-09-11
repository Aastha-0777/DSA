#include <stdio.h>
#define SIZE 5

int arr[SIZE] = {10, 15, 35, 50, 67}; // max = 67

int arrMax(int previous, int current)
{

    int max = arr[previous];
    if (arr[current] > arr[previous])
    {

        max = arr[current];
        if (current < SIZE)
        {
            return arrMax(previous + 1, current + 1);
        }
    }
    else
    {

        return max;
    }

} // end of arrMax

int main()
{

    int maxMain = arrMax(-1, 0);

    printf("MAX : %d", maxMain);

} // end of main