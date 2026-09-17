#include<stdio.h>
#include<string.h>


void merge(char a[][30],int low,int mid , int high)
{
    int i=low;
    int j=mid+1;
    int k=0;

    char temp[50][50];

    while(i<=mid && j<=high)
    {
        if(strcmp(a[i],a[j]) < 0) // 1 < 3
        {
            strcpy(temp[k],a[i]);
            i++;
        }
        else
        {
            strcpy(temp[k],a[j]);
            j++;
        }
        k++;
    }

    // 8 2
    while(i<=mid)
    {
        strcpy(temp[k],a[i]);
        i++;
        k++;
    }

    while(j<=high)
    {
        strcpy(temp[k],a[j]); // 8
        j++;
        k++;
    }

    //temp --> a
    for(i=low , k=0 ;i<=high;i++ , k++)
    {
        strcpy(a[i],temp[k]);
    }
}

void mergeSort(char a[][30],int low,int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;

        mergeSort(a,low,mid); //1st
        mergeSort(a,mid+1,high); //2nd

        merge(a,low,mid,high);
    }
}

int main()
{
    char a[20][30];  //max 20 names , per name 30 max 
    int no;

    printf("\nEnter size of name = ");
    scanf("%d",&no);

    printf("\nEnter Names = ");
    for(int i=0;i<no;i++)
    {
        scanf("%s",&a[i]);
    }

    mergeSort(a,0,no-1); // mid find / divide

    printf("\nSorted Array = ");
    for(int i=0;i<no;i++)
    {
        printf("%s ",a[i]);
    }

    return 0;
}

/*

1. Insert
2. Display
3. Delete
4. Update
5. Sort
6. Exit

*/