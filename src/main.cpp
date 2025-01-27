#include <iostream>
#include "TextPort.h"
int main () {
	//TextPort KermanTable("data/names.txt","read");
	//KermanTable.printCurrentRow();
	
	std::cout<<std::endl<<"Initiating Test 2";
	TextPort letter("data/letter.txt","write");
	std::cout<<std::endl;
 
 return 0; 
}