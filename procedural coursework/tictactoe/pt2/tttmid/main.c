
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "playGame.h"
#include "initGame.h"

/*
 * main function: program entry point
 */

int main(int argc, char *argv[])
{


    Game *game; // pointer for the game structure
    Game agame2;
    game = &agame2;
    Game *help;

    if(argv[1] == NULL)//checking that the user has passed in arguments using command line
    {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return 0;
    }
    if(argv[2] == NULL)
    {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return 0;
    }


    int bs = atoi(argv[1]);//converting char to integer

    int len = atoi(argv[2]);


    help = initGame(bs, len);

    if(help == NULL)
    {
        return 0;//if input invalid exit
    }

    for (int i = 0; i < game->boardSize; i++)
    {

        for (int k = 0; k < game->boardSize; k++)
        {

            agame2.board[i][k] = help->board[i][k];//making board
        }
    }
    game->boardSize = bs;//setting values
    game->turns = 0;
    game->winLength = len;
    game->maxTurns = bs * bs;

    playGame( game );


    return 0;
}
