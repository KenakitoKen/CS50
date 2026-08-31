#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    int x;
    do
    {
        x = get_int("Please enter a positive number: ");
    }
    while (x <= 0 || x >= 9);

    for (int i = 0; i < x; i++)
    {
        for (int a = (x - i) - 1; a > 0; a--)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//            printf("%d", a);