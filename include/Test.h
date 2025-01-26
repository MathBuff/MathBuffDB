#ifndef _LM_TEST_H_  // Header guard start
#define _LM_TEST_H_

#include<iostream>

//T1------------------------------------------------------------------------

template <typename T1, typename T2> auto greaterNumber(T1 x, T2 y){
	return (x>y) ? x: y; //Ternary operator, if (), then x, else y.
}

void greaterNumberTestFunct();

//T2------------------------------------------------------------------------
template <typename generalTypeName>
class ClassName{
public:
	generalTypeName data;
	
};

void classNameTest();
//--------------------------------------------------------------------------


#endif // Header guard end

