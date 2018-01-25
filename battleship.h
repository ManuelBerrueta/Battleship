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

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ROWS 10
#define NUM_COLS 10

#define CARRIER 5
#define BATTLESHIP 4
#define CRUISER 3
#define SUBMARINE 3
#define DESTROYER 2

typedef enum dir
{
	NOTUSED, VERTICAL, HORIZONTAL
} Dir;

typedef struct stats {
	int hits;
	int misses;
	int shots;
	double hit_miss_rat;
	int win_lose;
}Stats;


//888888888888888888888888888-=   Function declarations   =-8888888888888888888888888888888\\

/******************************************************************************************
                                   Main Game Functions
*******************************************************************************************/

//Include functions that run battleship
void battleship(void);

//Player1
int player_shoot(char player2_board[][NUM_COLS], char p2_display[][NUM_COLS], char * ship_type, FILE * outfile);
int check_target(char player2_board[][NUM_COLS], char p2_display[][NUM_COLS], int x, int y);


// Computer random choosing shooting
int comp_shoot(char player_board[][NUM_COLS], char p_display[][NUM_COLS], char * ship_type, FILE * outfile);
void pick_rand_shot(int *row_st, int *col_st);

//Player 2 sunks ship check
int check_if_sunk_ship(char players_board[][NUM_COLS], char players_display_board[][NUM_COLS], char * player, char  * ship_type, FILE * outfile);

//Player 1 Sunk ship check
int check_p1_sunk_ship(char players_board[][NUM_COLS], char * player, char  * ship_type, FILE * outfile);



/******************************************************************************************
                                  Placing Ships
*******************************************************************************************/
void manually_enter_ships(char player1_board[][NUM_COLS]);
void randomly_place_ships(char player1_board[][NUM_COLS]);
//Function to place ships in game board
void pop_ships(char p1_board[][NUM_COLS], int num_cells, char ship_type_character, int direction, int row_start, int col_start);
int get_hor_or_vert(void);
void generate_start_pt(int ship_length, int direction, int rows, int cols, int *row_st, int *col_st);

/******************************************************************************************
                                  Board Functions
*******************************************************************************************/
//Initializes board
void init_board(char board[][NUM_COLS], int rows, int cols);

//Print Boards
void print_board(char board[][NUM_COLS], int rows, int cols);

//Makes randon decision and returns 0 or 1 for player to start first
int who_goes_first();

//Function that gets coordinates from the user
//One array will be the ship coordinate array
void get_coordinate(int * pXvalue, int * pYvalue);

//Indivually get X and Y
int get_x(void);
int get_y(void);


//Get Direction, Vertical or Horizontal
int get_direction();

/*
Function for checking coordinate and make sure that ship is within bounds,
and not populate over ships
*/
int check_outbounds(char player1_board[][NUM_COLS], int direction, int ship_size, int x_value, int y_value);

/******************************************************************************************
                                   Score Card Functions
*******************************************************************************************/




/******************************************************************************************
                                          Menu
*******************************************************************************************/
void welcome_screen(void);
void start_menu(void);
int menu_decision(void);

/******************************************************************************************
                                     File Functions
*******************************************************************************************/
void test_write_file(FILE *file_to_test_write);

#endif // BATTLESHIP_H

