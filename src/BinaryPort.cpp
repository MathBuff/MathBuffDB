#include "BinaryPort.h"

//PRIVATE FUNCTIONS
void BinaryPort::changeFileState(std::string state){
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
		throwFileLinkError1();
	}
}

void BinaryPort::setFileToIn(){
	
		genericFileVariableName.open(filePath, std::ios::in|std::ios::binary);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "in";
			//printFileLinkStatus();
		}
		else{
			throwFileLinkError1();
		}
		
}

void BinaryPort::setFileToOut(){
	
		genericFileVariableName.open(filePath, std::ios::out|std::ios::binary);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "out";
			//printFileLinkStatus();
		}
		else{
			throwFileLinkError1();
		}
}

void BinaryPort::setFileToApp(){
	genericFileVariableName.open(filePath, std::ios::app|std::ios::binary);
		
		if(genericFileVariableName.is_open()){
			this->fileState = "app";
			//printFileLinkStatus();
			
		}
		else{
			throwFileLinkError1();
		}
	
}

void BinaryPort::setFileToNULL(){
	genericFileVariableName.close();
	this->fileState = "NULL";
}

//ERRORS
void BinaryPort::throwFileLinkError1(){
	std::cout<<std::endl<<std::endl<<"[ERROR 1]:"<<std::endl;
	std::cout<<"BinaryPort Class Object Failed to access passed File."<<std::endl;
	std::cout<<"File either does not exist, or the entered path is invalid."<<std::endl;
	std::cout<<"_Common issues_:"<<std::endl;
	std::cout<<"Did you Forget writing the file format into the path?"<<std::endl;
	std::cout<<"Did you check if the path is written correctly relative to the current working directory?"<<std::endl;
	printCurrentWorkingDirectory();
	std::cout<<"If the file is within the directory, the first file name should not have a / beforehand."<<std::endl;
	std::cout<<"[Program Terminated]"<<std::endl<<std::endl<<std::flush;
	throw std::runtime_error("exemption Thrown");
}

//PUBLIC FUNCTIONS

void BinaryPort::printCurrentWorkingDirectory(){
	std::cout<< "Current working directory: " << std::filesystem::current_path() << std::endl;
	
}
				/*Shows you the path that you can access other files from.
				Its the working directory of the program, its like where the program is in the filing system.*/
			