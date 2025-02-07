#ifndef _LM_BinaryLOAD_H_  
#define _LM_BinaryLOAD_H_

#include <iostream>

class BinaryLoad{
	private:
	
	public:
		//Controlers
				void loadMemory(std::string loadFilePath);
					//Loads in Memory from File
				void printMemory();
				
				void saveMemory(std::string saveFilePath);
				
				void clearMemory();
				
				int getChunkMemory(int chunkMemoryLocation); //not sure what the return should be here
				
				void reWriteChunk(int chunkMemoryLocation);
	
	
};

#endif // Header guard end