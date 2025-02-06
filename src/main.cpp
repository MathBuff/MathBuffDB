//#include "CPPSocket.h"
//CPPSocket A;
#include <iostream>
#include "TextPort.h"
#include "TextLoad.h"
#include <fstream>
struct Record{
	char name[40];
	unsigned short age;
	float gp;
};

int main () {
	std::fstream f ("data/records.dat",std::ios::out|std::ios::binary);
	Record rec {"Jeffery Epstien",81,3.49};
	if(f){
	f.write(reinterpret_cast<char*>(&rec),sizeof(Record));
	f.close();
	}
	
	Record rec2;
	
	f.open("data/records.dat",std::ios::in|std::ios::binary);
	f.read(reinterpret_cast<char*>(&rec2),sizeof(Record));
	
	std::cout<<rec2.name<<std::endl;
	std::cout<<rec2.age<<std::endl;
	std::cout<<rec2.gp<<std::endl;
	return 0;


}