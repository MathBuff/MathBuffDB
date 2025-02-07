#ifndef _LM_BinaryLOAD_CHUNK_1_H_  
#define _LM_BinaryLOAD_CHUNK_1_H_ 
struct Chunk {
	//Some set of Data variables of common size
		float float1;
		float float2;
		float float3;
		int integer;

	//Some sort of initialization in case we miss stuff in writing.
		Chunk(float f1 = 0.0f, float f2 = 0.0f, float f3 = 0.0f, int i = 0)
			: float1(f1), float2(f2), float3(f3), integer(i) {} 
			//Initialization list sets all to 0.

    // Write functions to Serialize Data to a binary format (order Matters)
		void writeToFile(std::ofstream &outFile) const {	//We pass in parameters after pointer refference
			outFile.write(reinterpret_cast<const char*>(&float1), sizeof(float));
			outFile.write(reinterpret_cast<const char*>(&float2), sizeof(float));
			outFile.write(reinterpret_cast<const char*>(&float3), sizeof(float));
			outFile.write(reinterpret_cast<const char*>(&integer), sizeof(int));
		}

    // Deserialize Data from a binary format (should be same order as writing it)
		void readFromFile(std::ifstream &inFile) {
			inFile.read(reinterpret_cast<char*>(&float1), sizeof(float));
			inFile.read(reinterpret_cast<char*>(&float2), sizeof(float));
			inFile.read(reinterpret_cast<char*>(&float3), sizeof(float));
			inFile.read(reinterpret_cast<char*>(&integer), sizeof(int));
		}
	
	
	//Print Function For convience.
		void print() const {
			std::cout << "Floats: " << float1 << ", " << float2 << ", " << float3<<std::endl;
			std::cout<< "Associated Integer: " << integer << std::endl;
		}
};

#endif // Header guard end