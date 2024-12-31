#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = s.length();
    
    if(cnt % 2 == 0)
    {
        int k = (cnt / 2);
        int kk = k-1;
        answer += s[kk];
        answer += s[k];
    }
    
    else
    {
        int k = ceil(cnt/2);
        answer += s[k];
    }
    return answer;
}