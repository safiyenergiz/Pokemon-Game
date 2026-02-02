#include <stdio.h>
#include <string.h>
#include "structs.h"
#include <math.h>
#include <stdlib.h>
// gcc -Wall -Werror -Wextra *.c -o project
// ./project
void game(Player *player1, Player *player2, Type type[])
{
    int roundnumber = 1;

    char playerName1[MAX_NAME_LEN];
    char playerName2[MAX_NAME_LEN];

    printf("Enter player name: \n ");
    scanf("%s", playerName1);

    printf("Enter player name: \n ");
    scanf("%s", playerName2);

    strcpy(player1->name, playerName1);

    strcpy(player2->name, playerName2);
    while (
        ((player1->team[0].currentHP > 0 || player1->team[1].currentHP > 0 || player1->team[2].currentHP > 0 || player1->team[3].currentHP > 0 || player1->team[4].currentHP > 0 || player1->team[5].currentHP > 0)) &&
        (player2->team[0].currentHP > 0 || player2->team[1].currentHP > 0 || player2->team[2].currentHP > 0 || player2->team[3].currentHP > 0 || player2->team[4].currentHP > 0 || player2->team[5].currentHP > 0))
    {
        roundD(player1, player2, type, roundnumber);
        roundnumber++;
    }
    if (player1->team[0].currentHP <= 0 && player1->team[1].currentHP <= 0 && player1->team[2].currentHP <= 0 && player1->team[3].currentHP <= 0 && player1->team[4].currentHP <= 0 && player1->team[5].currentHP <= 0)
    {
        printf("%s won this fight", player2->name);
    }
    else if (player2->team[0].currentHP <= 0 && player2->team[1].currentHP <= 0 && player2->team[2].currentHP <= 0 && player2->team[3].currentHP <= 0 && player2->team[4].currentHP <= 0 && player2->team[5].currentHP <= 0)
    {
        printf("%s won this fight", player1->name);
    }
}
void roundD(Player *player1, Player *player2, Type type[], int roundnumber)
{

    printf("\n---  ROUND %d  ---\n", roundnumber);
    fflush(stdout);
    printf("%s your current Pokemon: %s current HP: %d \n ", player1->name, player1->team[player1->currentIndex].name, player1->team[player1->currentIndex].currentHP);
    printf("enter your choise : %s  \n 1-Attack 2-Change Pokemon \n ", player1->name);

    int choose1;
    int moves1;
    int changeChoose;
    int realpokemon[6];

    scanf("%d", &choose1);

    while (choose1 < 1 || choose1 > 2) // control of the player 1 choise
    {
        printf("%s pleas select 1 or 2 \n", player1->name);
        scanf("%d", &choose1);
        if (choose1 == 1 || choose1 == 2)
        {
            break;
        }
    }

    printf("%s your current Pokemon: %s current HP: %d \n ", player2->name, player2->team[player2->currentIndex].name, player2->team[player2->currentIndex].currentHP);
    printf("enter your choise : %s  \n 1-Attack 2-Change Pokemon \n ", player2->name);
    int choose2;
    int moves2;
    int changeChoose1;
    int realpokemon1[6];
    scanf("%d", &choose2);

    while (choose2 < 1 || choose2 > 2) // control of the player 2 choise
    {
        printf("pleas select 1 or 2 \n");
        scanf("%d", &choose2);
        if (choose2 == 1 || choose2 == 2)
        {
            break;
        }
    }
    //------------------------------------------------------- player1 choise
    if (choose1 == 1) // attack
    {
        printf("MOVES\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d - %s\t ", (i + 1), player1->team[player1->currentIndex].moves[i].name);
            if ((i + 1) % 2 == 0)
            {
                printf("\n");
            }
        }
        printf("Choose one move %s: \n", player1->name);
        scanf("%d", &moves1);
        while (moves1 < 1 || moves1 > 4) // control of the correct move
        {
            printf("Player1 pleas select between 1 - 4\n");
            scanf("%d", &moves1);
            if (moves1 == 1 || moves1 == 2 || moves1 == 3 || moves1 == 4)
            {
                break;
            }
        }
    }
    else if (choose1 == 2) // change
    {
        printf("\t POKEMONS:\n");
        int printed = 0;

        for (int i = 0; i < 6; i++)
        {
            if (player1->team[i].currentHP > 0)
            {
                printf("%d - %s\t ", (printed + 1), player1->team[i].name);
                realpokemon[printed] = i;
                printed++;

                if (printed % 2 == 0)
                {
                    printf("\n");
                }
            }
        }
        printf("\n choose one pokemon 1-%d \n", printed);
        scanf("%d", &changeChoose);

        if (changeChoose <= 0 || changeChoose > printed)

        {
            while (1)
            {
                printf("\npleas choose one pokemon 1-%d \n", printed);
                scanf("%d", &changeChoose);
                if (changeChoose > 0 && changeChoose < printed + 1)
                {
                    changeChoose = realpokemon[changeChoose - 1]; // indeks kaymasını printlerken bastığımız pokemonları bir arrayde kaydederek bu şekilde çözğüyoruz
                    break;
                }
            }
        }
        else
        {
            if (changeChoose > 0 && changeChoose < printed + 1)
            {
                changeChoose = realpokemon[changeChoose - 1];
            }
        }
    }
    //----------------------------------------------------------------------------------------------player 2 choise

    if (choose2 == 1) // ifplayer2 choise attack
    {
        printf("MOVES\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d - %s\t ", (i + 1), player2->team[player2->currentIndex].moves[i].name);
            if ((i + 1) % 2 == 0)
            {
                printf("\n");
            }
        }
        printf("Choose one move %s: \n", player2->name);
        scanf("%d", &moves2);
        while (moves2 < 1 || moves2 > 4) // control of the correct move
        {
            printf("pleas select between 1 - 4 \n");
            scanf("%d", &moves2);
            if (moves2 == 1 || moves2 == 2 || moves2 == 3 || moves2 == 4)
            {
                break;
            }
        }
    }
    //--------------------------------------------------------------
    else if (choose2 == 2) // ifplayer2 choise change
    {
        printf("\t POKEMONS:\n");
        int printed = 0;

        for (int i = 0; i < 6; i++)
        {
            if (player2->team[i].currentHP > 0)
            {
                printf("%d - %s\t ", (printed + 1), player2->team[i].name);
                realpokemon1[printed] = i;
                printed++;

                if (printed % 2 == 0)
                {
                    printf("\n");
                }
            }
        }
        printf("\nchoose one pokemon 1-%d \n", printed);
        scanf("%d", &changeChoose1);

        if (changeChoose1 <= 0 || changeChoose1 > printed)

        {
            while (1)
            {
                printf("\npleas choose one pokemon 1-%d \n", printed);
                scanf("%d", &changeChoose1);
                if (changeChoose1 > 0 && changeChoose1 < printed + 1)
                {
                    changeChoose1 = realpokemon1[changeChoose1 - 1]; // indeks kaymasını printlerken bastığımız pokemonları bir arrayde kaydederek bu şekilde çözğüyoruz
                    break;
                }
            }
        }
        else
        {
            if (changeChoose1 > 0 && changeChoose1 < printed + 1)
            {
                changeChoose1 = realpokemon1[changeChoose1 - 1];
            }
        }
    }
    //--------------------------------------------------------------------------------- player1 and player2 compare choises
    if (choose1 == 1 && choose2 == 1) // if two sides choise attack
    {
        if (player1->team[player1->currentIndex].speed > player2->team[player2->currentIndex].speed) // control of the speed
        {

            if (attack(player1, player2, moves1, type) == 0) // defender is not fainted so its attak for defender
            {
                attack(player2, player1, moves2, type);
            }
            else
            {
                return;
            }
        }
        else if (player1->team[player1->currentIndex].speed < player2->team[player2->currentIndex].speed) // if player 2 speed > player1
        {

            if (attack(player2, player1, moves2, type) == 0) // defender is not fainted so its attak for defender
            {
                attack(player1, player2, moves1, type);
            }
            else
            {
                return;
            }
        }
        else if (player1->team[player1->currentIndex].speed == player2->team[player2->currentIndex].speed) // if speeds equal random
        {
            int r = rand() % 2; // 0-1
            if (r == 1)
            {
                if (attack(player1, player2, moves1, type) == 0) // defender is not fainted so its attak for defender
                {
                    attack(player2, player1, moves2, type);
                }
                else
                {
                    return;
                }
            }
            else
            {
                if (attack(player2, player1, moves2, type) == 0) // defender is not fainted so its attak for defender
                {
                    attack(player1, player2, moves1, type);
                }
                else
                {
                    return;
                }
            }
        }
    }
    else if (choose1 == 1 && choose2 == 2) // one side attack one side change
    {
        if (attack(player1, player2, moves1, type) == 0)
        {
            change(player2, changeChoose1);
        }
        else
        {
            return;
        }
    }
    else if (choose1 == 2 && choose2 == 1) // one side attack one side change
    {
        if (attack(player2, player1, moves2, type) == 0)
        {
            change(player1, changeChoose);
        }
        else
        {
            return;
        }
    }
    if (choose1 == 2 && choose2 == 2) // both side change
    {
        change(player1, changeChoose);
        change(player2, changeChoose1);
    }
}
int attack(Player *player1, Player *player2, int moves1, Type type[])
{
    float damage = 0.0;

    if (player1->team[player1->currentIndex].moves[moves1 - 1].category == SPECIAL) // if player 1 atack special
    {
        damage = (float)player1->team[player1->currentIndex].moves[moves1 - 1].power * ((float)player1->team[player1->currentIndex].spAtk / (float)player2->team[player2->currentIndex].spDef) * findefective(player1, player2, moves1 - 1, type); // SPEACİAL ATACK
        player2->team[player2->currentIndex].currentHP = player2->team[player2->currentIndex].currentHP - damage;

        if (player2->team[player2->currentIndex].currentHP >= 0)
        {
            printf("%s  dealt %.0f damage to %s current health is  %d \n", player1->team[player1->currentIndex].name, damage, player2->team[player2->currentIndex].name, player2->team[player2->currentIndex].currentHP); // player2 pokemon current hp  azaldı
        }
        else
        {
            printf("%s  dealt %.0f damage to %s current health is  0 \n", player1->team[player1->currentIndex].name, damage, player2->team[player2->currentIndex].name); // player2 pokemon current hp  azaldı
        }
    }
    else if (player1->team[player1->currentIndex].moves[moves1 - 1].category == PHYSICAL) // ifplayer1 attack physical
    {
        damage = (float)player1->team[player1->currentIndex].moves[moves1 - 1].power * ((float)player1->team[player1->currentIndex].attack / (float)player2->team[player2->currentIndex].defense) * findefective(player1, player2, moves1 - 1, type); // PHYSİCAL ATACK
        player2->team[player2->currentIndex].currentHP = player2->team[player2->currentIndex].currentHP - damage;
        if (player2->team[player2->currentIndex].currentHP >= 0)
        {
            printf("%s  dealt %.0f damage to %s current health is  %d \n", player1->team[player1->currentIndex].name, damage, player2->team[player2->currentIndex].name, player2->team[player2->currentIndex].currentHP); // player2 pokemon current hp  azaldı
        }
        else
        {
            printf("%s  dealt %.0f damage to %s current health is  0 \n", player1->team[player1->currentIndex].name, damage, player2->team[player2->currentIndex].name); // player2 pokemon current hp  azaldı
        }
    }
    if (player2->team[player2->currentIndex].currentHP <= 0)
    {
        change(player2, -1);
        printf("%s your pokemon fainted so automaticly changed your new pokemon:%s \n", player2->name, player2->team[player2->currentIndex].name);
        return 1; // defender fainted for attacer and change automaticly
    }
    return 0; // defender pokemon alive
}

float findefective(Player *player1, Player *player2, int movesindex, Type type[])
{

    float type1effects = 1.0;
    float type2effects = 1.0;
    float stab = 1.0;
    if (strcmp(player1->team[player1->currentIndex].types[0].name, player1->team[player1->currentIndex].moves[movesindex].type.name) == 0 || strcmp(player1->team[player1->currentIndex].types[1].name, player1->team[player1->currentIndex].moves[movesindex].type.name) == 0)
    {
        stab = 1.5;
    }
    else
    {
        stab = 1.0;
    }

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (strcmp(type[i].name, player1->team[player1->currentIndex].types[0].name) == 0 && strcmp(type[i].effects[j].defName, player2->team[player2->currentIndex].types[0].name) == 0)
            {
                type1effects = type[i].effects[j].multiplier;
            }

            if (strcmp(player2->team[player2->currentIndex].types[1].name, "NONE") == 0 || strcmp(player2->team[player2->currentIndex].types[1].name, "-") == 0)
            {
                type2effects = 1.0;
            }
            else if (strcmp(type[i].name, player1->team[player1->currentIndex].types[1].name) == 0 && strcmp(type[i].effects[j].defName, player2->team[player2->currentIndex].types[1].name) == 0)
            {
                type2effects = type[i].effects[j].multiplier;
            }
        }
    }
    return (type2effects * type1effects * stab);
}
int change(Player *player, int changeChoose)
{

    if (changeChoose == -1) //-1 for fainted situation
    {
        for (int i = 0; i < 6; i++)
        {
            if (player->team[i].currentHP > 0)
            {
                player->currentIndex = i;
                return 2; // otamaticly changed
            }
        }
    }
    if (player->team[changeChoose].currentHP > 0)
    {
        player->currentIndex = changeChoose;
        return 1; // normaly changed
    }
    return 0; // hiç pokemon yok → game over
}













