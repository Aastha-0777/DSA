/*

HW : 

Employee Record Search System

Create a program that:

Take input for N employees.
Store:
	Employee ID
	Employee Name
	Salary

Ask the user for an Employee ID to search.

Use Linear Search only to find the employee.
	If found, display all details.
	If not found, display "Employee Not Found".

Count and display:
Total comparisons made during the search.

*/

#include <stdio.h>
#define MAX 100

struct Employee{

    int empId;
    char name[70];
    int salary;

};

void scanData();
void searchEmpById();

struct Employee empList[MAX];
int listCounter = 0;

int main(){


	int choice;

	do{

		printf("---------------------------- EMP MANAGEMENT SYSTEM ----------------------------");
		printf("\n1.Enter the Employee's Data.");
		printf("\n2.Search Employee by Id.");
		printf("\n3.Exitng the Program.");
		printf("\nEnter Your Choice : ");
		scanf("%d", &choice);

		switch(choice){

			case 1: scanData();
					break;

			case 2: searchEmpById();
					break;

			case 3: printf("Exting the Employee Management Application.");
					break;

			default: printf("Invalid Choice.");

		}//end of switch-case

	}while(choice != 3);//end of do-while

	return 0;

}//end of main

void scanData(){

	struct Employee e;

	printf("---------------------------- ENTER EMPLOYEE DATA ----------------------------");
	printf("\nEnter the Employee's ID : ");
	scanf("%d", &e.empId);
	printf("\nEnter the Employee's Name : ");
	scanf(" %s", e.name);
	printf("\nEnter the Employee's Salary : ");
	scanf("%d", &e.salary);

	empList[listCounter] = e;
	listCounter++;

}//end of scanData

void searchEmpById(){

	int searchCounter = 0;
	int id, found = 0, i;

	printf("---------------------------- SEARCH EMP BY ID ----------------------------");

	printf("\nEnter the ID You Want to Search : ");
	scanf("%d", &id);

	for(i = 0; i < listCounter; i++){

		if(empList[i].empId == id){

			found = 1;
			searchCounter++;
			break;

		}else{

			searchCounter++;

		}//end of inner if-else

	}//end of for

	if(found){

		printf("\nThe ID %d is Found at index %d. Here is the Employee's Detail : ", id, i + 1);
		printf("\nEmployee's Name : %s", empList[i].name);
		printf("\nEmployee's ID : %d", empList[i].empId);
		printf("\nEmployee's Salary : %d", empList[i].salary);

		printf("\nTotal comparisons made during the search : %d\n", searchCounter);

	}else{

		printf("\nEmployee Not Found.\n");

	}//end of if-else

}//end of searchEmpById