#include "BinaryPort.h"
#include <filesystem>

//Private:

	template <typename Chunk>
	void BinaryPort<Chunk>::stateChanger(state code){
		switch(code){
			
			case state::FREE:
					//std::cout<<"FREE"<<std::endl;
					currentState = state::FREE;
					filer.close();
				break; 
				
			case state::SUPPLANT:
				if(currentState == state::SUPPLANT){
					//Nothing needs to be done
				}
					else{
						filer.open(filePath, std::ios::out | std::ios::binary);
						currentState = state::SUPPLANT;
						//std::cout<<"SUPPLANT"<<std::endl;
						fileOpenedErrorCheck();
					}
				break;
				
			case state::READ:
				if(currentState == state::READ){
					//Nothing needs to be done
					
				}
					else{
						filer.open(filePath, std::ios::in | std::ios::binary);
						currentState = state::READ;
						//std::cout<<"READ"<<std::endl;
						fileOpenedErrorCheck();
					}
				break;
				
			case state::APPEND:
				if(currentState == state::APPEND){
					//Nothing needs to be done
				}
					else{
						filer.open(filePath, std::ios::app | std::ios::binary);
						currentState = state::APPEND;
						//std::cout<<"APPEND"<<std::endl;
						fileOpenedErrorCheck();
					}
				break;
			}	
	}
			
	template <typename Chunk>
	void BinaryPort<Chunk>::fileOpenedErrorCheck(){
		if(filer.is_open()){
			//No error
		}
		else{
			throw std::ios_base::failure("BinaryPort Failed to open the Target file");
		}
	}

//public:	
	//(Setters & Getters)

		template <typename Chunk>
		void BinaryPort<Chunk>::setFilePath(std::string input){
			this->filePath = input;
		}
		
		template <typename Chunk>
		int BinaryPort<Chunk>::checkChunkSize(){
			Chunk instance;
			return sizeof(instance);
		}
		
		template <typename Chunk>
		std::string BinaryPort<Chunk>::getFilePath(){
			
			return this->filePath;
		}

	//Analysis Methods
		
		template <typename Chunk> //Need to test this
			std::streampos BinaryPort<Chunk>::checkBinFileSize(){
			stateChanger(state::FREE);
			filer.open(filePath, std::ios::binary);
			
			filer.seekg(0, std::ios::end); // Move the file cursor to the end
			std::streampos fileSize = filer.tellg();
			stateChanger(state::FREE);
			
			return fileSize;
		}
	
	//Reading
		template <typename Chunk> //Need to test
		void BinaryPort<Chunk>::read(Chunk readReturn){
			stateChanger(state::READ);
			filer.read(reinterpret_cast<char*>(&readReturn), sizeof(readReturn));
		}	
	
	//Supplanting
		template <typename Chunk>
		void BinaryPort<Chunk>::supplant(Chunk data){
			stateChanger(state::SUPPLANT);
			filer.write(reinterpret_cast<char*>(&data), sizeof(data));
		}
		
	
	//Appending
		template <typename Chunk>
		void BinaryPort<Chunk>::append(Chunk data){
			stateChanger(state::APPEND);
			filer.write(reinterpret_cast<char*>(&data), sizeof(data));
		}
		
	//Print Text Function
		template <typename Chunk>
		void BinaryPort<Chunk>::printFuck(){

			std::cout<<"FUCK"<<std::endl;
		}