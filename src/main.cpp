//#include "CPPSocket.h"
//CPPSocket A;
#include <iostream>
#include "TextPort.h"
#include "TextLoad.h"

int main () {
	TextPort File ("data/names.txt");
	
	std::cout<<File.checkTotalLineCount()<<std::endl;
	
	TextLoad manip;
	
	manip.loadMemory("data/names.txt");
	
	std::cout<<manip.getMemoryLineCount()<<std::endl;
	
	manip.printMemory();


}