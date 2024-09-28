
#include <stdio.h>

#include "game.h"
#include "playGame.h"
#include "endGame.h"
#include "initGame.h"
#include <string.h>

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) {

  char symbols[2] = { 'X','O' };
  // player 'X' plays first
  int valid = 0;


  // starting board
  printf("New game starting\n");

  showGame(game);



  // Your game should be controlled by an outer loop
  // Each pass through the loop is one completed move by a player

  while( game->turns <9 )
  {
      valid = 0;

      // Request a move from the next player and check it is valid (an unused square within the board)
      if( (game->turns) % 2 == 1)//finding which player will be moving
      {
          printf("Player %c: Enter your move as row column values:\n",symbols[1]); // use this to request the player move
      }


      else if((game->turns) % 2 == 0)
      {
          printf("Player %c: Enter your move as row column values:\n",symbols[0]); // use this to request the player move
      }


      while(valid == 0)//making sure user enters valid input by repeating till valid
      {
        int numbers = 0;//number of values
        int checker = 0;//check if alright
        int width = 0;//stores width
        int depth = 0;//stores depth
        int len = 0;//actual length of input
        char buffer[1000];
        int intbuff[1000];
        int intbuff2[] = {0,0};
        // read the players move from the keyboard, expected as two integers coordinates as shown on the board

        for(int i = 0; i<1000; i++)
        {
            buffer[i] = ' ';
            intbuff[i] = -1;
        }

        fgets(buffer,1000,stdin);//getting input
        len = strlen(buffer);

        for(int i = 0; i<sizeof(buffer); i++)
        {
            intbuff[i] = (int)(buffer[i]);//converting array to integers

        }
        for(int k = 0; k<len-1;k++)
            {
                if( intbuff[k] >57 && checker == 0)//if the ascii value is not equal to number print error
                {
                    printf("Move rejected. Please try again\n");
                    checker = 1;
                    continue;
                }
                if(intbuff[k]<48 && intbuff[k] != 32 && checker == 0)
                {
                    printf("Move rejected. Please try again\n");
                    checker = 1;
                    continue;
                }
            }


        for(int k = 0; k<sizeof(intbuff); k++)
        {
            if(k == 0 && intbuff[k] >47 && intbuff[k]< 58)
            {
                numbers++;
            }
            else if(intbuff[k] >47 && intbuff[k]< 58 && intbuff[k-1] == 32){
                numbers++;
            }//finding out how many numbers have been inputed by the user

        }


        if(numbers != 2 && checker == 0)
        {
            printf("Move rejected. Please try again\n");
            checker = 1;
            continue;
        }//if the there are too many numbers print error

        else
        {
            int width_depth = -1;
            for(int k = 0; k<sizeof(intbuff); k++)
            {
                //convert each number to integers and store in array
                if(k == 0 && intbuff[k]>47 && intbuff[k]<58 )
                {
                    width_depth++;
                    intbuff2[width_depth] = (intbuff[k])- 48;
                }
                else if(intbuff[k]>47 && intbuff[k]<58 && intbuff[k-1]>47 && intbuff[k-1]<58 )
                {
                    intbuff2[width_depth] = (intbuff2[width_depth]*10) + ((intbuff[k])- 48);
                }
                else if (intbuff[k]>47 && intbuff[k]<58 && intbuff[k-1] == 32)
                {
                    width_depth++;
                    intbuff2[width_depth] = ((intbuff[k]))- 48;
                }

            }
            width = intbuff2[0];//set array index equal to variables
            depth = intbuff2[1];
        }
        if(checker == 0)//if parameters are ok
        {
            valid = makeMove(game,symbols[(game->turns)%2],width,depth);
        }




      }
      // After each completed move display the board


      showGame(game);

      game->turns = (game->turns)+1;//couting number of turns by users

      // After each valid move you can test for win or draw using functions you implement in endGame.c
      if(winGame(game,'X') == 1)
      {
          printf("Player %c has won\n",symbols[0]);
          return;

      }
      if(winGame(game,'O') == 1)
      {
          printf("Player %c has won\n",symbols[1]);
          return;
      }
       // use to announce a winner - game is over
      if(drawGame(game) == 1)
      {
        printf("Match is drawn\n"); // use to announce a draw - game is over
        return;
      }
  }

  return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {

  printf("\n");
  printf("    ");

  for(int i = 0; i<game->boardSize;i++)
  {
      printf("  %d",i);
  }

  printf("\n");
  printf("\n");


  for(int i = 0; i<game->boardSize; i++)
  {
      printf(" %c  ");
      for(int k = 0; k<game->boardSize; k++)
      {
          printf("  %c",game->board[i][k]);
      }
      printf("\n");
  }


  return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove( Game *game, char symbol,int width,int depth ) {


  // test that the chosen location is a valid empty space
  // if we do not accept the move return 0

  if(width > 2 )//if one of the numbers is too big
      {
         // If the move is invalid you should repeat the request for the current player
         printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move
         return 0;
      }
  else if(depth > 2)
      {
         // If the move is invalid you should repeat the request for the current player
         printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move
         return 0;
      }

  if(game->board[width][depth] != '.')//if the space is already taken
      {
         // If the move is invalid you should repeat the request for the current player
         printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move
         return 0;
      }




  //updating the table when valid
  game->board[width][depth] = symbol;//add symbol to board



   return 1; // move accepted
}

