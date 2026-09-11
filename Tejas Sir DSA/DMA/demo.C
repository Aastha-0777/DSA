#include<stdio.h>
#include<stdlib.h>

int main(){

    int *a;

    a = (int *) malloc(sizeof(int));

    printf("Enter the value of a : ");
    scanf("%d", a);

    printf("a : %d", *a);

    return 0;

}//end of main