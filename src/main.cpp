#include <iostream>
#include "TextPort.h"

int main () {
	TextPort KerbalTable("data/names.txt");

	KerbalTable.printFileToLineNum(25);
	
	
	std::cout<<"====Program Stop===="<<std::endl;
 
 return 0; 
}



