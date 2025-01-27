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

void TextPort::coutToCurrentRow(std::string input){
		changeFileState("write");
		genericFileVariableName<< input;
}

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