#include <stdio.h>
#include <ctype.h> // isalpha function is in here
#include <string.h> // strlen function is in here
#include <math.h> // round off function is in here

int main(void)
{
    // Get text from user
    string text = get_string("Text: \n");

    // Variables for words
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // Checks to see if its uppercase or lowercase letters in ascii
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if ((text[i] == '.') || (text[i] == '?') || (text[i] == '!'))
        {
            sentences++;
        }
    }
    // Calculate Coleman-liau Index
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);


    // Prints grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
