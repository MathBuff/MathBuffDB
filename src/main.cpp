#include <iostream>
#include "TextPort.h"
int main () {
	/*TextPort KermanTable("data/names.txt");
	
	std::cout<<KermanTable.readLine()<<std::endl;
	std::cout<<KermanTable.readLine()<<std::endl;
	std::cout<<KermanTable.readLine()<<std::endl;
	std::cout<<KermanTable.readLine()<<std::endl;	
	*/
	
	TextPort Letter ("data/letter.txt");
	Letter.writeCout("Joe mama,");
	Letter.writeCout("\n");
	Letter.writeCout("Can Suck my balls cause,");
	Letter.writeCout("\n");
	Letter.writeCout("Is so Fat...");
	Letter.writeCout("\n");
	Letter.writeCout("I came on her furry tits :OOOO");
	
	std::cout<<std::endl;
 
 return 0; 
}