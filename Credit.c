#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool luhnalg(long
             card_number); // Letting the compiler know that there will be a functiong of boolean type named "luhnalg" taking card_number as argument.

int main(void)
{
    long card_number;
    long number_length = 0;
    int length = 0;



    do // Prompting the user to insert a valid card number.
    {
        card_number = get_long("Number: ");
        number_length = card_number;

        while (number_length != 0) // Establish the length of the credit card number.
        {
            number_length /= 10; // Each division by 10 eliminates the last digit from the card number. /= Updates the new value until number_length = 0.
            length++; // With each digit eliminated, we increment the length until there is nothing to divide (when number_length = 0). This way we get the length.
        }

    }
    while (card_number != (long)card_number); // Just checking if our card number has the right format


    if (luhnalg(card_number) == true) // We use the boolean function we wrote at a later stage in the code and check if it is True.
    {
        // Dividing the card number by 1e1x (x depends on the length of the card number) will give us the first two digits.
        int type_16 = card_number / 1e14;
        int type_15 = card_number / 1e13;
        int type_13 = card_number / 1e12; // We divide by 1e12 because we are interested only in the first number for Visa.

        if (length != 16 && length != 15 && length != 13 && card_number == (long)card_number) // Just checking the length.
        {
            printf("INVALID\n");
        }

        // Next, if the lengths are valid (16, 15 or 13), we check if the first two digits (or first digit) of the card number are a valid Mastercard, Visa, or AMEX card.

        else if (length == 16)
        {
            if (type_16 >= 51 && type_16 <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (type_16 >= 40 && type_16 <= 49)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }

        else if (length == 15)
        {
            if (type_15 == 34 || type_15 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (length == 13)
        {
            if (type_13 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

    }
    else // If boolean luhnalg returns 0 (false), the card number is invalid == it didn't pass the luhn algorithm test.
    {
        printf("INVALID\n");
    }

}


bool luhnalg(long card_number) // We declare luhnalg as boolean, because that's all we need to check.
{
    long card_copy =
        card_number; // We assign a new variable which is equal to the card_number, so that we can alterate it without alterating the original.
    int sum1 = 0;

    for (int cd = 0; card_copy > 0; cd++) // cp represents the current digit within the card number.
    {
        if (cd % 2 == 0) // If modulo 2 returns 0, it means that we are looking at an even number.
        {
            sum1 += card_copy % 10; // We add the last digit from the card number to the sum.
            card_copy /= 10; // This way we eliminate the next digit in the card number.
        }
        else // Note that by placing the condition above (if cd % 2 == 0), the else condition automatically means (else if cd % 2 != 0). Thus, the odd positions from the card nr.
        {
            int oddnr = (card_copy % 10) *
                         2; // These are the actual underlined numbers (the odd ones). We multiply by two as dictated in the algorithm.
            sum1 += (oddnr / 10 + oddnr % 10); // We need to add the DIGITS of the products to the sum, not the numbers themselves.
            // Easiest to explain is by example. If one of the products is 24, we need to add 2 and 4 to the final sum.
            // We can return the 2 by dividing 24 / 10, but that would only return the 2 since "oddnr" is an integer.
            // Thus, we need to add the rest (given by the modulo) as well.
            card_copy /= 10; // Same as above
        }
    }
    return (sum1 % 10) ==
            0; // This is the final condition of the algorithm. If last digit (as taken by modulo 10) of the final sum is 0, then the credit card number is valid!
}


