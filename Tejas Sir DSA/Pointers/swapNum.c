#include <stdio.h>

void swap(int *p, int *q){

    int temp;

    temp = *p;
    *p = *q;
    *q = temp;

}//end of swap

int main(){

    int a = 7;
    int b = 6;

    printf("a : %d b : %d", a, b);

    swap(&a, &b);

    printf("\na : %d b : %d", a, b);

    return 0;

}//end of main