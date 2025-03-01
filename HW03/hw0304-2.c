#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
	int32_t num = 0;
	int32_t total = 0;
	int32_t rod = 0;
	int32_t count = 0;
	int32_t j = 0;
	int32_t disk = 1;
	int32_t num1 = 4;
	int32_t rod_odd[3] = {2,3,1};
	int32_t rod_even[3]= {3,2,1};
	int32_t z = 0;
	int32_t num_list[20];
	printf( "Please enter the disk number (2-20): " );
	scanf( "%d" , &num );
	if( num < 2 || num > 20 ){
		printf( "Error input!\n" );
		return 0;
	}
	for( z = 0 ; z < num ; z++ )
	{
		num_list[z] =0;
	}
	if (num % 2 == 0){
		rod_odd [0] = 3;
		rod_odd [1] = 2;
		rod_odd [2] = 1;
		rod_even [0] = 2;
		rod_even [1] = 3;
		rod_even [2] = 1;
	}

    total = pow( 2 , num ) - 1;
    	
    //num為偶數

    if( num % 2 == 0 ){

		for( int32_t i = 1 ; i <= total ; i++ ){
			printf( "move disk " );
			//計算disk
			//total為奇數時
			if( i % 2 != 0 ){
				disk = 1;
				printf( "%d" , disk );
			}
			//total為偶數時
			else{
				count = i;

				int32_t k = 0;

				int32_t sum = 0;

				while(1){

					count /= 2;

					sum ++;

					int32_t tmp = 0;

					tmp = count;

					if( tmp % 2 == 0 ){

						k = sum;

						continue;

					}

					else{

						k = sum;

						break;

					}

				}

				disk = k + 1;

				printf( "%d" , disk ); 

			}

			printf( " to rod " );



			if(disk % 2 == 0){		

				printf( "%d\n" , rod_even[num_list[disk]] );

				if ( num_list[disk] == 2 ){

					num_list[disk]=0;

				}

				else{

					num_list[disk]++;

				}	

			}

			else{

				printf("%d\n",rod_odd[num_list[disk]]);

				if (num_list[disk]==2)

					num_list[disk]=0;

				else

					num_list[disk]++;

			}

				}

		

	}

	//num為奇數

	else{

	int32_t odd_rod2 = 2;

	int32_t even_rod2 = 3;

		for( int32_t i = 1 ; i <= total ; i++ ){

			printf( "move disk " );

			//計算disk

			//total為奇數時

			if( i % 2 != 0 ){

				disk = 1;

				printf( "%d" , disk );

			}

			//total為偶數時

			else{

				count = i;

				int32_t k = 0;

				int32_t sum = 0;

				while(1){

					count /= 2;

					sum ++;

					int32_t tmp = 0;

					tmp = count;

					if( tmp % 2 == 0 ){

						k = sum;

						continue;

					}

					else{

						k = sum;

						break;

					}

				}

				disk = k + 1;

				printf( "%d" , disk ); 

			}

			printf( " to rod " );

			j = i;

			//計算rod

			//total為偶數時

			if( disk % 2 == 0 ){		

				printf( "%d\n" , rod_even[num_list[disk]] );

				if ( num_list[disk] == 2 ){

					num_list[disk]=0;

				}

				else{

					num_list[disk]++;

				}

			}

			//total為奇數時

			else{

				printf("%d\n",rod_odd[num_list[disk]]);

				if ( num_list[disk] == 2 ){

					num_list[disk]=0;

				}

				else{

					num_list[disk]++;

				}

			}

		}

	}

	

	return 0;

}
