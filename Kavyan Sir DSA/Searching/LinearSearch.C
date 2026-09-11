#include<stdio.h>

int main(){

    int arr[100], n, i, key, found = 0;

    printf("\nEnter the Number of Elemets You Want to Add : ");
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){

        printf("\nEnter the Elements Number %d : ", i + 1);
        scanf("%d", &arr[i]);

    }//end of 1st for

    printf("\nThe Elements are : ");

    for(i = 0; i < n; i++){

        printf("%d ", arr[i]);

    }//end of 2st for

    printf("\nEnter the Element You Want to Search : ");
    scanf("%d", &key);

    for ( i = 0; i < n; i++){
        
        if(arr[i] == key){

            found = 1;
            break;

        }//end of inner if

    }//end of 3rd for
    
    if(found){

        printf("The Element %d is Found at the Index %d.", key, i + 1);

    }else{

        printf("The Element %d not Found in the Array.", key);

    }//end of if-else

}//end of main 
