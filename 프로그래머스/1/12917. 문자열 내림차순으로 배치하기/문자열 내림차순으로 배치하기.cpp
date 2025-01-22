#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), [](char a, char b) {
        if (a == b) return false;
        if (isupper(a) && islower(b)) return false;
        if (islower(a) && isupper(b)) return true;  
        return a > b;
    });
    return s;
}
