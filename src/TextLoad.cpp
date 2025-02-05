#include "TextLoad.h"
#include <vector>
//MEMORY FUNCTIONS & OBJECTS
	TextLoad::TextLoad(){
		return;
	}
	
	void TextLoad::loadMemory(std::string loadFilePath){ //CHECK
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
		
	}
	
	void TextLoad::saveMemory(std::string saveFilePath){
		return;
	}
	
	void TextLoad::clearMemory(){
		return;
	}
	
	TextLoad::~TextLoad(){
		return;
	}
	
//ACCESS FUNCTIONS
	int TextLoad::getMemoryLineCount(){//CHECK
		
		return memory.size();
		
	}
	
	std::string	TextLoad::getLine(int lineNumber){
		return "";
	}

//CONTROL FUNCTIONS

	void TextLoad::printLine(int lineNumber){
		return;
	}
	
	void TextLoad::reWriteLine(int lineNumber){
		return;
	}
	
	void TextLoad::newTopLine(std::string input){
		return;
	}
	
	void TextLoad::newBottemLine(std::string input){
		return;
	}
	
	void TextLoad::removeLine(int lineNumber){
		return;
	}
	
	void TextLoad::removeLineRange (int initialLine, int FinalLine){
		return;
	}