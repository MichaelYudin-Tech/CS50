#include <math.h>
#include <stdlib.h>
#include "readability.h"

struct Readability
{
    char *text;
};

struct Readability *makeReadability(char *text)
{
    struct Readability *r = malloc(sizeof(struct Readability));
    r->text = text;
    return r;
}

int getNumberOfSentences(struct Readability *rt)
{
    int count = 0;
    for (int i = 0; rt->text[i]; i++)
    {
        if (rt->text[i] == 33 || rt->text[i] == 46 || rt->text[i] == 63)
            count++;
    }

    return count;
}

int getNumberOfWords(struct Readability *rt)
{
    int count = 0;
    for (int i = 0; rt->text[i]; i++)
    {
        if (rt->text[i] == ' ')
            count++;
    }

    return count;
}

int getNumberOfLetters(struct Readability *rt)
{
    int count = 0;
    for (int i = 0; rt->text[i]; i++)
    {
        if (rt->text[i] >= 'a' && rt->text[i] <= 'z' || rt->text[i] >= 'A' && rt->text[i] <= 'Z')
            count++;
    }

    return count;
}

int getTextGrade(struct Readability *rt)
{
    return round((0.0588 * (getNumberOfLetters(rt) / getNumberOfWords(rt)) * 100) - (0.296 * (getNumberOfLetters(rt) / getNumberOfWords(rt)) * 100) - 15.8);
}
