#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int userNum;
    while (true)
    {
        userNum = get_int("Heght: ");
        if (userNum > 0 && userNum < 9)
        {
            break;
        }
    }

    int n = userNum;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j < n; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
