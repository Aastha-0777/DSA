#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char arr[20][20];
int no;

void swap(char a[20] , char b[20])
{
    char temp[20];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

int quick(char a[][20],int low,int high)
{
    char pivot[20];

    strcpy(pivot,a[high]); 
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(char a[][20],int low,int high)
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
        scanf("%s",&arr[i]);
    }
}

void display()
{
    printf("\nArray = ");
    for(int i=0;i<no;i++)
    {
        printf("%s ",arr[i]);
    }
}

void sort()
{
    quickSort(arr,0,no-1);
    printf("\nArray sorted successfully...");
}

void update()
{
    char newValue[20],oldValue[20];

    printf("\nEnter Old Value = ");
    scanf("%s",oldValue);

    printf("\nEnter New Value = ");
    scanf("%s",newValue);

    for(int i=0;i<no;i++)
    {
        if(strcmp(arr[i],oldValue) == 0)
        {
            strcpy(arr[i],newValue);
            printf("\nUpdated successfully..");
            return;
        }
    }
    printf("\nElement not found..");

}

void deleteValue()
{
    char value[20];

    printf("\nEnter Value You want to delete = ");
    scanf("%s",value);

    for(int i=0;i<no;i++)
    {
        if(!(strcmp(arr[i],value)))
        {
            for(int j=i;j<no-1;j++)
            {
                strcpy(arr[j],arr[j+1]);
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