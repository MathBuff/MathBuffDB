#include "ASCII_Table.h"

ASCII_Table::ASCII_Table(std::string filePathInput)
	:filePath(filePathInput){}

ASCII_Table::void openFileToRead(){
	
		genericFileVariableName.open(filePath, ios::in);
		
		if(genericFileVariableName.is_open()){
			std::cout<<std::endl<<"Initial File Link Successful";
		}
		else
			std::cout<<std::endl<<"File Failed to link";
	
}

ASCII_Table::std::string PrintCurrentRow(){
	std::string data;
	if(genericFileVariableName.is_open()){
		genericFileVariableName<<data;
		std::cout<<std::endl<<data;
	}
	else
	std::cout<<std::endl<<"Failed to read Data";
	
}