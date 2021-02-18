#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Conditions to print
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    int score = 0;
    int loweralphabet[26], upperalphabet[26];


    for (int i = 0; i < 26; i++) // Generate two arrays which contain the ASCII integers associated with the letters of the alphabet.
    {
        loweralphabet[i] = 97 + i; // 97 is a, and with each increment of i, we get to the next number associated to the next letter of the alphabet.
        upperalphabet[i] = 65 + i; // Same as above, but for uppercase.
    }

    for (int j = 0, le = strlen(word); j < le; j++)
    {
        for (int n = 0; n < 26; n++)
        {
            if (loweralphabet[n] == word[j] || upperalphabet[n] == word[j]) // n verifies the letter in the alphabet, and j verifies for the character in the string. If they match, score the associated point!
            {
                score = score + POINTS[n]; // lower/upperalphabet arrays match the POINTS[] array in terms of points, and thus they will add the correct nr. of points to the final sum.
            }
            else
            {
                score += 0; // Basically do nothing if word[j] does not match any character in lower/upperalphabet arrays.
            }
        }
    }


    return score;
}
