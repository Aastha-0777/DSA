/*
Challenge 2: "Contains Duplicate"Problem:
             Given an integer array nums, return true if any value appears at least twice in the array,
             and return false if every element is distinct.
             Example: Input: nums = [1, 2, 3, 1] | Output: true
             Interview Strategy: A brute force O(N^2) solution (nested loops) will fail here.
             Since you are learning, try to solve this with a single linear scan O(N).
             Note: For extra points, think about what data structure (Hash Map/Set) would make this search faster.
*/

#include <stdio.h>
#define SIZE 100

int containDuplicat(int arr[], int n){

    for (int i = 0; i < n; i++){
    
        int key = arr[i];

        for (int j = i + 1; j < n; j++){
        
            if(key == arr[j]){

                return 1;

            }

        }
           
    }

    return 0;

}//end of containDuplicat

int main()
{

    int arr[SIZE];
    int n;

    printf("Enter the Number of Elements You want to Enter : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        printf("Enter the value of arr[%d] : ", i);
        scanf("%d", &arr[i]);

    }//end of for

    if(containDuplicat(arr, n)){

        printf("The Array Contains Duplicates!!");

    }else{

        printf("The Array does Not Contain Duplicates");

    }//end fo if-else

    return 0;

} // end of main
