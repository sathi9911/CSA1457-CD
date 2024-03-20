#include <iostream>
#include <string>

int main() {
    std::string arr[18][3] = {
        {"E", "+", "F"}, {"E", "*", "F"}, {"E", "(", "F"}, {"E", ")", "F"}, {"E", "i", "F"},
        {"E", "$", "F"}, {"F", "+", "F"}, {"F", "*", "F"}, {"F", "(", "F"}, {"F", ")", "F"},
        {"F", "i", "F"}, {"F", "$", "F"}, {"T", "+", "F"}, {"T", "*", "F"}, {"T", "(", "F"},
        {"T", ")", "F"}, {"T", "i", "F"}, {"T", "$", "F"},
    };

    std::string prod = "EETTFF";
    std::string res[6][3] = {
        {"E", "+", "T"}, {"T", "", ""}, {"T", "*", "F"}, {"F", "", ""}, {"(", "E", ")"}, {"i", "", ""},
    };

    std::string stack[5][2];
    int top = -1;

    // Your logic here...

    return 0;
}

