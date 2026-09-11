#include <stdio.h>
 
int main(){

    int a = 60, b = 7;
    int *p;
    int *q;

    printf("a : %d b : %d", a, b);

    p = &a;
    q = &b;

    int c = *p + *q;

    printf("\nThe Sum of a and b : %d", c);

}//end of main