#ifndef _LM_FILE_H_  // Header guard start
#define _LM_FILE_H_

#include<iostream>
class File{
private:
    std::string name;
    std::string data;
    
public:

//Constructor
	File(std::string name, std::string data);

//Setters
	void setName(std::string inputName);
	void setData(std::string inputData);
	
//Getters
	std::string getName();
	std::string getData();
	
//Functions
	void filePrint();
	
};

#endif // Header guard end