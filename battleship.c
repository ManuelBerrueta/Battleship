/**********************************************************************************************
* Programmer: Manuel Berrueta                                                                 *
* WSU ID: 011585195                                                                           *
*                                                                                             *
* Class: CptS 121; Sec 1   Lab 2                                                              *
* Programming Assignment: PA6                                                                 *
*                                                                                             *
* Date: 20171023                                                                              *
*                                                                                             *
* Description: PA6 Assignment - A program that simulates the game battleship. Its a 2 player  *
*								game, you vs the computer.  You try to sink each other's ship *
*                               fleet.                                                        *
*                                                                                             *
**********************************************************************************************/

#include "battleship.h"

//Function that has everything together to make the game work
void battleship(void)
{
	//Most of game will go here	
}
















/*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
                                    Shooting Functions
888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/

int player_shoot(char player2_board[][NUM_COLS], char p2_display[][NUM_COLS], char * ship_type, FILE * outfile)
{
	int x = -1, y = -1, good_to_shoot = 0;

	while (good_to_shoot == 0)
	{
		printf("\n\n\t\t\t LETS SHOOT SOME SHIPS DOWN!! \n\n");
		printf("Enter coordinates where you haven't shot before\n");
		get_coordinate(&x, &y);
		good_to_shoot = check_target(player2_board, p2_display, x, y);
	}

	if (good_to_shoot == 1)
	{
		printf("Your shot to target [%d, %d] was a HiT! \n", x, y);
		*ship_type = player2_board[y][x];
		fprintf(outfile, "Player 1: HIT [%d, %d] \n", x, y);
		return 1;
	}
	else
	{
		printf("Your shot to target [%d, %d] was a MISS! \n", x, y);
		fprintf(outfile, "Player 1: MISS [%d, %d] \n", x, y);
		return 0;
	}

	//print to file the results of shot*************************************************************888888888888888888888888888
}


// Computer random choosing shooting
int comp_shoot(char player_board[][NUM_COLS], char p_display[][NUM_COLS], char * ship_type, FILE * outfile)
{
	int check_coordinate = -1, x = 0, y = 0;


	check_coordinate = 0;

	while (check_coordinate == 0)
	{
		pick_rand_shot(&y, &x);
		check_coordinate = check_target(player_board, player_board, x, y);
	}
	if (check_coordinate == 1)
	{
		printf("Computer's shot to target [%d, %d] was a HiT! \n", x, y);
		fprintf(outfile, "Player 2: HIT [%d, %d] \n", x, y);
		*ship_type = player_board[y][x];
		fprintf(outfile, "Player 1: HIT [%d, %d] \n", x, y);

		return 1;
	}
	else
	{
		printf("Computer's shot to target [%d, %d] was a MISS! \n", x, y);
		fprintf(outfile, "Player 2: MISS [%d, %d] \n", x, y);
		return 0;
	}

	//print to file the results of shot*************************************************************888888888888888888888888888



}

void pick_rand_shot(int *row_st, int *col_st)
{
	*col_st = rand() % NUM_COLS;
	*row_st = rand() % NUM_ROWS;
}


//Checks to make sure target has not been shot before
int check_target(char player2_board[][NUM_COLS], char p2_display[][NUM_COLS], int x, int y)
{
	int good_to_go = -1;
	
	if (player2_board[y][x] != '~')
	{
		if (p2_display[y][x] != '*') ///or
		{
			good_to_go = 1;
			p2_display[y][x] = '*';
		}
		else if (p2_display[y][x] == '*')
		{
			printf("You've already shot in those coordinates!\n");
			good_to_go = 0;
			return good_to_go;
		}
	}
	if (player2_board[y][x] == '~')
	{
		if (p2_display[y][x] != 'm')
		{
			p2_display[y][x] = 'm';
			good_to_go = 2;
		}
		else if (p2_display[y][x] == 'm')
		{
			printf("You've already shot in those coordinates!\n");
			good_to_go = 0;
			return good_to_go;
		}
	}
	return good_to_go;
}

//Player 1 sunk ship checking
int check_p1_sunk_ship(char players_board[][NUM_COLS], char * player, char  * ship_type, FILE * outfile)
{
	int row_index = 0, col_index = 0, ship_counter = 0, done = 0;
	char ship[18] = { '\0' };

	//if (*ship_type == '\0')//testing only
	//{
	//	strcat(ship, "[TEST SUCCESSFUL]");
	//}
	if (*ship_type == 'c')
	{
		strcat(ship, "[Carrrier]");
	}
	if (*ship_type == 'b')
	{
		strcat(ship, "[Battleship]");
	}
	if (*ship_type == 'r')
	{
		strcat(ship, "[Cruiser]");
	}
	if (*ship_type == 's')
	{
		strcat(ship, "[Submarine]");
	}
	if (*ship_type == 'd')
	{
		strcat(ship, "[Destroyer]");
	}


	for (; row_index < NUM_ROWS; ++row_index) //outer loop for which row we are in
	{
		for (col_index = 0; col_index < NUM_COLS; ++col_index)
		{
			if (players_board[row_index][col_index] == *ship_type)
			{
				ship_counter++;
			}
		}
	}
	if (ship_counter < 1)
	{
		printf("\n-=-=-=-= %s, Your %s has been sunk! =-=-=-=-=- \n\n", player, ship);
		fprintf(outfile, "%s,  %s has been sunk \n", player, ship);
		fflush(outfile);
	}
}



//Player 2 sunk ship checking
int check_if_sunk_ship(char players_board[][NUM_COLS], char players_display_board[][NUM_COLS], char * player, char  * ship_type, FILE * outfile)
{
	int row_index = 0, col_index = 0, ship_counter = 0, done = 0;
	char ship[18] = { '\0' };
	
	//if (*ship_type == '\0')//testing only
	//{
	//	strcat(ship, "[TEST SUCCESSFUL]");
	//}
	if (*ship_type == 'c')
	{
		strcat(ship, "[Carrrier]");	
	}
	if (*ship_type == 'b')
	{
		strcat(ship, "[Battleship]");
	}
	if (*ship_type == 'r')
	{
		strcat(ship, "[Cruiser]");
	}
	if (*ship_type == 's')
	{
		strcat(ship, "[Submarine]");
	}
	if (*ship_type == 'd')
	{
		strcat(ship, "[Destroyer]");
	}


	for (; row_index < NUM_ROWS; ++row_index) //outer loop for which row we are in
	{
		for (col_index = 0; col_index < NUM_COLS; ++col_index)
		{
			if (players_board[row_index][col_index] == *ship_type)
			{
				ship_counter++;
			}
			if (players_display_board[row_index][col_index] == '*')
			{
				ship_counter--;
			}
		}
	}
	if (row_index == NUM_ROWS && ship_counter < 1)
	{
		printf("\n-=-=-=-= %s, Your %s has been sunk! =-=-=-=-=- \n\n", player, ship);
		fprintf(outfile, "%s,  %s has been sunk \n", player, ship);
		fflush(outfile);
	}

}






/******************************************************************************************
                                           Board Functions
*******************************************************************************************/
int who_goes_first()
{
	int goes_first = 0;		//Set your values to stuff out of range for debugging

	goes_first = rand() % 2;

	//If active is for testing only
	//printf("Random = %d \n\n", goes_first);
	//system("pause");

	if (goes_first == 0)
	{
		//Player 1 goes first
		printf("Player 1, You get to go first!\nPress [ENTER] to START GAME \n");
		system("pause");
		system("cls");


	}
	else if (goes_first == 1)
	{
		printf("Computer goes first! \nPress [ENTER] to START GAME \n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("Something went wrong, Please Restart game");
		printf("Error Code: %d \n", goes_first);
		system("pause");
	}

	return goes_first;

}

//Initializes the game board by populating the multi dimensional array with ~.
void init_board(char board[][NUM_COLS], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < rows; ++row_index) //outer loop for which row we are in
	{
		for (col_index = 0; col_index < cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

//Prints the game board by populating the multi dimensional array.
void print_board(char board[][NUM_COLS], int rows, int cols)
{
	int row_index = 0, col_index = 0;
	printf("   0 1 2 3 4 5 6 7 8 9\n");

	for (; row_index < NUM_ROWS; ++row_index)
	{
		//Column index number
		printf("%d  ", row_index);

		for (col_index = 0; col_index < NUM_COLS; ++col_index)
		{


			//board[row_index][col_index] = '~';
			printf("%c ", board[row_index][col_index]);
		}
		printf("\n");
		putchar;
	}
	printf("\n");
}