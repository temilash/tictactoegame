
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include <string.h>

/*
 * Intialise game data for a new game
 */

Game *initGame() {

  Game *game;

  //printf("Incorrect parameter values for board size or win length. Exiting\n");

  char boarddef[3][3];
  Game agame;
  game = &agame;


  for(int i = 0; i< 3; i++){

    for(int k = 0; k<3; k++){

        boarddef[i][k] = '.';
    }
  }
  for(int i = 0; i< 3; i++){

    for(int k = 0; k<3; k++){

        game->board[i][k] = boarddef[i][k];
    }
  }
  game->boardSize = 3;
  game->turns = 0;
  game->maxTurns = 9;
  game->winLength = 3;



  return game;
}


