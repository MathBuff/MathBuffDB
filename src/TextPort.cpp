#include "TextPort.h"
#include "algorithm"

//PRIVATE==========================================================

//State Changers
void TextPort::setFileToRead(){
	
		genericFileVariableName.open(filePath, std::ios::in);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "read";
			getFileLinkStatus();
		}
		else
			std::cout<<std::endl<<"File Failed to link with setFileread()";
	
}

void TextPort::setFileToWrite(){
	
		genericFileVariableName.open(filePath, std::ios::out);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "write";
			getFileLinkStatus();
			
		}
		else
			std::cout<<std::endl<<"File Failed to link with setFileread()";	
}

/*Used by Text Tools to ensure no reopening of files which Wipes
Data from file being written to.*/

void TextPort::writeStateSignal(){ //UPDATE//
	if(getFileState()=="write"){
		return;
	}
	else{
		changeFileState("write");
		return;
	}
	
}

void TextPort::readStateSignal(){ //UPDATE//
	if(getFileState()=="read"){
		return;
	}
	else{
		changeFileState("read");
		return;
	}
	
}

//UTILITY
std::string TextPort::removeCarriageReturns(const std::string& input) {
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());
    return result;
}

//PUBLIC============================================================

//Constructor 
TextPort::TextPort(std::string filePathInput)
	:filePath(filePathInput),fileState("NULL"){
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

void TextPort::writeCout(std::string input){
	writeStateSignal();
	genericFileVariableName<<input;	
}

/*I need to implement appending
It apparently will allow you to write to the file 
without wiping the file entirely.
*/

//Data Readers

std::string TextPort::getFileLinkStatus(){ 
	return "Linked to file: ["+getFilePath()+"] for "+getFileState();
}


std::string TextPort:: readLine(){ 
	std::string data;
	
	if(genericFileVariableName.is_open()){
	getline(genericFileVariableName,data);
	return removeCarriageReturns(data);
	}
	else
	std::cout<<std::endl<<"Failed to read Data with readLine(), File not Open";
	return "NoData";
}

std::string  TextPort:: readCin(){ 

	std::string data;
	
	if(genericFileVariableName.is_open()){
		genericFileVariableName>>data;
		return data;
	}
	else
	std::cout<<std::endl<<"Failed to read Data with readCin(), File not Open";
	return "NoData";
}
//Reads first non whitespace input, but Stops at following whitespace ( space, tab, or newline.)

void TextPort::noEscapeCharASCIIDataLinePrint(){
	
	std::cout<<"Dumping line Data with no escape charaters"<<std::endl;
	std::string line = readLine();
	for (char c : line) {
    std::cout << "[" << c << "] -> ASCII: " << static_cast<int>(c) << std::endl;
}
	std::cout << std::endl;
}

