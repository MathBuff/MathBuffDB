#include<iostream>
#include<iomanip>
#include "Test.h"

template<typename T>
constexpr T pi = T{3.14159265};


int main(){
	std::cout<<"\n==Start==\n";
	
	std::cout<< std::setprecision(20)<<pi<long double>;
	
	std::cout<<"\n--End--\n\n";
	return 0;
}
