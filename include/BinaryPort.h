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
			//PRIVATE VARIABLES [Users please ignore these]
				//Universal fstream Variable
					std::fstream filer;
					
				//File Related Information
					std::string filePath = "no_set_target";
					
				//Class State Information & Logic
					enum class state {
						FREE = 0,
						SUPPLANT = 1,
						READ = 2,
						APPEND = 3
					};
					
					state currentState;
				
					void stateChanger(state code);
					
					void fileOpenedErrorCheck();
				
		public:	
			// (Setters & Getters)
				void setFilePath(std::string input);
				int checkChunkSize();//Returns value in bytes
				std::string getFilePath();
				
			//Analysis Methods
				std::streampos checkBinFileSize();
					/*Returns the number of bytes in target Binary file.
					Might not be needed in all honesty since reading in you can just
					count the chunks given you know their size*/
			
			//Reading
				void read(Chunk readReturn);
					/*Reads the next chunk in the file.
					This chunks value is then copied to the passed chunk.
					Note that both the passed chunk and file chunk have to be the same.
					Each read moves the cursor 1 chunk, allowing for repeated reads 
					to read the whole file.*/
			
			//Supplanting
				void supplant(Chunk data);
					/*Wipes or creates target file from scratch and begins writing chunks.
					Cursor moves with chunks allowing for repeated writes.*/
			
			//Appending
				void append(Chunk data);
					/*Writes new Chunks to the end of a target file.
					If the target file does not exist it will be made.
					Cursor moves with appended writes allowing for repeated writes.*/
					
			//Manual File Closeing
				void fileClose();
					/*If you close a file when your done, it prevents the OS from freezing
					its use from other processes and can reduce data loss if the program 
					closes abbruptly*/
};

#include "BinaryPort.tpp"

#endif // Header guard end