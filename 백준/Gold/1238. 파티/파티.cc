#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector<int> dijkstra(int N, const vector<vector<pair<int, int>>>& graph, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N + 1, INT_MAX);
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currPos = pq.top().second;
        pq.pop();

        if (currDist > dist[currPos])
            continue;

        for (auto& road : graph[currPos]) {
            int nextPos = road.first;
            int shortcutDist = road.second;

            if (dist[nextPos] > currDist + shortcutDist) {
                dist[nextPos] = currDist + shortcutDist;
                pq.push({ dist[nextPos], nextPos });
            }
        }
    }

    return dist;
}

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<pair<int, int>>> reverseGraph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        reverseGraph[b].push_back({ a, c }); // 역방향 그래프 생성
    }

    // X에서 모든 노드로의 최단 거리
    vector<int> distFromX = dijkstra(N, graph, X);
    // 모든 노드에서 X로의 최단 거리
    vector<int> distToX = dijkstra(N, reverseGraph, X);

    int maxTime = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        int roundTripTime = distFromX[i] + distToX[i];
        maxTime = max(maxTime, roundTripTime);
    }

    cout << maxTime << endl;

    return 0;
}