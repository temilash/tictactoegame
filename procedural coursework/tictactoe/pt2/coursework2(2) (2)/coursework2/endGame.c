
#include <stdio.h>

#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {

  int validh = 0;
  int validv = 0;
  int validdl = 0;
  int validdr = 0;

  for(int i = 0; i<game->boardSize; i++)
  {

      for(int k = 0; k<game->boardSize; k++)
      {
          validh = 0;
          validv = 0;
          validdl = 0;
          validdr = 0;
          if(game->boardSize - k > game->winLength)//checking horizontal values
          {
              printf("hello");
              for(int r = 0; r<game->winLength;r++)
              {
                  if(game->board[i][r+k] == symbol){
                    validh++;
                }
                if(validv == game->winLength )
                {
                    return 1;
                }
              }



          }
          if(game->boardSize - i > game->winLength)//checking vertical values
          {
              for(int r = 0; r<game->winLength;r++)
              {
                  if(game->board[r+k][k] == symbol)
                    {
                        validv++;
                    }
                  if(validh == game->winLength )
                    {
                        return 1;
                    }
              }
          }




          if(i+game->winLength < game->boardSize && k+game->winLength< game->boardSize)
          {
              for( int t = 0; t< game->winLength; t++)
              {
                  if(game->board[i+t][k+t] == symbol)
                  {
                      validdl = 0;
                  }
                  if(validdl == game->winLength)
                  {
                      return 1;
                  }
              }
          }
          if(i + game->winLength < game->boardSize && k - game->winLength > -1)
          {
              for( int t = 0; t< game->winLength; t++)
              {
                  if(game->board[i+t][k-t] == symbol)
                  {
                      validdr = 0;
                  }
                  if(validdl == game->winLength)
                  {
                      return 1;
                  }
              }
          }
      }
      }



  return 0;  // continue
}

// test for a draw
int drawGame( Game *game ) {

  if(winGame(game,'X') == 0 && winGame(game,'X') && game->turns == game->maxTurns)
  {
      return 1;
  }

  return 0; // continue
}

