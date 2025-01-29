#ifndef _LM_ASCIITABLE_H_  
#define _LM_ASCIITABLE_H_
#include <iostream>
#include <fstream>
#include <string>

//This is a class meant to read and write UNIX Style ASCII Text File Data
class TextPort{
	private:
		
		//VARIABLES
			std::string filePath; 
				//The linked File to Interface with
			
			std::fstream genericFileVariableName; 
				// The File Variable for open & close file state control
			
			std::string fileState; 
				/*
				null: no set state
				in: The read state
				out: The wipe and write state
				app: The append state
				*/
		
		//I
			void changeFileState(std::string state);
			
		//II
			void setFileToIn();
		
			void setFileToOut();
			
			void setFileToApp();
			
	
	public:
		//1
			TextPort(std::string filePathInput);
		
		//2
			std::string getFilePath();

			std::string getFileState();

		//3
			void supConCout(std::string input);
				/* "Supplant And Continue Cout": 
				Wipes file clean before writing.
				First entry and successive SupCon function entries are saved.
				Writes to the file like cout*/
				
			void appendCout(std::string input);
				/*Will non destructively access file.
				Writes to the bottem of the file like cout.*/
			
		//4
			std::string readCurLineRem();
				/*"Read Cursor Line remainder"
				Returns string of the remaining part of a line from cursor.
				Will automatically set cursor to next line when done.
				Does not read carridge returns "\r".
				Does not read new line "\n" chars at the end of a line into return*/
		
			std::string readCurCin();
				/*Will return string of non whitespace chars right of the cursor, 
				stops at next whitespace char*/
			
		//5
			void printFileLinkStatus(); 
			
			void printFileToLineNum(int input);
			
		//6
			std::string removeCarriageReturns(const std::string& input);
				/*This is used for the readCurLine function to allow it to
				Get rid of carridge returns "\r", preventing return form 
				causing cout to no produce expected output.
				*/
			
			void noEscapeCharASCIIDataLinePrint();
	
};

#endif // Header guard end

/*TODO
Find way to control cursor



Ideas:
Figure out what seeking is
GOAL:
Make it so you can read & write to a specific Line in the .txt File

*/