#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t yys = 0;
    int32_t mms = 0;
    int32_t dds = 0;
    int32_t yye = 0;
    int32_t mme = 0;
    int32_t dde = 0;
    int32_t yy1 = 0;
    int32_t yy2 = 0;
    int32_t remainder1 = 0;
    int32_t remainder2 = 0;
    int32_t reversedInteger1 = 0;
    int32_t reversedInteger2 = 0;
    int32_t n = 0;
    char c = 0;

	//input output
    printf( "Start Date: " );
    scanf( "%d%c%d%c%d" , &mms , &c , &dds , &c , &yys );
    printf( "End Date: " );
    scanf( "%d%c%d%c%d" , &mme , &c , &dde , &c , &yye );

	//把年拆成兩部份(月.日）
	yy1 = yys % 100;
	yy2 = yys / 100;
	
	//error input
	if( mms > 13 || mme > 13 || dds > 31 || dde > 31 ){
		printf( "Didn't exist that day!\n" );
		return 0;
	} 
	if( yye < yys ){
		printf( "Error input!\n" );
		return 0;
	}
	if( yye == yys && mme < mms ){
		printf( "Error input!\n" );
		return 0;
	}
	if( yye == yys && mme == mms && dde < dds ){
		printf( "Error input!\n" );
		return 0;
	}
	if( (yys / 4 != 0 && mms == 2 && dds > 28) || (yye / 4 != 0 && mme == 2 && dde > 28) ){
		printf( "Error input!\n" );
		return 0;
	}
	if( (((mme == 4 ||mms == 4)||(mme == 6 ||mms == 6)||(mme == 9 ||mms == 9)||(mme == 11 ||mms == 11)) && (dds > 30 ||dde > 30)) ){
		printf( "Error input!\n" );
		return 0;
	}
	n = yye - yys;
	for(int32_t i = 0 ; i <= n ; i++){
		//把數字reverse
		while( yy1 != 0 ){
			remainder1 = yy1 % 10;
			reversedInteger1 = reversedInteger1 * 10 + remainder1;
			yy1 /= 10;
		}
		while( yy2 != 0 ){
			remainder2 = yy2 % 10;
			reversedInteger2 = reversedInteger2 * 10 + remainder2;
			yy2 /= 10;
		}
		
		//判斷是否要printf
		if( reversedInteger1 > 0 && reversedInteger1 < 13 ){
			switch( reversedInteger1 ){
				case 2:
					//閏年判斷
					if( yys % 4 == 0){
						if( reversedInteger2 >= 1 && reversedInteger2 <= 29){
						printf( "%02d-%02d-%d\n" , reversedInteger1 , reversedInteger2 , yys);
						}
					}else{
						if( reversedInteger2 >= 1 && reversedInteger2 <= 28){
						printf( "%02d-%02d-%d\n" , reversedInteger1 , reversedInteger2 , yys);
						}
					}
					break;
				case 1:case 3:case 5:case 7:case 8:case 10:case 12:
					if( reversedInteger2 >= 1 && reversedInteger2 <= 31){
						printf( "%02d-%02d-%d\n" , reversedInteger1 , reversedInteger2 , yys);
						}
					break;
				default:
					if( reversedInteger2 >= 1 && reversedInteger2 <= 30){
						printf( "%02d-%02d-%d\n" , reversedInteger1 , reversedInteger2 , yys);
						}
					break;
			}
		}
	yys += 1;
	yy1 = yys % 100;
	yy2 = yys / 100;
	reversedInteger1 = 0;
	reversedInteger2 = 0;
	remainder1 = 0;
	remainder2 = 0;
}

    return 0;
}
