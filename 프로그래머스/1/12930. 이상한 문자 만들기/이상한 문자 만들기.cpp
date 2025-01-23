#include <string>
#include <cctype> // toupper, tolower 함수 사용
using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0; 

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') 
        {
            answer += ' ';
            index = 0;
        } else 
        {
            if (index % 2 == 0) 
            {
                answer += toupper(s[i]);
            }
            else 
            {
                answer += tolower(s[i]);
            }
            index++;
        }
    }
    return answer;
}
