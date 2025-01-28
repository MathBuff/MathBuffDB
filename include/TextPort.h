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
			
		//State Signalers
			void writeStateSignal();
			
			void readStateSignal();
			
		//Utility
			std::string removeCarriageReturns(const std::string& input);
				/*This is used for the readLine function to allow it to
				Get rid of carridge returns and causing cout to mess up.
				After reading on it, it doesn't seem to need to exist.
				*/
	
	public:
		//Constructor
			TextPort(std::string filePathInput);
		
		//Text File IO Changer
			void changeFileState(std::string state); 
			
		//Getters For private Members
			std::string getFilePath();
			std::string getFileState();

		//Writing Tools
		void writeCout(std::string input);
			//Will Wipe File if writing to it for the first Time
			
		//File Printers
			std::string getFileLinkStatus(); 
		
			std::string readLine();
		
			std::string readCin(); 
			
		//DataDump
			void noEscapeCharASCIIDataLinePrint();
	
};

#endif // Header guard end

/*IF this text fails it is likely you did not spell the 
file name correctly to access OR you are missing the 
format like .txt*/