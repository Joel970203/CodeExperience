#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = false;
    int k = s.length();
    
    if(k == 4 || k == 6)
    {
        for(int i=0;i<k;i++)
        {
            int start = s[i] - '0';
            if(start < 0 || start > 9)
            {
                return answer;
            }
        }
        answer = true;
    }
    return answer;
}