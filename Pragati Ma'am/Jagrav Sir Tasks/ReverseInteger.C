#include<stdio.h>
#include<limits.h>

int reverse(int num){

    long long rev = 0;
        //321
        //32
    while(num != 0){

        int digit = num % 10; //1 2
        rev = rev * 10 + digit; // 1 12
        if(rev > INT_MAX || rev < INT_MIN){

            return 0;

        }
        num  /=  10;   //32    

    }

    return (int)rev;

}

int main(){

    int num;
    printf("Enter a Number : ");
    scanf("%d", &num);
    int revNum = reverse(num);
    printf("The Reverse of %d is %d.\n", num, revNum);

    return 0;

}