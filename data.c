#include <stdio.h>
#include <string.h>
#include "structs.h"
#include <stdlib.h>
#include <time.h>


void initializeTypes(Type AllTypes[])
{
    FILE *file = fopen("types.txt", "r"); // read
    if (file == NULL)
    {
        printf(" types.txt cannot find!");
        return;
    }

    char attackingTypeName[MAX_NAME_LEN];

    for (int i = 0; i < MAX_TYPES; i++) // for 18 type
    {

        if (fscanf(file, "%s", attackingTypeName) != 1)
        {

            break;
        }

        strcpy(AllTypes[i].name, attackingTypeName); // save atteck typ name

        for (int j = 0; j < MAX_TYPES; j++) // for 18 multipilier
        {

            char defendingTypeName[MAX_NAME_LEN];
            float multiplier;

            if (fscanf(file, "%s %f", defendingTypeName, &multiplier) != 2)
            {
                break;
            }

            strcpy(AllTypes[i].effects[j].atkName, attackingTypeName); // save effects array
            strcpy(AllTypes[i].effects[j].defName, defendingTypeName);
            AllTypes[i].effects[j].multiplier = multiplier;
        }
    }
    fclose(file);
}
void initializeMoves(Move AllMoves[],Type AllTypes[])
{
    FILE *file = fopen("moves.txt", "r");

    if (file == NULL)
    {
        printf(" moves.txt cannot find!");
        return;
    }
    char name[MAX_NAME_LEN];
    char typec[MAX_NAME_LEN];
    char category[15];
    float power;
    int i = 0;
    while (fscanf(file, "%s %s %s %f", name, typec, category, &power) == 4)
    {
        for (int j = 0; j < 18; j++)
        {
            if (strcmp(AllTypes[j].name, typec) == 0)
            {
                AllMoves[i].type = AllTypes[j];
                break;
            }
        }

        strcpy(AllMoves[i].name, name);

        if (strcmp(category, "Physical") == 0)
            AllMoves[i].category = PHYSICAL;
        else if (strcmp(category, "Special") == 0)
            AllMoves[i].category = SPECIAL;

        AllMoves[i].power = power;
        i++;
    }
    fclose(file);
}

void initializePokemons(Pokemon AllPokemons[],Type AllTypes[],Move AllMoves[])
{
    FILE *file = fopen("pokemon.txt", "r");

    if (file == NULL)
    {
        printf("pokemon.txt cannot find!");
        return;
    }
    char name[MAX_NAME_LEN];
    int maxHP;
    int attack;
    int defense;
    int spAtk;
    int spDef;
    int speed;
    char type1Name[MAX_NAME_LEN];
    char type2Name[MAX_NAME_LEN];
    

    int i = 0;

    while (fscanf(file, "%s %s %s %d  %d %d %d %d %d ", name, type1Name, type2Name, &maxHP, &attack, &defense, &spAtk, &spDef, &speed) == 9 
)
    {

        strcpy(AllPokemons[i].name, name);
        AllPokemons[i].maxHP = maxHP;
        AllPokemons[i].currentHP = maxHP;
        AllPokemons[i].attack = attack;
        AllPokemons[i].defense = defense;
        AllPokemons[i].spAtk = spAtk;
        AllPokemons[i]. spDef = spDef;
        AllPokemons[i].speed = speed;
    

        for (int j = 0; j < MAX_TYPES; j++)
        {
            if (strcmp(AllTypes[j].name, type1Name) == 0)
            {
                AllPokemons[i].types[0] = AllTypes[j];
            }
            if(strcmp( "-" , type2Name)==0 ){
              strcpy(AllPokemons[i].types[1].name, "NONE");

            }
            else if(strcmp(AllTypes[j].name, type2Name) == 0)
            {
                AllPokemons[i].types[1] = AllTypes[j];
            }
        }
        for (int k = 0; k < 6; k++)
     {
       

        int used[4];

        used[0] = rand() % 486;
        do { used[1] = rand() % 486; } while (used[1] == used[0]);
        do { used[2] = rand() % 486; } while (used[2] == used[0] || used[2] == used[1]);
        do { used[3] = rand() % 486; } while (used[3] == used[0] || used[3] == used[1] || used[3] == used[2]);

        for (int z = 0; z < 4; z++)
            AllPokemons[i].moves[z] = AllMoves[used[z]];
     }

       

        i++;
    }
    
    

    fclose(file);
}
void initializePlayers(Player *player1, Player *player2,
                       Pokemon AllPokemons[])
{

    int numbers[12];
    int count = 0;
    srand(time(NULL));
  
    while (count < 12)
    {
        int unique = rand() % 1015; // 0–1014
        int exists = 0;

        for (int i = 0; i < count; i++)
        {
            if (numbers[i] == unique)
            {
                exists = 1;
                break;
            }
        }

        if (!exists)//EXİST==0
        {
            numbers[count++] = unique;
        }
    }
  
   
    for (int i = 0; i < 6; i++)
    {
        player1->team[i] = AllPokemons[numbers[i]];

       
    }

    for (int i = 0; i < 6; i++)
    {
        player2->team[i] = AllPokemons[numbers[i + 6]];

    
    }
   
    player1->currentIndex = 0;
    player2->currentIndex = 0;

}
void initialize(Type types[],
                Move moves[],
                Pokemon pokemons[],
                Player *player1,
                Player *player2)
{
    initializeTypes(types);
    


    initializeMoves(moves, types);
 


    initializePokemons(pokemons, types, moves);
  

    
    initializePlayers(player1, player2, pokemons);
   

  
}


