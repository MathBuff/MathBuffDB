#include<iostream>
#include "File.h"
int main(){
	std::cout<<"\n==Start==\n";
	
	File file1("Homework", "8====D");
	file1.filePrint();
	
	std::cout<<"\n--End--\n\n";
	return 0;
}
