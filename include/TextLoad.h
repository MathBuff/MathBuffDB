#ifndef _LM_TEXTLOAD_H_  
#define _LM_TEXTLOAD_H_
#include "TextPort.h"
#include <vector>
class TextLoad{
	
	private:
		TextPort File;
		
		std::vector<std::string> memory;

	public:
		//MEMORY FUNCTIONS & OBJECTS
			TextLoad();
			
			void loadMemory(std::string loadFilePath);
			
			void printMemory();
			
			void saveMemory(std::string saveFilePath);
			
			void clearMemory();
			
			~TextLoad();
			
		//ACCESS FUNCTIONS
			int getMemoryLineCount();
			std::string	getLine(int lineNumber);
		
		//CONTROL FUNCTIONS
		
			void printLine(int lineNumber);
			
			void reWriteLine(int lineNumber);
			
			void newTopLine(std::string input);
			void newBottemLine(std::string input);
			
			void removeLine(int lineNumber);
			void removeLineRange (int initialLine, int FinalLine);
};


#endif // Header guard end