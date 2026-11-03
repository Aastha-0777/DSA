#include<stdio.h>

int minMoves(int* nums, int numsSize) {
    
    int maxValue = nums[0];
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > maxValue)
            maxValue = nums[i];
    }

    int totalMoves = 0;
    for(int i = 0; i < numsSize; i++)
        totalMoves += maxValue - nums[i];

    return totalMoves;

}

int main(){

    int nums[3] = {1, 2, 3};

    int res = minMoves(nums, 3);

    printf("%d ", res);

}