#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    queue<pair<int, int>> q;

    for (int i = 0; i < progresses.size(); i++) 
    {
        q.push({progresses[i], speeds[i]});
    }

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++) 
        {
            auto cur = q.front(); q.pop();
            int new_progress = cur.first + cur.second;
            q.push({new_progress, cur.second});
        }

        int cnt = 0;
        while (!q.empty() && q.front().first >= 100) 
        {
            q.pop();
            cnt++;
        }

        if (cnt > 0) 
        {
            answer.push_back(cnt);
        }
    }

    return answer;
}
