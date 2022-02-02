#include "readability.h"
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *text = get_string("Text: ");
    struct Readability *textInput = makeText(text);
    int grade = getTextGrade(textInput);
    grade > 0 && grade <= 16 ? printf("Grade: %d\n", grade) : printf("%s\n", grade < 1 ? "Before Grade 1\n" : "Grade 16+\n");
}