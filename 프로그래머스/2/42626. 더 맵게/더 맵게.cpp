#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]);
    }
    
while (!pq.empty()) {
        int minimal = pq.top();
        if (minimal >= K) return answer;  // 모든 음식이 K 이상

        // 남은 게 하나뿐인데 아직 K 미만이면 실패
        if (pq.size() < 2) return -1;

        // 두 개 뽑아서 섞기
        pq.pop();
        int second_minimal = pq.top(); pq.pop();
        pq.push(minimal + (second_minimal*2));
        answer++;
    }
    return -1;
}