#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "basic.h"

int32_t move_way( int32_t x, int32_t y );
int32_t final_point( int32_t i );
int32_t bonus( int32_t i );
void all_case(void);
int32_t max_route(void);
void total_point(void);
void total_type(void);
int32_t count_type(void);

int32_t maximum[3] = {0};
int32_t pick[70][8] = {0};
int32_t location[70] = {0};
int32_t score = 0;
int32_t point[5][5] = {0};
int32_t total[70] = {0};
int32_t movement[70][9];

int32_t path[70][2] = {0};

int main()
{	
//printf( "main\n" );
	//ID1 ID2對應point的值(已加上)
	for( int32_t i = 0 ; i < 5 ; i++ ){
		for( int32_t j = 0 ; j < 5 ; j++ ){
			if( AttributeID1[i][j] == 1 ){
				point[i][j] += 125;
			}
			if( AttributeID1[i][j] == 2 ){
				point[i][j] += 100;
			}
			if( AttributeID1[i][j] == 3 ){
				point[i][j] += 75;
			}
			if( AttributeID1[i][j] == 4 ){
				point[i][j] += 50;
			}
			if( AttributeID1[i][j] == 5 ){
				point[i][j] += 50;
			}
			if( AttributeID1[i][j] == 6 ){
				point[i][j] += 25;
			}
			if( AttributeID1[i][j] == 7 ){
				point[i][j] += 10;
			}
			if( AttributeID2[i][j] == 1 ){
				point[i][j] += 125;
			}
			if( AttributeID2[i][j] == 2 ){
				point[i][j] += 100;
			}
			if( AttributeID2[i][j] == 3 ){
				point[i][j] += 75;
			}
			if( AttributeID2[i][j] == 4 ){
				point[i][j] += 50;
			}
			if( AttributeID2[i][j] == 5 ){
				point[i][j] += 50;
			}
			if( AttributeID2[i][j] == 6 ){
				point[i][j] += 25;
			}
			if( AttributeID2[i][j] == 7 ){
				point[i][j] += 10;
			}
		}
	}
	int32_t x = 0;
	int32_t y = 0;
	move_way( x, y );
	max_route();
	printf( "1st Top Total Point: %d. Type of five Artifacts: " , maximum[0] );
	for( int32_t i = 0 ; i < 8 ; i++ ){
		if( pick[ maximum[0] ][i] != 0 ){
			printf( "%d " , pick[ maximum[0] ][i] );
		}
	}
	printf( ".\n" );
	printf( "2nd Top Total Point: %d. Type of five Artifacts: " , maximum[1] );
	for( int32_t i = 0 ; i < 8; i++ ){
		if( pick[ maximum[1] ][i] != 0 ){
			printf( "%d " , pick[ maximum[1] ][i] );
		}
	}
	printf( ".\n" );
	printf( "3rd Top Total Point: %d. Type of five Artifacts: " , maximum[2] );
	for( int32_t i = 0 ; i < 8 ; i++ ){
		if( pick[ maximum[2] ][i] != 0 ){
			printf( "%d " , pick[ maximum[2] ][i] );
		}
	}
	printf( ".\n" );
	printf( "Target Boss required: %d\n" , bossPoint );
	//final result
	if( maximum[2] >= bossPoint ){
		printf( "\033[32;mReady Perfectly!\033[0m\n" );
	}
	else{
		printf( "\033[31;mGonna be OK.\033[0m\n" );
	}
	return 0;
}

int32_t num = 0;
int32_t source[70] = {0};
void all_case( void ){
//printf( "all_case\n" );
//printf( "main\n" );
	source[1]  = 100001111;
	source[2]  = 100010111;
	source[3]  = 100011011;
	source[4]  = 100011101;
	source[5]  = 100011110;
	source[6]  = 100100111;
	source[7]  = 100101011;
	source[8]  = 100101101;
	source[9]  = 100101110;
	source[10] = 100110011;
	source[11] = 100110101;
	source[12] = 100110110;
	source[13] = 100111001;
	source[14] = 100111010;
	source[15] = 100111100;
	source[16] = 101000111;
	source[17] = 101001011;
	source[18] = 101001101;
	source[19] = 101001110;
	source[20] = 101100011;
	source[21] = 101100101;
	source[22] = 101100110;
	source[23] = 101101001;
	source[24] = 101101010;
	source[25] = 101101100;
	source[26] = 101110001;
	source[27] = 101110010;
	source[28] = 101110100;
	source[29] = 101111000;
	source[30] = 101010011;
	source[31] = 101010101;
	source[32] = 101011001;
	source[33] = 101011010;
	source[34] = 101010110;
	source[35] = 101011100;
	source[36] = 10000111;
	source[37] = 10001011;
	source[38] = 10001101;
	source[39] = 10001110;
	source[40] = 10010011;
	source[41] = 10010101;
	source[42] = 10010110;
	source[43] = 10011001;
	source[44] = 10011010;
	source[45] = 10011100;
	source[46] = 10100011;
	source[47] = 10100101;
	source[48] = 10100110;
	source[49] = 10101001;
	source[50] = 10101010;
	source[51] = 10101100;
	source[52] = 10110001;
	source[53] = 10110010;
	source[54] = 10110100;
	source[55] = 10111000;
	source[56] = 11000011;
	source[57] = 11000101;
	source[58] = 11000110;
	source[59] = 11001001;
	source[60] = 11001010;
	source[61] = 11001100;
	source[62] = 11010001;
	source[63] = 11010010;
	source[64] = 11010100;
	source[65] = 11011000;
	source[66] = 11100001;
	source[67] = 11100010;
	source[68] = 11100100;
	source[69] = 11101000;
	source[70] = 11110000;
}
	
int32_t move_way( int32_t x, int32_t y ){
//printf( "move_way\n" );
//printf( "main\n" );
	all_case();
	//turn right or turn down
	for( int32_t i = 1 ; i <= 70 ; i++ ){
		for( int32_t j = 0 ; j < 8 ; j++ ){
			num = source[i] % 10;
			movement[i][j] = num;
			source[i] /= 10;
		}
	}
	
	//commend
	for( int32_t i = 1 ; i <= 70 ; i++ ){
		for( int32_t j = 0 ; j < 8 ; j++ ){
			if( movement[i][j] == 0 ){
				path[i][0] += 1;
			}
			else{
				path[i][1] += 1;
			}
		}
	}
}

void total_point(void){
	for( int32_t i = 1 ; i <= 70 ; i++ ){
		for( int32_t j = 0 ; j < 8 ; j++ ){
			location[i] += point[ path[i][0] ][ path[i][1] ];
		}
	}
	return;
} 

int32_t value[70] = {0};

void total_type(void){
//printf( "total_type\n" );
//printf( "main\n" );
	for( int32_t i = 1 ; i <= 70 ; i++ ){
		for( int32_t j = 0 ; j < 8 ; j++ ){
			pick[i][j] = TypeOfAttribute[ path[i][0] ][ path[i][1] ];
		}
	}
	return;
}

int32_t type1 = 0;
int32_t type2 = 0;
int32_t type3 = 0;
int32_t type4 = 0;
int32_t type5 = 0;
int32_t type6 = 0;
int32_t type7 = 0;

//Type bonus
int32_t bonus( int32_t i ){
//printf( "bonus\n" );
//printf( "main\n" );
	total_type();
	for( int32_t j = 0 ; j < 8 ; j++ ){
		switch( pick[i][j] ){
			case 1:
			type1 ++;
			break;
			
			case 2:
			type2 ++;
			break;
			
			case 3:
			type3 ++;
			break;
			
			case 4:
			type4 ++;
			break;
			
			case 5:
			type5 ++;
			break;
			
			case 6:
			type6 ++;
			break;
			
			case 7:
			type7 ++;
			break;
			
			default:
			break;
		}
	}
}

int32_t count_type(void){
//printf( "count_type\n" );
//printf( "main\n" );
	//count type point
	if( type1 >= 2 && type1 < 4 ){
		score += 10;
	}
	if( type1 >= 4 ){
		score += 160;
	}
	if( type2 >= 2 && type2 < 4 ){
		score += 20;
	}
	if( type2 >= 4 ){
		score += 150;
	}
	if( type3 >= 2 && type3 < 4 ){
		score += 35;
	}
	if( type3 >= 4 ){
		score += 75;
	}
	if( type4 >= 2 && type4 < 4 ){
		score += 50;
	}
	if( type4 >= 4 ){
		score += 135;
	}
	if( type5 >= 2 && type5 < 4 ){
		score += 60;
	}
	if( type5 >= 4 ){
		score += 125;
	}
	if( type6 >= 2 && type6 < 4 ){
		score += 75;
	}
	if( type6 >= 4 ){
		score += 95;
	}
	if( type7 >= 2 && type7 < 4 ){
		score += 100;
	}
	if( type7 >= 4 ){
		score += 110;
	}
	return score;
}

//count one route maximum
int32_t final[22] = {0};
int32_t final_point( int32_t i ){ 
//printf( "final_point\n" );
//printf( "main\n" );
	total_point();
	total_type();  
	 if( value[1] ){
	 	pick[i][0] = 0;
	 	pick[i][1] = 0;
	 	location[0] = 0;
	 	location[1] = 0;
	 }
	 if( value[2] ){
	 	pick[i][0] = 0;
	 	pick[i][2] = 0;
	 	location[0] = 0;
	 	location[2] = 0;
	 }
	 if( value[3] ){
	 	pick[i][0] = 0;
	 	pick[i][3] = 0;
	 	location[0] = 0;
	 	location[3] = 0;
	 }
	 if( value[4] ){
	 	pick[i][0] = 0;
	 	pick[i][4] = 0;
	 	location[0] = 0;
	 	location[4] = 0;
	 }
	 if( value[5] ){
	 	pick[i][0] = 0;
	 	pick[i][5] = 0;
	 	location[0] = 0;
	 	location[5] = 0;
	 }
	 if( value[6] ){
	 	pick[i][0] = 0;
	 	pick[i][6] = 0;
	 	location[0] = 0;
	 	location[6] = 0;
	 }
	 if( value[7] ){
	 	pick[i][1] = 0;
	 	pick[i][2] = 0;
	 	location[1] = 0;
	 	location[2] = 0;
	 }
	 if( value[8] ){
	 	pick[i][1] = 0;
	 	pick[i][3] = 0;
	 	location[1] = 0;
	 	location[3] = 0;
	 }
	 if( value[9] ){
	 	pick[i][1] = 0;
	 	pick[i][4] = 0;
	 	location[1] = 0;
	 	location[4] = 0;
	 }
	 if( value[10] ){
	 	pick[i][1] = 0;
	 	pick[i][5] = 0;
	 	location[1] = 0;
	 	location[5] = 0;
	 }
	 if( value[11] ){
	 	pick[i][1] = 0;
	 	pick[i][6] = 0;
	 	location[1] = 0;
	 	location[6] = 0;
	 }
	 if( value[12] ){
	 	pick[i][2] = 0;
	 	pick[i][3] = 0;
	 	location[2] = 0;
	 	location[3] = 0;
	 }
	 if( value[13] ){
	 	pick[i][2] = 0;
	 	pick[i][4] = 0;
	 	location[2] = 0;
	 	location[4] = 0;
	 }
	 if( value[14] ){
	 	pick[i][2] = 0;
	 	pick[i][5] = 0;
	 	location[2] = 0;
	 	location[5] = 0;
	 }
	 if( value[15] ){
	 	pick[i][2] = 0;
	 	pick[i][6] = 0;
	 	location[2] = 0;
	 	location[6] = 0;
	 }
	 if( value[16] ){
	 	pick[i][3] = 0;
	 	pick[i][4] = 0;
	 	location[3] = 0;
	 	location[4] = 0;
	 }
	 if( value[17] ){
	 	pick[i][3] = 0;
	 	pick[i][5] = 0;
	 	location[3] = 0;
	 	location[5] = 0;
	 }
	 if( value[18] ){
	 	pick[i][3] = 0;
	 	pick[i][6] = 0;
	 	location[3] = 0;
	 	location[6] = 0;
	 }
	 if( value[19] ){
	 	pick[i][4] = 0;
	 	pick[i][5] = 0;
	 	location[4] = 0;
	 	location[5] = 0;
	 }
	 if( value[20] ){
	 	pick[i][4] = 0;
	 	pick[i][6] = 0;
	 	location[4] = 0;
	 	location[6] = 0;
	 }
	 if( value[21] ){
	 	pick[i][5] = 0;
	 	pick[i][6] = 0;
	 	location[5] = 0;
	 	location[6] = 0;
	 }
	 
	 //add
	 for( int32_t i = 1 ; i < 22 ; i++ ){
	 	for( int32_t j = 0 ; j < 70 ; j++ ){
	 		for( int32_t k = 0 ; k < 8 ; k++ ){
	 			value[j] += pick[j][k];
	 		}
	 	}
	 	bonus(i);
	 	value[i] += score;
	 }
	 
	 //sorting
	 int32_t max = 0;
	 max = final[0];
	 for( int32_t i = 1 ; i < 22 ; i++ ){
	 	if( value[i] > max ){
	 		max = value[i];
	 	}
	 }
	 return max;
}

//find the maximum
int32_t max_route(void){
//printf( "max_route\n" );
//printf( "main\n" );
	for( int32_t i = 1 ; i <= 70 ; i++ ){ 
		final_point(i);
	}
	maximum[0] = value[1];
	maximum[1] = value[1];
	maximum[2] = value[1];
	for( int32_t i = 0 ; i < 70 ; i++ ){
		if( value[i] > maximum[0] ){
			maximum[1] = maximum[0];
			maximum[0] = value[i];
		}
		else if( total[i] > maximum[1] ){
			maximum[2] = maximum[1];
			maximum[1] = value[i];
		}
		else if( total[i] > maximum[2] ){
			maximum[2] = value[i];
		}
	}
}
