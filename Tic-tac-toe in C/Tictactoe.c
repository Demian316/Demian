//This is tic-tac-toe game implemented by C language.

#include<stdio.h>

void display(char b[][3])
{
	int i, j, num = 0;
	printf("    0 1 2\n");
	printf(" ---------\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d: ", num++);
		for (j = 0; j < 3; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}

int win_check(char b[][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		if (b[i][0] == b[i][1] && b[i][0] == b[i][2])
		{
			if (b[i][0] == 'X' || b[i][0] == 'O')
				return 1;
		}
		else if (b[0][i] == b[1][i] && b[0][i] == b[2][i])
		{
			if (b[0][i] == 'X' || b[0][i] == 'O')
				return 1;
		}
		else if (b[0][0] == b[1][1] && b[0][0] == b[2][2])
		{
			if (b[0][0] == 'X' || b[0][0] == 'O')
				return 1;
		}
		else if (b[0][2] == b[1][1] && b[0][2] == b[2][0])
		{
			if (b[0][2] == 'X' || b[0][2] == 'O')
				return 1;
		}
	return 0;
}

int nobody_wins(char arr[][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (arr[i][j] == ' ')
				return 0;
	return 1; //판이 다 채워졌으면 1반환 
}

void start_game(char arr[][3], char answer)
{
	int row, col;

	while (1)
	{
		printf("Player %c<행 열>: ", answer);
		scanf("%d %d", &row, &col);
		if (arr[row][col] != ' ')
			continue;
		else
		{
			arr[row][col] = answer;
			break;
		}
	}
	display(arr);
}

int main(void)
{
	int col, row, i, j;
	char game[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			game[i][j] = ' ';

	display(game);



	while (1)
	{
		if (nobody_wins(game) == 1)
		{
			printf("Nobody wins!");
			break;
		}
		start_game(game, 'X');
		if (win_check(game) == 1)
		{
			printf("Player X wins!");
			break;
		}

		if (nobody_wins(game) == 1)
		{
			printf("Nobody wins!");
			break;
		}
		start_game(game, 'O');
		if (win_check(game) == 1)
		{
			printf("Player O wins!");
			break;
		}
	}
}
