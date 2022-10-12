#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // This is a basic input name program.
    string name = get_string("What's your name? ");
    printf("Hello, %s\n", name);
}
