#include <math.h>
#include <cs50.h>
#include <stdio.h>

/**
 * @brief Calculates the grade of text by the Coleman-Liau formula
 * @param text 
 * @return int Coleman-Liau index grade of the text input 
 */
double readability(char const *text);

/**
 * @brief Consts the number of letters, words and sentences in a string
 * 
 * @param str 
 * @return int* array with the number of sentences, number of words, and number of letters in this order
 */
int *countLettersWordsAndSentences(char const *str);

int main(void)
{
    char *text = get_string("Text: ");
    double index = readability(text);

    if (index >= 1 && index <= 16)
        printf("%s, %f\n", "Grade", index);
    else
        printf("%s, \n", index < 1 ? "Before Grade 1" : "Grade 16+");
}

double readability(char const *text)
{
    int *count = countLettersWordsAndSentences(text);
    float sentences = count[0];
    float words = count[1];
    float letters = count[2];
    return round((0.0588 * (letters / words) * 100) - (0.296 * (sentences / words) * 100) - 15.8);
}

int *countLettersWordsAndSentences(char const *str)
{
    int i = 0;
    static int results[3];
    int numberOfWords = 1;
    int numberOfLetters = 0;
    int numberOfSentences = 1;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            numberOfWords++;
        else if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            numberOfLetters++;
        else if (str[i] == 33 || str[i] == 46 || str[i] == 63)
            numberOfSentences++;
        i++;
    }
    results[0] = numberOfSentences;
    results[1] = numberOfWords;
    results[2] = numberOfLetters;
    return results;
}