#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;//EMPTY
int static stackSize = 0;

void static size(){

    stackSize++;

}//end of counter

void push(int data){

    top++;
    stack[top] = data;

    size();

}//end of push

int isEmpty(){

    if(top == -1){

        return 1;

    }//end of if

    return 0;

}//end of isEmpty


void pop(){

    if(isEmpty()){

        printf("The Stack is EMPTY!!\n");

    }else{

        printf("%d is Removed from the Stack!!\n", stack[top]);
        top--;

    }//end of if-else

}//end of pop

void display(){

    if(isEmpty()){

        printf("The Stack is EMPTY!!\n");

    }else{

        for(int i = top; i >= 0; i--){

            printf("| %d |\n", stack[i]);

        }//end of for

    }//end of if- else

}//end of display

int main(){

    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

}//end of main