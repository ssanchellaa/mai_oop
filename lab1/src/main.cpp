#include <iostream>

#include "translate_into_turkish.hpp"

int main(){
    int number;
    std::cout << "Введите число от 0 до 99 включительно: ";
    std::cin >> number;

    std::string TurkishName = TranslateIntoTurkish(number);

    std::cout << "Турецкое название числа: " << TurkishName << std::endl;


}