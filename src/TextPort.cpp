#include "TextPort.h"
#include "algorithm"

//PRIVATE==========================================================

//I
void TextPort::changeFileState(std::string state){
	if(state=="in"){
		if(this->fileState =="in"){
			//Do nothing
			return;
		}
		else{
			genericFileVariableName.close();
			setFileToIn();
			return;
		}
		
	}
	else if(state=="out"){
		if(this->fileState =="out"){
			//Do nothing
			return;
		}
		else{
			genericFileVariableName.close();
			setFileToOut();
			return;
		}
	}
	else if(state=="app"){
		if(this->fileState=="app"){
			//Do nothing
			return;
		}
		else{
			genericFileVariableName.close();
			setFileToApp();
			return;
		}
	}
	else{
		std::cout<<"changeFileState() was called but did nothing"<<std::endl;
	}
}

//II
void TextPort::setFileToIn(){
	
		genericFileVariableName.open(filePath, std::ios::in);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "in";
			//printFileLinkStatus();
		}
		else
			std::cout<<std::endl<<"File Failed to link with setFileRead()";
}

void TextPort::setFileToOut(){
	
		genericFileVariableName.open(filePath, std::ios::out);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "out";
			//printFileLinkStatus();
		}
		else
			std::cout<<std::endl<<"File Failed to link with setFileWrite()";
}

void TextPort::setFileToApp(){
	genericFileVariableName.open(filePath, std::ios::app);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "app";
			//printFileLinkStatus();
			
		}
		else
			std::cout<<std::endl<<"File Failed to link with setFileAppend()";	
	
	
}


//PUBLIC============================================================

//1 
TextPort::TextPort(std::string filePathInput)
	:filePath(filePathInput),fileState("NULL"){
}



//2
	std::string TextPort::getFilePath(){
		return this->filePath;
	}
	std::string TextPort::getFileState(){
		return this->fileState;
	}
//3

void TextPort::supConCout(std::string input){ 
	
	changeFileState("out"); 
	genericFileVariableName<<input;	
}

void TextPort::appendCout(std::string input){
	
	changeFileState("app");
	genericFileVariableName<<input;
}

//4

std::string TextPort::readCurLineRem(){ 
	std::string data;
	changeFileState("in");
	
	if(genericFileVariableName.is_open()){
	getline(genericFileVariableName,data);

	return removeCarriageReturns(data);
	//Removes \r from strings so that output is more predictable in console
	}
	else
	std::cout<<std::endl<<"Failed to read Data with readLine(), File not Open";
	return "NoData";
}

std::string  TextPort:: readCurCin(){ 
	/*"Read Current Line via cin like method"
	Reads first non whitespace input, 
	but Stops at following whitespace ( space, tab, or newline.)*/
	std::string data;
	changeFileState("in");
	if(genericFileVariableName.is_open()){
		genericFileVariableName>>data;
		return data;
	}
	else
	std::cout<<std::endl<<"Failed to read Data with readCin(), File not Open";
	return "NoData";
}
	

//5

void TextPort::printFileLinkStatus(){ 
	std::cout<< "Linked to file: ["+getFilePath()+"] for "+getFileState()<<std::endl;
}

void TextPort::printFileToLineNum(int input){
	//This function uses readCurLineRem, can cause problems later
	int i=0;
	std::cout<<"\nDumping the lines 1 to "<<input<<" of: "+getFilePath()<<std::endl;
	
	while(i!=input){
	i++;
		if(genericFileVariableName.eof()){
			std::cout<<"End of data dump for: "+getFilePath()<<std::endl;
			return;
		}
	
	std::cout<<"Line["<<i<<"]:"+readCurLineRem()<<std::endl;
	}
}

//6

void TextPort::noEscapeCharASCIIDataLinePrint(){
	
	std::cout<<"Dumping line Data with no escape charaters"<<std::endl;
	std::string line = readCurLineRem();
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

