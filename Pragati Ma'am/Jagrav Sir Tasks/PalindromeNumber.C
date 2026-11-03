#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{

    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int rev = 0;

    while (x > rev)
    {
        rev = (rev * 10) + (x % 10);
        x /= 10;
    } // end of while

    return x == rev || x == rev / 10;
    
}

int main()
{

    bool res = isPalindrome(-121);
    printf("%d", res);

    return 0;
}