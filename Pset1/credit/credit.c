#include <cs50.h>
#include <stdio.h>

/**
 * @brief Reports whether a credit card has a valid American Express, MasterCard, or Visa card number.
 * 
 * @param cardNum 
 * @return char AMEX or MASTERCARD or VISA or INVALID
 */
char *credit(long cardNum);

/**
 * @brief Checks if credit card's number is valid
 * 
 * @param cardNumber credit card number
 * @return true if credit card number is valid, otherwise false
 */
bool isValidCard(long cardNumber);

/**
 * @brief Checks the length (number of digits) of long number
 * 
 * @param n long number
 * @return int n length
 */
int numLength(const long n);

/**
 * @brief Get the first digit of long number
 * 
 * @param n
 * @return int 
 */
int getFirstDigit(long n);

int main(void)
{
    long cardNum = get_long("Number: ");
    printf("%s\n", credit(cardNum));
}

char *credit(long cardNum)
{
    if (isValidCard(cardNum))
    {
        int firstDigit = getFirstDigit(cardNum);
        int secondDigit = (cardNum / 10) % 10;
        int cardNumLength = numLength(cardNum);
        return cardNumLength == 15 && firstDigit == 3 && secondDigit == 7 || secondDigit == 4   ? "AMEX"
               : firstDigit == 5 && secondDigit >= 1 && secondDigit <= 5 && cardNumLength == 16 ? "MASTERCARD"
               : cardNumLength == 13 || cardNumLength == 16 && firstDigit == 4                  ? "VISA"
                                                                                                : "INVALID";
    }

    return "INVALID";
}

bool isValidCard(long cardNum)
{
    int cardNumLength = numLength(cardNum);
    if (cardNumLength < 13 || cardNumLength > 16 || cardNumLength == 14)
        return false;

    int digitsSum = 0, multipliedProductsSum = 0, i = 0;

    while (i <= cardNumLength)
    {
        int temp = cardNum % 10;

        if (i % 2 == 0)
            digitsSum += temp; // The sum of the digits that weren’t multiplied by 2.

        else if (temp * 2 >= 10)                        // Multiply every other digit by 2, starting with the number’s second-to-last digit,
            multipliedProductsSum += temp * 2 % 10 + 1; // and then add those products’ digits together.
        else
            multipliedProductsSum += (temp * 2);
        cardNum = cardNum / 10;
        i++;
    }
    return (digitsSum + multipliedProductsSum) % 10 == 0; // If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
}

int numLength(const long n)
{
    if (n < 10)
        return 1;
    return 1 + numLength(n / 10);
}

int getFirstDigit(long n)
{
    while (n >= 10)
        n /= 10;
    return n;
}