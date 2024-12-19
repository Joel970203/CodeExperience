#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    unordered_set<char> skipSet(skip.begin(), skip.end());
    vector<char> validChars;
    for (char c = 'a'; c <= 'z'; c++) {
        if (skipSet.find(c) == skipSet.end()) {
            validChars.push_back(c);
        }
    }

    int validSize = validChars.size();

    string result = "";
    for (char c : s) {
        int currentIndex = find(validChars.begin(), validChars.end(), c) - validChars.begin();

        int newIndex = (currentIndex + index) % validSize;

        result += validChars[newIndex];
    }

    return result;
}