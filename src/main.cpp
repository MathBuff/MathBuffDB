#include <iostream>
#include "TextPort.h"
int main () {
	//TextPort KermanTable("data/names.txt","read");
	//KermanTable.printCurrentRow();
	
	TextPort letter("data/letter.txt","write");
	letter.coutToCurrentRow("Dear Putin,\n");
	letter.coutToCurrentRow("You have been a very bad man.\n");
	letter.coutToCurrentRow("It's about time you fucking stop the war you dumb bitch\n");
	letter.coutToCurrentRow("Your's Truely,\n");
	letter.coutToCurrentRow("Stalin <3\n");
	std::cout<<std::endl;
 
 return 0; 
}