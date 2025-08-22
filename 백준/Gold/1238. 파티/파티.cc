#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<int> dijkstra(const vector<vector<pair<int,int>>> &graph, int start, int N) {
    vector<int> dist(N+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {cost, node}

    while (!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();

        if (cost > dist[node]) continue;

        for (auto [w, next] : graph[node]) {
            if (dist[next] > cost + w) {
                dist[next] = cost + w;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X; 
    cin >> N >> M >> X; // N=학생 수(마을), M=도로 수, X=파티 장소

    vector<vector<pair<int,int>>> graph(N+1);
    vector<vector<pair<int,int>>> rev_graph(N+1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});     // 정방향
        rev_graph[v].push_back({w, u}); // 역방향
    }

    // X → i
    vector<int> dist_from_X = dijkstra(graph, X, N);

    // i → X (역그래프에서 X 출발하면 됨)
    vector<int> dist_to_X = dijkstra(rev_graph, X, N);

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (dist_from_X[i] == INF || dist_to_X[i] == INF) continue;
        answer = max(answer, dist_from_X[i] + dist_to_X[i]);
    }

    cout << answer << "\n";
}
