/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   :Deyang Xie
	ID     :150162204
	Email  :dxie17@myseneca.ca
	Section:NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_lives 10
#define MIN_lives 1
#define MAX_path_length 70
#define MIN_path_length 10
#define multiple 5

typedef struct
{
	int lives;
	char player;
	int treasure;
	int positions_history[MAX_path_length];
} PlayerInfo;

typedef struct
{
	int allowmoves;
	int path_length;
	int bombs[MAX_path_length];
	int treasure_buried[MAX_path_length];
} GameInfo;

void printfexample(int n)
{
	int p = 1, q;
	printf("(Example:");
	for (p = 1; p <= n; p++)
	{
		q = p % 4;
		if (q == 0 || q == 1)
		{
			printf(" 1");
		}
		else if (q == 2 || q == 3)
		{
			printf(" 0");
		}
	}
	printf(")");
}

int main()
{
	PlayerInfo playerinfo = { 0,'\0',0,{0} };
	GameInfo gameinfo = { 0,0,{0},{0} };
	int i, n, m, l = 0, tr, gettreasure = 0, MAX_moves, MIN_moves;
	char position_current[MAX_path_length] = { '\0' }, gamepath[MAX_path_length] = { '\0' }, prulerby10[MAX_path_length] = { '\0' };
	int prulerby1[MAX_path_length] = { 0 };
	int moves_history[MAX_path_length] = { 0 };


	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n");

	printf("\nPLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &playerinfo.player);

	printf("Set the number of lives: ");
	scanf("%d", &playerinfo.lives);

	while (playerinfo.lives > MAX_lives || playerinfo.lives < MIN_lives)
	{
		printf("     Must be between %d and %d!\n", MIN_lives, MAX_lives);
		printf("Set the number of lives: ");
		scanf("%d", &playerinfo.lives);
	}

	printf("Player configuration set-up is complete\n");


	printf("\nGAME Configuration\n");
	printf("------------------\n");

	printf("Set the path length (a multiple of %d between %d-%d): ", multiple, MIN_path_length, MAX_path_length);
	scanf("%d", &gameinfo.path_length);

	while ((gameinfo.path_length % multiple != 0) || gameinfo.path_length< MIN_path_length || gameinfo.path_length>MAX_path_length)
	{
		printf("     Must be a multiple of %d and between %d-%d!!!\n", multiple, MIN_path_length, MAX_path_length);
		printf("Set the path length (a multiple of %d between %d-%d): ", multiple, MIN_path_length, MAX_path_length);
		scanf("%d", &gameinfo.path_length);
	}

	printf("Set the limit for number of moves allowed: ");
	scanf("%d", &gameinfo.allowmoves);

	MIN_moves = playerinfo.lives;
	MAX_moves = (int)(0.75 * gameinfo.path_length);

	while (gameinfo.allowmoves > MAX_moves || gameinfo.allowmoves < MIN_moves)
	{
		printf("    Value must be between %d and %d\n", MIN_moves, MAX_moves);
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gameinfo.allowmoves);
	}

	printf("\nBOMB Placement\n");
	printf("--------------\n");

	printf("Enter the bomb positions in sets of %d where a value\n", multiple);
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printfexample(multiple);
	printf(" NOTE: there are %d to set!\n", gameinfo.path_length);

	for (i = 0; (i < gameinfo.path_length / multiple); i++)
	{
		printf("   Positions [%2d-%2d]: ", (i * multiple + 1), (i * multiple + multiple));

		for (n = 0; n < multiple; n++)
		{
			scanf("%d", &gameinfo.bombs[i * multiple + n]);
		}
	}

	printf("BOMB placement set\n");

	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\n", multiple);
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printfexample(multiple);
	printf(" NOTE: there are %d to set!\n", gameinfo.path_length);

	for (i = 0; (i < gameinfo.path_length / multiple); i++)
	{
		printf("   Positions [%2d-%2d]: ", (i * multiple + 1), i * multiple + multiple);

		for (n = 0; n < multiple; n++)
		{
			scanf("%d", &gameinfo.treasure_buried[i * multiple + n]);
		}
	}

	printf("TREASURE placement set\n");
	printf("\nGAME configuration set-up is complete...\n");

	printf("\n------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");


	printf("Player:\n");
	printf("   Symbol     : %c\n", playerinfo.player);
	printf("   Lives      : %d\n", playerinfo.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");


	printf("\nGame:\n");
	printf("   Path Length: %d\n", gameinfo.path_length);
	printf("   Bombs      : ");
	for (i = 0; i < gameinfo.path_length; i++)
	{
		printf("%d", gameinfo.bombs[i]);
	}

	printf("\n   Treasure   : ");
	for (i = 0; i < gameinfo.path_length; i++)
	{
		printf("%d", gameinfo.treasure_buried[i]);
	}

	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");


	for (i = 0; i <= gameinfo.path_length; i++)
	{
		gamepath[i] = '-';
		if ((i + 1) % 10 == 0)
		{
			if (i == 0)
			{
				prulerby10[i] = '|';
			}
			if ((i + 1) / 10 == 1)
			{
				prulerby10[i] = '1';
			}

			else if ((i + 1) / 10 == 2)
			{
				prulerby10[i] = '2';
			}
			else if ((i + 1) / 10 == 3)
			{
				prulerby10[i] = '3';
			}
			else if ((i + 1) / 10 == 4)
			{
				prulerby10[i] = '4';
			}
			else if ((i + 1) / 10 == 5)
			{
				prulerby10[i] = '5';
			}
			else if ((i + 1) / 10 == 6)
			{
				prulerby10[i] = '6';
			}
			else if ((i + 1) / 10 == 7)
			{
				prulerby10[i] = '7';
			}

			else if ((i + 1) / 10 == 8)
			{
				prulerby10[i] = '8';
			}
			else if ((i + 1) / 10 == 9)
			{
				prulerby10[i] = '9';
			}

		}

		else if ((i + 1) % 10 > 0)
		{
			prulerby10[i] = '|';
		}

		prulerby1[i] = ((i + 1) % 10);
	}

	printf("\n  ");

	for (i = 0; i < gameinfo.path_length; i++)
	{
		printf("%c", gamepath[i]);
	}

	printf("\n  ");

	for (i = 0; i < gameinfo.path_length; i++)
	{
		printf("%c", prulerby10[i]);
	}

	printf("\n  ");


	for (i = 0; i < gameinfo.path_length; i++)
	{
		printf("%d", prulerby1[i]);
	}

	printf("\n+---------------------------------------------------+\n");
	printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d", playerinfo.lives, playerinfo.treasure, gameinfo.allowmoves);
	printf("\n+---------------------------------------------------+\n");

	for (m = 0; m < gameinfo.path_length; m++)
	{
		position_current[m] = ' ';
	}



	while ((playerinfo.lives > 0) && (gameinfo.allowmoves > 0))
	{

		for (i = 0; i < gameinfo.path_length; i++)
		{
			l = 0;
			moves_history[i] = 0;
			printf("Next Move [1-%d]: ", gameinfo.path_length);
			scanf("%d", &moves_history[i]);

			while ((moves_history[i] < 1) || (moves_history[i] > gameinfo.path_length))
			{
				l = 0;
				printf("  Out of Range!!!\n");
				moves_history[i] = 0;
				printf("Next Move [1-%d]: ", gameinfo.path_length);
				scanf("%d", &moves_history[i]);
				continue;
			}

			for (n = 0; n < i; n++)
			{
				if (moves_history[i] == moves_history[n])
				{
					l = 1;
					printf("\n===============> Dope! You've been here before!");

					printf("\n\n  ");

					tr = moves_history[i] - 1;
					position_current[tr] = playerinfo.player;

					for (m = 0; m < gameinfo.path_length; m++)
					{
						printf("%c", position_current[m]);
						position_current[m] = ' ';
					}
					printf("\n  ");
					for (m = 0; m < gameinfo.path_length; m++)
					{
						printf("%c", gamepath[m]);
					}

					printf("\n  ");
					for (m = 0; m < gameinfo.path_length; m++)
					{
						printf("%c", prulerby10[m]);
					}
					printf("\n  ");
					for (m = 0; m < gameinfo.path_length; m++)
					{
						printf("%d", prulerby1[m]);
					}

					printf("\n+---------------------------------------------------+\n");
					printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining:  %d", playerinfo.lives, gettreasure, gameinfo.allowmoves);
					printf("\n+---------------------------------------------------+\n");
					break;
				}
			}

			if (l != 1)
			{

				tr = moves_history[i] - 1;
				position_current[tr] = playerinfo.player;

				if (gameinfo.treasure_buried[moves_history[i] - 1] == 0 && gameinfo.bombs[moves_history[i] - 1] == 0)
				{
					printf("\n===============> [.] ...Nothing found here... [.]\n");
					gamepath[moves_history[i] - 1] = '.';
					gameinfo.allowmoves -= 1;
					if (gameinfo.allowmoves == 0)
					{
						break;
					}
				}
				else if (gameinfo.bombs[moves_history[i] - 1] > 0 && gameinfo.treasure_buried[moves_history[i] - 1] == 0)
				{
					printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
					gamepath[moves_history[i] - 1] = '!';
					gameinfo.allowmoves -= 1;
					playerinfo.lives -= 1;
					if (playerinfo.lives == 0)
					{
						printf("\nNo more LIVES remaining!");
						break;
					}
					if (gameinfo.allowmoves == 0)
					{
						break;
					}
				}
				else if (gameinfo.bombs[moves_history[i] - 1] == 0 && gameinfo.treasure_buried[moves_history[i] - 1] > 0)
				{
					printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
					gamepath[moves_history[i] - 1] = '$';
					gameinfo.allowmoves -= 1;
					gettreasure += 1;
					if (gameinfo.allowmoves == 0)
					{
						break;
					}
				}
				else if (gameinfo.bombs[moves_history[i] - 1] > 0 && gameinfo.treasure_buried[moves_history[i] - 1] > 0)
				{
					printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
					printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
					gamepath[moves_history[i] - 1] = '&';
					playerinfo.lives -= 1;
					gettreasure += 1;
					gameinfo.allowmoves -= 1;
					if (playerinfo.lives == 0)
					{
						printf("No more LIVES remaining!");
						break;
					}

					if (gameinfo.allowmoves == 0)
					{
						break;
					}
				}

				printf("\n  ");
				for (m = 0; m < gameinfo.path_length; m++)
				{
					printf("%c", position_current[m]);
					position_current[m] = ' ';
				}
				printf("\n  ");
				for (m = 0; m < gameinfo.path_length; m++)
				{
					printf("%c", gamepath[m]);
				}

				printf("\n  ");
				for (m = 0; m < gameinfo.path_length; m++)
				{
					printf("%c", prulerby10[m]);
				}
				printf("\n  ");
				for (m = 0; m < gameinfo.path_length; m++)
				{
					printf("%d", prulerby1[m]);
				}

				printf("\n+---------------------------------------------------+\n");
				printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining:  %d", playerinfo.lives, gettreasure, gameinfo.allowmoves);
				printf("\n+---------------------------------------------------+\n");
			}

		}

		printf("\n\n  ");
		for (m = 0; m < gameinfo.path_length; m++)
		{
			printf("%c", position_current[m]);
			position_current[m] = ' ';
		}
		printf("\n  ");
		for (m = 0; m < gameinfo.path_length; m++)
		{
			printf("%c", gamepath[m]);
		}

		printf("\n  ");
		for (m = 0; m < gameinfo.path_length; m++)
		{
			printf("%c", prulerby10[m]);
		}
		printf("\n  ");
		for (m = 0; m < gameinfo.path_length; m++)
		{
			printf("%d", prulerby1[m]);
		}

		printf("\n+---------------------------------------------------+\n");
		printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining:  %d", playerinfo.lives, gettreasure, gameinfo.allowmoves);
		printf("\n+---------------------------------------------------+\n");

	}

	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n");

	printf("\nYou should play again and try to beat your score!\n");

	return 0;
}
