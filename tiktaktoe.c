#include<stdio.h>
#include<stdlib.h>		//for using screen clear function

//array to store the responses
char board[3][3]={'-','-','-',
				  '-','-','-',
				  '-','-','-'};

int gameover = 0;
int rowth=0;		//theoritical row
int colth=0;		//theoritical column
int i=1;
int r;				//actual row
int c;				//actual column

void draw(){			//main game cross screen 
	printf("\n\n\n\n\n\n\t\t\t\t\t##########################\n");
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##   %c  ##   %c  ##   %c  ##\n",board[0][0],board[0][1],board[0][2]);
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##########################\n");
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##   %c  ##   %c  ##   %c  ##\n",board[1][0],board[1][1],board[1][2]);
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##########################\n");
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##   %c  ##   %c  ##   %c  ##\n",board[2][0],board[2][1],board[2][2]);
				printf("\t\t\t\t\t##      ##      ##      ##\n");
				printf("\t\t\t\t\t##########################\n\n\n");
				printf("\t\t\t\t\tPLAYER 1 = X    PLAYER 2 = O \n");
}

void player(){			//show player turn and take input from player
	printf("\n\n\n\t\t\t\t############################################\n");
		  printf("\t\t\t\t#            Player %d turn                 #\n",i);
		  printf("\t\t\t\t#                                          #\n");
		  printf("\t\t\t\t#     Enter the row you want to mark       #\n");
		  printf("\t\t\t\t#               row = ");
		  scanf("%d",&rowth);
		  printf("\t\t\t\t#                                          #\n");
		  printf("\t\t\t\t#      Enter the row you want to mark      #\n");
		  printf("\t\t\t\t#               col = ");
		  scanf("%d",&colth);
		  printf("\t\t\t\t#                                          #\n");
		  printf("\t\t\t\t############################################");
		  }

void response(){ 		//validates the response from the player and save it in array
	 r = rowth-1;
     c = colth-1;
    int er;
	if(r<=2 && c<=2){
				if (board[r][c] != 'X' && board[r][c] != 'O')	{
							if (i==1)
							{board[r][c]='X';
							    i = 2; }
							 
							else if (i==2)
							{board[r][c]='O';
								i = 1; }
							 
				}
				else 	{
					printf("\n\t\t\t\t ERROR = already occupied.....\n\t\t\t\t Press any INTEGER to resume..");
					scanf("%d",&er);
				}
	}
	else {
				printf("\n\t\t\t\t ERROR = Invlid Choice.....\n\t\t\t\t Press any INTEGER to resume..");
				scanf("%d",&er);
	}
}

void winner(){ 			//winner screen
	system("cls");
	draw();
	     if (i==1) i=2;
	else if (i==2) i=1;
	printf("\n\n\n\t\t\t\t############################################\n");
		  printf("\t\t\t\t##           CONGRATULATIONS !!           ##\n");
		  printf("\t\t\t\t##                                        ##\n");
		  printf("\t\t\t\t##         PLAYER %d WON THE MATCH         ##\n",i);
		  printf("\t\t\t\t##                                        ##\n");
		  printf("\t\t\t\t############################################\n");
		  
		  gameover = 1 ;
}

void gamedraw(){		//gameover screen
	system("cls");
	draw();
	printf("\n\n\n\t\t\t\t############################################\n");
		  printf("\t\t\t\t##            !!!! ERROR !!!!             ##\n");
		  printf("\t\t\t\t##                                        ##\n");
		  printf("\t\t\t\t##               GAME DRAW                ##\n");
		  printf("\t\t\t\t##                                        ##\n");
		  printf("\t\t\t\t############################################\n");
		  gameover = 1 ;
}

void checkwinner(){		//cheak winner's winning and gamedraw possibilities
						 if(board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X') winner();
					else if(board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X') winner();
					else if(board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X') winner();
					else if(board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X') winner();
					else if(board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X') winner();
					else if(board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X') winner();
					else if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X') winner();
					else if(board[2][0]=='X' && board[1][1]=='X' && board[0][2]=='X') winner();

					else if(board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O') winner();
					else if(board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O') winner();
					else if(board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O') winner();
					else if(board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O') winner();
					else if(board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O') winner();
					else if(board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O') winner();
					else if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O') winner();
					else if(board[2][0]=='O' && board[1][1]=='O' && board[0][2]=='O') winner();
					
					else if(	(board[0][0]=='X'|| board[0][0]=='O') && (board[0][1]=='X'|| board[0][1]=='O') && (board[0][2]=='X'|| board[0][2]=='O')&&
					            (board[1][0]=='X'|| board[1][0]=='O') && (board[1][1]=='X'|| board[1][1]=='O') && (board[1][2]=='X'|| board[1][2]=='O')&&
							    (board[2][0]=='X'|| board[2][0]=='O') && (board[2][1]=='X'|| board[2][1]=='O') && (board[2][2]=='X'|| board[2][2]=='O')      ){ gamedraw();}
}

int main(){
	while (gameover == 0){
			system("cls");
			draw();
			player();
			response();
			checkwinner();
			}
	return 0;
}
