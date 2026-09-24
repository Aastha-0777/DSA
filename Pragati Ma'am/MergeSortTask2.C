/*
Enter Number of Employees = 5

Name = Rahul
Salary = 45000

Name = Priya
Salary = 60000

Name = Amit
Salary = 45000

Name = Neha
Salary = 75000

Name = Karan
Salary = 60000

1. Insert
2. Display
3. Sort
4. Update -- Name , salary
5. Delete
6. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAX_NAME_LENGTH 50

char names[MAX][MAX_NAME_LENGTH];
int salaries[MAX];

void insertEmp(int* numEmp){

    char name[MAX_NAME_LENGTH];
    int salary;

    printf("Enter Name = ");
    scanf("%s", name);
    printf("Enter Salary = ");
    scanf("%d", &salary);

    if(*numEmp < MAX){
        strcpy(names[*numEmp], name);
        salaries[*numEmp] = salary;
        (*numEmp)++;
        printf("Employee inserted successfully.\n");
    } else {
        printf("Cannot insert more employees. Maximum limit reached.\n");
    }//end of if-else

}//end of insertEmp

void displayEmp(int numEmp){

    if(numEmp <= 0){

        printf("No employees to display.\n");
        return;

    }else{

        printf("Employee Details:\n");
        for(int i = 0; i < numEmp; i++){

            printf("Name: %s, Salary: %d\n", names[i], salaries[i]);

        }//end of for

    }

}//end of displayEmp

void merge(int low, int mid, int high){

    int i = low;
    int j = mid + 1;
    int k = 0;

    char tempNames[MAX][MAX_NAME_LENGTH];
    int tempSalaries[MAX];

    while(i <= mid && j <= high){

        if(salaries[i] < salaries[j]){

            strcpy(tempNames[k], names[i]);
            tempSalaries[k] = salaries[i];
            i++;

        }else{

            strcpy(tempNames[k], names[j]);
            tempSalaries[k] = salaries[j];
            j++;

        }//end of if-else

        k++;

    }//end of 1st while

    while(i <= mid){

        strcpy(tempNames[k], names[i]);
        tempSalaries[k] = salaries[i];
        i++;
        k++;

    }//end of 2nd while

    while(j <= high){

        strcpy(tempNames[k], names[j]);
        tempSalaries[k] = salaries[j];
        j++;
        k++;

    }//end of 3rd while

    for(i = low, k = 0; i <= high; i++, k++){

        strcpy(names[i], tempNames[k]);
        salaries[i] = tempSalaries[k];

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

void sortEmp(int numEmp){

    //merge sort

    mergeSort(0, numEmp - 1);

    printf("Employees sorted by salary successfully.\n");

}//end of sortEmp

void updateEmp(int numEmp){

    char name[MAX_NAME_LENGTH];
    int salary;
    int found = 0;

    printf("Enter Name of Employee to Update = ");
    scanf("%s", name);

    for(int i = 0; i < numEmp; i++){

        if(strcmp(names[i], name) == 0){

            printf("Enter New Salary = ");
            scanf("%d", &salary);
            salaries[i] = salary;
            found = 1;
            printf("Employee updated successfully.\n");
            break;

        }//end of if

    }//end of for

    if(!found){
        printf("Employee not found.\n");
    }//end of if

}//end of updateEmp

void deleteEmp(int* numEmp){

    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter Name of Employee to Delete = ");
    scanf("%s", name);

    for(int i = 0; i < *numEmp; i++){

        if(strcmp(names[i], name) == 0){

            for(int j = i; j < *numEmp - 1; j++){

                strcpy(names[j], names[j + 1]);
                salaries[j] = salaries[j + 1];

            }//end of inner for

            (*numEmp)--;
            found = 1;
            printf("Employee deleted successfully.\n");
            break;

        }//end of if

    }//end of outer for

    if(!found){
        printf("Employee not found.\n");
    }//end of if

}//end of deleteEmp

int main(){

    int numEmp;

    printf("Enter Number of Employees = ");
    scanf("%d", &numEmp);

    for(int i = 0 ; i < numEmp; i++){

        printf("\nName = ");
        scanf("%s", names[i]);

        printf("Salary = ");
        scanf("%d", &salaries[i]);

    }//end of for

    int choice = 0;

    do{

        printf("-------------------- Menu--------------------\n");
        printf("1.Insert at last\n");
        printf("2.Display\n");
        printf("3.Sort on Salary\n");
        printf("4.Update -- Name, Salary\n");
        printf("5.Delete\n");
        printf("6.Exit\n");
        printf("Enter your choice = ");
        scanf("%d", &choice);

        switch(choice){

            case 1 : insertEmp(&numEmp);
                break;

            case 2 : displayEmp(numEmp);
                break;

            case 3 : sortEmp(numEmp);
                break;

            case 4 : updateEmp(numEmp);
                break;

            case 5 : deleteEmp(&numEmp);
                break;

            case 6 : printf("Exiting the program...\n");
                exit(0);
                break;

            default : printf("Invalid choice. Please try again.\n");

        }//end of switch

    }while(choice != 0);

    return 0;

}//end of main