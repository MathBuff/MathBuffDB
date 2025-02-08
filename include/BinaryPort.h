#ifndef _LM_BINARYPORT_H_  
#define _LM_BINARYPORT_H_ 
#include <iostream>
#include <fstream>
#include <string>

/*This class takes fstream and simplifies its operations
for reading and writing a target binary file.
The binary files being read here are intended to be organized 
in predicatable chunks of generalized type.

I put in a template because, 
if you wanted to have a binary file of integers,
all you have to do is pass int for chunk.

If you wanted to have a binary file of a certain
structure, all you have to do is pass that structure
for chunk.
*/

template <typename Chunk>
class BinaryPort{
	
		private:
			//PRIVATE VARIABLES
				//Universal fstream Variable
					std::fstream filer;
				//File Related Information
					std::string filePathTarget;
					int chunkSize;
					
				//Class State Information & Logic
					enum class state {
						FREE = 0,
						SUPPLANT = 1,
						READ = 2,
						APPEND = 3
					};
					
					state currentState;
				
					void stateChanger(state code);
				
		public:	
			// (Setters & Getters)
				
				void setFilePathTarget(std::string input);
				void setChunkSize(int chunkBytes);
				
				std::string getFilePath();
				int getChunkSize();
				
			//Analysis Methods
				
				int checkBinFileSize();
					//Returns the number of bytes in target Binary file

				int checkBinFileChunkCount();
					//Calculates number of chunks if a file.
			
			//Reading
				Chunk readChunk();
					/*Reads the next chunk in the file.
					Each read moves the cursor 1 chunk, allowing for repeated reads 
					to read the whole file.
					*/
			
			//Supplanting
				void supplantChunk(Chunk data);
					/*Wipes or creates target file from scratch and begins writing chunks.
					Cursor moves with chunks allowing for repeated writes.*/
			
			//Appending
				void appendChunk(Chunk data);
					/*Writes new Chunks to the end of a target file.
					If the target file does not exist it will be made.
					Cursor moves with appended writes allowing for repeated writes.*/
					
				void printFuck();
};

#include "BinaryPort.tpp"

#endif // Header guard end