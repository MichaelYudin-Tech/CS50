#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void count(string text);
void grade_level(void);
// I rather have all these variables be global than return a single variable every time and have to write 2 more functions
// for a more complex program I would of course write seperate functions to have single responsability
float letters = 0;
// I'm starting to count at 1 since my code doesn't capture the final word in the text, since it ends with period and doesn't have a space after it
float words = 1;
float sentences = 0;
int index = 0;
string grade = NULL;

int main(void)
{
    string sample_text = 0;
    // prompt user for sample text
    sample_text = get_string("Text: ");
    // counts letters, words and sentences, all in one function
    count(sample_text);
    // grades the text and prints the correct grade level
    grade_level();
}

// iterates through all the letters
// I wanted to save lines of code and not make seperate functions to count letters, words and sentences
// since it's very easy to understand
void count(string text)
{
    int i = 0;

    while (text[i] != '\0')
    {
        if (tolower(text[i]) >= 'a' && tolower(text[i]) <= 'z') // I convert the letters to lowercase to simplify the code
        {
            letters++;
        }
        else if (text[i] == 32) // '32' = space in ASCII
        {
            words++;
        }
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63) // '33' = !; '46' = .; '63' = ? in ASCII
        {
            sentences++;
        }
        i++;
    }
}

// I opted to printf in this function so that I don't have to concatenate "Grade " & (int)index
void grade_level(void)
{
    index = round((0.0588 * (letters / words) * 100) - (0.296 * (sentences / words) * 100) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %d\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}