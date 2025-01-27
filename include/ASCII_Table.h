#ifndef _LM_ASCIITABLE_H_  
#define _LM_ASCIITABLE_H_
#include <iostream>
#include <fstream>
#include <string>

//This is a class meant to read and write ASCII Table Data
class ASCII_Table{
	private:
		
		std::string filePath;
		
		fstream genericFileVariableName;
	
	public:
		
		ASCII_Table(std::string filePathInput);
		
		void openFileToRead();
		
		std::string PrintCurrentRow();
	
};

#endif // Header guard end