#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for(int i=0;i<n;i++)
    {
        int k = x * (i+1);
        answer.push_back({k});
    }
    return answer;
}