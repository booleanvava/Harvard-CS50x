#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// We want to create a cypher substitution. Taking an argument made of 26 letters and transform it into a cypher for our "plaintext" variable.

char *cipher(string text, string key[]); // This is the prototype function for the decyphering code.
int loweralphabet[26], upperalphabet[26];

int main(int argc, string key[])
{

    for (int l = 0; l < 26; l++) // Generate two arrays which contain the ASCII integers associated with the letters of the alphabet.
    {
        loweralphabet[l] = 97 + l; // 97 is a, and with each increment of i, we get to the next number associated to the next letter of the alphabet.
        upperalphabet[l] = 65 + l; // Same as above, but for uppercase.
    }

    if (argc != 2) // Checking if the user inputted the correct number of arguments (1).
    {
        printf("Please enter a 26 characters long key on the command line. Provide ONE CLA. \n");
        return 1;
    }
    else if (strlen(key[1]) != 26) // If the key inserted by the user is not 26 characters long, return an error (1).
    {
        printf("Your key needs to be 26 characters long.\n ");
        return 1;
    }
    else  // Checking each element from the key for being an alphabetic character with the isalpha function.
    {
        for (int j = 0; j < 26; j++)
        {
            if (isalpha(key[1][j]) == 0)
            {
                printf("You entered an illegal character.\n");
                return 1;
            }
        }

    }

    for (int q = 0; q < 26; q++) // Checking for duplicates. We do this using a double loop.
    {
        for (int w = q + 1; w < 27; w++)
        {
            if (key[1][q] == key[1][w])
            {
                return 1;
            }
        }
    }




    string plaintext = get_string("plaintext: "); // The plaintext variable we want to convert into a ciphered text.
    printf("ciphertext: %s\n", cipher(plaintext, key)); // Calling the function we made later in the code. It needs the text to decipher (in this case, plaintext), and a key to decipher it with (in this case, key).
    return 0; // 0 means that there were no errors.

}

char *cipher(string text, string key[]) // We initialise it as type char * for avoiding complications with the memory types.
{
    string dkey = key[1];
    string dtext = malloc(strlen(text) + 1); // We need to tell the computer to allocate some memory (the length of our text to decipher, plus one for the final "/0"). If we do not do this, we will get an error when trying to append the dtext[n] part of the memory.

    for (int i = 0; i < strlen(text); i++) // Again, we use a double loop to alter the dtext variable. The end goal is to transform the text into a ciphered version fo itself using the key provided by the user.
    {
        for (int j = 0; j < 26; j++) // Same principle as the double loop from above. For each character from the text, if the character from the text is found in one of the alphabets, add one character from the alphabetical coinciding key character (j) into the dtext variable at the coinciding memory location (i).
        {
            if (text[i] == upperalphabet[j])
            {
                dtext[i] = dkey[j];
            }
            else if (text[i] == loweralphabet[j])
            {
                dtext[i] = dkey[j];
            }
            else if (isalpha(text[i]) == 0) // If the character is not in the alphabet, just append dtext with the coinciding text character.
            {
                dtext[i] = text[i];
            }
        }

    }

    for (int k = 0; k < strlen(text); k++) // The ciphering needs to be case insensitive. Verifying if the coinciding characters are properly cased and changing them accordingly.
    {
        bool boolupper = isupper(text[k]);
        bool boolower = islower(text[k]);
        if (boolupper == 1)
        {
            dtext[k] = toupper(dtext[k]);
        }
        else if (boolower == 1)
        {
            dtext[k] = tolower(dtext[k]);
        }

    }

    return dtext; // The final product of our work.

}
