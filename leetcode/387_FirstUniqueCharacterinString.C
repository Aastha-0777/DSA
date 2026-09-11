/*
Problem: First Unique Character in a String (LeetCode #387)
Description: Given a string s, find the first non-repeating character in it
and return its index. If it does not exist, return -1.

Constraints:
- s consists of only lowercase English letters ('a' through 'z').
- Time Complexity: O(N) where N is the length of the string.
- Space Complexity: O(1) (since the lowercase English alphabet has a fixed size of 26).

Example 1:
Input: s = "leetcode"
Output: 0 (since 'l' is the first unique character)

Example 2:
Input: s = "loveleetcode"
Output: 2 (since 'v' is the first unique character)

Example 3:
Input: s = "aabb"
Output: -1 (all characters repeat)
*/

#include <stdio.h>
#include <string.h>
#define ALFSIZE 26

int firstUnqChar(char str[]);

int main()
{

    char string[70];
    int firstUnqCharIdx;

    printf("\nEnter a String in lowercase : ");
    gets(string);

    firstUnqCharIdx = firstUnqChar(string);

    printf("\nThe Index of First Unique Character in the String \"%s\" is %d.", string, firstUnqCharIdx);

    return 0;

} // end of main

int firstUnqChar(char *str)
{

    int letterCounter[ALFSIZE] = {0};
    char letterArr[ALFSIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                               'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char filteredArray[strlen(str)];

    int idx, unqCounter;

    for (int i = 0; i < strlen(str); i++)
    {

        for (int j = 0; j < ALFSIZE; j++)
        {

            if (str[i] == letterArr[j])
            {

                letterCounter[j]++;
                idx = j;
            }
        }

    } // end of for

    for (int i = 0, j = 0; i < ALFSIZE; i++)
    {

        if (letterCounter[i] == 1)
        {

            filteredArray[j] = letterArr[i];
            j++;
        }

        unqCounter = j;

    } // end of for

    for (int i = 0; i < strlen(str); i++)
    {

        for (int j = 0; j < unqCounter; j++)
        {

            if (str[i] == filteredArray[j])
            {

                return i;

            } // end of if

        } // end of for
    }

    return -1;

} // end of firstUnqChar