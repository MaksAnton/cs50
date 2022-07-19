#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// This function counts the number of letters
int count_letters(string text);
// This function counts the number of words
int count_words(string text);
// This function counts the number of sentences
int count_sentences(string text);
//This function calculates the grade
int grade_calculation(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentences(text);

    int index = grade_calculation(letters, words, sentences);


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

// Functions
int count_letters(string text)
{
    int res = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            res++;
        }
    }
    return res;
}

int count_words(string text)
{
    int res = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            res++;
        }
    }
    return res;
}

int count_sentences(string text)
{
    int res = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            res++;
        }
    }
    return res;
}

int grade_calculation(int letters, int words, int sentences)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    float res = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(res);
    return index;
}

