/*
Project: Command-Line Warehouse Inventory Manager
Concepts: Basics of C, Parallel Arrays, Linear Search

Data Structures Needed (Parallel Arrays):
    1. int itemIDs[MAX];    // Stores the unique ID of the product
    2. int quantities[MAX]; // Stores how many are in stock
    3. float prices[MAX];   // Stores the price of the product
    4. int count = 0;       // Tracks how many items are currently in the warehouse

Features to Implement:
    1. Add Item: Insert a new ID, quantity, and price at the 'count' index, then increment 'count'.
    2. Search Item: Use Linear Search to find an item by its ID and print its details.
    3. Update Stock: Use Linear Search to find an item by its ID, then update its quantity.
    4. Display All: Loop through the arrays from index 0 to 'count - 1' and print the full inventory.
*/

#include <stdio.h>
#define MAX 100

int itemIDs[MAX];
int quantities[MAX];
float prices[MAX];
int count = 0;

void addItem();
int getIndexById(int id);
void searchItem();
void updateStock();
void displayPerticular(int idx);
void displayAll();

int main()
{

    int choice;

    do
    {

        printf("\n--------------------- Command-Line Warehouse Inventory Manager ---------------------");
        printf("\n1. Add Item");
        printf("\n2. Search Item");
        printf("\n3. Update Search");
        printf("\n4. Dispaly All");
        printf("\n5. Exit the Program");
        printf("\nEnter from the above Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            addItem();
            break;

        case 2:
            searchItem();
            break;

        case 3:
            updateStock();
            break;

        case 4:
            displayAll();
            break;

        case 5:
            printf("\nExiting the Command-Line Warehouse Inventory Manager Program...");
            break;

        default:
            printf("\nInvalid Choice!!");

        } // end of swithc

    } while (choice != 5); // end of do-while loop

    return 0;

} // end of main

void addItem()
{

    printf("\nEnter the Item's ID : ");
    scanf("%d", &itemIDs[count]);
    printf("Enter the Item's Quantity : ");
    scanf("%d", &quantities[count]);
    printf("Enter the Item's Prices : ");
    scanf("%f", &prices[count]);

    printf("\nItem Added Successfully!!");

    count++;

} // end of addItem

int getIndexById(int id)
{

    for (int i = 0; i < count; i++)
    {

        if (itemIDs[i] == id)
        {

            return i;

        } // end of if

    } // end of for

    return -1;

} // end of getIndexById

void searchItem()
{

    int id, idx;

    printf("\nEnter the Id of the Item You Want to Search : ");
    scanf("%d", &id);

    idx = getIndexById(id);

    if (idx == -1)
    {

        printf("\nID Not Found!!");
    }
    else
    {

        printf("\n============== Item Details ==============");
        displayPerticular(idx);

    } // end of if - else

} // end of searchItem

void updateStock()
{

    int id, idx;
    int qunt;

    printf("\nEnter the Id of the Item You Want to Update : ");
    scanf("%d", &id);

    idx = getIndexById(id);

    if (idx == -1)
    {

        printf("\nID Not Found!!");
    }
    else
    {

        printf("\nEnter the New Quantity : ");
        scanf("%d", &qunt);

        quantities[idx] = qunt;

        printf("Stock Updated Successfully!!");
    }

} // end of updateStock

void displayPerticular(int idx)
{

    printf("\nItem ID : %d", itemIDs[idx]);
    printf("\nItem Quantity : %d", quantities[idx]);
    printf("\nItem Price : %.2f", prices[idx]);

} // end of displayPerticular

void displayAll()
{

    printf("\n=================== Items Added ===================");

    for (int i = 0; i < count; i++)
    {

        displayPerticular(i);
        printf("\n-------------------------------");

    } // end of for

} // end of displayAll