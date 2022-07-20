#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// This function checks if the argument is a number
bool only_digits(string s);
// This function shifts the letter to the specified index
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (!(argc == 2 && only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext:  ");

    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
}

// Fanctions:
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = (c - 'A' + n) % 26 + 'A';
            return c;
        }
        else
        {
            c = (c - 'a' + n) % 26 + 'a';
            return c;
        }
    }
    else
    {
        return c;
    }
}

