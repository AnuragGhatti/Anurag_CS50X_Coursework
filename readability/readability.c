#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int letters = 0;
    int sentences = 0;
    int words = 1;

    string text = get_string("Text: ");
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if isalpha (text[i])
        {
            letters++;
        }
        else if (text[i] == '.')
        {
            sentences++;
        }
        else if (text[i] == '!')
        {
            sentences++;
        }
        else if (text[i] == '?')
        {
            sentences++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
    }

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade_level = round(index);

    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}
