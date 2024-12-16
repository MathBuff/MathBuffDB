#include "File.h"
#include <iostream>

//Constructor
	File::File(std::string name, std::string data) : name(name), data(data){}

//Setters
	void File::setName(std::string inputName){
		this->name = inputName;
	}
	void File::setData(std::string inputData){
		this->data=inputData;
	}
	
//Getters
	std::string File::getName(){
		return name;
	}
	std::string File::getData(){
		return data;
	}

//Functions
void File::filePrint(){
	std::cout<<"\nFile:[ name: " << name <<" | data: "<< data<< " ]"<< std::endl;
	}