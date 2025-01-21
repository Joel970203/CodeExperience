#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int main() {
    fastio();

    int N, M, A, B;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);
    vector<int> result;  

    for (int i = 0; i < M; i++) 
    {
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0) 
        {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int next : graph[cur]) 
        {
            indegree[next]--;
            if (indegree[next] == 0) 
            {
                q.push(next);
            }
        }
    }

    if (result.size() == N) 
    {
        for (int i = 0; i < N; i++) 
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
