#include <iostream>
#include "TextPort.h"

int main () {
	TextPort KerbalTable("data/names.txt");
	
	KerbalTable.printEntireFile();
	
	std::cout<<std::endl;
	
	//std::cout<<"file edit status: "<<KerbalTable.getFileEditedStatus()<<std::endl;
	//std::cout<<"The Line count appears to be: "<<KerbalTable.checkTotalLineCount()<< " Lines."<<std::endl;
	
	
	std::cout<<"====Program Stop===="<<std::endl;
 
 return 0; 
}



