#include<stdio.h>

int mySqrt(int x) {
    
    int low = 0;
    int high = x;
    
    while(low <= high){

        int mid = (low + high) / 2;
        long long sq = (long long)mid * mid;
        if(sq == x){
            return mid;
        }else if(sq < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }

    }

    return high;

}

int main(){

    return 0;

}//end of main