#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;

pair<vector<int>,int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start, int end) {
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int answer;
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        if (u == end)
        {
            answer = d; 
            break;
        }

        for (auto [w, v] : graph[u]) 
        {
            if (dist[v] > d + w) 
            {
                dist[v] = d + w;
                parent[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }

    for (int i = end; i != -1; i = parent[i])
    {
        ans.push_back(i);
    }

    reverse(ans.begin(), ans.end());

    return { ans,answer };
}

int main() 
{
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ w, v }); // 단방향
    }

    int s, e;
    cin >> s >> e;

    auto[arr,cnt] = dijkstra(graph, s, e);

    cout << cnt << "\n" << arr.size() << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

}
