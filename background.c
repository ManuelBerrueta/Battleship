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

/******************************************************************************************
                                  Placing Ships
*******************************************************************************************/
void manually_enter_ships(char player1_board[][NUM_COLS])
{
	//Temp Coordinates
	int x = -1, y = -1;
	//Horizontal or Vertical
	int horizontal_or_vertical = 0, check_coordinate = 0;
	
	//Manually Enter Coordinates for Player 1's board ships Function call
	char intructions[] = { "Your coordinate will be the starting point of the ships\nYou will decide if you want to go horizontal or vertical\nPay attention to the cells required per ship and count ahead so you don't go out of bounds\n" };
	printf("%s", intructions);
	printf("Manually Enter Each Ships Starting Coordinates x y \n");

	/*888888888888888888888888888
	Start Loop for 5 ships here
	88888888888888888888888888888*/
	//Use a Switch statement for ship

	for (int ship_type = 0; ship_type < 5; ship_type++)
	{
		//Switch statement if i = 0
		switch (ship_type)
		{
		case 0:
			printf("Starting coordinate of Carrier (Remember its 5 Cells \n");

			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				//Reset X and Y
				x = -1;
				y = -1;

				//get_coordinates //possisble 2nd array
				get_coordinate(&x, &y);
				
				//Direction
				horizontal_or_vertical = get_direction();
				check_coordinate = check_outbounds(player1_board, horizontal_or_vertical, 5, x, y);
				if (check_coordinate != 1)
				{
					printf("Your ship can not be placed using those coordinates \n");
					printf("Coordinates could be out of bounds, overlapping already placed ships, or the ship is too big and it will run out of bounds\n");
					system("pause");
				}
			}

			//Populating ships into board
			pop_ships(player1_board, 5, 'c', horizontal_or_vertical, y, x);

			//TEST PRINT OF SHIPS
			print_board(player1_board, NUM_ROWS, NUM_COLS);

			system("pause");
			system("cls");
			break;
		
		case 1:
			printf("Starting coordinate of Battleship (Remember its 4 Cells \n");

			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				//Reset X and Y
				x = -1;
				y = -1;

				//get_coordinates //possisble 2nd array
				get_coordinate(&x, &y);

				//Direction
				horizontal_or_vertical = get_direction();
				check_coordinate = check_outbounds(player1_board, horizontal_or_vertical, 4, x, y);
				if (check_coordinate != 1)
				{
					printf("Your ship can not be placed using those coordinates \n");
					printf("Coordinates could be out of bounds, overlapping already placed ships, or the ship is too big and it will run out of bounds\n");
					system("pause");
				}
			}

			//Populating ships into board
			pop_ships(player1_board, 4, 'b', horizontal_or_vertical, y, x);

			//TEST PRINT OF SHIPS
			print_board(player1_board, NUM_ROWS, NUM_COLS);

			system("pause");
			system("cls");
			break;

		case 2:
			printf("Starting coordinate of Cruiser (Remember its 3 Cells \n");
			
			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				//Reset X and Y
				x = -1;
				y = -1;

				//get_coordinates //possisble 2nd array
				get_coordinate(&x, &y);

				//Direction
				horizontal_or_vertical = get_direction();
				check_coordinate = check_outbounds(player1_board, horizontal_or_vertical, 3, x, y);
				if (check_coordinate != 1)
				{
					printf("Your ship can not be placed using those coordinates \n");
					printf("Coordinates could be out of bounds, overlapping already placed ships, or the ship is too big and it will run out of bounds\n");
					system("pause");
				}
			}

			//Populating ships into board
			pop_ships(player1_board, 3, 'r', horizontal_or_vertical, y, x);

			//TEST PRINT OF SHIPS
			print_board(player1_board, NUM_ROWS, NUM_COLS);

			system("pause");
			system("cls");
			break;

		case 3:
			printf("Starting coordinate of Submarine (Remember its 3 Cells \n");
			
			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				//Reset X and Y
				x = -1;
				y = -1;

				//get_coordinates //possisble 2nd array
				get_coordinate(&x, &y);

				//Direction
				horizontal_or_vertical = get_direction();
				check_coordinate = check_outbounds(player1_board, horizontal_or_vertical, 3, x, y);
				if (check_coordinate != 1)
				{
					printf("Your ship can not be placed using those coordinates \n");
					printf("Coordinates could be out of bounds, overlapping already placed ships, or the ship is too big and it will run out of bounds\n");
					system("pause");
				}
			}

			//Populating ships into board
			pop_ships(player1_board, 3, 's', horizontal_or_vertical, y, x);

			//TEST PRINT OF SHIPS
			print_board(player1_board, NUM_ROWS, NUM_COLS);

			system("pause");
			system("cls");
			break;

		case 4:
			printf("Starting coordinate of Destroyer (Remember its 2 Cells \n");
			
			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				//Reset X and Y
				x = -1;
				y = -1;

				//get_coordinates //possisble 2nd array
				get_coordinate(&x, &y);

				//Direction
				horizontal_or_vertical = get_direction();
				check_coordinate = check_outbounds(player1_board, horizontal_or_vertical, 4, x, y);
				if (check_coordinate != 1)
				{
					printf("Your ship can not be placed using those coordinates \n");
					printf("Coordinates could be out of bounds, overlapping already placed ships, or the ship is too big and it will run out of bounds\n");
					system("pause");
				}
			}

			//Populating ships into board
			pop_ships(player1_board, 2, 'd', horizontal_or_vertical, y, x);

			//TEST PRINT OF SHIPS
			print_board(player1_board, NUM_ROWS, NUM_COLS);

			system("pause");
			system("cls");
			break;

		default:
			printf("Something went south, you probably entered an invalid option!");
		}
	}
	
	//for loop to enter coordinates in an array for storage

}


void test_random_plc(char player1_board[][NUM_COLS])
{
	Dir direction = VERTICAL;

	int col_st = 0, row_st = 0, check_coordinate = -1;

	while (check_coordinate == 0)
	{


		direction = get_hor_or_vert();
		generate_start_pt(5, direction, NUM_ROWS, NUM_COLS, &row_st, &col_st);

		check_coordinate = check_outbounds(player1_board, direction, 5, col_st, row_st);
	}

//Populating ships into board
pop_ships(player1_board, 5, 'c', direction, &row_st, &col_st);

}

void randomly_place_ships(char player1_board[][NUM_COLS])
{
	int direction = -1;

	int col_st = 0, row_st = 0, check_coordinate = -1;


	/*888888888888888888888888888
	Start Loop for 5 ships here
	88888888888888888888888888888*/
	//Use a Switch statement for ship

	for (int ship_type = 0; ship_type < 5; ship_type++)
	{
		//Switch statement if i = 0
		switch (ship_type)
		{
		case 0:
			//Check For out of bounds and overlapping
			check_coordinate = 0;

			while (check_coordinate == 0)
			{
			direction = get_hor_or_vert();
			generate_start_pt(5, direction, NUM_ROWS, NUM_COLS, &row_st, &col_st);
			check_coordinate = check_outbounds(player1_board, direction, 5, col_st, row_st);
			}

			//Populating ships into board
			pop_ships(player1_board, 5, 'c', direction, row_st, col_st);

			break;

		case 1:
			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				direction = get_hor_or_vert();
				generate_start_pt(4, direction, NUM_ROWS, NUM_COLS, &row_st, &col_st);
				check_coordinate = check_outbounds(player1_board, direction, 4, col_st, row_st);
			}

			//Populating ships into board
			pop_ships(player1_board, 4, 'b', direction, row_st, col_st);

			break;

		case 2:
			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				direction = get_hor_or_vert();
				generate_start_pt(5, direction, NUM_ROWS, NUM_COLS, &row_st, &col_st);
				check_coordinate = check_outbounds(player1_board, direction, 4, col_st, row_st);
			}

			//Populating ships into board
			pop_ships(player1_board, 3, 'r', direction, row_st, col_st);

			break;

		case 3:

			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				direction = get_hor_or_vert();
				generate_start_pt(5, direction, NUM_ROWS, NUM_COLS, &row_st, &col_st);
				check_coordinate = check_outbounds(player1_board, direction, 4, col_st, row_st);
			}

			//Populating ships into board
			pop_ships(player1_board, 3, 's', direction, row_st, col_st);

			break;

		case 4:
			//Check For out of bounds and overlapping
			check_coordinate = 0;
			while (check_coordinate == 0)
			{
				direction = get_hor_or_vert();
				generate_start_pt(5, direction, NUM_ROWS, NUM_COLS, &row_st, &col_st);
				check_coordinate = check_outbounds(player1_board, direction, 4, col_st, row_st);
			}
			//Populating ships into board
			pop_ships(player1_board, 2, 'd', direction, row_st, col_st);
			
			break;

		default:
			printf("Something went south, you probably entered an invalid option!");
		}
	}

	//for loop to enter coordinates in an array for storage


}


/***********************************************************
              Ship Populating
 ***********************************************************/
//Function populates ships based on user entered parameters
void pop_ships(char p1_board[][NUM_COLS], int num_cells, char ship_type_character,int direction, int row_start, int col_start)
{
	int horizontal = 0, vertical = 0, horizontal_or_vertical = 0, index = 0;

	/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	   CODE FOR PICKING HORIZONTAL OR VERTICAL
	  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
	horizontal_or_vertical = direction;


	if (horizontal_or_vertical == 1)
	{
		for ( ; index < num_cells; ++index)
		{
			p1_board[row_start + index][col_start] = ship_type_character;
		}
	}
	if (horizontal_or_vertical == 2)
	{
		for (index; index < num_cells; ++index) //outer loop for which row we are in
		{
			p1_board[row_start][col_start + index] = ship_type_character;
		}
	}
	//else
	//{
	//	printf("Something went wrong, error code: horizontal_or_vertical = %d \n", horizontal_or_vertical);
	//}

}

/*888888888888888888888888888888888888
Functions For Random Populating Ships
88888888888888888888888888888888888888*/
void generate_start_pt(int ship_length, int direction, int rows, int cols, int *row_st, int *col_st)
{
	if (direction == 2) // horizontal
	{
		*row_st = rand() % rows; // 0 - 9
		*col_st = rand() % (cols - ship_length + 1);
	}
	else // vertical
	{
		*row_st = rand() % (rows - ship_length + 1);
		*col_st = rand() % cols; // 0 - 9
	}
}


/*88888888888888888888888888888888888
   Directional Decisions
8888888888888888888888888888888888888*/
int get_hor_or_vert(void)
{
	int horizontal_or_vertical = 0;		//Set your values to stuff out of range for debugging

	horizontal_or_vertical = rand() % 2 + 1;

	return horizontal_or_vertical;
}


/*******************************************************************
                            Coordinate 
 *******************************************************************/

 //Function that gets coordinates from the user
//One array will be the ship coordinate array
//Does not work
void get_coordinate(int * pXvalue, int * pYvalue)
{
	do
	{
		printf("Enter X value [between 0 - 9] ::>  ");
		scanf("%d", pXvalue);
	}while (*pXvalue < 0 || *pXvalue > 9);

	do
	{
		printf("Enter Y value [between 0 - 9] ::>  ");
		scanf("%d", pYvalue);
	}while (*pYvalue < 0 || *pYvalue > 9);
	/*
	Code for checking coordinate and make sure that ship is within bounds,===================================================INSERT HERE!
	and not populate over ships
	*/
}


//Get Direction, Vertical or Horizontal
int get_direction()
{
	int hor_or_vert = 0;

	printf("Do you want to go Vertical or Horizontal from your coordinate? \n");
	printf("1 For Vertical \n");
	printf("2 For Horizontal \n");
	printf("::> ");

	scanf("%d", &hor_or_vert);

	while (hor_or_vert <1 || hor_or_vert > 2)
	{
		printf("VALUE MUST BE 1 or 2!!\n\n");
		printf("1 For Vertical \n");
		printf("2 For Horizontal \n");
		printf("::> ");
		scanf("%d", &hor_or_vert);
	}
	return hor_or_vert;
}


//Gets X Coordinate
int get_x(void)
{
	int enter_x = -1;

	do {
		printf("Enter X value (Between 0 - 9): ");
		scanf("%d", &enter_x);
	} while (enter_x < 0 || enter_x > 9);
	return enter_x;
}
//Gets Y Coordinate
int get_y(void)
{
	int enter_y = -1;

	do {
		printf("Enter Y value (Between 0 - 9): ");
		scanf("%d", &enter_y);
	} while (enter_y < 0 || enter_y > 9);
	return enter_y;
}


/*
Function for checking coordinate and make sure that ship is within bounds,
and not populate over ships
*/
int 
check_outbounds(char player1_board[][NUM_COLS], int direction, int ship_size, int x_value, int y_value)
{
	int good_to_go = -1;
	//run a loop to check for characters other than '~'
	
	if (direction == 1)
	{
		for (int i = 0; i < ship_size; i++)
		{
			if ((player1_board[y_value + i][x_value] != '~') || (y_value + ship_size) > 10)
			{
				good_to_go = 0;
				break;
			}
			else
			{
				good_to_go = 1;
			}
		}
	}
	if (direction == 2)
	{
		for (int i = 0; i < ship_size; i++)
		{
			if ((player1_board[y_value][x_value + i] != '~') || (x_value + ship_size) > 10)
			{
				good_to_go = 0;
				break;
			}
			else
			{
				good_to_go = 1;
			}
		}
	}
	return good_to_go;
}


/******************************************************************************************
                                       File Functions
*******************************************************************************************/

void test_write_file(FILE *file_to_test_write)
{
	char file_test_string[1000] = { '\0' };
	
	printf("What do you want to write to file for testing?");
	gets(file_test_string);
	fputs(file_test_string, file_to_test_write);
}


/******************************************************************************************
                                             Menu
*******************************************************************************************/

//Welcome Screen with title and destructions
void welcome_screen(void)
{
	char rules[] = "Battleship is a two player game. \nThe objective of the game is to sink all ships in your enemy's fleet. \nThe Player to sink his/her enemy's fleet first wins. \nBoth players' fleets consist of 5 ships that are hidden from the enemy. \nEach ship may be differentiated by its ""size"" (besides the Cruiser and Submarine) or number of cells it expands on the game board. \nThe Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells. \nPress ENTER to start the game!";

	printf("-=--=-==---=-=---=-=--=----=- Welcome To Battleship -=--=-==---=-=---=-=--=----=- \n\n");

	printf("%s \n\n", rules);

	system("pause");
	system("cls");
}

void start_menu(void)
{
	system("color 8f");
	printf("    -=-=-==---=-=---=-=--= Battleship =--=-=---=-=--=-=- \n\n");
	printf("           Please select an option from the menu: \n");
	printf("    1. Enter ships manually using a starting coordinate\n");
	printf("    2. Program randomly place ships \n");
	printf("::>  ");

	//For testing purposes only:
	/*system("pause");*/
}

//Gets the Players decision to  Manually place ships or Randomly enter
int menu_decision(void)
{
	int option = 0;

	scanf("%d", &option);

		while (option < 1 || option >2)
		{
			system("cls");
			system("color 4");

			printf("%c", 7);
			printf("]]]]]]]]]Please Enter A VALID INTEGER NUMBER OF 1 or 2[[[[[[[[ \n\n");
			start_menu();
			scanf("%d", &option);
		}
	return option;
}