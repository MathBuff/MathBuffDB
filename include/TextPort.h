#ifndef _LM_ASCIITABLE_H_  
#define _LM_ASCIITABLE_H_
#include <iostream>
#include <fstream>
#include <string>

//This is a class meant to read and write ASCII Table Data
class TextPort{
	private:
	
		std::string filePath; 
			//The linked File to Interface with
		
		std::fstream genericFileVariableName; 
			// The File Variable
		
		std::string fileState; 
			//The file State for reador write
			
		//State Setters used by changeFileState()
			void setFileToRead();
		
			void setFileToWrite();
	
	public:
		//Constructor
			TextPort(std::string filePathInput, std::string fileState);
		
		//Text File IO Changer
			void changeFileState(std::string state); 
			
		//Getters For private Members
			std::string getFilePath();
			std::string getFileState();

		//Writing Tools
		void coutToCurrentRow(std::string input);
			
		//File Printers
			void printFileLinkStatus();
		
			void printCurrentRow();
		
			void cinCurrentRow();
	
};

#endif // Header guard end

/*IF this text fails it is likely you did not spell the 
file name correctly to access OR you are missing the 
format like .txt*/