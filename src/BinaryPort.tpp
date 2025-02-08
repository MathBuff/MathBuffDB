#include "BinaryPort.h"
#include <filesystem>

//Private:

			template <typename Chunk>
			void BinaryPort<Chunk>::stateChanger(state code){
				switch(code){
					
					case state::FREE:
							std::cout<<"FREE"<<std::endl;
							filer.close();
						break; 
						
					case state::SUPPLANT:
						if(currentState == state::SUPPLANT){
							//Nothing needs to be done
						}
						else{
							filer.open(filePathTarget, std::ios::out | std::ios::binary);
							//if you are writing binary with the fstream object
							
							currentState = state::SUPPLANT;
							
							std::cout<<"SUPPLANT"<<std::endl;
						}
						break;
						
					case state::READ:
						if(currentState == state::READ){
							//Nothing needs to be done
							
						}
						else{
					
							filer.open(filePathTarget, std::ios::in | std::ios::binary);
							//if you are reading binary with the fstream object
							
							std::cout<<"READ"<<std::endl;
						}
						break;
						
					case state::APPEND:
						if(currentState == state::APPEND){
							//Nothing needs to be done
						}
						else{
					
							filer.open(filePathTarget, std::ios::app | std::ios::binary);
							//if you are appending binary with the fstream object
							
							std::cout<<"APPEND"<<std::endl;
						}
						break;
					}	
			}
				
//public:	
		// (Setters & Getters)
		
			template <typename Chunk>
			void BinaryPort<Chunk>::setFilePathTarget(std::string input){
				
			}
			
			template <typename Chunk>
			void BinaryPort<Chunk>::setChunkSize(int chunkBytes){
				
			}
			
			template <typename Chunk>
			std::string BinaryPort<Chunk>::getFilePath(){
				return "";
			}
			
			template <typename Chunk>
			int BinaryPort<Chunk>::getChunkSize(){
				return 1;
			}
			
		//Analysis Methods
			
			template <typename Chunk>
			int BinaryPort<Chunk>::checkBinFileSize(){
				return 1;
			}
				

			template <typename Chunk>
			int BinaryPort<Chunk>::checkBinFileChunkCount(){
				return 1;
			}
				
		
		//Reading
			template <typename Chunk>
			Chunk BinaryPort<Chunk>::readChunk(){
				Chunk A;
				return A;
			}	
		
		//Supplanting
			template <typename Chunk>
			void BinaryPort<Chunk>::supplantChunk(Chunk data){
				
			}
			
		
		//Appending
			template <typename Chunk>
			void BinaryPort<Chunk>::appendChunk(Chunk data){
				
			}
			
			template <typename Chunk>
			void BinaryPort<Chunk>::printFuck(){
				std::cout<<"FUCK"<<std::endl;
				state A = state::FREE;
				stateChanger(A);
			}