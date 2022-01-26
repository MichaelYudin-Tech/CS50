#include <cs50.h>
#include <stdio.h>
#include <string.h>

// first we need the variable for the credit card number to be type long
// I want to run through the card digits, but I don't want the original card number to be lost
long Card, CardCheck = 0;
// then I need a variable to count the amount of digits in the credit card number - Digits
// I also need a variable to help me keep track of 'every other digit' for the checksum - i
// 2 more variables to check the first and second digits of the card
// and 2 variables to run the checksum, one for each series of numbers that I am adding togethe
int Digits, i, FirstDigit, SecondDigit, Checksum, Checksum2 = 0;
// a final variable for the card type
string CardType = "INVALID";
// a function to count the digits in the card number
// in this function I am also storing the first two digits of the card and determining it's type
// since I'm already going through all the digits, I'm also going to run a checksum in this function
void Count_Digits(void)
{
    //init to not get errors on back to back runs
    Digits = 0;
    i = 0;
    FirstDigit = 0;
    SecondDigit = 0;
    Checksum = 0;
    Checksum2 = 0;
    CardType = "INVALID";
    CardCheck = Card;
    do
    {
        // on the second to last iteration of the reduction of digits i will be storing the first two digits of the number
        // i'm only storing the CardCheck in FirstDigit when all but the last digit have been reduced from the number in order to not accidentally try to store a long in an int
        if ((CardCheck < 100) && (CardCheck > 10))
        {
            SecondDigit = (CardCheck % 10); // will give me the remainder, i.e. the second digit, e.g. 53 % 10 = 3
            FirstDigit = (CardCheck / 10); // will give me the first digit, e.g. 53 / 10 = 5
            Digits += 2;
            if (i == 0)
            {
                Checksum += ((FirstDigit * 2) / 10) + ((FirstDigit * 2) % 10);
                Checksum2 += SecondDigit;
            }
            else
            {
                Checksum += ((SecondDigit * 2) / 10) + ((SecondDigit * 2) % 10);
                Checksum2 += FirstDigit;
            }
            Checksum += Checksum2;
            break;
        }
        if (i == 0)
        {
            Checksum2 += CardCheck % 10;
            i = 1;
        }
        else
        {
            Checksum += (((CardCheck % 10) * 2) / 10) + (((CardCheck % 10) * 2) % 10);
            i = 0;
        }

        CardCheck /= 10;

        Digits++;
    }
    while ((CardCheck != 0));
    if ((Checksum % 10) == 0)
    {
        switch (FirstDigit)
        {
            case 3:
                if (((SecondDigit == 4) || (SecondDigit == 7)) && (Digits == 15))
                {
                    CardType = "AMEX";
                    break;
                }
                CardType = "INVALID";
                break;

            case 4:
                if ((Digits == 13) || (Digits == 16))
                {
                    CardType = "VISA";
                    break;
                }
                CardType = "INVALID";
                break;

            case 5:
                if (((SecondDigit > 0) && (SecondDigit < 6)) && (Digits == 16))
                {
                    CardType = "MASTERCARD";
                    break;
                }
                CardType = "INVALID";
                break;
        }
    }
    return;
}

int main(void)
{
    // get card number from the user
    do
    {
        Card = get_long("Number: ");
    }
    while ((Card < 0) || (Card > 12345678901234567));
    if ((Card > 123456789012) && (Card < 12345678901234567))
    {
        Count_Digits();
    }
    printf("%s\n", CardType);

}