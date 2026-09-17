#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAMESNUM 20
#define NAMESIZE 30

char arr[NAMESNUM][NAMESIZE]; // 20 names of 30 char each can be stored;

void insert(int size)
{

    printf("\nEnter the Names : ");
    for (int i = 0; i < size; i++)
    {

        scanf("%s", &arr[i]);
    }

    printf("\nNames Entered Successfully!!");

} // end of insert

void display(int size)
{

    printf("\nNames : ");
    for (int i = 0; i < size; i++)
    {

        printf("%s ", arr[i]);

    } // end of for

} // end of display

void merge(int low, int mid, int high){

    int i = low;
    int j = mid + 1;
    int k = 0;

    char temp[50][50];

    while(i <= mid && j <= high){

        if(strcmp(arr[i], arr[j]) < 0){

            strcpy(temp[k], arr[i]);
            i++;

        }else{

            strcpy(temp[k], arr[j]);
            j++;

        }//end of if-else

        k++;

    }//end of 1st while

    while(i <= mid){

        strcpy(temp[k], arr[i]);
        i++;
        k++;

    }//end of 2nd while

    while(i <= mid){

        strcpy(temp[k], arr[j]);
        j++;
        k++;

    }//end of 3rd while

    
    for(i = low, k = 0; i <= high + 1; i++, k++){

        strcpy(arr[i], temp[k]);

    }//end of for

}//end of merge

void mergeSort(int low, int high){

    if(low < high){

        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid+1, high);

        merge(low, mid, high);

    }

}//end of mergeSort

int main()
{

    int choice = 0;
    int num;

    do
    {

        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Delete");
        printf("\n4. Update");
        printf("\n5. Sort");
        printf("\n6. Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("\nEnter the size of name : ");
            scanf("%d", &num);
            insert(num);
            break;

        case 2:
            display(num);
            break;

        case 3:
            //deleteName(num);
            break;

        case 4:
            break;

        case 5:
            mergeSort(0, num - 1);
            break;

        case 6:
            printf("\nExting the Programe...");
            exit(0);
            break;

        default:
            printf("\nInvalide Choice!!!");

        } // end of switch

    } while (choice != 0);

} // end of main