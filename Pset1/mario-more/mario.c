#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // we need 3 variables:
    // 1. Height is the maximum number of lines
    // 2. i is the incremental loop variable running against the maximum
    // 3. x is the decremental variable for the decreasing amount of spaces at the start of each line
    int Height, i, x = 0;
    // get Height from the user
    do
    {
        Height = get_int("Height: ");
    }
    // repeat asking for Height until a value between 0 and 9 is received
    while ((Height < 1) || (Height > 8));
    // repeat a number of times equal to the value of Height
    for (i = 1; i < Height + 1; i++)
    {
        x = 0;
        // print the spaces at the start of each line a number of times equal to Height - i so that the pyramid is not skewed
        // while going through the loop - on each repetition - the amount of spaces will decrease as the number of lines increases
        while (x != (Height - i))
        {
            printf(" ");
            x++;
        }
        x = 0;
        // print the amount of hash symbols corresponding to the current line number(i), for the left part of the pyramid
        while (x != i)
        {
            printf("#");
            x++;
        }
        // two spaces between each part of the pyramid
        printf("  ");
        x = 0;
        // print the amount of hash symbols corresponding to the current line number(i), for the right part of the pyramid
        while (x != i)
        {
            printf("#");
            x++;
        }
        // drop down one line after each loop iteration
        printf("\n");
    }
}
