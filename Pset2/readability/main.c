#include "readability.h"
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *text = "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him."; // get_string("Text: ");
    struct Readability *textInput = makeText(text);
    int grade = getTextGrade(textInput);
    grade > 0 && grade <= 16 ? printf("Grade: %d\n", grade) : printf("%s\n", grade < 1 ? "Before Grade 1\n" : "Grade 16+\n");
}