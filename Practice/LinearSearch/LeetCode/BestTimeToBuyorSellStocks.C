/*
Problem: Best Time to Buy and Sell Stock (Blind 75)
Description: You are given an array 'prices' where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example:
Input: prices = {7, 1, 5, 3, 6, 4}
Output: 5 (Buy on day 2 at price 1 and sell on day 5 at price 6. Profit = 6 - 1 = 5)

Constraint: Solve this with a single pass O(N) time complexity and O(1) space.
*/

#include <stdio.h>
#define MAX 100

int maxProfit(int* prices, int pricesSize)
{

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++)
    {

        if (prices[i] < minPrice)
        {

            minPrice = prices[i];

        } // end of if

        if (prices[i] - minPrice > maxProfit)
        {

            maxProfit = prices[i] - minPrice;

        } // end of 2nd if

    } // end of for

    return maxProfit;

} // end of maxProfit

int main()
{

    int salePrice[MAX];
    int n;

    printf("Enter the Number of Days Record You Want to Enter : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("Enter Sales Price of Day %d : ", i + 1);
        scanf("%d", &salePrice[i]);
    }

    int maxPro = maxProfit(salePrice, n);

    printf("The Maximum Profit is : %d", maxPro);

    return 0;

} // end of main