#ifndef _LM_TEXTPORT_H_  
#define _LM_TEXTPORT_H_
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
				
		//PRIVATE FUNCTIONS: 
			//Class Users can ignore these functions, internal object use only.
			//I
				void changeFileState(std::string state);
				
			//II
				void setFileToIn();
			
				void setFileToOut();
				
				void setFileToApp();

				void setFileToNULL();
				
			//III
				void markFileEdit();
					/*Used in functions that make changes to the text file in any way.
					This way the program has a way to know if reading everyting to check
					Line count or whatever is neccesary.*/
			//IV
				void throwFileLinkError();
					/*A function to cause entire program to end and make main return 1*/
	
	public:
		//1 (Constructor)
			TextPort(std::string filePathInput);
		
		//2 (Getters)
			std::string getFilePath();

			std::string getFileState();
			
			bool getFileEditedStatus();
			

		//3 (File writing Functions)
			void supConCout(std::string input);
				/* "Supplant And Continue Cout": 
				Wipes file clean before writing.
				First entry and successive SupCon function entries are saved.
				Writes to the file like cout*/
				
			void appendCout(std::string input);
				/*Will non destructively access file.
				By default, it Writes right of the bottem line's text.
				To be clear, it does not add a new line unless given a \n char.
				Can be used in combination with cursor movements to overwrite data.*/
			
		//4 (File reading Functions)
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
				
		//5 (OS Cursor Control)
			void cursorToLineStart(int lineNumber);
			
			void cursorToCurLineEnd();
			
			void cursorToCurLineStart();
			
			int cursorCurrentLine();
			
			int cursorCurrentLinePositionCharUTF_8();
			
			void cursorMoveForward(int CharsUTF_8);
			
			void cursorMoveBackward(int CharsUTF_8);
			
			
			
		//6 (Writing Methods)
			/*These Methods are OS heavy.
			It is important to consider using a datastructure within the program to
			make manipulations to the text file after reading rather than running around a 
			bunch with the cursor which will ultimately lead to more operations than neccesary.*/
			
			void wipeLine(int lineNumber);
			
			void removeLine(int lineNumber);
			
			void insertNewLineBelow(int lineNumber);
			
			std::string getLineRow(int lineNumber);
			
		//7 (Console Printing Functions)
			void printFileLinkStatus(); 
			
			void printFileToLineNum(int input);
			
			void printEntireFile();
				//Prints All of selected File to Console.
			
			void printCurrentWorkingDirectory();
			
			void noEscapeCharASCIIDataLinePrint();
				/*Reads right of the cursor of remaing part of line.
				Prints ascii character values of each character on line*/
			
		
		//8 (File Analysis)
			int checkTotalLineCount();
				/*If file edited is true.
				This function Reads entire file once and counts up each line. 
				Then sets totalLineCount Var to new count.
				Can also be used to return the new count directly.
				If file edited is false, it will only return the existing 
				totalLineCount */	
				
		//9 (Utility)
			std::string removeCarriageReturns(const std::string& input);
				/*This is used for the readCurLine function to allow it to
				Get rid of carridge returns "\r", preventing return form 
				causing cout to no produce expected output.
				*/
	
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