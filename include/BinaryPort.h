#ifndef _LM_BINARYPORT_H_  
#define _LM_BINARYPORT_H_ 
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

template <typename genChunk>
class BinaryPort{
	
		private:
			//PRIVATE VARIABLES
				std::string filePath;
			
		public:
			// (Constructor)
				BinaryPort();
				
			// (Setters & Getters)
				
				void setFilePath(std::string input);
				
				std::string getFilePath();
				
				void setNewChunk(genChunk newLoadedChunk);
				
				int getBinaryFileSize();
					//0 to 2,147,483,647 bytes on 32bit sys(2.1ish gb max File Size)
					
				int getChunkSize();

				int calculateNumChunksInFile();
};

#endif // Header guard end