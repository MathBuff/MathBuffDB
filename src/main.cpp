//#include "CPPSocket.h"
//CPPSocket A;
#include <iostream>
#include "TextPort.h"
#include "TextLoad.h"

int main () {
	
	TextLoad manip;
	manip.loadMemory("data/input.txt");
	std::string A;
	int B;
	
	manip.printMemory();

	std::cout<<"Line to Append"<<std::endl;
	std::cin>>B;
	std::cin.ignore();
	std::cout<<"Appender"<<std::endl;
	getline(std::cin, A);
	std::cout<<"Received"<<A<<std::endl;
	
	manip.appendLine(A,B);
	
	manip.saveMemory("data/output.txt");



}