#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string expression;
    cin >> expression;

    int result = 0;
    stringstream ss;
    ss << expression;

    int number;
    char operation;
    ss >> number;
    result += number;

    bool minus_found = false;

    while (ss >> operation >> number) {
        if (operation == '-') {
            minus_found = true;
        }

        if (minus_found) {
            result -= number;
        }
        else {
            result += number;
        }
    }

    cout << result << endl;
    return 0;
}
