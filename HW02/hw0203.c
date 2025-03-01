#include <stdio.h>
#include <stdint.h>

int main()
{
	//初始化變數
	long num = 0,sum= 0,num_var = 0,numlong = 0;
	int32_t count = 0,arr[100],count1 = 0;
	printf( "Please enter a number: " );
	scanf( "%ld" , &num);
	numlong = num;
	//error input
	if( num > 2147483647){
	printf( "the number is over 32-bits\n" );
	return 0;
	}
	//計算數字位數
	while( numlong != 0 ){
	numlong /= 10;
	count ++;
	}
	//只有一位數的時候
	if( count == 1 ){
	printf( "Final: %ld\n" , num );
	return 0;
	}
	numlong = num;
	//運算式輸出
	while( count > 1){
		for( int i = 0 ; i <= count-1 ; i++){
			//把數字放入陣列
			num_var = numlong % 10;
			arr[i] = num_var;
			numlong /= 10;
			sum += num_var;
		}
		for( int32_t i = count-1 ; i > 0 ; i--){
			printf( "%d + " , arr[i] );
		}
		printf( "%d = %ld\n" , arr[0] , sum );
		count = 0;
		numlong = sum;
		while(numlong != 0){
			numlong /= 10;
			count ++;
		}
		numlong=sum;
		sum=0;
	}
	printf( "Final: %ld\n" , numlong );
	return 0;
}
