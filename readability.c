#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int coleminau(string input); // Prototype function, letting the compiler know that it will exist.

int main(void)
{
    string text = get_string("Text: "); // User's input

    int grade = coleminau(text); // Coleman-Linau function explained later

    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

int coleminau(string input) // We output an Integer and ask for a string
{
    int n = strlen(input);
    int sentencecount = 0;
    int wordcount = 1;
    int lettercount = 0;

    for (int i = 0; i < n; i++)
    {
        if (input[i] == 46 || input[i] == 33 || input[i] == 63) // 46, 33, 63 = ".", "!", "?"
        {
            sentencecount += 1; // If we come across these characters, it means we have a sentence.
        }
        else if (input[i] == 32) // 32 = " ", it means we encountered a word. We initiated wordcount at 1 earlier because the first word will not be counted (there will be no space before it).
        {
            wordcount += 1;
        }
        else if (((65 <= input[i]) && (input[i] <= 90)) || ((97 <= input[i]) && (input[i] <= 122))) //The many parantheses are there because of the way in which C interprets "and" and "or" symbols.
        {
            lettercount += 1;
        }
    }

    float L = (float)lettercount * 100.0 / (float)wordcount; // Make everything a float for a proper output.
    float S = (float)sentencecount * 100.0 / (float)wordcount;

    float index = 0.0588 * L - 0.296 * S - 15.8; // Coleman-Linau formula
    return (float) round(index); // That's how we round, and we finally get the rounded Grade index, as we wanted.
}
