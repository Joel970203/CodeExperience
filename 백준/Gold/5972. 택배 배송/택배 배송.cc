#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; 

int N, M;
vector<vector<pair<int, int>>> arr;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist.assign(N + 1, INF);
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node]) continue;

        for (auto& edge : arr[node]) {
            int w = edge.first;
            int next = edge.second;

            if (dist[node] + w < dist[next]) {
                dist[next] = dist[node] + w;
                pq.push({ dist[next], next });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    arr.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({ w, v });
        arr[v].push_back({ w, u });
    }

    dijkstra(1);

    cout << dist[N] << "\n";

    return 0;
}