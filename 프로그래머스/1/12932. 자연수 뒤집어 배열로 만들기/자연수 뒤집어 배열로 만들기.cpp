#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(1)
    {
        if(n<10)
        {
            answer.push_back(n);
            break;
        }
        int k = n % 10;
        answer.push_back(k);
        n /= 10;
    }
    return answer;
}