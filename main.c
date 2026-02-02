#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"


int main() {
    Type *types = malloc(sizeof(Type) * 18);
    Move *moves = malloc(sizeof(Move) * 486);
    Pokemon *pokemons = malloc(sizeof(Pokemon) * 1015);

    Player player1, player2;

 

    initialize(types, moves, pokemons, &player1, &player2);
   
    
    game(&player1, &player2, types);

    free(types);
    free(moves);
    free(pokemons);

    return 0;
}