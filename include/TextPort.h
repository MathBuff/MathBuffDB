#ifndef _LM_TEXTPORT_H_  
#define _LM_TEXTPORT_H_
#include <iostream>
#include <fstream>
#include <string>

/*
Text Port works for UTF-8 & ASCII.
It essentially is how I can more easily read or write to a text file using a class object.

supplantCout();

readCurLineRem();

checkTotalLineCount();

printFile();

Are the functions of note, everything else is kinda fluff.

Advanced operations like ommiting lines and such was not dutiful.
Database behavior should be better implemented with another class and using program memory with RAM.
*/


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
				
		//PRIVATE FUNCTIONS: 
			//Class Users can ignore these functions, internal object use only.
			//I
				void changeFileState(std::string state);
				
			//II
				void setFileToIn();
			
				void setFileToOut();
				
				void setFileToApp();

				void setFileToNULL();
				
					
			//III (ERRORS)
				void throwFileLinkError1();
					/*A function to cause entire program to end and make main return 1.
					Does so in the specfic event that the last entered path for the object,
					is not accessable or valid*/
					
				void throwParameterError2();
					/*Error Thrown if printFileLineToLine is used incorrectly*/
	
	public:
		//1 (Constructor)
			TextPort(std::string filePathInput = "pleaseSetFilePath");
		
		//2 (Getters & Setters)
			std::string getFilePath();

			std::string getFileState();
			
			void setFilePath(std::string input);
			

		//3 (File writing Functions)
			void supConCout(std::string input);
				/* "Supplant And Continue Cout": 
				Wipes file clean before writing, or makes a new one if it doesn't already exist.
				First entry and successive SupCon function entries are saved.
				Writes to the file like cout.
				!_This should be your main way of writing files_!*/
				
			void appendCout(std::string input);
				/*Will non destructively access file.
				By default, it Writes right of the bottem line's text.
				To be clear, it does not add a new line unless given a \n char.
				Can be used in combination with cursor movements to overwrite data, but I chose
				to forgo such an implementation.*/
			
		//4 (File reading Functions)
			std::string readCurLineRem();
				/*"Read Cursor Line remainder"
				Returns string of the remaining part of a line from cursor.
				Will automatically set cursor to next line when done.
				Does not read carridge returns "\r".
				Does not read new line "\n" chars at the end of a line into return.
				!_This should be your main way of reading files._!*/
		
			std::string readCurCin();
				/*"Read the Current Line which the cursor lies via cin like method"
				Reads first non whitespace input, 
				but Stops at following whitespace ( space, tab, or newline.)*/
				
			std::string findLineReturn(int lineNumber);
				/*"Find Line And Return Value"
				It reads but doesn't return until you reach the desired line number.
				At proper line, it then returns the whole line.
				Out of bounds line Number will throw an error.
				Do not use for anything but one and done reads to avoid slowdowns.
				*/
				
		//5 (Cursor)
			void resetFileState();
				/*Lets say you were reading a file and want to start from the begining again.
				you can reset the cursor back to the start by using this function.
				Doing so with writing functions will undo the file in essence.
				To do so with append will bring you back right of the last line of the text file.*/
			
		//6 (Console Printing Functions)
		
			void printFile();
				//Prints Entire File as is
				
			void printFileWithLineNum();
				//Prints All of selected File to Console with [i]: line numbers
			
			void printFileToLineNum(int input);
				/*Prints from zero to input lines of the text file.
				If the line number is greater than that of the lines in the file it merely
				stops at the end of the file.*/
			
			void printFileLineToLine(int firstLine, int lastLine);
				//Will read but not cout until first line reached, it will continue printing until last line is usurped.
			
			void printFileLine(int lineNumber);
				//Will read down to the line number and state the contents in console.
				//Much More effective to use printLineToLine if multiple elements in a row.
			
			void printFileLinkStatus(); 
				/*Tells you if file is reading/writing & the path at the moment.*/
			
			void printCurrentWorkingDirectory();
				/*Shows you the path that you can access other files from.
				Its the working directory of the program, its like where the program is in the filing system.*/
			
			void noEscapeCharASCIIDataLinePrint();
				/*Reads right of the cursor of remaing part of line.
				Prints ascii character values of each character on line.
				Doesn't work with other UTF-8 characters.*/
			
		
		//7 (File Analysis)
			int checkTotalLineCount();
				/*Will read through file lines to count up all the lines in the file.
					DO NOT use this function in a loop for reading or writing!
					The Function will reset the cursor to count the lines and it will mess you up!
				*/	
				
		//8 (Utility)
			std::string removeCarriageReturns(const std::string& input);
				/*This is used for the readCurLineRem function to allow it to
				Get rid of carridge returns "\r", preventing return form 
				causing cout to no produce expected output.
				*/
				
	//REMOVED
		/*
		I've decided against implementing these since I see it as a potential
		bottleneck if you rely on this type of stuff too much to write and edit files.
				
		//A (OS Cursor Control) [Stubbed Only]
			void cursorToLineStart(int lineNumber);
			
			void cursorToCurLineEnd();
			
			void cursorToCurLineStart();
			
			int cursorCurrentLine();
			
			int cursorCurrentLinePositionCharUTF_8();
			
			void cursorMoveForward(int CharsUTF_8);
			
			void cursorMoveBackward(int CharsUTF_8);
			
			
			
		//B (Writing Methods) [Stubbed Only]
			These Methods are OS heavy.
			It is important to consider using a datastructure within the program to
			make manipulations to the text file after reading rather than running around a 
			bunch with the cursor which will ultimately lead to more operations than neccesary.
			
			void wipeLine(int lineNumber);
			
			void removeLine(int lineNumber);
			
			void insertNewLineBelow(int lineNumber);
			
			std::string getLineRow(int lineNumber);
		*/	
	
};

#endif // Header guard end