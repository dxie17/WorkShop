/*
	==================================================
	Workshop #5 (Part-1):
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
#define MAX_moves 26
#define MIN_moves 3

typedef struct
{
	int lives;
	char player;
	int treasure;
	int positions_history[100];
} PlayerInfo;

typedef struct
{
	int moves;
	int path_length;
	int bombs[100];
	int treasure_buried[100];
} GameInfo;



int main()
{
	PlayerInfo playerinfo = { 0,'\0',0,{0} };
	GameInfo gameinfo = { 0,0,{0},{0} };
	int i;

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

	printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_path_length, MAX_path_length);
	scanf("%d", &gameinfo.path_length);

	while ((gameinfo.path_length % 5 != 0) || gameinfo.path_length< MIN_path_length || gameinfo.path_length>MAX_path_length)
	{
		printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_path_length, MAX_path_length);
		printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_path_length, MAX_path_length);
		scanf("%d", &gameinfo.path_length);
	}

	printf("Set the limit for number of moves allowed: ");
	scanf("%d", &gameinfo.moves);

	while (gameinfo.moves > MAX_moves || gameinfo.moves < MIN_moves)
	{
		printf("    Value must be between %d and %d\n", MIN_moves, MAX_moves);
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gameinfo.moves);
	}

	printf("\nBOMB Placement\n");
	printf("--------------\n");

	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.path_length);

	for (i = 0; (i < gameinfo.path_length / 5); i++)
	{
		printf("   Positions [%2d-%2d]: ", (i * 5 + 1), (i * 5 + 5));
		scanf("%d %d %d %d %d", &gameinfo.bombs[i * 5], &gameinfo.bombs[i * 5 + 1], &gameinfo.bombs[i * 5 + 2], &gameinfo.bombs[i * 5 + 3], &gameinfo.bombs[i * 5 + 4]);
	}

	printf("BOMB placement set\n");

	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.path_length);

	for (i = 0; (i < gameinfo.path_length / 5); i++)
	{
		printf("   Positions [%2d-%2d]: ", (i * 5 + 1), i * 5 + 5);
		scanf("%d %d %d %d %d", &gameinfo.treasure_buried[i * 5], &gameinfo.treasure_buried[i * 5 + 1], &gameinfo.treasure_buried[i * 5 + 2], &gameinfo.treasure_buried[i * 5 + 3], &gameinfo.treasure_buried[i * 5 + 4]);
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

	return 0;

}
