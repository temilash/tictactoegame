
#include <stdio.h>

#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {

  int validh = 0;//variables to check whether winner has been found
  int validv = 0;
  int validdl = 0;
  int validdr = 0;


  for(int p = 0; p<game->boardSize; p++)
  {


      for(int q = 0; q<game->boardSize; q++)
      {//finding each element in board
          validh = 0;
          validv = 0;

          if(p+game->winLength <= game->boardSize)
          {//making sure the winlength wouldnt be out of the board

            for(int t = 0; t<game->winLength; t++)//iterate through each element for a length of winlength
            {
                if(game->board[p+t][q] == symbol)//if element is equal to symbol
                {
                    validv++;
                }

            }

            if(validv == game->winLength)// if there is a suitable number in a row
            {
                return 1;//winner found
            }

          }
          if(q+game->winLength <= game->boardSize)//iterate through each element for a length of winlength
          {

            for(int t = 0; t<game->winLength; t++)
            {

                if(game->board[p][q+t] == symbol)//if element is equal to symbol
                {
                    validh++;
                }

            }

            if(validh == game->winLength)
            {
                return 1;
            }
          }
      }
  }
  for(int p = 0; p<game->boardSize; p++)
  {

      for(int q = 0; q<game->boardSize;q++)
      {

          validdl = 0;
          validdr = 0;
          if(q+game->winLength <= game->boardSize && p+game->winLength <= game->boardSize)//checking diagonals
          {//making sure the winlength wouldnt be out of the board

            for(int t = 0; t<game->winLength; t++)
            {

                if(game->board[p+t][q+t] == symbol)
                {
                    validdr++;
                }

            }
            if(validdr == game->winLength)
            {
                return 1;
            }
          }
          if(q-game->winLength >= -1 && p+game->winLength <= game->boardSize)
          {//finding other diagonal
            for(int t = 0; t<game->winLength; t++)
            {
                if(game->board[p+t][q+t] == symbol)
                {
                    validdl++;
                }

            }
            if(validdl == game->winLength)
            {
                return 1;
            }
          }
      }
  }



  return 0;  // continue
}

// test for a draw
int drawGame( Game *game ) {

  if(winGame(game,'X') == 0 && winGame(game,'X') == 0 && game->turns == game->maxTurns)
  {
      return 1;
  }

  return 0; // continue
}



