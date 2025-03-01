#include <stdio.h>
#include <stdint.h>
#include "mine.h"
int32_t new_board[16][30];
int32_t set_values( int32_t x, int32_t y, int32_t value );
int32_t count_area( void );
int32_t total_area( void );
int32_t check( int32_t i, int32_t j, int32_t k );
void maximum( void );

int32_t new_board1( int32_t const board[16][30] ){

	//find mines
	for( int32_t i = 0 ; i < 16 ; i++ ){
		for( int32_t j = 0 ; j < 30 ; j++ ){
			if( board[i][j] == 1 ){
				new_board[i][j] = -2;
			}
		}
	}
	
	//find numbers
	for( int32_t i = 0 ; i < 16 ; i++ ){
		for( int32_t j = 0 ; j < 30 ; j++ ){
		    //printf( "i=%d, j=%d\n\t", i, j );
			//not mine
			if( board[i][j] == 0 ){
				//left
				if( j - 1 >= 0 ){
					if( board[i][j - 1] == 1 ){
						new_board[i][j]++;
						//printf( "left, " );
					}
				}
				//left up
				if( i - 1 >= 0 && j - 1 >= 0 ){
					if( board[i - 1][j - 1] == 1 ){
						new_board[i][j]++;
						//printf( "left up, " );
					}
				}
				//left down
				if( i + 1 < 16 && j - 1 >= 0 ){
					if( board[i + 1][j - 1] == 1 ){
						new_board[i][j]++;
						//printf( "left down, " );
					}
				}
				//right
				if( j + 1 < 30 ){
					if( board[i][j + 1] == 1 ){
						new_board[i][j]++;
						//printf( "right, " );
					}
				}
				//right up
				if( i - 1 >= 0 && j + 1 < 30 ){
					if( board[i - 1][j + 1] == 1 ){
						new_board[i][j]++;
						//printf( "right up, " );
					}
				}
				//right down
				if( i + 1 < 16 && j + 1 < 30 ){
					if( board[i + 1][j + 1] == 1 ){
						new_board[i][j]++;
						//printf( "right down, " );
					}
				}
				//up
				if( i - 1 >= 0 ){
					if( board[i - 1][j] == 1 ){
						new_board[i][j]++;
						//printf( "up, " );
					}
				}
				//down
				if( i + 1 < 16 ){
					if( board[i + 1][j] == 1 ){
						new_board[i][j]++;
						//printf( "down, " );
					}
				}
				//printf( "\n\t%d\n", new_board[i][j] );
			}
		}
	}
	for( int32_t i = 0 ; i < 16 ; i++ ){
		for( int32_t j = 0 ; j < 30 ; j++ ){
			if( new_board[i][j] != -2 && new_board[i][j] != 0 ){
	 			new_board[i][j] = -1;
	 		}
	 	}
	 }
	return 0;	
}

//the same area
int32_t set_values( int32_t x, int32_t y, int32_t value ){
	//printf( "%d, %d, value: %d\n", x, y,value );
	if( x < 0 || x >= 16 || y < 0 || y >= 30 )
	{
		return 0;
	}
	
	if( new_board[x][y] != 0 )
	{
		return 0;
	}
	
	new_board[x][y] = value;
	
	set_values( x - 1, y - 1, value );
	set_values( x - 1, y, value );
	set_values( x - 1, y + 1, value );
	set_values( x, y - 1, value );
	set_values( x, y + 1, value );
	set_values( x + 1, y - 1, value );
	set_values( x + 1, y, value );
	set_values( x + 1, y + 1, value );
}

//count the number
int32_t value = 1;
int32_t count_area(void){
	for( int32_t i = 0 ; i < 16 ; i++ )
	{
		for( int32_t j = 0 ; j < 30 ; j++ )
		{
			if( new_board[i][j] == 0 )
			{
				set_values( i, j, value );
				value++;
			}
		}
	}
	total_area();
}

//count area
int32_t total[481] = {0};
int32_t total_area(void){
	for( int32_t i = 0 ; i < 16 ; i++ )
	{
		for( int32_t j = 0 ; j < 30 ; j++ )
		{
			if( new_board[i][j] != -1 && new_board[i][j] != -2 )
			{
				total[ new_board[i][j] ]++;
				continue;
			}
			
			if( new_board[i][j] == -1 )
			{
				for( int k = 0 ; k < 481 ; k++ )
				{
					if( check( i, j, k ) == 1 )
					{
						total[k]++;
					}
				}
			}	
		}
	}	
}

int32_t check( int32_t i, int32_t j, int32_t k ){
	for( int32_t k = 0 ; k < 481 ; k++ ){
		if( i - 1 >= 0 && j - 1 >= 0 ){
			if( new_board[i - 1][j - 1] == k ){
				return 1;
			}
		}
		if( i - 1 >= 0 ){
			if( new_board[i - 1][j] == k ){
				return 1;
			}
		}
		if( i - 1 >= 0 && j + 1 < 30 ){
			if( new_board[i - 1][j + 1] == k ){
				return 1;
			}
		}
		if( j - 1 >= 0 ){
			if( new_board[i][j - 1] == k ){
				return 1;
			}
		}
		if( j + 1 < 30 ){
			if( new_board[i][j + 1] == k ){
				return 1;
			}
		}
		if( i + 1 < 16 && j - 1 >= 0 ){
			if( new_board[i + 1][j - 1] == k ){
				return 1;
			}
		}
		if( i + 1 < 16 ){
			if( new_board[i + 1][j] == k ){
				return 1;
			}
		}
		if( i + 1 < 16 && j + 1 < 30 ){
			if( new_board[i + 1][j + 1] == k ){
				return 1;
			}
		}
	}
}

int32_t max = 0;
int32_t max_id = -1;
void maximum(void){
	max = total[0];
	for( int32_t i = 0 ; i < 481 ; i++ ){
		if( total[i] > max ){
			max = total[i];
			max_id = i;
		}
	}
}

int find_good_cells( const int32_t board[16][30], int32_t row[480], int32_t col[480] ){
	new_board1( board );
	count_area();
	total_area();
	maximum();
	int32_t idx = 0;

	for( int32_t i = 0 ; i < 16 ; i++ ){
		for( int32_t j = 0 ; j < 30 ; j++ ){
			if( new_board[i][j] == max_id )
			{
				row[idx] = i;
				col[idx] = j;
				idx++;
			}
			else{
				row[idx] = -1;
				col[idx] = -1;
			}
		}
	}
	
	return 0;	
}
