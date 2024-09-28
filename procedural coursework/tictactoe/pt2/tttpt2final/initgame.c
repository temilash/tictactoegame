
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
  }
  if(boardSize < 3)
  {
      printf("Incorrect parameter values for board size or win length. Exiting\n");
  }
  if(winLength < 3)
  {
      printf("Incorrect parameter values for board size or win length. Exiting\n");
  }
  if(boardSize>8)
  {
      printf("Incorrect parameter values for board size or win length. Exiting\n");
  }



  char boarddef[8][8];
  Game agame;
  game = &agame;


  for(int i = 0; i< boardSize; i++){

    for(int k = 0; k<boardSize; k++){

        boarddef[i][k] = '.';
    }
  }
  for(int i = 0; i< boardSize; i++){

    for(int k = 0; k<boardSize; k++){

        game->board[i][k] = boarddef[i][k];
    }
  }
  game->boardSize = boardSize;
  game->turns = 0;
  game->maxTurns = boardSize*boardSize;
  game->winLength = winLength;




  return game;
}



