
#include <stdio.h>
#include <stdlib.h>

#include "game.h"

/*
 * main function: program entry point
 */

int main(int argc, char *argv[])
{


    Game *game; // pointer for the game structure
    Game agame2;
    game = &agame2;

    printf("lol");

    if(argv[1] == NULL)
    {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return;
    }
    if(argv[2] == NULL)
    {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return;
    }


    int bs = atoi(argv[1]);

    int len = atoi(argv[2]);


    Game *help = initGame(bs, len);

    for (int i = 0; i < game->boardSize; i++)
    {

        for (int k = 0; k < game->boardSize; k++)
        {

            agame2.board[i][k] = help->board[i][k];
        }
    }
    game->boardSize = bs;
    game->turns = 0;
    game->winLength = len;
    game->maxTurns = bs * bs;

    playGame(game);

    free(game); // free heap memory that was used

    return 0;
}
