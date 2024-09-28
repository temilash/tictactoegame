
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"
#include <string.h>

/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {


  Game *game ; // pointer for the game structure
  Game agame2;
  game = &agame2;

  Game *help = initGame();

  for(int i = 0; i< 3; i++){

    for(int k = 0; k<3; k++){

        agame2.board[i][k] = help->board[i][k];
    }
  }
  game->boardSize = help->boardSize;
  game->turns = help->turns;
  game->winLength = help->winLength;
  game->maxTurns = help->maxTurns;



  playGame(game);

  // play a full game


  return 0;
}

