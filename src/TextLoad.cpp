#include "TextLoad.h"
#include <deque>
#include <stdexcept>
//MEMORY FUNCTIONS & OBJECTS
	
	void TextLoad::loadMemory(std::string loadFilePath){ 
		File.setFilePath(loadFilePath);
		
		int j = File.checkTotalLineCount();

		
		for(int i = 1;i<=j;i++){
			memory.push_back(File.readCurLineRem());
		}
		
		return;
	}
	
	void TextLoad::printMemory(){ 
		
		int j = getMemoryLineCount();
		
		for(int i = 1;i<=j;i++){
			std::cout<<"["<<i<<"]:"<<memory.at(i-1)<<std::endl;
			//Vectors index at zero -1 needed
		}
		
		return;
		
	}
	
	void TextLoad::saveMemory(std::string saveFilePath){
		File.setFilePath(saveFilePath);
		
		int j = getMemoryLineCount();
		
		for(int i = 1;i<=j;i++){
			File.supConCout(memory.at(i-1));
			//Vectors index at zero -1 needed
			if (i == j){
				return; //Final Line does not need a \n
			}
			File.supConCout("\n");
			//End line character to end the line in the text file.
		}
		
	}
	
	void TextLoad::clearMemory(){
		std::deque<std::string>().swap(memory);
		//Moves current deque contents to a new deque, leaving the original blank.
		//Once this function moves out of scope, the new deque is properly deleted.
	}
	
	
//ACCESS FUNCTIONS
	int TextLoad::getMemoryLineCount(){//CHECK
		
		return memory.size();
		
	}
	
	std::string	TextLoad::getLine(int lineNumber){
		if (lineNumber<=getMemoryLineCount() && lineNumber>0){
			
			return memory.at(lineNumber-1);
			
		}
		else{
			throw std::out_of_range ("\nTextLoad.cpp_TextLoad::getLine() was tasked with finding a line number\nout of bounds to what lines are loaded loaded into memory");
			
		}
		
	}

//CONTROL FUNCTIONS

	void TextLoad::printLine(int lineNumber){
		std::cout<< getLine(lineNumber) <<std::endl;
	}
	
	void TextLoad::reWriteLine(std::string input,int lineNumber){
		memory.at(lineNumber-1) = input;
	}
	
	void TextLoad::prependLine(std::string input, int lineNumber){
		std::string lineToPrepend = getLine(lineNumber);
		std::string prepender = input;
		reWriteLine(prepender+lineToPrepend,lineNumber);
	}
	
			
	void TextLoad::appendLine(std::string input, int lineNumber){
		std::string lineToAppend = getLine(lineNumber);
		std::string appender = input;
		reWriteLine(lineToAppend+appender,lineNumber);
	}
		
	
	void TextLoad::newTopLine(std::string input){
		memory.emplace_front(input);
	}
	
	void TextLoad::newBottemLine(std::string input){
		memory.emplace_back(input);
	}
	
	void TextLoad::removeLine(int lineNumber){
		if (lineNumber > 0 && lineNumber <= getMemoryLineCount()){
				memory.erase(memory.begin() + (lineNumber - 1));
		} 
		else {
				throw std::out_of_range("removeLine() received an out-of-bounds line number");
		}
	}
	
	void TextLoad::removeLineRange (int firstLine, int lastLine){
		
	int j = getMemoryLineCount();
	int i = firstLine-1;
	
		if(firstLine>lastLine||lastLine<=0||firstLine<=0||j<lastLine){
			throw std::runtime_error("removeLineRange Had out of bounds parameters");
		}
		else{
				memory.erase(memory.begin() + (firstLine - 1), memory.begin() + lastLine);
				
				memory.shrink_to_fit();//Shrinks memory to release unused capacity post erase.
		}
	}