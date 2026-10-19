#include <stdio.h>

int check_game(char board[3][3])
{
    int i;

    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;

        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main(void)
{
    char board[3][3];
    int x, y, k, i;

    for (x = 0; x < 3; x++)
        for (y = 0; y < 3; y++)
            board[x][y] = ' ';

    for (k = 0; k < 9; ) {
        printf("(x, y) 좌표: ");

        if (scanf("%d %d", &x, &y) != 2) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }

        if (x < 0 || x >= 3 || y < 0 || y >= 3) {
            printf("좌표는 0부터 2까지 입력하세요.\n");
            continue;
        }

        if (board[x][y] != ' ') {
            printf("이미 놓인 자리입니다. 다시 입력하세요.\n");
            continue;
        }

        board[x][y] = (k % 2 == 0) ? 'X' : 'O';

        for (i = 0; i < 3; i++) {
            printf("---|---|---\n");
            printf("%c  | %c | %c\n",
                board[i][0], board[i][1], board[i][2]);
        }
        printf("---|---|---\n");

        if (check_game(board)) {
            printf("%c 승리!\n", board[x][y]);
            break;
        }

        k++;
    }

    if (k == 9 && !check_game(board))
        printf("무승부입니다!\n");

    return 0;
}