#include <stdio.h>

char board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

int gameover = 0;
int currentPlayer = 1;

void drawBoard() {
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        printf("\t\t\t\t\t");
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void playerMove() {
    int row, col;
    printf("\n\nPlayer %d's turn\n", currentPlayer);
    printf("Enter the row and column (1-3): ");
    scanf("%d %d", &row, &col);
    row--;
    col--;

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
        if (currentPlayer == 1)
            board[row][col] = 'X';
        else
            board[row][col] = 'O';
    } else {
        printf("Invalid move! Try again.\n");
        playerMove();
    }
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
            return 1;
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-'))
        return 1;

    // Check for draw
    int draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                draw = 0;
                break;
            }
        }
    }
    if (draw) return 2;

    return 0;
}

void togglePlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    while (!gameover) {
        drawBoard();
        playerMove();
        int result = checkWin();
        if (result == 1) {
            drawBoard();
            printf("Player %d wins!\n", currentPlayer);
            gameover = 1;
        } else if (result == 2) {
            drawBoard();
            printf("It's a draw!\n");
            gameover = 1;
        } else {
            togglePlayer();
        }
    }

    return 0;
}
