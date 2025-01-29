#include <iostream>
#include "TextPort.h"

int main () {
	TextPort KerbalTable("data/names.txt");
	
	KerbalTable.appendCout("\nSmelly");
	KerbalTable.appendCout("Toes");
	KerbalTable.printFileToLineNum(25);
	
	
	std::cout<<"====Program Stop===="<<std::endl;
 
 return 0; 
}



