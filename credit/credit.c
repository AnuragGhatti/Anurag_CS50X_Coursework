#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number = get_long("Number: ");

    int luhn_sum = 0;         // sum of digits used in luhn's algorithm
    int digits;               // iterates through each digit in the card number
    int count = 0;            // counts the number of digits in the number
    int first_two_digits = 0; // first 2 digits of the card number
    int first_digit = 0;      // first digit of the card number

    while (card_number > 0) // iterates through card number
    {
        digits = card_number % 10; // checks last digit

        if (count % 2 == 0) // checks if digit even
        {
            luhn_sum = luhn_sum + digits;
        }
        else if (count % 2 != 0) // if not even
        {
            int odd_product = digits * 2; // doubles the 2nd last digits
            luhn_sum += (odd_product / 10) + (odd_product % 10); // adds to the luhn_sum(divided a two digit #)
        }

        if (card_number < 100 && card_number >= 10) // checks if there are only 2 remaining digits
        {
            first_two_digits = card_number;
        }
        if (card_number < 10 && card_number > 0) // checks if there is only 1 remaining digit
        {
            first_digit = card_number;
        }

        card_number /= 10;
        count++;
    }

    if (luhn_sum % 10 != 0) // checks if checksum is valid
    {
        printf("INVALID\n");
        return 0;
    }

    if (count == 15 && (first_two_digits == 34 || first_two_digits == 37)) // American Express
    {
        printf("AMEX\n");
        return 0;
    }
    else if (count == 16 &&
             (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 ||
              first_two_digits == 54 || first_two_digits == 55)) // Mastercard
    {
        printf("MASTERCARD\n");
        return 0;
    }
    if ((count == 13 || count == 16) && first_digit == 4) // Visa
    {
        printf("VISA\n");
        return 0;
    }
    else // All other scenarios
    {
        printf("INVALID\n");
        return 0;
    }
}
