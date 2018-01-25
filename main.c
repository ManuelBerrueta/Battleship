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


int main(void)
{
	char p1_board[NUM_ROWS][NUM_COLS] = { { '~' } };
	char p2_board[NUM_ROWS][NUM_COLS] = { { '~' } };
	char p2_display_board[NUM_ROWS][NUM_COLS] = { { '~' } };
	FILE *logfile = NULL;
	//Variable for who starts first
	int coin_toss = -1, manual_or_random = 0;

	//Variable to keep track of turns
	int track_turns = 1;

	//Keep track of ship type shot
	char  ship_type = '\0';
	char  test_str[15] = { '\0' };

	//Player 
	int hit_or_miss = -1;

	//Game Status
	int game_over = 0;
	
	//Stats Struct
	Stats p1Stats = { 0, 0, 0, 0.0, '\0' };
	Stats p2Stats = { 0, 0, 0, 0.0, '\0' };

	//Randomness
	srand((unsigned int)time(NULL));

	//The Battleship logfile
	logfile = fopen("battleship.log", "w");


	//88888888888888 START OF GAME CODE 888888888888888888\\

	//Initialiazing Game Boards
	//Player1
	init_board(p1_board, NUM_ROWS, NUM_COLS);
	//Player2
	init_board(p2_board, NUM_ROWS, NUM_COLS);
	randomly_place_ships(p2_board);

	//Player2 Game Display
	init_board(p2_display_board, NUM_ROWS, NUM_COLS);

	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ \
	Testing Functions
	\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
	//TESTING

	system("color 2e");

	//Menus
	welcome_screen();
	start_menu();

	//Makes decision of entering ships manually or randomly
	//Returns 1 for Manual entering and 2 for random entering
	manual_or_random = menu_decision();

	if (manual_or_random == 1)
	{
		system("color 0e");
		manually_enter_ships(p1_board);
		

		//Testing
		system("pause");
	}
	else if (manual_or_random == 2)
	{
		//Random Enter ships in to Player 1s board function call
		randomly_place_ships(p1_board);

		system("COLOR A");
		printf("\n\n \t\t    [Ships Randomly Entered] \n\n");

		system("pause");
		system("cls");
	}
	


	//Random Selecting Who Goes First
	coin_toss = who_goes_first();



	/****************************************************************************************************
	                                   START OF GAME LOOP
	*****************************************************************************************************/

	//Print Game Boards
	printf(" -=[ Player1's Board ]=- \n");
	print_board(p1_board, NUM_ROWS, NUM_COLS);
	printf(" -=[ Player2's Board ]=- \n");
	print_board(p2_display_board, NUM_ROWS, NUM_COLS); 
	//Testing
	//print_board(p2_board, NUM_ROWS, NUM_COLS); //Needschanged to P2_Display when coding & Testing is done!!!!!!!!!!!!!!!!!!!!!!!

	while (game_over != 1)
	{
		if (coin_toss == 0)
		{
			/*888888888888888888888888888888888
			            Player 1
			8888888888888888888888888888888888888*/
			ship_type = '\0';
			hit_or_miss = player_shoot(p2_board, p2_display_board, &ship_type, logfile);
			fflush(logfile);

			if (hit_or_miss == 1)
			{
				check_if_sunk_ship(p2_board, p2_display_board, "Player2", &ship_type, logfile);
				p1Stats.hits++;
				p1Stats.shots++;
			}
			if (hit_or_miss == 0)
			{
				p1Stats.misses++;
				p1Stats.shots++;
			}

			if (p1Stats.hits == 17)
			{
				printf("-=-=-=-=-= PLAYER 1 HAS WON THE GAME! =-=-=-=-=- \n\n");
				p1Stats.win_lose = 1;
				game_over = 1;
			}

			/*888888888888888888888888888888888
			              Computer
			8888888888888888888888888888888888888*/
			ship_type = '\0';

			hit_or_miss = comp_shoot(p1_board, p1_board, &ship_type, logfile);

			if (hit_or_miss == 1)
			{
				check_p1_sunk_ship(p1_board, "Player1", &ship_type, logfile);
				p2Stats.hits++;
				p2Stats.shots++;
			}
			if (hit_or_miss == 0)
			{
				p2Stats.misses++;
				p2Stats.shots++;
			}

			if (p2Stats.hits == 17)
			{
				printf("-=-=-=-=-= PLAYER 2 HAS WON THE GAME! =-=-=-=-=- \n\n");
				p2Stats.win_lose = 1;
				game_over = 1;
			}
			fflush(logfile);
			system("pause");
			
			system("cls");

			//Print Updated Boards
			print_board(p1_board, NUM_ROWS, NUM_COLS);
			print_board(p2_display_board, NUM_ROWS, NUM_COLS);

			track_turns++;
		}
		if (coin_toss == 1) //Computer Goes First
		{
			/*888888888888888888888888888888888
			           Computer
			8888888888888888888888888888888888888*/
			ship_type = '\0';
			hit_or_miss = comp_shoot(p1_board, p1_board, &ship_type, logfile);
			
			if (hit_or_miss == 1)
			{
				check_p1_sunk_ship(p1_board, "Player1", &ship_type, logfile);
				p2Stats.hits++;
				p2Stats.shots++;
			}
			if (hit_or_miss == 0)
			{
				p2Stats.misses++;
				p2Stats.shots++;
			}
			
			if (p2Stats.hits == 17)
			{
				printf("-=-=-=-=-= PLAYER 2 HAS WON THE GAME! =-=-=-=-=- \n\n");
				p2Stats.win_lose = 1;
				game_over = 1;
			}
			fflush(logfile);
			
			/*888888888888888888888888888888888
			             Player 1
			8888888888888888888888888888888888888*/
			ship_type = '\0';
			hit_or_miss = player_shoot(p2_board, p2_display_board, &ship_type, logfile);
			if (hit_or_miss == 1)
			{
				check_if_sunk_ship(p2_board, p2_display_board, "Player2", &ship_type, logfile);
				p1Stats.hits++;
				p1Stats.shots++;
			}
			if (hit_or_miss == 0)
			{
				p1Stats.misses++;
				p1Stats.shots++;
			}
			fflush(logfile);
			system("pause");
			system("cls");

			if (p1Stats.hits == 17)
			{
				printf("-=-=-=-=-= PLAYER 1 HAS WON THE GAME! =-=-=-=-=- \n\n");
				p1Stats.win_lose = 1;
				game_over = 1;
			}
			
			//Print Updated Boards
			print_board(p1_board, NUM_ROWS, NUM_COLS);
			print_board(p2_display_board, NUM_ROWS, NUM_COLS);

			track_turns++;
		}
	}

	/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	                 Game Stats
	@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
	p1Stats.hit_miss_rat = p1Stats.hits / p1Stats.misses;
	if (p1Stats.win_lose == 1)
	{
		fprintf(logfile, "\n\n ====== Player 1 won the game ======\n");
	}
	else
	{
		fprintf(logfile, "\n\n ====== Player 1 lost the game ======\n");
	}
	fprintf(logfile, ":::::Player 1 Stats:::::\n");
	fprintf(logfile, "Total Hits: %d \n", p1Stats.hits);
	fprintf(logfile, "Total Misses: %d \n", p1Stats.misses);
	fprintf(logfile, "Total Number of shots: %d\n", p1Stats.shots);
	fprintf(logfile, "Hit to Miss Ratio: %lf", p1Stats.hit_miss_rat);



	p2Stats.hit_miss_rat = p2Stats.hits / p2Stats.misses;
	if (p2Stats.win_lose == 1)
	{
		fprintf(logfile, "\n\n ===== Player 2 won the game =====\n");
	}
	else
	{
		fprintf(logfile, "\n\n ====== Player 2 lost the game ======\n");
	}
	fprintf(logfile, ":::::Player 2 Stats:::::\n");
	fprintf(logfile, "Total Hits: %d \n", p2Stats.hits);
	fprintf(logfile, "Total Misses: %d \n", p2Stats.misses);
	fprintf(logfile, "Total Number of shots: %d\n", p2Stats.shots);
	fprintf(logfile, "Hit to Miss Ratio: %lf", p2Stats.hit_miss_rat);

	//Should be the last thing after the game is over
	fclose(logfile);

	return 0;
}