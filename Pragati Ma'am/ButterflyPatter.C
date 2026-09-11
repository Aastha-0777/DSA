/*

*        *
**      **
***    ***
****  ****
**********
**********
****  ****
***    ***
**      **
*        *

*/

#include<stdio.h>

int main(){

    // int n;

    // printf("Enter the No of Row You Want : ");
    // scanf("%d", &n);

    for(int i = 1; i <= 7; i++){

        printf("* ");

        for(int j = 1; j <= 7; j++){

            if(i == 5 || i == 6){

                printf("* ");

            }else if ( j == 7 ){

                printf("* ");

            }else{

                printf(" ");

            }

        }//end of inner for

        printf("\n");

    }//end of outer for

    return 0;

}//end of main

/*

#include <stdio.h>
int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int stars = (i <= 5) ? i : (10 - i);
            if (j <= stars || j >= 10 - stars) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}

*/