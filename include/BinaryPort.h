#ifndef _LM_BINARYPORT_H_  
#define _LM_BINARYPORT_H_ 
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
class BinaryPort{
		private:
		//PRIVATE VARIABLES
			std::string fileState; 
			std::fstream genericFileVariableName;
			std::string filePath;
			struct chunk;
			
		//PRIVATE FUNCTIONS
			void changeFileState(std::string state);
			
			void setFileToIn();
			
			void setFileToOut();
				
			void setFileToApp();

			void setFileToNULL();
			
		//ERRORS
			void throwFileLinkError1();
			
		public:
		//PUBLIC FUNCTIONS
			BinaryPort(struct newChunk);
			
			
			
			void printCurrentWorkingDirectory();
				/*Shows you the path that you can access other files from.
				Its the working directory of the program, its like where the program is in the filing system.*/
			
			

};

#endif // Header guard end