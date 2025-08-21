#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>()); // 내림차순 정렬
    
    int answer = 0;
    for (int i = 0; i < citations.size(); i++) 
    {
        // i번째 논문은 citations[i]번 인용됨
        // i+1 편이 citations[i] 이상 인용되었다면
        // 6 5 3 1 0 
        if (citations[i] >= i+1) 
        {
            answer = i+1;
        } 
        else break;
    }
    return answer;
}
