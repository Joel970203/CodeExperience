#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);
    vector<int> semester(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            semester[i] = 1; 
        }
    }

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int next : graph[current])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
                semester[next] = semester[current] + 1; 
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << semester[i] << " ";
    }
    cout << endl;

    return 0;
}