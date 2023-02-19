#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char rotate(char a, int key);

int main(int argc, string argv[])
{
    // Making sure that the input has one and only one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Making sure every character in argv[1] is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Converting argv[1] from string to an int
    int k = atoi(argv[1]);

    // Prompting user for plaintext
    string p = get_string("plaintext:  ");

    // Roating characters if letters
    printf("ciphertext: ");
    int sz = strlen(p);
    for (int i = 0; i < sz; i++)
    {
        if (isdigit(p[i]) || (isalnum(p[i]) == 0))
        {
            printf("%c", p[i]);
        }
        else
        {
            printf("%c", rotate(p[i], k));
        }
    }
    printf("\n");
    return 0;
}

char rotate(char a, int key)
{
    int alphacode = 0;

    if (islower(a))
    {
        alphacode = a - 97;
    }
    else if (isupper(a))
    {
        alphacode = a - 65;
    }

    int deff = 25 - alphacode;

    while (key > deff)
    {
        key -= deff;
        alphacode = -1;
        deff = 25 - alphacode;
    }

    int y = alphacode + key;
    if (islower(a))
    {
        y += 97;
    }
    else if (isupper(a))
    {
        y += 65;
    }

    return y;
}