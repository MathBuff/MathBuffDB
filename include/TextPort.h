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
				
			int totalLineCount;
				//Last total Line count for file
			
			
			bool fileEdited;
				//True: The text file had been edited by the program internally
				//False: The text file had not been internally edited by the program.
				
		
		//I
			void changeFileState(std::string state);
			
		//II
			void setFileToIn();
		
			void setFileToOut();
			
			void setFileToApp();

			void setFileToNULL();
			
		//II
			void markFileEdit();
				/*Used in functions that make changes to the text file in any way.
				This way the program has a way to know if reading everyting to check
				Line count or whatever is neccesary.*/
			
	
	public:
		//1
			TextPort(std::string filePathInput);
		
		//2
			std::string getFilePath();

			std::string getFileState();
			
			bool getFileEditedStatus();

		//3
			void supConCout(std::string input);
				/* "Supplant And Continue Cout": 
				Wipes file clean before writing.
				First entry and successive SupCon function entries are saved.
				Writes to the file like cout*/
				
			void appendCout(std::string input);
				/*Will non destructively access file.
				Writes right of the bottem line's text
				To be clear, it does not add a new line unless given a \n char*/
			
		//4
			std::string readCurLineRem();
				/*"Read Cursor Line remainder"
				Returns string of the remaining part of a line from cursor.
				Will automatically set cursor to next line when done.
				Does not read carridge returns "\r".
				Does not read new line "\n" chars at the end of a line into return*/
		
			std::string readCurCin();
				/*"Read Current Line via cin like method"
				Reads first non whitespace input, 
				but Stops at following whitespace ( space, tab, or newline.)*/
				
			
		//5
			void printFileLinkStatus(); 
			
			void printFileToLineNum(int input);
			
			void printEntireFile();
			
			void noEscapeCharASCIIDataLinePrint();
				/*Reads right of the cursor of remaing part of line.
				Prints ascii character values of each character on line*/
			
		//6	
			std::string removeCarriageReturns(const std::string& input);
				/*This is used for the readCurLine function to allow it to
				Get rid of carridge returns "\r", preventing return form 
				causing cout to no produce expected output.
				*/
			
		//7
			int checkTotalLineCount();
				/*If file edited is true.
				This function Reads entire file once and counts up each line. 
				Then sets totalLineCount Var to new count.
				Can also be used to return the new count directly.
				If file edited is false, it will only return the existing 
				totalLineCount */
	
};

#endif // Header guard end

/*TODO
Try making a function that prints from line # to line #.

We need a specific solution for moving to a specific line, and then
either reading or writing(non-destructively).

Ideas:
Figure out what seeking is.
Don't bother making this first try computationally efficient much, outside
of the complete obvious.
See if I can avoid having to do datastructure work as long as possible.
So that way upgrades are more intuitive.

GOAL:
Make it so you can read & write to a specific Line in the .txt File

*/