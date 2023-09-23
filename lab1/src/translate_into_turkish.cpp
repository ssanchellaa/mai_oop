#include "../src/translate_into_turkish.hpp"

std::string TranslateIntoTurkish(int number){
    const std::string units[] = {"sıfır", "bir", "iki", "üç", "dört", "beş", "altı", "yedi", "sekiz", "dokuz"};
    const std::string tens[] = {"", "on", "yirmi", "otuz", "kırk", "elli", "altmış", "yetmiş", "seksen", "doksan"};

    if (number >= 0 && number <= 9){
        return units[number];
    }else if (number >= 10 && number <= 99){
        int unit = number % 10;
        int ten = number - number % 10; 

        if (unit == 0){
            return tens[ten / 10];
        }else{
            return tens[ten / 10] + " " + units[unit];
        }
    }
    return "Число не подходит. Пожалуйста, введите число от 0 до 99 включительно";
}