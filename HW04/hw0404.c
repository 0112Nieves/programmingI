#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//Surround the board
bool is_valid_input(int32_t y, int32_t x){
    
    bool result = 0;
    switch(y){
        case 0:case 16:
            if( x == 0 )
                result = 1;
            break;
        case 1:case 15:
            if( x >= 0 && x <= 1 )
                result = 1;
            break;
        case 2:case 14:
            if( x >= 0 && x <= 2 )
                result = 1;
            break;
        case 3:case 13:
            if( x >= 0 && x <= 3 )
                result = 1;
            break;
        case 4:case 12:
            if( x >= 0 && x <= 12 )
                result = 1;
            break;
        case 5:case 11:
            if( x >= 0 && x <= 11 )
                result = 1;
            break;
        case 6:case 10:
            if( x >= 0 && x <= 10 )
                result = 1;
            break;
        case 7:case 9:
            if( x >= 0 && x <= 9 )
                result = 1;
            break;
        case 8:
            if( x >= 0 && x <= 8 )
                result = 1;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

//change to virtual coordinate
int convert_virtual_x(int32_t y, int32_t x){
    switch(y){
        case 0:case 1:case 2:case 3:case 8:case 9:case 10:case 11:case 12:
            x += 4;
            break;
        case 4:
            x += 0;
            break;
        case 5:
            x += 1;
            break;
        case 6:
            x += 2;
            break;
        case 7:
            x += 3;
            break;
        case 13:
            x += 9;
            break;
        case 14:
            x += 10;
            break;
        case 15:
            x += 11;
            break;
        case 16:
            x += 12;
            break;
    }
    
    return x;
}

//change to real coordinate
int convert_real_x(int32_t y, int32_t x){
    switch(y){
        case 0:case 1:case 2:case 3:case 8:case 9:case 10:case 11:case 12:
            x -= 4;
            break;
        case 4:
            x -= 0;
            break;
        case 5:
            x -= 1;
            break;
        case 6:
            x -= 2;
            break;
        case 7:
            x -= 3;
            break;
        case 13:
            x -= 9;
            break;
        case 14:
            x -= 10;
            break;
        case 15:
            x -= 11;
            break;
        case 16:
            x -= 12;
            break;
    }
    
    return x;
}

char board[17][13]={
                            {'Y'},
                          {'Y','Y'},
                        {'Y','Y','Y'},
                      {'Y','Y','Y','Y'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W'},
      {'W','W','W','W','W','W','W','W','W','W','W','W'},
        {'W','W','W','W','W','W','W','W','W','W','W'},
          {'W','W','W','W','W','W','W','W','W','W'},
            {'W','W','W','W','W','W','W','W','W'},
          {'G','W','W','W','W','W','W','W','W','R'},
        {'G','G','W','W','W','W','W','W','W','R','R'},
      {'G','G','G','W','W','W','W','W','W','R','R','R'},
    {'G','G','G','G','W','W','W','W','W','R','R','R','R'},
                      {'W','W','W','W'},
                        {'W','W','W'},
                          {'W','W'},
                            {'W'}

};

void show_board(){

    for( int32_t i = 0 ; i < 17 ; i++ ){
    
        if( i == 3 || i == 13 ){
            for( int32_t k = 0 ; k < 18 ; k++ )
                printf( " " );
        }

        if( i == 2 || i == 14 ){
            for( int32_t k = 0 ; k < 20 ; k++ )
                printf( " " );
        }

        if( i == 1 || i == 15 ){
            for( int32_t k = 0 ; k < 22 ; k++ )
                printf( " " );
        }

        if( i == 0 || i == 16 ){
            for( int32_t k = 0 ; k < 24 ; k++ )
                printf( " " );
        }

        if( i == 5 || i == 11 ){
            for( int32_t k = 0 ; k < 2 ; k++ )
                printf( " " );
        }

        if( i == 6 || i == 10){
            for( int32_t k = 0 ; k < 4 ; k++ )
                printf( " " );
        }

        if( i == 7 || i == 9 ){
            for( int32_t k = 0 ; k < 6 ; k++ )
                printf( " " );
        }

        if( i == 8 ){
            for( int32_t k = 0 ; k < 8 ; k++ )
                printf( " " );
        }

        for( int32_t j = 0 ; j < 13 ; j++ ){

            if( board[i][j] == 'Y' ) 
                printf( "\e[0;33m*\e[0m   " );

            if( board[i][j] == 'G' )
                printf( "\e[0;32m*\e[0m   " );

            if( board[i][j] == 'R' )
                printf( "\e[0;31m*\e[0m   " );
                
            if( board[i][j] == 'W' )
                printf( "*   " );         
        }
        printf( "\n\n" );
    }
    return;
}

bool end(){
	if( board[4][0] == 'R' && board[4][1] == 'R' && board[4][2] == 'R' && board[4][3] == 'R' && board[5][0] == 'R' && board[5][1] == 'R' && board[5][2] == 'R' && board[6][0] == 'R' && board[6][1] == 'R' && board[7][0] == 'R' ){
        	printf( "The Winner is Red\n" );
        	return 1;
        }
        if( board[13][0] == 'Y' && board[13][1] == 'Y' && board[13][2] == 'Y' && board[13][3] == 'Y' && board[14][0] == 'Y' && board[14][1] == 'Y' && board[14][2] == 'Y' && board[15][0] == 'Y' && board[15][1] == 'Y' && board[16][0] == 'Y' ){
        	printf( "The Winner is Yellow\n" );
        	return 1;
        }
        if( board[4][12] == 'G' && board[4][11] == 'G' && board[4][10] == 'G' && board[4][9] == 'G' && board[5][11] == 'G' && board[5][10] == 'G' && board[5][9] == 'G' && board[6][10] == 'G' && board[6][9] == 'G' && board[7][9] == 'G' ){
        	printf( "The Winner is Green\n" );
        	return 1;
        }
    return 0;
}
//turn one block
bool side_movable(int32_t y0, int32_t x0, int32_t y1, int32_t x1){

    if( is_valid_input(y0, x0) == 0 || is_valid_input(y1, x1) == 0 )
        return 0;
    bool result = 0;
    int32_t vir_x0 = convert_virtual_x(y0, x0);
    if( y0 == y1 ){
        if( (board[y0][x0+1] == 'W') && (x1 == x0+1) )
            result = 1;
        if( (board[y0][x0-1] == 'W' ) && ( x1 == x0-1) )
            result = 1;
    }
    else{
        if((board[y0+1][convert_real_x(y0+1,vir_x0)]=='W')&&(y1==y0+1&&x1==convert_real_x(y0+1,vir_x0)))   
            result = 1; //left down
        if((board[y0+1][convert_real_x(y0+1,vir_x0+1)]=='W')&&(y1==y0+1&&x1==convert_real_x(y0+1,vir_x0+1)))
            result = 1;//right down
        if((board[y0-1][convert_real_x(y0-1,vir_x0-1)]=='W')&&(y1==y0-1&&x1==convert_real_x(y0-1,vir_x0-1)))
            result = 1;//left up
        if((board[y0-1][convert_real_x(y0-1,vir_x0)]=='W')&&(y1==y0-1&&x1==convert_real_x(y0-1,vir_x0)))
            result = 1;//right down
    }

    return result;
}

//jump mode
bool jump_movable(int32_t y0, int32_t x0, int32_t y1, int32_t x1){

    if(is_valid_input(y0,x0)==0||is_valid_input(y1,x1)==0)
        return 0;
    if(board[y1][x1]!='W')
        return 0;
    bool result = 0;
    int32_t vir_x0 = convert_virtual_x(y0,x0);//get virtural x
    if((board[y0+1][convert_real_x(y0+1,vir_x0)]=='G'
    ||board[y0+1][convert_real_x(y0+1,vir_x0)]=='Y'
    ||board[y0+1][convert_real_x(y0+1,vir_x0)]=='R')
    &&(board[y0+2][convert_real_x(y0+2,vir_x0)]=='W')
    &&(y1==y0+2&&x1==convert_real_x(y0+2,vir_x0)))
        result = 1;//left down
    if((board[y0+1][convert_real_x(y0+1,vir_x0+1)]=='G'
    ||board[y0+1][convert_real_x(y0+1,vir_x0+1)]=='Y'
    ||board[y0+1][convert_real_x(y0+1,vir_x0+1)]=='R')
    &&(board[y0+2][convert_real_x(y0+2,vir_x0+2)]=='W')
    &&(y1==y0+2&&x1==convert_real_x(y0+2,vir_x0+2)))
        result = 1;//right down
    if((board[y0-1][convert_real_x(y0-1,vir_x0)]=='G'
    ||board[y0-1][convert_real_x(y0-1,vir_x0)]=='Y'
    ||board[y0-1][convert_real_x(y0-1,vir_x0)]=='R')
    &&(board[y0-2][convert_real_x(y0-2,vir_x0)]=='W')
    &&(y1==y0-2&&x1==convert_real_x(y0-2,vir_x0)))
        result = 1;//right up
    if((board[y0-1][convert_real_x(y0-1,vir_x0-1)]=='G'
    ||board[y0-1][convert_real_x(y0-1,vir_x0-1)]=='Y'
    ||board[y0-1][convert_real_x(y0-1,vir_x0-1)]=='R')
    &&(board[y0-2][convert_real_x(y0-2,vir_x0-2)]=='W')
    &&(y1==y0-2&&x1==convert_real_x(y0-2,vir_x0-2)))
        result = 1;//left up
    if((board[y0][x0-1]=='G'
    ||board[y0][x0-1]=='Y'
    ||board[y0][x0-1]=='R')
    &&(board[y0][x0-2]=='W')
    &&(y1==y0 && x1==x0-2))
        result = 1;//left jump
    if((board[y0][x0+1]=='G'
    ||board[y0][x0+1]=='Y'
    ||board[y0][x0+1]=='R')
    &&(board[y0][x0+2]=='W')
    &&(y1==y0 && x1==x0+2))
        result = 1;//right jump
    return result;
}

bool multi_movable(int32_t y0, int32_t x0, int32_t y1, int32_t x1){
    int32_t vir_x0 = convert_virtual_x(y0, x0);
    if(board[y1][x1]!='W')
        return 0;

    if((x0 == x1)&&(y0 == y1))
        return 1;
    
    if(vir_x0-2>0&&y0-2>=0){
        if(jump_movable(y0,x0,y0-2,convert_real_x(y0-2,vir_x0-2))){
            if(multi_movable(y0-2,convert_real_x(y0-2,vir_x0-2),y1,x1))
                return 1;
        }
    }

    if(y0-2>=0){
        if(jump_movable(y0,x0,y0-2,convert_real_x(y0-2,vir_x0))){
            if(multi_movable(y0-2,convert_real_x(y0-2,vir_x0),y1,x1))
                return 1;
        }
    }

    if(jump_movable(y0,x0,y0+2,convert_real_x(y0+2,vir_x0+2))){
        if(multi_movable(y0+2,convert_real_x(y0+2,vir_x0+2),y1,x1))
            return 1;
    }

    if(jump_movable(y0,x0,y0+2,convert_real_x(y0+2,vir_x0))){
        if(multi_movable(y0+2,convert_real_x(y0+2,vir_x0),y1,x1))
            return 1;
    }
    
    if(x0-2>0){
        if(jump_movable(y0,x0,y0,x0-2)){
            if(multi_movable(y0,x0-2,y1,x1))
                return 1;
        }
    }
    
    if(jump_movable(y0,x0,y0,x0+2)){
        if(multi_movable(y0,x0+2,y1,x1))
            return 1;
    }
    
    return 0;
}

//input output
void move_step(){
    while(1){
            char comma, buffer;
            int32_t x0, y0, x1, y1;
            
            printf( "  From: " );
            scanf( "%d%c%d" , &y0 , &comma , &x0 );
            printf( "  To: " );
            scanf( "%d%c%d" , &y1 , &comma , &x1 );
            printf( "\n" );
            if( is_valid_input(y0, x0) == 0 || is_valid_input(y1, x1) == 0 ){
                printf( "please input valid step\n" );
                continue;
            }
            if( (side_movable(y0, x0, y1, x1)) == 0 && multi_movable(y0, x0, y1, x1) == 0 ){
                   printf( "please input valid step\n" );
                   continue;
                }        
            else{
                buffer = board[y0][x0];
                board[y0][x0] = 'W';
                board[y1][x1] = buffer;
                break;
            }
        }   
}

//play the game
int main(){
	while(1){
        printf( "Yellow Player turn:\n" );
        move_step();
        show_board();
		if(end())
			break;
			
        printf( "Green Player turn:\n" );
        move_step();
        show_board();
        if(end())
			break;

        printf( "Red Player turn:\n" );
        move_step();
        show_board();
        if(end())
			break;
        
        //final
   }     
	return 0;
}
