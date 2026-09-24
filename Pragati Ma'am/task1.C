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
        for(int i = top; i > 0; i--){

            stack[i] = stack[i - 1];
            
        }//end of for

        stack[0] = value;

    }//end of if - else
    
}//end of insertFirst

void insertLast(int value){

    if(top == SIZE){

        printf("\nStack is Full!!");

    }else{

        //insert at SIZE - 1 index
        
        stack[top + 1] = value;


    }

}

void insertMiddle(int idx, int value){

    if(top == SIZE){

        printf("\nStack is Full!!");

    }else{

        top++;
        for(int i = top; i > idx; i--){

            stack[i] = stack[i - 1];

        }//end of for

        stack[idx] = value;

    }//end of if - else

}

void display(){

    printf("\nStack Elements : ");
    for(int i = 0; i < SIZE; i++){

        printf("%d ", stack[i]);

    }//end of for

}

int main(){

    insertFirst(10);
    insertFirst(20);
    insertLast(90);
    insertMiddle(5, 67);//inserting 67 at index 5
    insertFirst(70);
    insertLast(80);
    display();

    return 0;

}//end of main