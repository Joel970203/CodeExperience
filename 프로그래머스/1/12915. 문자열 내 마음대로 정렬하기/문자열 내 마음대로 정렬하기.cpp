#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> solution(vector<string> strings, int n) 
{
    sort(strings.begin(), strings.end(), [n](const string &a, const string &b)
         {
            if (a[n] == b[n]) return a < b; // 같은 경우, 사전 순으로 정렬
            return a[n] < b[n];  // n번째 문자 기준으로 정렬
         });
    return strings;
}