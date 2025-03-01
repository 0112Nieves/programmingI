#include <stdio.h>
#include <stdint.h>
#define NC printf("\e[0m")
#define RED printf("\e[0;31m")
#define GRN printf("\e[0;32m")
#define BLUE printf("\e[0;34m")
#define YELLOW printf("\e[0;33m")
#define WHITE printf("\e[0;37m")
#define ORANGE printf("\e[0;35m")

//setup cube
char cube[6][9] = 
{           {'R','R','R',
             'R','R','R',
             'R','R','R'},
            {'B','B','B',
             'B','B','B',
             'B','B','B'},
            {'O','O','O',
             'O','O','O',
             'O','O','O'},
            {'G','G','G',
             'G','G','G',
             'G','G','G'},
            {'W','W','W',
             'W','W','W',
             'W','W','W'},
            {'Y','Y','Y',
             'Y','Y','Y',
             'Y','Y','Y'}      };
             
char current_list[6][9] = 
{           {'R','R','R',
             'R','R','R',
             'R','R','R'},
            {'B','B','B',
             'B','B','B',
             'B','B','B'},
            {'O','O','O',
             'O','O','O',
             'O','O','O'},
            {'G','G','G',
             'G','G','G',
             'G','G','G'},
            {'W','W','W',
             'W','W','W',
             'W','W','W'},
            {'Y','Y','Y',
             'Y','Y','Y',
             'Y','Y','Y'}      };

//movement function
void movement1(){
	for( int32_t i = 0 ; i < 3 ; i++ ){
		cube[0][i] = current_list[3][i];
		cube[1][i] = current_list[0][i];
		cube[2][i] = current_list[1][i];
		cube[3][i] = current_list[2][i];
	}
	cube[4][0]=current_list[4][2];
    cube[4][1]=current_list[4][5];
    cube[4][2]=current_list[4][8];
    cube[4][3]=current_list[4][1];
    cube[4][5]=current_list[4][7];
    cube[4][6]=current_list[4][0];
    cube[4][7]=current_list[4][3];
    cube[4][8]=current_list[4][6];
}

void movement2(){
	for( int32_t i = 3 ; i < 6 ; i++ ){
		cube[0][i] = current_list[3][i];
		cube[1][i] = current_list[0][i];
		cube[2][i] = current_list[1][i];
		cube[3][i] = current_list[2][i];
	}
}

void movement3(){
	for( int32_t i = 6 ; i < 9 ; i++ ){
		cube[0][i] = current_list[3][i];
		cube[1][i] = current_list[0][i];
		cube[2][i] = current_list[1][i];
		cube[3][i] = current_list[2][i];
	}
	cube[5][0]=current_list[5][6];
    cube[5][1]=current_list[5][3];
    cube[5][2]=current_list[5][0];
    cube[5][3]=current_list[5][7];
    cube[5][5]=current_list[5][1];
    cube[5][6]=current_list[5][8];
    cube[5][7]=current_list[5][5];
    cube[5][8]=current_list[5][2];
}

void movement4(){
	for( int32_t i = 0 ; i < 7 ; i = i + 3 ){
		cube[0][i] = current_list[4][i];
		cube[5][i] = current_list[0][i];
		cube[2][8 - i] = current_list[5][i];
		cube[4][i] = current_list[2][8 - i];
	}
	cube[3][0]=current_list[3][6];
    cube[3][1]=current_list[3][3];
    cube[3][2]=current_list[3][0];
    cube[3][3]=current_list[3][7];
    cube[3][5]=current_list[3][1];
    cube[3][6]=current_list[3][8];
    cube[3][7]=current_list[3][5];
    cube[3][8]=current_list[3][2];
}

void movement5(){
	for( int32_t i = 1 ; i < 8 ; i = i + 3 ){
		cube[0][i] = current_list[4][i];
		cube[5][i] = current_list[0][i];
		cube[2][8 - i] = current_list[5][i];
		cube[4][i] = current_list[2][8 - i];
	}
}

void movement6(){
	for( int32_t i = 2 ; i < 9 ; i = i + 3 ){
		cube[0][i] = current_list[4][i];
		cube[5][i] = current_list[0][i];
		cube[2][8 - i] = current_list[5][i];
		cube[4][i] = current_list[2][8 - i];
	}
	cube[1][0]=current_list[1][2];
    cube[1][1]=current_list[1][5];
    cube[1][2]=current_list[1][8];
    cube[1][3]=current_list[1][1];
    cube[1][5]=current_list[1][7];
    cube[1][6]=current_list[1][0];
    cube[1][7]=current_list[1][3];
    cube[1][8]=current_list[1][6];
}

void change_color( char color ){
	switch(color){
		case 'R':
			RED;
			break;
		case 'B':
			BLUE;
			break;
		case 'O':
			ORANGE;
			break;
		case 'G':
			GRN;
			break;
		case 'W':
			WHITE;
			break;
		case 'Y':
			YELLOW;
			break;
	}
}

int main()
{	
	int32_t in = 0;
	
	printf( "Start:\n" );
	printf( "\e[0;31m* * *\e[0m\n" );
	printf( "\e[0;31m* * *\e[0m\n" );
	printf( "\e[0;31m* * *\e[0m\n" );
	
	while(1){
		//record current list
		for( int32_t i = 0 ; i < 6 ; i++ ){
			for( int32_t j = 0 ; j < 9 ; j++ ){
				current_list[i][j] = cube[i][j];
			}
		}
		
		//input
		printf( "Input [0-6]: " );
		scanf( "%d" , &in );
		
		//end the game
		if( in == 0 ){
			break;
		}
		
		//commend
		switch(in){
			case 1:
				movement1();
				break;
			case 2:
				movement2();
				break;
			case 3:
				movement3();
				break;
			case 4:
				movement4();
				break;
			case 5:
				movement5();
				break;
			case 6:
				movement6();
				break;
			default:
				printf( "error input\n" );
				break;
		}
		for( int32_t j = 0 ; j < 9 ; j++ ){
			change_color(cube[0][j]);
			printf( "* " );
			NC;
			if( (j == 2) || (j == 5) || (j == 8) ){
				printf( "\n" );
			}
		}
	}
	return 0;
}
