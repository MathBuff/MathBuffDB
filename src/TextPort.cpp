#include "TextPort.h"

//PRIVATE==========================================================

//State Changers
void TextPort::setFileToRead(){
	
		genericFileVariableName.open(filePath, std::ios::in);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "read";
			printFileLinkStatus();
		}
		else
			std::cout<<std::endl<<"File Failed to link with setFileread()";
	
}

void TextPort::setFileToWrite(){
	
		genericFileVariableName.open(filePath, std::ios::out);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "write";
			printFileLinkStatus();
			
		}
		else
			std::cout<<std::endl<<"File Failed to link with setFileread()";
	
}

//Used by Writing Tools to ensure no reopening of files which Wipes
//Data from file being written to.

void TextPort::continueWritingState(){
	if(getFileState()=="write"){
			return;
	}
	else{
		changeFileState("write");
		return;
	}
		
	
}

//PUBLIC============================================================

//Constructor 
TextPort::TextPort(std::string filePathInput, std::string fileState)
	:filePath(filePathInput),fileState(fileState){
			changeFileState(fileState);
	}

//Text File IO Changer
void TextPort::changeFileState(std::string state){
	if(state=="read"){
		setFileToRead();
	}
	else if(state=="write"){
		setFileToWrite();
	}
}

//Getters For private Members
	std::string TextPort::getFilePath(){
		return this->filePath;
	}
	std::string TextPort::getFileState(){
		return this->fileState;
	}
//Writing Tools

void TextPort::coutToCurrentRow(std::string input){
	continueWritingState();
	genericFileVariableName<<input;	
}

/*I need to implement appending
It apparently will allow you to write to the file 
without wiping the file entirely.
*/

//Data Printers

void TextPort::printFileLinkStatus(){
	std::cout<<std::endl<<"Linked to file: [";
	std::cout<< getFilePath()+"] for "+ getFileState();
}


void TextPort:: printCurrentRow(){
	std::string data;
	getline(genericFileVariableName,data);
	std::cout<<std::endl<<data;
}

void TextPort:: cinCurrentRow(){
	std::string data;
	if(genericFileVariableName.is_open()){
		genericFileVariableName>>data;
		std::cout<<std::endl<<data;
	}
	else
	std::cout<<std::endl<<"Failed to read Data with cinCurrentRow()";
}