#include <stdio.h>
#define SIZE 7

int arr[SIZE];

int isDuplicate(int data)
{

    for (int i = 0; i < SIZE; i++)
    {

        if (arr[i] == data)
        {

            return 1;
            
        } // end of if

    } // end of for

    return 0;

} // end of isDuplicate

void insertItem(int location, int data)
{

    if (!isDuplicate(data))
    {

        for (int i = SIZE - 1; i >= location - 1; i--)
        {

            arr[i] = arr[i - 1];

        } // end of for

        arr[location - 1] = data;
    }
    else
    {

        printf("%d data is Already Present.\n", data);

    } // end of if-else

} // end of insertItem

void removeItem(int location)
{

    for (int i = location - 1; i < SIZE - 1; i++)
    {

        arr[i] = arr[i + 1];

    } // end of for

    arr[SIZE - 1] = 0;

} // end of removeItem

void display()
{

    for (int i = 0; i < SIZE; i++)
    {

        printf("%d ", arr[i]);

    } // end of for

    printf("\n");

} // end of display

int main()
{

    insertItem(1, 10);
    insertItem(2, 20);
    insertItem(1, 30);
    insertItem(1, 40);
    insertItem(3, 50);
    insertItem(3, 60);
    insertItem(4, 10);
    display();
    removeItem(2);
    display();

    return 0;

} // end of main