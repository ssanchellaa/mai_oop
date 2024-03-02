#include "five.hpp"
#include <algorithm>

using namespace std;

bool is_digit_under_five(char s) {
    return (0 <= s - '0') && (s - '0' < 5);
}

Five::Five() : length{0}, number{nullptr} {}

Five::Five(const initializer_list<unsigned char> & t) {
    initializer_list<unsigned char>::iterator it = t.begin();
    while (*it == '0') {
        ++it;
    }
    if (it == t.end()) {
        --it;
    }
    length = t.end() - it;
    number = new unsigned char[length];
    for (int i = 0; i < length; ++i) {
        int j = t.size() - 1 - i;
        if (!is_digit_under_five(*(t.begin() + j))) throw logic_error("Error occured. Digits must be under 5.");
        number[i] = *(t.begin() + j);
    }
}


Five::Five(const string & t) {
    int start_idx = 0;
    while (t[start_idx] == '0') {
        ++start_idx;
    }
    if (start_idx == t.size()) {
        --start_idx;
    }
    length = t.size() - start_idx;
    number = new unsigned char[length];
    for (int i = 0; i < length; ++i) {
        int j = t.size() - 1 - i;
        if (!is_digit_under_five(t[j])) throw logic_error("Error occured. Digits must be under 5.");
        number[i] = t[j];
    }
}
Five::Five(const Five & other) {
    number = new unsigned char[other.length];
    length = other.length;

    for (int i = 0; i < length; i++) {
        number[i] = other.number[i];
    }
}

Five::~Five() noexcept {
    if (length > 0) {
        length = 0;
        delete[] number;
        number = nullptr;
    }
}

int Five::size() const noexcept {
    return length;
}

unsigned char* Five::array() const noexcept {
    return number;
}

ostream& operator<<(ostream & os, const Five & t) {
    int i = t.size();
    while(i--) {
        os << t.array()[i];
    }
    return os;
}

Five& Five::operator=(const Five & t) {
    if (length > 0) {
        delete[] number;
    }
    length = t.length;
    number = new unsigned char[length];

    for (int i = 0; i < length; ++i) {
        number[i] = t.number[i];
    }

    return *this;
}

bool Five::operator==(const Five & t) const {
    if (length != t.length) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (number[i] != t.number[i]) {
            return false;
        }
    }
    return true;
}

bool Five::operator!=(const Five & t) const {
    return !(*this == t);
}

bool Five::operator>(const Five & t) const {
    if (length != t.length) {
        return length > t.length;
    }
    int i = length;
    while(i--) {
        if (number[i] != t.number[i]) {
            return number[i] > t.number[i];
        }
    }
    return false;
}

bool Five::operator>=(const Five & t) const {
    return (*this > t) || (*this == t);
}

bool Five::operator<(const Five & t) const {
    return !(*this >= t);
}

bool Five::operator<=(const Five & t) const {
    return !(*this > t);
}

Five Five::operator+(const Five & t) {
    int final_length = max(length, t.length) + 1;
    string res(final_length, '0');

    for (int i = 0; i < final_length - 1; i++) {
        int sum = ((i < length) ? number[i] - '0' : 0) + ((i < t.length) ? t.number[i] - '0' : 0);
        res[i + 1] += (res[i] - '0' + sum) / base;
        res[i] = (res[i] - '0' + sum) % base + '0';
    }

    reverse(res.begin(), res.end());

    return Five(res);
}

Five Five::operator-(const Five & t) {
    if (*this < t) {
        throw logic_error("Error occured. Result must be positive.");
    }

    if (*this == t) {
        return Five("0");
    }

    int final_length = max(length, t.length);
    string res(final_length, '0');

    for (int i = 0; i < final_length - 1; i++) {
        res[i] += number[i] - '0' - ((i < t.length) ? t.number[i] - '0' : 0);
        if (res[i] - '0' < 0) {
            res[i] += base;
            res[i + 1] -= 1;
        }
    }
    res[final_length - 1] += number[final_length - 1] - '0' - ((final_length == t.length) ? t.number[final_length - 1] - '0' : 0);

    reverse(res.begin(), res.end());

    return Five(res);
}