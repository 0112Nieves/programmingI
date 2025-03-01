#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
	int32_t level,atk,type1,status,move_power,move_type,power;         		
	int32_t move_category,def,weather,terrain,damage,stab,type2;
	double factor;
	
	//input
	printf( "Attacker\n" );
	printf( "    level : " );
	scanf( "%d" , &level );
	printf( "    atk : ");
	scanf( "%d" , &atk );
	printf( "    type : " );
	scanf( "%d" , &type1 );
	printf( "    status : " );
	scanf( "%d" , &status );
	printf( "    move_power : " );
	scanf( "%d" , &move_power );
	printf( "    move_type : " );
	scanf( "%d" , &move_type );
	printf( "    move_category : " );
	scanf( "%d" , &move_category );
	printf( "Target\n" );
	printf( "    def : " );
	scanf( "%d" , &def );
	printf( "    type : " );
	scanf( "%d" , &type2 );
	printf( "Environment\n" );
	printf( "    weather : " );
	scanf( "%d" , &weather );
	printf( "    terrain : " );
	scanf( "%d" , &terrain );
	
	factor = 1;
	
	//weather加成
	if( type1 == 0 && weather == 1)
	{
		factor = (float)factor * 0.5;
	}
	if( type1 == 0 && weather == 2)
	{
		factor = factor * 2;
	}
	if( type1 == 1 && weather == 1)
	{
		factor = factor * 2;
	}
	if( type1 == 1 && weather == 2)
	{
		factor = (float)factor * 0.5;
	}
	
	//attacker 和 move_type 相同
	if( type1 == move_type )
	{
		factor = factor * 2;
	}
	
	//type1 和 type2 加成
	if( type1 == 0 )
	{
		switch( type2 )
		{
			case 0:case 2:case 7:
				factor = (float)factor * 0.5;
				break;
			case 1:case 4:case 5:
				factor = factor * 2;
				break;
		}
	}

	if( type1 == 1 )
	{
		switch( type2 )
		{
			case 0:case 1:case 4:case 7:
				factor = (float)factor * 0.5;
				break;
			case 2:
				factor = factor * 2;
				break;
		}
	}

	if( type1 == 2 )
	{
		switch( type2 )
		{
			case 1:case 2:case 3:case 7:
				factor = (float)factor * 0.5;
				break;
			case 0:case 4:case 5:
				factor = factor * 2;
				break;
		}
	}
	
	if( type1 == 3 )
	{
		switch( type2 )
		{
			case 4:case 6:
				factor = (float)factor * 0.5;
				break;
			case 2:
				factor = factor * 2;
				break;
		}
	}

	if( type1 == 4 )
	{
		switch( type2 )
		{
			case 5:
				factor = (float)factor * 0.5;
				break;
			case 1:case 3:
				factor = factor * 2;
				break;
		}
	}

	if( type1 == 5 )
	{
		switch( type2 )
		{
			case 3:
				factor = factor * 0;
				break;
			case 1:case 4:case 6:
				factor = factor * 2;
				break;
		}
	}

	if( type1 == 6 )
	{
		switch( type2 )
		{
			case 2:case 6:case 7:
				factor = (float)factor * 0.5;
				break;
			case 0:case 3:
				factor = factor * 2;
				break;
			case 5:
				factor = factor * 0;
				break;
		}
	}

	if( type1 == 7 )
	{
		switch( type2 )
		{
			case 7:
				factor = factor * 2;
				break;
		}
	}

	if (( move_category == 0 && status == 1 ) || ( move_category == 1 && status == 2 ))
	{
    	factor = (float)factor * 0.5;
    }
    
    //地形加成
    if( terrain == 1 && type1 ==2 )
    { 
    	factor = factor * 2;
    }
    
	if( terrain == 2 && type1 ==6 )
	{ 
    	factor = factor * 2;
    }
    
	if( terrain == 3 && type1 ==7 )
	{
    	factor = (float)factor * 0.5;
    }
    
    //天氣加成
    if( weather == 3 && type1 == 2 )
    {
    	atk = (float)atk * 0.5;
    }
    
	if( weather == 4 && type1 == 3 )
	{
    	atk = atk * 2;
    }
	
	damage = (float)floor((floor((level * 2 + 10) * atk * move_power / (250 * def)) + 2) * factor);
	
	if(damage == 0){
    	damage = 1;
    }
	
	printf( "Damage --> %d\n" , damage );
	return 0;
}
