#include "TextPort.h"
#include "algorithm"

//PRIVATE==========================================================

//I
void TextPort::changeFileState(std::string state){
	if(state=="read"){
		if(this->fileState =="read"){
			//Do nothing
			return;
		}
		else{
			genericFileVariableName.close();
			setFileToRead();
			return;
		}
		
	}
	else if(state=="write"){
		if(this->fileState =="write"){
			//Do nothing
			return;
		}
		else{
			genericFileVariableName.close();
			setFileToWrite();
			return;
		}
	}
	else{
		std::cout<<"changeFileState() was called but did nothing"<<std::endl;
	}
}

//II
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



//PUBLIC============================================================

//1 
TextPort::TextPort(std::string filePathInput)
	:filePath(filePathInput),fileState("read"){
	}



//2
	std::string TextPort::getFilePath(){
		return this->filePath;
	}
	std::string TextPort::getFileState(){
		return this->fileState;
	}
//3

void TextPort::writeCout(std::string input){
	changeFileState("write");
	genericFileVariableName<<input;	
}

//4

std::string TextPort:: readLine(){ 
	
	std::string data;
	changeFileState("read");
	
	if(genericFileVariableName.is_open()){
	getline(genericFileVariableName,data);
	//getFileLinkStatus();

	return removeCarriageReturns(data);
	}
	else
	std::cout<<std::endl<<"Failed to read Data with readLine(), File not Open";
	return "NoData";
}

std::string  TextPort:: readCin(){ 
	std::string data;
	changeFileState("read");
	if(genericFileVariableName.is_open()){
		genericFileVariableName>>data;
		return data;
	}
	else
	std::cout<<std::endl<<"Failed to read Data with readCin(), File not Open";
	return "NoData";
}
	//Reads first non whitespace input, but Stops at following whitespace ( space, tab, or newline.)

//5

std::string TextPort::getFileLinkStatus(){ 
	return "Linked to file: ["+getFilePath()+"] for "+getFileState();
}

//6

void TextPort::noEscapeCharASCIIDataLinePrint(){
	
	std::cout<<"Dumping line Data with no escape charaters"<<std::endl;
	std::string line = readLine();
	for (char c : line) {
    std::cout << "[" << c << "] -> ASCII: " << static_cast<int>(c) << std::endl;
}
	std::cout << std::endl;
}

std::string TextPort::removeCarriageReturns(const std::string& input) {
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());
    return result;
}

