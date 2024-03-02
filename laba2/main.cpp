#include "five.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Five elem1{'0', '0', '2', '0', '0'};
    Five elem2;
    string a = "010";
    elem2 = Five(a);

    Five sum = elem1 + elem2;
    Five diff = elem1 - elem2;

    cout << elem1 << ' ' << elem2 << endl;
    cout << sum << endl;
    cout << diff << endl;

    return 0;
}