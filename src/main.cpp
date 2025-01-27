#include <iostream>

template <class T>
constexpr T speed_of_light = T(299'792'458);

int main(){
std::cout << speed_of_light <double> << '\n';
std::cout << speed_of_light <float> << '\n';
std::cout << speed_of_light <int> << '\n';
std::cout << speed_of_light <long> << '\n';
}
