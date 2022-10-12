#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        // get block height from user
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // number of hash incrementing by 1
    for (int h = 0; h < n; h++)
    {
        for (int j = 0; j < n; j++) // builds rectanglular block
        {
            if (h + j < n - 1)
            {
                printf(" "); // gets rid of hashs on left side of pyramid
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
