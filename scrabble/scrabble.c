#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int player_one_points = 0;
    int player_two_points = 0;
    int alphabet_score[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                            1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string player_one = get_string("Player 1: ");
    string player_two = get_string("Player 2: ");

    string words[2];
    words[0] = player_one;
    words[1] = player_two;

    int first_length = strlen(player_one);
    int second_length = strlen(player_two);

    for (int i = 0; i < first_length; i++)
    {
        if (isalpha(player_one[i]))
        {
            int location = toupper(player_one[i]) - 'A';
            player_one_points += alphabet_score[location];
        }
    }

    for (int i = 0; i < second_length; i++)
    {
        if (isalpha(player_two[i]))
        {
            int location = toupper(player_two[i]) - 'A';
            player_two_points += alphabet_score[location];
        }
    }

    if (player_one_points > player_two_points)
    {
        printf("Player 1 wins!\n");
        return 0;
    }
    else if (player_one_points < player_two_points)
    {
        printf("Player 2 wins!\n");
        return 0;
    }
    else
    {
        printf("Tie!\n");
        return 0;
    }
}
