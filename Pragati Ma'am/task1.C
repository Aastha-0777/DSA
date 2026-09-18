/*
To implement insertion and deletion operations in a stack from the start, middle, and end using an array in C.
*/

#include<stdio.h>
#define SIZE 10
int stack[SIZE];
int top = -1;
 
void insertFirst(int value){

    if(top == SIZE){

        printf("\nStack is Full!!");
        

    }else{

        top++;
        for(int i = SIZE - 1; i >= 0; i--){

            stack[i] = stack[i - 1];

        }//end of for

        stack[0] = value;
       

    }//end of if - else

}//end of insertFirst

void insertLast(int value){

    if(top == SIZE){

        printf("\nStack is Full!!");

    }else{

        top++;
        for(int i = SIZE - 1; i <= 0; i++){

            stack[i - 1] = stack[i];
            
        }//end of for

        stack[SIZE - 1] = value;

    }//end of if - else

}

void insertMiddle(int idx, int value){

    if(top == SIZE){

        printf("\nStack is Full!!");

    }else{

        top++;
        stack[idx] = value;

    }

}

void display(){

    printf("\nStack Elements : ");
    for(int i = 0; i < SIZE; i++){

        printf("\n| %d |", stack[i]);

    }

}

int main(){

    insertFirst(10);
    insertFirst(20);
    insertLast(90);
    insertMiddle(5, 67);
    insertFirst(70);
    display();

    return 0;

}//end of main