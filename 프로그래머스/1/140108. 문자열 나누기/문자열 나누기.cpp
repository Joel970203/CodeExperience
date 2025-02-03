#include <string>
using namespace std;

int solution(string s) {
    int answer = 0;
    int count_x = 0, count_other = 0;
    char x = s[0];
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == x) {
            count_x++;
        } else {
            count_other++;
        }
        
        if (count_x == count_other) {
            answer++;
            if (i + 1 < s.length()) {
                x = s[i + 1]; 
            }
            count_x = count_other = 0;
        }
    }

    if (count_x != 0 || count_other != 0) {
        answer++;
    }

    return answer;
}
