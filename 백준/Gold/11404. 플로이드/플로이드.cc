#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; 

int n, m;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start) 
{
    vector<int> dist(n + 1, INF); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (const auto& next : graph[cur]) 
        {
            int nextCost = cost + next.first;
            int nextNode = next.second;

            if (nextCost < dist[nextNode]) 
            {
                dist[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }
    return dist;
}

int main()
{
    cin >> n >> m;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ w, v }); 
    }

    vector<vector<int>> result(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        vector<int> dist = dijkstra(i);
        for (int j = 1; j <= n; j++) 
        {
            if (dist[j] == INF) result[i][j] = 0;
            else result[i][j] = dist[j];
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
