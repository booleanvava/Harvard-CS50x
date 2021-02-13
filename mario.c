#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int bricks;
    do
    {
        bricks = get_int("How tall do you want the pyramid to be (in levels) ? \n");
    }
    while (bricks < 1 || bricks > 8); // Ask again for input if the user inserts a number higher than 9 or lower than 1


    for (int i = 0; i < bricks;
         i++)          // The loop with "i" as an increment is to iterate through the levels of the pyramid
    {
        for (int j = 0; j < bricks;
             j++)     // The loop with "j" as an increment is to iterate through the number of bricks within each level on the left side
        {
            if (i + j < bricks - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        for (int k = 0; k < bricks + 2;
             k++)    // The loop with "k" as an increment is to iterate through the number of bricks within each level on the right side
        {
            if (i + k == bricks) // This is to implement the space between left and right side of the pyramids.
                {
                printf("  ");
                }
            else if (i + k > bricks - 1)    // Same principle as the "i + j" applied earlier.
                {
                    printf("#");
                }
            }

            printf("\n"); // Jumps to the new level
        }


}
