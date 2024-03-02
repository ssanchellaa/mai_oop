#pragma once
#include <string>
#include <iostream>

using namespace std;

class Five {
public:
    Five();
    Five(const initializer_list<unsigned char> & t);
    Five(const string & t);
    Five(const Five & other);
    bool operator==(const Five & t) const;
    bool operator!=(const Five & t) const;
    bool operator>(const Five & t) const;
    bool operator>=(const Five & t) const;
    bool operator<(const Five & t) const;
    bool operator<=(const Five & t) const;
    Five& operator=(const Five & t);
    Five operator+(const Five & t);
    Five operator-(const Five & t);
    int size() const noexcept;
    unsigned char* array() const noexcept;
    ~Five() noexcept;
private:
    int length;
    unsigned char* number;
    const int base = 5;
};

ostream& operator<<(ostream & os, const Five & t);