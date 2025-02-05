//#include "CPPSocket.h"
//CPPSocket A;
#include <iostream>
#include "TextPort.h"


int main () {
	std::cout << "_Program Start_" << std::endl;
	
	
	
	TextPort File("data/names.txt");
	File.printEntireFile();
	

	std::cout << std::endl;
		std::cout << "_Program End_" << std::endl;
	
	
 return 0; 
}






