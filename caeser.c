#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Checking if there is only 1 arguments and it is a number
    if (argc != 2)
    {
        // Remind user to use key number
        printf("Usage: ./caesar key\n");
        // Exit command
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            // Remind user to use key number
            printf("Usage: ./caesar key\n");
            // Exit command for error
            return 1;
        }


    }
    int k = atoi(argv[1]);
    // Ask for unencrypted text
    string plaintext = get_string("plaintext: ");
    // Prints encryted text
    printf("ciphertext: ");


    for (int j = 0; j < strlen(plaintext); j++)
    {
        // Handles upper case letters
        if (isupper(plaintext[j]))
        {
            printf("%c", (((plaintext[j] + k) - 65) % 26) + 65);
        }
        // Handles lower case letters
        else if (islower(plaintext[j]))
        {
            printf("%c", (((plaintext[j] + k) - 97) % 26) + 97);
        }
        // Print everything as is
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");

}
