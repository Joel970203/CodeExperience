#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.length(); i++) {
        if('A' <= s[i] && s[i] <= 'Z') {  // 대문자
            int key = s[i] + n;
            if(key > 'Z') {
                key -= 26;
            }
            char change = key;
            answer += change;
        }
        else if('a' <= s[i] && s[i] <= 'z') {  // 소문자
            int key = s[i] + n;
            if(key > 'z') {
                key -= 26;
            }
            char change = key;
            answer += change;
        }
        else {  // 공백인 경우
            answer += " ";
        }
    }

    return answer;
}
