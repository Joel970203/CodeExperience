#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pLen = p.length();
    
    for (int i = 0; i <= t.length() - pLen; i++) {
        string tmp = t.substr(i, pLen);
        long tmpInt = stol(tmp), pInt = stol(p);
        
        if (tmpInt <= pInt) answer += 1;
    }
    return answer;
}