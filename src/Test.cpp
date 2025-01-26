#include "Test.h"

//T1-----------------------------------------------------------------
void greaterNumberTestFunct(){

	std::cout<<"\ngreaterNumber() Test INITIATED ...\n";
	
	std::cout<<"\nType in an integer number X\n";
	int X; //Integer Type
	std::cin>>X;
	
	std::cout<<"\nType in a float number Y \n";
	float Y; // Float Type
	std::cin>>Y;
	std::cout<<"\nUsing greaterNumber(), to compare\n";

	std::cout<< "\nThe greater Number is: " << greaterNumber(X,Y) << std::endl;
	
	if(greaterNumber(X,Y) == 0){
	std::cout<< std::endl<<"Comparison Failed or both numbers are zero...";
	std::cout<<"Ending Program"<<std::endl;	
	}
}
//T2------------------------------------------------------------------------

void classNameTest(){
	ClassName<int> variableName;
	variableName.data = 5;
	std::cout<<std::endl<<variableName.data<<std::endl;

}
