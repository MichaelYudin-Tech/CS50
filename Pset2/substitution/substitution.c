#include <stdio.h>
#include <cs50.h>

string keyToDifference(char key[]);
string getInputAndEncrypt(int keyLetterDifference[]);
int printOutput(string cipherText);

int main(int argc, string argv[])
{
    return  argc != 1 ? printf("Please input 1 command line argument only\n") : keyToDifference(argv[1]);
}

string keyToDifference(char key[])
{
    int i = 0;
    int keyLetterDifference[];
    while (key[i] != '\0')
    {
        keyLetterDifference[i] = tolower(key[i] - 97 + i);
        i++;
    }
    return getInputAndEncrypt(keyLetterDifference);
}

string getInputAndEncrypt(int keyLetterDifference[])
{
    int i = 0;
    string cipherText;
    string plainText = get_string("plaintext: \n");
    while (plainText[i] != '\0')
    {
        if (tolower(plainText[i]) >= 'a' && tolower(plainText[i]) <= 'z')
        {
            cipherText[i] = plainText[i] + keyLetterDifference[i];
        }
        i++;
    }
    return printOutput(cipherText)
}

int printOutput(string cipherText)
{
    printf("ciphertext: %s\n", cipherText)
    return 0
}