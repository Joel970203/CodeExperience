#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    unordered_map<char, int> lastIndex; 
    vector<int> result;

    for (int i = 0; i < s.size(); i++) {
        char currentChar = s[i];
        if (lastIndex.find(currentChar) != lastIndex.end()) {
           
            result.push_back(i - lastIndex[currentChar]);
        } else {
            result.push_back(-1);
        }
        lastIndex[currentChar] = i; 
    }

    return result;
}
