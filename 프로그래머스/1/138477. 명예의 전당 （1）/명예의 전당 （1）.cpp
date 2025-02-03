#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq; 

    for (int i = 0; i < score.size(); i++) {
        pq.push(score[i]);

        if (pq.size() > k) {
            pq.pop();
        }

        answer.push_back(pq.top());
    }

    return answer;
}
