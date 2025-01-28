#ifndef _LM_ASCIITABLE_H_  
#define _LM_ASCIITABLE_H_
#include <iostream>
#include <fstream>
#include <string>

//This is a class meant to read and write UNIX Style ASCII Text File Data
class TextPort{
	private:
		
		//Variables
			std::string filePath; 
				//The linked File to Interface with
			
			std::fstream genericFileVariableName; 
				// The File Variable
			
			std::string fileState; 
				//The file State for reador write
		
		//I
			void changeFileState(std::string state);
			
		//II
			void setFileToRead();
		
			void setFileToWrite();
			
	
	public:
		//1
			TextPort(std::string filePathInput);
		
		 
			
		//2
			std::string getFilePath();
			std::string getFileState();

		//3
			void writeCout(std::string input);
				//Will Wipe File if writing to it for the first Time
			
		//4
			std::string readLine();
		
			std::string readCin(); 
			
		//5
			std::string getFileLinkStatus(); 
			
		//6
			std::string removeCarriageReturns(const std::string& input);
				/*This is used for the readLine function to allow it to
				Get rid of carridge returns and causing cout to mess up.
				After reading on it, it doesn't seem to need to exist.
				*/
			
			void noEscapeCharASCIIDataLinePrint();
	
};

#endif // Header guard end

/*TODO
Figure Out what appending is
Figure out what seeking is
GOAL:
Make it so you can read & write to a specific Line in the .txt File