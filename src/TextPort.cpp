#include "TextPort.h"
#include "algorithm"
#include <cstdlib>
#include <filesystem>

//PRIVATE==========================================================
//PRIVATE VARIABLES
	//No need for them to be listed here, check .h file for info.

//PRIVATE FUNCTIONS
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
		throwFileLinkError();
	}
}

//II
void TextPort::setFileToIn(){
	
		genericFileVariableName.open(filePath, std::ios::in);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "in";
			//printFileLinkStatus();
		}
		else{
			std::cout<<std::endl<<"SetFile state to in Failed"<<std::endl;
			throwFileLinkError();
		}
		
}

void TextPort::setFileToOut(){
	
		genericFileVariableName.open(filePath, std::ios::out);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "out";
			//printFileLinkStatus();
		}
		else{
			throwFileLinkError();
		}
}

void TextPort::setFileToApp(){
	genericFileVariableName.open(filePath, std::ios::app);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "app";
			//printFileLinkStatus();
			
		}
		else{
			throwFileLinkError();
		}
	
}

void TextPort::setFileToNULL(){
	genericFileVariableName.close();
	this->fileState = "NULL";
}

//III
void TextPort::markFileEdit(){
	this->fileEdited = 1;
}

//IV
void TextPort::throwFileLinkError(){
	std::cout<<std::endl<<std::endl<<"[ERROR 1]:"<<std::endl;
	std::cout<<"TextPort Class Object Failed to link to passed File."<<std::endl;
	std::cout<<"File either does not exist, or the entered path is invalid."<<std::endl;
	std::cout<<"_Common issues_:"<<std::endl;
	std::cout<<"Did you Forget writing the file format into the path?"<<std::endl;
	std::cout<<"Did you check if the path is written correctly relative to the current working directory?"<<std::endl;
	printCurrentWorkingDirectory();
	std::cout<<"If the file is within the directory, the first file name should not have a / beforehand."<<std::endl;
	std::cout<<"[Program Terminated]"<<std::endl<<std::endl<<std::flush;
	exit(1);
}


//PUBLIC============================================================

//1 (Constructor)
TextPort::TextPort(std::string filePathInput)
	:filePath(filePathInput),fileState("NULL"),fileEdited(0){
}

//2 (Getters)
	std::string TextPort::getFilePath(){
		return this->filePath;
	}
	std::string TextPort::getFileState(){
		return this->fileState;
	}
	bool TextPort::getFileEditedStatus(){
		return this->fileEdited;
	}
	
//3 (File writing Functions)

void TextPort::supConCout(std::string input){ 
	
	changeFileState("out"); 
	genericFileVariableName<<input;	
	markFileEdit();
}

void TextPort::appendCout(std::string input){
	changeFileState("app");
	genericFileVariableName<<input;
	markFileEdit();
}

//4 (File reading Functions)

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

//5 (Cursor)
	void TextPort::resetFileState(){
		setFileToNULL();
	}

//6 (Console Printing Functions)

void TextPort::printFile(){
	setFileToNULL();//File reset for cursor
	int lineCount = checkTotalLineCount();
	
	for (int i = 0; i < lineCount; i++){
		std::string buffer = readCurLineRem();
		std::cout << buffer << std::endl;
	}
	setFileToNULL();//File reset for cursor
}

void TextPort::printFileWithLineNum(){
	//std::cout<<"\nTotal Console Data dump for: "+getFilePath()<<std::endl;
	//std::cout<<"Please note that the [i]:'s are not a part of the file."<<std::endl<<std::endl;
	
	int i=0;
	setFileToNULL();//File reset for cursor
	
	do{
		i++;
		std::cout<<"["<<i<<"]:"+readCurLineRem()<<std::endl;
	}while(!genericFileVariableName.eof());
	
	//std::cout<<std::endl<<"End of Total Data Dump for: "+getFilePath()<<std::endl;
	setFileToNULL();//File reset for cursor
		return;
	
}


void TextPort::printFileToLineNum(int input){
	//This function uses readCurLineRem
	//std::cout<<"\nDumping the lines 1 to "<<input<<" of: "+getFilePath()<< " to console"<<std::endl;
	setFileToIn();//This needs to be set so that file.eof doesn't read incorrectly
	int i=0;
	while(i!=input){
	i++;
		
		if(genericFileVariableName.eof()){
			//std::cout<<"End of data dump for: "+getFilePath()<<std::endl;
			setFileToNULL();//File reset for cursor
			return;
		}
		std::cout<<readCurLineRem()<<std::endl;
	
	}
}

void TextPort::printFileLinkStatus(){ 
	std::cout<< "Linked to file: ["+getFilePath()+"] for "+getFileState()<<std::endl;
}

void TextPort::printCurrentWorkingDirectory(){
	std::cout<< "Current working directory: " << std::filesystem::current_path() << std::endl;
}

void TextPort::noEscapeCharASCIIDataLinePrint(){
	
	std::cout<<"Dumping line Data with no escape charaters"<<std::endl;
	std::string line = readCurLineRem();
	for (char c : line) {
    std::cout << "[" << c << "] -> ASCII: " << static_cast<int>(c) << std::endl;
	}
	std::cout << std::endl;
}

//7 (File Analysis)
int TextPort::checkTotalLineCount(){
		
	int i=0;
	//Reseting File so that the cursor starts at the top with read line.
	//This function uses readCurLineRem
		setFileToNULL();
	
		do {
			i++;
			readCurLineRem();
		}while(!genericFileVariableName.eof());
		
	setFileToNULL();
	//This resets the cursor again so that future processes won't get messed up.
		
		return i;
}

//8 (Utility)
std::string TextPort::removeCarriageReturns(const std::string& input) {
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());
    return result;
}

//REMOVED
/*
//A (OS Cursor Control) [Stubbed Only]
	void cursorToLineStart(int lineNumber){
		return;
	}
	
	void cursorToCurLineEnd(){
		return;
	}
	
	void cursorToCurLineStart(){
		return;
	}
	
	int cursorCurrentLine(){
		return 0;
	}
	
	int cursorCurrentLinePositionCharUTF_8(){
		return 0;
	}
	
	void cursorMoveForward(int CharsUTF_8){
		return;
	}
	
	void cursorMoveBackward(int CharsUTF_8){
		return;
	}
	
//B (Writing Methods) [Stubbed Only]
	
	void wipeLine(int lineNumber){
		return;
	}
	
	void removeLine(int lineNumber){
		return;
	}
	
	void insertNewLineBelow(int lineNumber){
		return;
	}
	
	std::string getLineRow(int lineNumber){
		return "No Integration";
	}
*/

