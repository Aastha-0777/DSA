#include<stdio.h>
#include<stdlib.h>

int main(){

    int *num1, *num2;
    int *ans;

    num1 = (int *) malloc(sizeof(int));
    num2 = (int *) malloc(sizeof(int));
    ans = (int *) malloc(sizeof(int));

    printf("Enter the value of Number 1 : ");
    scanf("%d", num1);
    printf("Enter the value of Number 2 : ");
    scanf("%d", num2);

    *ans = *num1 + *num2;

    printf("Answer : %d", *ans);

}//end of main