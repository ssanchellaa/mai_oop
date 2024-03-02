#include <iostream>
//#include <string>
#include "func.hpp"
using namespace std;


int main(){
    string stroka;
    string stroka2;
    std::cin >> stroka;
    stroka2 = foo(stroka);
    std::cout << stroka2 << std::endl;
    return 0;
}