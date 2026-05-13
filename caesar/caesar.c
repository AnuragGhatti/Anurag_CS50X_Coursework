#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit((unsigned char) argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    long key_long = strtol(argv[1], NULL, 10);
    int k = (int) (key_long % 26);

    string p = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        char c = p[i];

        if (isupper((unsigned char) c))
        {
            char rotated = (char) (((c - 'A' + k) % 26) + 'A');
            printf("%c", rotated);
        }
        else if (islower((unsigned char) c))
        {
            char rotated = (char) (((c - 'a' + k) % 26) + 'a');
            printf("%c", rotated);
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
