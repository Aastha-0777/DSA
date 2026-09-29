#include<stdio.h>
#include<stdlib.h>

int a[20],no;

void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int quick(int a[],int low,int high)
{
    int pivot;

    pivot = a[high]; // 4 2 5 8 6 7 
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

int quickSort(int a[],int low,int high)
{
    if(low < high)
    {
        int pivot = quick(a,low,high);

        quickSort(a,low,pivot-1);
        quickSort(a,pivot+1,high);
    }
}

void insert()
{
    printf("\nEnter Size = ");
    scanf("%d",&no);

    printf("\nEnter Array Elements = ");

    for(int i = 0; i < no; i++)
    {
        scanf("%d",&a[i]);
    }
}

void display()
{
    printf("\nArray = ");
    for(int i=0;i<no;i++)
    {
        printf("%d ",a[i]);
    }
}

void sort()
{
    quickSort(a,0,no-1);
    printf("\nArray sorted successfully...");
}


void update()
{
    int newValue,oldValue;

    printf("\nEnter Old Element = ");
    scanf("%d",&oldValue);

    printf("\nEnter New Element = ");
    scanf("%d",&newValue);

    for(int i=0;i<no;i++)
    {
        if(a[i] == oldValue)
        {
            a[i] = newValue;
            printf("\nUpdated successfully..");
            return;
        }
    }
    printf("\nElement not found..");

}

void deleteValue()
{
    int value;

    printf("\nEnter Element = ");
    scanf("%d",&value);

    for(int i=0;i<no;i++)
    {
        if(a[i] == value)
        {
            for(int j=i;j<no-1;j++)
            {
                a[j] = a[j+1];
            }
            no--;
            printf("\nDeleted successfully...");
            return;
        }
    }
    printf("Element not found...");
}


int main()
{
    int ch;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Sort");
        printf("\n4. Update");
        printf("\n5. Delete");
        printf("\n6. Exit");

        printf("\nEnter choice = ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:insert();
            break;

            case 2:display();
            break;

            case 3:sort();
            break;

            case 4:update();
            break;

            case 5:deleteValue();
            break;

            case 6:printf("\nProgram ended..");
                   exit(0);
            break;

            default:printf("\nInvalid choice..");
            break;
        }

    } while (ch!=6);
    

    return 0;
}

/*
1. insert
2. display
3. sort
4. exit

update
delete
*/