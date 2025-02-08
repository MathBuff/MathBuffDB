#include <iostream>
#include "BinaryPort.h"

struct A{
	char a1 = 'H';
	float a2 = 2134.25;
	bool a3 = false;
	 int a4 = 1287289;
	int a5 = 10;
	void print(){
		std::cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<std::endl;
	}
}__attribute__((packed));


int main() {
    
	BinaryPort<A> port1;
	
	std::cout<<port1.checkChunkSize()<<std::endl;
	
	std::cout<<port1.getFilePath()<<std::endl;
	
	port1.setFilePath("data/fart.bin");
	
	std::cout<<port1.getFilePath()<<std::endl;
	
	A messege;
	
	A telegram;
	
	std::cout<<port1.checkBinFileSize()<<std::endl;
	
	port1.supplant(messege);
	
	port1.read(telegram);
	
	
	
	telegram.print();
	
    return 0;
}


