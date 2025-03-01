#include "mymemcmp.h"

int32_t mymemcmp( const void *cs, const void *ct, size_t count )
{	
	const unsigned char *su1, *su2;
	int32_t res = 0;
	
	for( su1 = cs, su2 = ct ; 0 < count ; ++su1, ++su2, count-- ){
		if( (res = *su1 - *su2) != 0 ){
			break;
		}
	}
	
	return res;
}
