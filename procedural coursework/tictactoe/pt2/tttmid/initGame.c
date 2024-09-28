
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

  Game *game;

  // for incorrect boardSize or winLength you should return a NULL pointer
  if(winLength>boardSize)
  {
      printf("Incorrect parameter values for board size or win length. Exiting\n");
      return NULL;
  }
  else if(boardSize < 3)
  {
      printf("Incorrect parameter values for board size or win length. Exiting\n");
      return NULL;
  }
  else if(winLength < 3)
  {
      printf("Incorrect parameter values for board size or win length. Exiting\n");
      return NULL;
  }
  else if(boardSize>8)
  {
      printf("Incorrect parameter values for board size or win length. Exiting\n");
      return NULL;
  }



  char boarddef[8][8];
  Game agame;
  game = &agame;
 //setting initial values
  for(int i = 0; i< boardSize; i++){

    for(int k = 0; k<boardSize; k++){

        boarddef[i][k] = '.';
    }
  }
  for(int i = 0; i< boardSize; i++){

    for(int k = 0; k<boardSize; k++){

        game->board[i][k] = boarddef[i][k];//set pointer is equal to
    }
  }
  game->boardSize = boardSize;
  game->turns = 0;
  game->maxTurns = boardSize*boardSize;
  game->winLength = winLength;




  return game;
}




