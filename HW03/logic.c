#include "logic.h"
#include <stdio.h>

bool cOut, tmpS, tmpC;
bool z0, z1, z2, z3, z4, z5, z6, z7;

bool norGate(bool a, bool b) {
    return !(a || b);
}
bool notGate(bool a){
	return norGate(a, 0);
}
bool andGate(bool a, bool b){
	return norGate(!a, !b);
}
bool orGate(bool a, bool b){
	if( a == 0 && b == 0 ){
		return norGate(1, 0);
	}
	else{
		return norGate(0, 0);
	}
}
bool xorGate(bool a, bool b){
	if( (a == 0 && b == 0) || (a == 1 && b == 1) ){
		return norGate(1, 0);
	}
	else{
		return norGate(0, 0);
	}
}
bool xnorGate(bool a, bool b){
	if( (a == 0 && b == 0) || (a == 1 && b == 1) ){
		return norGate(0, 0);
	}
	else{
		return norGate(1, 0);
	}
}
bool nandGate(bool a, bool b){
	if( a == 1 && b == 1 ){
		return norGate(1, 0);
	}
	else{
		return norGate(0, 0);
	}
}
bool halfAdder(bool a, bool b){
	bool tmpC = andGate(a, b);
	bool tmpS = xorGate(a, b);
	return tmpS;
}
bool fullAdder(bool a, bool b, bool c_in){
	extern bool tmpC;
	c_in = tmpC;
						//c1			c2			s1
	bool cOut = orGate(halfAdder(a, b), halfAdder(halfAdder(a, b), c_in));
	bool tmpS = halfAdder((halfAdder(a, b), c_in), c_in);
	/*cOut = cOut << 1;*/
	return 2 * cOut + tmpS;
	printf( "test: %d\n" , 2 * cOut + tmpS );
}
