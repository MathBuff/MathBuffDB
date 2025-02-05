//#include "CPPSocket.h"
//CPPSocket A;
#include <iostream>
#include "TextPort.h"


int main () {
	TextPort File("data/names.txt");
	
	File.appendCout("🤤🤤🤤🤤🤤🤤");
	File.printFile();
	
	
 return 0; 
}






