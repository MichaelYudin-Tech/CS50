#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get input from user, print out greeting including the input.
    printf("Hello %s!\n", get_string("What's your name?"));
}