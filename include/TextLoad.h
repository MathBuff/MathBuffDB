#ifndef _LM_TEXTLOAD_H_  
#define _LM_TEXTLOAD_H_
#include "TextPort.h"
#include <deque>
class TextLoad{
	
	private:
		TextPort File;
		
		std::deque<std::string> memory;

	public:
		//MEMORY FUNCTIONS & OBJECTS
				
			void loadMemory(std::string loadFilePath);
				//Loads in the entirity of a UTF-8 Text File
			
			void printMemory();
				//Prints out currently Loaded Memory with the form [index]: Content 
			
			void saveMemory(std::string saveFilePath);
				//Supplants memory into a new file, or overwrite a previous one.
				
			void clearMemory();
				//Wipes the active memory of the Text Load class.
			
		//ACCESS FUNCTIONS
			int getMemoryLineCount();
				//retreives the number of lines in memory.
				
			std::string	getLine(int lineNumber);
				//Finds line in loaded memory, throws excemption if out of range.
		
		//CONTROL FUNCTIONS
		
			void printLine(int lineNumber);
				//Prints the line in loaded Memory.
			
			void reWriteLine(std::string input,int lineNumber);
				//Deletes and rewrites and entire line
				
			void prependLine(std::string input, int lineNumber);
				//Writes at the beginning of an existing Line
			
			void appendLine(std::string input, int lineNumber);
				//Writes at the end of an existing Line.
				
			void newTopLine(std::string input);
				//Makes a new top Line
			void newBottemLine(std::string input);
				//Makes a new bottem Line
				
			void removeLine(int lineNumber);
				//Removes Line at Line Number
			void removeLineRange (int firstLine, int lastLine);
				//Removes a range of lines
};				


#endif // Header guard end