#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> computers(n + 1); 
    vector<int> indegree(n + 1, 0);     
    vector<vector<int>> graph(n + 1); 
    vector<int> dp(n + 1, 0);           
    \
    for (int i = 1; i <= n; i++)
    {
        cin >> computers[i].first >> computers[i].second;
    }
    \
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (computers[j].first == computers[i].first + 1) \
            {
                graph[i].push_back(j);
                indegree[j]++;
            }
        }
    }

    queue<int> q;
    \
    for (int i = 1; i <= n; i++)
    {
        if (computers[i].first == 1)
        {
            dp[i] = computers[i].second;  // 계급 1은 바로 실행
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            int transferTime = (cur - next) * (cur - next);  \
            dp[next] = max(dp[next], dp[cur] + transferTime + computers[next].second);  // dp[next] 갱신
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    \
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
