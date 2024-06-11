#include <stdio.h>
#include <stdlib.h>

char board[3][3] = { {'-', '-', '-'},
                     {'-', '-', '-'},
                     {'-', '-', '-'} };

int gameover = 0;
int currentPlayer = 1;

void draw() {
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\t##########################\n");
    for (int i = 0; i < 3; i++) {
        printf("\t\t\t\t\t##      ##      ##      ##\n");
        for (int j = 0; j < 3; j++) {
            printf("\t\t\t\t\t##   %c  ", board[i][j]);
        }
        printf("##\n");
        printf("\t\t\t\t\t##      ##      ##      ##\n");
        printf("\t\t\t\t\t##########################\n");
    }
    printf("\n\t\t\t\t\tPLAYER 1 = X    PLAYER 2 = O \n");
}

void player() {
    int row, col;
    printf("\n\n\n\t\t\t\t############################################\n");
    printf("\t\t\t\t#            Player %d turn                 #\n", currentPlayer);
    printf("\t\t\t\t#                                          #\n");
    printf("\t\t\t\t#     Enter the row you want to mark       #\n");
    printf("\t\t\t\t#               row = ");
    scanf("%d", &row);
    printf("\t\t\t\t#                                          #\n");
    printf("\t\t\t\t#      Enter the row you want to mark      #\n");
    printf("\t\t\t\t#               col = ");
    scanf("%d", &col);
    printf("\t\t\t\t#                                          #\n");
    printf("\t\t\t\t############################################");
    row--; col--;
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
        if (currentPlayer == 1)
            board[row][col] = 'X';
        else
            board[row][col] = 'O';
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    else {
        printf("\n\t\t\t\t ERROR = Invalid Choice.....\n\t\t\t\t Press any INTEGER to resume..");
        int er;
        scanf("%d", &er);
    }
}

void checkWinner() {
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '-')
        gameover = 1;
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '-')
        gameover = 1;
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '-')
        gameover = 1;
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '-')
        gameover = 1;
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '-')
        gameover = 1;
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '-')
        gameover = 1;
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
        gameover = 1;
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
        gameover = 1;
}

int main() {
    while (!gameover) {
        draw();
        player();
        checkWinner();
    }
    draw();
    printf("\n\n\n\t\t\t\t############################################\n");
    printf("\t\t\t\t##           CONGRATULATIONS !!           ##\n");
    printf("\t\t\t\t##                                        ##\n");
    printf("\t\t\t\t##         PLAYER %d WON THE MATCH         ##\n", currentPlayer);
    printf("\t\t\t\t##                                        ##\n");
    printf("\t\t\t\t############################################\n");

    return 0;
}
